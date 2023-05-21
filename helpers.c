#include "helpers.h"
#include <math.h>
int check(int a)
{
    if ( a > 255)
    {
        return 255;
    }
    else
    {
        return a;
    }
}
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for ( int i = 0 ; i < height ; i++ )
    {
        for( int j = 0 ; j < width ; j++ )
        {
            int avg=round((image[i][j].rgbtRed+image[i][j].rgbtBlue+image[i][j].rgbtGreen)/3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for ( int i = 0 ; i < height ; i++ )
    {
        for( int j = 0 ; j < width ; j++ )
        {
            int red=round(0.393*image[i][j].rgbtRed+0.769*image[i][j].rgbtGreen+0.189*image[i][j].rgbtBlue);
            int green=round(0.349*image[i][j].rgbtRed+0.686*image[i][j].rgbtGreen+0.168*image[i][j].rgbtBlue);
            int blue=round(0.272*image[i][j].rgbtRed+0.534*image[i][j].rgbtGreen+0.131*image[i][j].rgbtBlue);
            red=check(red);
            green=check(green);
            blue=check(blue);
            image[i][j].rgbtRed=red;
            image[i][j].rgbtBlue=blue;
            image[i][j].rgbtGreen=green;
        }
    }

    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
 RGBTRIPLE copy[height][width];
 for (int i=0;i<height;i++)
 {
    for(int j=0;j<width;j++)
    {
        copy[i][j]=image[i][j];
    }
 }
 for (int i = 0 ; i < height ; i++)
 {
    for(int j = 0 ; j < width/2 ; j++)
    {
        image[i][j]=copy[i][width-1-j];
        image[i][width-1-j]=copy[i][j];
    }
 }



}

// Blur image
int get_blur(int height, int width, RGBTRIPLE copy[height][width],int c,int i,int j)
{
    int sum=0;
    float count=0.0;
    for ( int row=0  ; row < height ; row++ )
    {
        if (row< i-1 || row >i+1)
        {
            continue;
        }
        for ( int col=0  ; col < width ; col++ ) {
            if( col<j-1 || col> j+1)
            {
                continue;
            }
            if(c==1)
            {
                sum+=copy[row][col].rgbtRed;
                count++;
            }
            if(c==2)
            {
                sum+=copy[row][col].rgbtBlue;
                count++;
            }
            if(c==3)
            {
                sum+=copy[row][col].rgbtGreen;
                count++;
            }
        }
    }
    if(count==0.0){
        return 0;
    }
    return round(sum/count);
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            copy[i][j]=image[i][j];
        }
    }

    for (int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            image[i][j].rgbtRed=get_blur(height,width,copy,1, i, j);
            image[i][j].rgbtBlue=get_blur(height,width,copy,2, i, j);
            image[i][j].rgbtGreen=get_blur(height,width,copy,3, i, j);
        }
    }



    return;
}
