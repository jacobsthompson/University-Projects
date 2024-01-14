# Lab04_functions.py

# Import numpy
import numpy as np
# Import math for sqrt (sqaure root for gradient_magnitude)
import math

def spatial_filter(input_image, filter_array):
    #spatial_filter applies a spatial filter (filter_array) onto an input_image. 
    #It goes pixel by pixel, and takes the sum of the 3x3 grid around said pixel, multiplied by the corresponding filter location value
    #Input: input_image is a pixel array size of w*h containing an image, filter_array is a 3x3 array with 9 multiplication values
    #Output: output_image is the same size as input_image, but every pixel has been multiplied and summed using the filter
    #Created by Jacob Thompson

    #find shape of input image and make new empty shape of same size
    rows, cols = input_image.shape
    output_image = np.zeros(shape=(rows,cols))

    #loop through every pixel in input_image
    for row in range(rows):
        for col in range(cols):
            #summation is the new value to stored in the output_image pixel
            summation = 0
            #loop through -1,0,1 in both the x and y direction to visit every adjecent pixel to our current pixel
            for fx in range(-1,2):
                for fy in range(-1,2):
                    #check if the current pixel is outside the bounds of the image
                    if (row+fx < 0 or row+fx >= rows or col+fy < 0 or col+fy >= cols):
                        #if so, using zero-padding, add 0 to the summation (0 * anything = 0)
                        summation += 0
                    else:
                        #if in bound, multiply the pixel at [row+fx][col+fy] (which will be one of the pixels in the 3x3 grid)
                        #by the filter array value at [fx+1][fy+1] (we add one to shift from -1 -> 2 to 0 -> 3)
                        summation += input_image[row+fx][col+fy] * filter_array[fx+1][fy+1]
            #after we have looped through every pixel in the 3x3 grid and added their values to summation
            #we set output_image[row][col] (current pixel location) to the value of summation
            output_image[row][col] = summation
    #return the filtered output image
    return output_image

def gradient_magnitude(input_image):
    #gradient_magnitude applies the Sobel Mask (both horizontal and vertical) to an input image
    #by applying our spatial_filter function using the 2 filter_arrays. Then for every pixel in the image,
    #we set the output to the magnitude of the sobel masks √(SobelX^2 + SobelY^2)
    #Input: input_image is a pixel array containing an image
    #Output: output_image is that same pixel array with gradient applied to the image
    #Created by Jacob Thompson

    #find shape of input image and make new empty shape of same size
    rows, cols = input_image.shape
    output_image = np.zeros(shape=(rows,cols))

    #create the 2 sobel mask arrays, in its horizontal and vertical orientations
    hsobel = [[-1,0,1],[-2,0,2],[-1,0,1]]
    vsobel = [[-1,-2,-1],[0,0,0],[1,2,1]]

    #apply both filters to the input image using spatial_filter
    hsobel_image = spatial_filter(input_image,hsobel)
    vsobel_image = spatial_filter(input_image,vsobel)

    #loop through every pixel in image
    for row in range(rows):
        for col in range(cols):
            #set the current pixel in output_image to √(curr_SobelX^2 + curr_SobelY^2)
            output_image[row][col] = math.sqrt((hsobel_image[row][col]**2)+(vsobel_image[row][col]**2))
    #return output_image containing gradient
    return output_image

def find_edges(input_image, threshold):
    #find_edges finds the edges in an image by using the gradient_magnitude filter
    #The function finds the gradient of an input image, and then checks if the value at every pixel is greater than the threshold.
    #If it is, that means that pixel is an edge and is set to white. If not, it's not an edge and is set to black
    #Input: input_image is a pixel array of an image, threshold is an int value that sets the sensitivity of what classifies as an edge
    #Ouput: edge_image is an image that only shows the edges of the input_image in black and white
    #Created by Jacob Thompson 

    #find shape of input image and make new empty shape of same size
    rows, cols = input_image.shape
    edge_image = np.zeros(shape=(rows,cols))

    #use gradient_magnitude to get the gradient of the input_image
    grad = gradient_magnitude(input_image)

    #loop through every pixel
    for row in range(rows):
        for col in range(cols):
            #check if the gradient value at current pixel is larger than the threshold
            if(grad[row][col] > threshold):
                #if it is, set that pixel to white (edge)
                edge_image[row][col] = 255;
            else:
                #if it isn't, set that pixel to black (non-edge)
                edge_image[row][col] = 0;
    #return the edge dectected image
    return edge_image
