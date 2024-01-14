#import pillow
from PIL import Image, ImageOps

#import numpy and asarray
import numpy as np
from numpy import asarray

#create new blank image 100x256 in size
im_pixels = np.zeros(shape=(100,256))

#nested loop through every pixel in image
for row in range(100):
	for col in range(256):
		#set the value of ith column pixel to the ith color value (0-255)
		im_pixels[row][col] = col

#create image from array, show image, save image
im = Image.fromarray(np.uint8(im_pixels))
im.show()
im.save("Gradient.jpg")

#calculate average of all pixels
avgvalue = 0;
for row in range(100):
	for col in range(256):
		avgvalue += im_pixels[row][col]

#divide all pixels added by the amount of pixels and print
avgvalue = avgvalue / (100*256)
print("Avergae Pixel Value: ", avgvalue)