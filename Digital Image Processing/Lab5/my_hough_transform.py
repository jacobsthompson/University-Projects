#my_hough_transform.py

#Import numpy
import numpy as np
#Import math library
import math

def my_hough_transform(i_edge):
	#my_hough_transform applies the hough transform to the input edge image
	#by finding the theta and row angles to each edge pixel and plots it into accumulator for every pixel
	#Input: i_edge is an image that has had edge detection done to it
	#Output: theta_out is the theta value on the most accumulated pixel
	#		 rho_out is the rho value on the most accumulated pixel
	#		 accumulator is the image with all rho and theta values plotted to it
	#Created by Jacob Thompson


	#find width and height of edge image
	rows, cols = i_edge.shape
	#find the diagonal length of the image using c = √(a^2+b^2)
	diagonal = int(np.ceil(np.sqrt(rows**2 + cols**2)))
	#create the accumulator image with the rows being all values of rho (2*diagonal+1) and theta (180: -89 to 90)
	accumulator = np.zeros(shape=(2*diagonal+1,180))
	#loop through every pixel i_edge
	for row in range(rows):
		for col in range(cols):
			#loop through every theta value for every pixel
			for theta in range(180):
				#convert theta-89 (so 0 = -89, 1 = -88, etc) to radians
				rad = math.radians(theta-89)
				#calculate rho using the formula p = xcos0 + ysin0, and add +diagonal to center the image
				rho = int(row*math.cos(rad) + col*math.sin(rad)) + diagonal
				#make sure only to count said pixel if it is an edge (=1 or not 0)
				if i_edge[row][col] != 0:
					#add one to the location in accumulator related to rho and theta
					accumulator[rho][theta] += 1;
	#find max value in accumulator
	#set mostvotes to the first pixel in accumulator
	mostvotes = accumulator[0][0]
	#the theta associated with mostvotes
	theta_out = 0
	#the rho associated with mostvotes
	rho_out = 0
	#loop through every pixel in accumulator
	for row in range(2*diagonal+1):
		for col in range(180):
			#if current pixel value is greater than current greatest value
			if accumulator[row][col] > mostvotes:
				#set mostvotes to new largest value
				mostvotes = accumulator[row][col]
				#set theta_out to theta at current pixel -89 (to fix offset)
				theta_out = col-89
				#set rho_out to rho at current pixel -diagonal+1 (to fix offset)
				rho_out = row - diagonal+1
	#return theta_out, rho_out, accumulator
	return theta_out, rho_out, accumulator


