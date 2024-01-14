#import pillow
from PIL import Image, ImageOps

#import numpy and asarray
import numpy as np
from numpy import asarray

#open Beginnings and show it
im = Image.open('Beginnings.jpg')
im.show()

#create a greyscale version of Beginnings and show it
im_gray = ImageOps.grayscale(im)
im_gray.show()

#create pixel array of image, and find its width and height (rows and columns)
im_gray_pixels = asarray(im_gray)
rows, cols = im_gray_pixels.shape

#find greatest pixel value with nested for loop, starting at 0,0 pixel
greatestvalue = im_gray_pixels[0][0]
#print(greatestvalue);
for row in range(rows):
	for col in range(cols):
		#if new pixel is greater than current value, set greatest to new value
		if im_gray_pixels[row][col] > greatestvalue:
			greatestvalue = im_gray_pixels[row][col]
print("Maximum Pixel Value: ", greatestvalue)

#set the new rotated width and height
rotatedrows = cols
rotatedcols = rows

#counterclockwise picture
#create new blank image array with rotated (counterclockwise) dimensions
im_gray_counter_pixels = np.zeros(shape=(rotatedrows,rotatedcols))

#loop through all pixels in rotated image
for row in range(rotatedrows):
	for col in range(rotatedcols):
		#starting at the top left, set the pixels of the new image equal to the original pixel starting at the top right and scanning the right side column to the top row of the new image
		im_gray_counter_pixels[row][col] = im_gray_pixels[col][rotatedrows-1-row]

#use pixel array to create image, show it, and save it
im_gray_counter = Image.fromarray(np.uint8(im_gray_counter_pixels))
im_gray_counter.show()
im_gray_counter.save("Beginnings_grayscale_counterclockwise.jpg")

#clockwise
#create new blank image array with rotated (clockwise) dimensions
im_gray_clockwise_pixels = np.zeros(shape=(rotatedrows,rotatedcols))

#loop through all pixels in rotated image
for row in range(rotatedrows):
	for col in range(rotatedcols):
		#starting at the top left, set the pixels of the new image equal to the original pixel starting at the bottom left and scanning the left side column going up to the top row of the new image
		im_gray_clockwise_pixels[row][col] = im_gray_pixels[rotatedcols-1-col][row]

#use pixel array to create image, show it, and save it
im_gray_clockwise = Image.fromarray(np.uint8(im_gray_clockwise_pixels))
im_gray_clockwise.show()
im_gray_clockwise.save("Beginnings_grayscale_clockwise.jpg")

#find greatest pixel value of rotated image with nested for loop, starting at 0,0 pixel
greatestrotatedvalue = im_gray_clockwise_pixels[0][0]
for row in range(rotatedrows):
	for col in range(rotatedcols):
		#if new pixel is greater than current value, set greatest to new value
		if im_gray_clockwise_pixels[row][col] > greatestrotatedvalue:
			greatestrotatedvalue = im_gray_clockwise_pixels[row][col]
print("Maximum Pixel Value: ", greatestrotatedvalue)

