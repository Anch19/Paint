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
        //this formula to rotate the image is been taken from chatgpt
    }

    int swap = img->w;
    img->w = img->h;
    img->h = swap;

    free(img->img);
    img->img = pixels;
}

void mirror_horizontal(image_t *img)
{
    NOT_IMPLEMENTED;
    UNUSED(img);
}

void mirror_vertical(image_t *img)
{
    NOT_IMPLEMENTED;
    UNUSED(img);
}

void resize(image_t *img, int new_width, int new_height)
{
    NOT_IMPLEMENTED;
    UNUSED(img);
    UNUSED(new_width);
    UNUSED(new_height);
}
