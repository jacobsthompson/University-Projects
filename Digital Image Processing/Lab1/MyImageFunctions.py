from PIL import Image, ImageOps

import numpy as np
from numpy import asarray

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