from PIL import Image, ImageOps

import numpy as np
from numpy import asarray

#for sqrt() and floor()
import math

def myImageInverse(in_matrix):
	#get width and height of image
	rows, cols = in_matrix.shape

	#create new blank pixel array of the same size
	out_matrix = np.zeros(shape=(rows,cols))

	#loop through every pixel
	for row in range(rows):
		for col in range(cols):
			#set pixel of same location in new array to the inverse value of the old pixel
			out_matrix[row][col] = 255 - in_matrix[row][col]

	return out_matrix

def myImageResize(in_matrix, rows, cols, type):
	#This function resizes an image using interpolation, by using the formula (M/M') to find the scaler value
	#Nearest Neighbor then takes the new pixel after scaler multiplied by the current row/col and floors it to set it to the nearest valid pixel
	#Bilinear takes the new pixel after scaler multiplied by the current row/col, floors it, then usses that as the left corner. It then finds the other 3 corners and uses matrix multiplacation to find the new pixel value
	#myImageResize takes in an image pixel matrix, two ints determining the width and height of the new image, and the type of interpolation method to do
	#the function outputs a new matrix that has been resized

	#sets M and N to original image's dimensions
	M, N = in_matrix.shape
	#creates new matrix with the size of new resized image
	out_matrix = np.zeros(shape=(rows,cols))
	#loop through pixel in every row and column in the new image
	for row in range(rows):
		for col in range(cols):
			#set newx and newy to be the mapped pixel, by applying the scaler M/M' and then applying it to each row and col in the loop
			newx = (M/rows);
			newy = (N/cols);
			#nearest neighbor
			if type == 'nearest':
				#multiply the scalar (newxy) by the current row/col, then round down to assign to the closest usable (int) pixel
				if newx <= 1:
					nearx = math.floor(newx*row)
				elif newx > 1:
					nearx = math.ceil(newx*row)
				if newy <= 1:
					neary = math.floor(newy*col)
				elif newy > 1:
					neary = math.ceil(newy*col)

				#set the next pixel in the new image to the pixel value at the nearx and neary
				out_matrix[row][col] = in_matrix[nearx][neary]
			#bilinear
			if type == 'bilinear':
				#round down the newx and newy multiplied by the current row and col and set to bix and biy
				bix = math.floor(newx*row)
				biy = math.floor(newy*col)
				#set our x1 and y1 to bix and biy, and then p1 to the value at that pixel in the original image
				x1 = bix
				y1 = biy
				p1 = in_matrix[x1][y1]
				#set x2 to the pixel to the right of bix, y2 = y1
				x2 = bix+1
				y2 = biy
				#if bix+1 is a valid pixel in bounds, set p2 to that value
				if(bix+1 < M):
					p2 = in_matrix[x2][y2]
				else:
					#if not, set p2 to the same value of p1
					p2 = in_matrix[x1][y1]
				#set y3 to the pixel below y1, x3 = x1
				x3 = bix
				y3 = biy+1
				#if biy+1 is valid, set p3 to that pixel value
				if(biy+1 < N):
					p3 = in_matrix[x3][y3]
				else:
					#if not set to x1 and y1
					p3 = in_matrix[x1][y1]
				#set x4 and y4 to the diagonal from x1 y1
				x4 = bix+1
				y4 = biy+1
				#if its a valid pixel, set p4 to that pixel
				if(bix+1 < M and biy+1 < N):
					p4 = in_matrix[x4][y4]
				else:
					#if not, set that pixel value to x1 y1
					p4 = in_matrix[x1][y1]
				#set the new pixel to find to newx and newy multiplied by current row and col
				x5 = newx * row;
				y5 = newy * col;
				#set the curr pixel in new image to result of mybilinear
				out_matrix[row][col] = mybilinear(x1,y1,p1,x2,y2,p2,x3,y3,p3,x4,y4,p4,x5,y5)
	#return our new image
	return out_matrix

def myRMSE(matrix1,matrix2):
	#This function calculates the Root Mean Square Error between the pixel values of 2 images: The orignal and one that has been interpolated
	#this function takes in 2 matrices with the same dimensions
	#it outputs an int value of the Root Mean Square Error, there being a XX% difference 

	#set M and N to dimensions of the first image (and the second techincally)
	M, N = matrix1.shape
	#variable to store sum
	RMSE = 0
	#loop through every pixel
	for m in range(M):
		for n in range(N):
			#add to RMSE the square of pixel value of image 1 minues pixel value of image 2
			RMSE += (matrix1[m][n] - matrix2[m][n])**2
	#once we do that for every pixel, divide RMSE by the area of the image, and square root it
	RMSE = math.sqrt(RMSE/(M*N))
	#return the RMSE value
	return RMSE;


def mybilinear(x1,y1,p1,x2,y2,p2,x3,y3,p3,x4,y4,p4,x5,y5):
	#This function mybilinear creates 3 Matricies: One containing x,y,x*y,1 for every xy pair, one with the p values, and one to be found that has the scalers a,b,c,d
	#It then inverses matrix A (x,y,x*y,1) and multiplies it by MatrixH (p1,p2,p3,p4), setting the results to MatrixG (a,b,c,d)
	#It then uses the formula ax + by + cxy + d to find the new pixel value
	#This function takes in 4 pairs of and x coord, y coord, and the pixel value at the point, as well as x5 and y5 being the new value to find at that pixel
	#It outputs a pixel value for x5 and y5

	#create a matrix storing the x value, y value, x*y value, and 1 for all 4 corners
	MatrixA = np.array([[x1,y1,x1*y1,1],[x2,y2,x2*y2,1],[x3,y3,x3*y3,1],[x4,y4,x4*y4,1]])
	#inverse matrix A
	InverseA = np.linalg.inv(MatrixA)
	#create a matrix storing the p values
	MatrixH = np.array([p1,p2,p3,p4])
	#multiply Matrix H by the Inverse of Matrix A to find a,b,c,d
	MatrixG = np.matmul(InverseA,MatrixH)

	#use the formula ax + by + cxy + d, round it, and return it
	return round(MatrixG[0]*x5 + MatrixG[1]*y5 + MatrixG[2]*x5*y5 + MatrixG[3])

