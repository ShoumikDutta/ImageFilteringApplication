## Documentation: Image Filtering Application

This documentation provides an overview and usage instructions for an image filtering application implemented in C.

### Introduction
The image filtering application allows users to apply different filters to BMP images. The application supports the following filters:

- Blur: Blurs the image by averaging the colors of neighboring pixels.
- Grayscale: Converts the image to grayscale by reducing the color channels.
- Reflection: Flips the image horizontally.
- Sepia: Applies a sepia tone effect to the image.

### Dependencies
To compile and run the image filtering application, ensure that you have the following dependencies installed:

- Standard C libraries (`stdio.h`, `stdlib.h`, `getopt.h`)
- The custom header file `helpers.h`, which provides helper functions for image manipulation.

### Usage
To use the image filtering application, follow these steps:

1. Compile the application using a C compiler, for example:
   ```
   gcc -o filter filter.c helpers.c
   ```

2. Run the compiled executable with the appropriate command-line arguments:
   ```
   ./filter [flag] infile outfile
   ```

   - Replace `[flag]` with one of the following filter options: `b` for Blur, `g` for Grayscale, `r` for Reflection, or `s` for Sepia.
   - Replace `infile` with the path to the input BMP image file.
   - Replace `outfile` with the desired path and filename for the output BMP image file.

3. The application will apply the selected filter to the input image and save the filtered image to the specified output file.
### Files
**helpers.c**

### grayscale

```c
void grayscale(int height, int width, RGBTRIPLE image[height][width])
```

This function converts an image to grayscale by averaging the RGB values of each pixel and setting them all to the same value.

**Parameters:**
- `height` (int): The height of the image.
- `width` (int): The width of the image.
- `image` (RGBTRIPLE[][]): The 2D array representing the image pixels.

### sepia

```c
void sepia(int height, int width, RGBTRIPLE image[height][width])
```

This function converts an image to sepia tones by applying specific color transformation formulas to each pixel.

**Parameters:**
- `height` (int): The height of the image.
- `width` (int): The width of the image.
- `image` (RGBTRIPLE[][]): The 2D array representing the image pixels.

### reflect

```c
void reflect(int height, int width, RGBTRIPLE image[height][width])
```

This function reflects the image horizontally by swapping the pixels from left to right.

**Parameters:**
- `height` (int): The height of the image.
- `width` (int): The width of the image.
- `image` (RGBTRIPLE[][]): The 2D array representing the image pixels.

### blur

```c
void blur(int height, int width, RGBTRIPLE image[height][width])
```

This function applies a blur effect to the image by averaging the RGB values of each pixel with its surrounding pixels.

**Parameters:**
- `height` (int): The height of the image.
- `width` (int): The width of the image.
- `image` (RGBTRIPLE[][]): The 2D array representing the image pixels.
```
### Limitations
- The application supports only 24-bit uncompressed BMP version 4.0 images. Other image formats are not supported.
- The application requires sufficient memory to store the image data. If there is not enough memory available, an error message will be displayed.
- Only one filter can be applied at a time. Attempting to apply multiple filters will result in an error message.


Contributions to the image filtering application are welcome. Feel free to submit a pull request with any enhancements or bug fixes.



