#import pillow
from PIL import Image, ImageOps

#import numpy and asarray
import numpy as np
from numpy import asarray

#open Watertower image and print it's image mode
im = Image.open('Watertower.tif')
print("image mode is: ", im.mode)

#show normal image
im.show()

#create pixel array from image, and find the width and height (rows and columns) of image
im_pixels = asarray(im)
rows, cols = im_pixels.shape

#find greatest value of pixel in image
#set starting value to first pixel
greatestvalue = im_pixels[0][0]
for row in range(rows):
	for col in range(cols):
		#if the new pixels value is bigger than current, set greatest to new value
		if im_pixels[row][col].any() > greatestvalue.any():
			greatestvalue = im_pixels

print("Maximum Pixel Value: ", greatestvalue)

#import inverse function
from MyImageFunctions import myImageInverse

#use function to make inverse pixel array
im_inverse_pixels = myImageInverse(im_pixels)

#create image from pixel array, show image, save image
im_inverse = Image.fromarray(np.uint8(im_inverse_pixels))

im_inverse.show()

im_inverse.save("Watertower_inverse.tif")
#for putting the image into the google doc pdf (TIF not supported)
im_inverse.save("Watertower_inverse.jpg")

#find greatest value of the inverse image
greatestinversevalue = im_inverse_pixels[0][0]
for row in range(rows):
	for col in range(cols):
		if im_inverse_pixels[row][col].any() > greatestinversevalue.any():
			greatestinversevalue = im_inverse_pixels

print("Maximum Pixel Value: ", greatestinversevalue)