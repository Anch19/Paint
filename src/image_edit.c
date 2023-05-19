#include "image_edit.h"

#include <stdlib.h>

#include "util.h"

void rotate_counterclockwise(image_t *img)
{
    // NOT_IMPLEMENTED;
    // UNUSED(img);
    pixel_t *pixels = malloc((img->w) * (img->h) * (sizeof(pixel_t)));
    for (int i = 0; i < img->h; i++)
    { // this goes upwards and iterates over the rows
        for (int j = 0; j < img->w; j++)
        { // this iterates over the no. of coloumns and runs horizontally
            int newrow = img->w - 1 - j;
            int newcolumn = i;
            pixels[newrow * img->h + newcolumn] = img->img[i * img->w + j];
            // pixels[(img->h - 1 - j) * img->h + i] = img->img[i * img->w + j];
        }
    }
    // note that the swapping formula has been partially taken by chatgpt.
    int swap = img->w;
    img->w = img->h;
    img->h = swap;

    free(img->img);
    img->img = pixels;
    // free(pixels);
}

void rotate_clockwise(image_t *img)
{
    // NOT_IMPLEMENTED;
    // UNUSED(img);
    pixel_t *pixels = malloc((img->w) * (img->h) * (sizeof(pixel_t)));
    for (int i = 0; i < img->h; i++)
    { // this goes upwards and iterates over the rows
        for (int j = 0; j < img->w; j++)
        { // this iterates over the no. of coloumns and runs horizontally
            int newrow = j;
            int newcolumn = img->h - 1 - i;
            pixels[newrow * img->h + newcolumn] = img->img[i * img->w + j];
        }
        // this formula to rotate the image is been taken from chatgpt
    }

    int swap = img->w;
    img->w = img->h;
    img->h = swap;

    free(img->img);
    img->img = pixels;
    // free(pixels);
}

void mirror_horizontal(image_t *img)
{
    int width = img->w;
    int height = img->h;

    pixel_t *mirror1 = malloc(width * height * (sizeof(pixel_t)));
    for (int i = 0; i < width; ++i)
    { // i gives number of coloum , it is x inn slides
        for (int j = 0; j < height; ++j)
        { // j gives the number of rows, it is y in slides
            mirror1[(j * width) + i] = img->img[(j * width) + width - (i + 1)];
        }
    }
    free(img->img);
    img->img = mirror1;
}

void mirror_vertical(image_t *img)
{
    int width = img->w;
    int height = img->h;

    pixel_t *mirror2 = malloc(width * height * (sizeof(pixel_t)));
    for (int i = 0; i < width; ++i)
    { // i gives number of coloum , it is x inn slides
        for (int j = 0; j < height; ++j)
        { // j gives the number of rows, it is y in slides
            mirror2[(j * width) + i] = img->img[((height - (j + 1)) * width) + i];
        }
    }
    free(img->img);
    img->img = mirror2;
}

void resize(image_t *img, int new_width, int new_height)
{
    
    int oldwidth = img->w;
    int oldheight = img->h;
     
     image_t *resized_image = malloc(sizeof(image_t));
     resized_image->w = new_width;
     resized_image->h = new_height;

        resized_image->img = calloc(new_width * new_height , sizeof(pixel_t));

        for (int i = 0; i < new_width; i++)
        {
            for (int j = 0; j < new_height; j++)
            {

                if(i<oldwidth && j <oldheight){
                resized_image->img[(j * new_width) + i]= img->img[(j * oldwidth) + i];
            }
        }
    }
     free(img->img);

    *img=*resized_image;
    
    
}
