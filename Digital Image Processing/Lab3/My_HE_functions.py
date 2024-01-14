# MyHEFunctions.py

# Import numpy
import numpy as np

def compute_histogram( image_pixels ):
    #compute_histogram stores counters in a 256 numpy vector, increasing the count
    #in the ith spot when i equals the value of a pixel in an image, repeated for all pixels
    #
    #Input: image_pixels is a float 32 pixel array
    #Output: vector is a 1D array with 256 values, storing the number of times pixel values are in the image
    #Created by Jacob Thompson

    #get the width and height of the image
    rows, cols = image_pixels.shape
    #create a vector array with 256 slots, all storing zero
    vector = np.zeros(shape=(256))

    #loop through every pixel in the image
    for row in range(rows):
        for col in range(cols):
            #add 1 to the count in the slot equal to the pixel value at [i][j]
            vector[int(image_pixels[row][col])] += 1
    #return the vector
    return vector


def equalize( in_image_pixels ):
    #equalize takes in an image, computes it's histogram. Using that data, it equalizes the histogram by renormalizing the array
    #then using the renormalized table to create a new, more balanced image
    #
    #Input: in_image_pixels is a float 32 pixel array
    #Output: out_image_pixels is the same as in_image_pixels in classification and size, but with the new equalized values
    #Created by Jacob Thompson

    #get the width and height of image
    rows, cols = in_image_pixels.shape
    #compute the original hustogram of the input image
    histo = compute_histogram(in_image_pixels)

    #calculate the cumulative sum of the histogram
    #set x to the first value in histo array
    x = iter(histo)
    #create a new array with the first value being the secon value in histo
    y = [next(x)]
    #loop through histo
    for i in x:
        #append (the last item in y + the ith item in x) into the y array
        y.append(y[-1]+i)
    #create a numpy array called csum using the y array
    csum = np.array(y)

    #renormalize the csum array
    #set renorm to the csum array minus the minimum value, then scale it by 255 (pixel values)
    renorm = (csum - csum.min()) * 255
    #find "Average" (max - min)
    N = csum.max() - csum.min()
    #set csum to renorm array divided by (max-min)
    csum = renorm / N
    #convert array to int to get rid of any floats (rounding)
    csum = csum.astype('uint8')
    #new output shape equal to input shape
    out_image_pixels = np.zeros(shape=(rows,cols))
    #loop through every pixel in new output image
    for row in range(rows):
        for col in range(cols):
            #set the pixel [i][j] in the output image to the csum index of the value of input[i][j] converted to int
            out_image_pixels[row][col] = csum[int(in_image_pixels[row][col])]
    #return equalized image
    return out_image_pixels;

def plot_histogram( hist ):
    # plot_histgram  Plots the length 256 numpy vector representing the normalized
    # histogram of a grayscale image.
    #
    # Syntax:
    #   plot_histogram( hist )
    #
    # Input:
    #   hist = The length 256 histogram vector..
    #
    # Output:
    #   none
    #
    # History:
    #   S. Newsam     10/15/2023   created

    # Import plotting functions from matplotlib.
    import matplotlib.pyplot as plt

    plt.bar( range(256), hist )

    plt.xlabel('intensity value');

    plt.ylabel('PMF'); 

    plt.show()
