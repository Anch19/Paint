#include "flood_fill.h"

#include <stdbool.h>
#include <stdlib.h>

#include "util.h"


void flood(image_t *img, int x, int y, pixel_t *target_color)
 {
    if (x < 0 || y < 0 || x >= img->w || y >= img->h)
         return;

    pixel_t *pixel = &img->img[(y * img->w) + x];

    // If the pixel has the same color as the target color, return
    if (pixel->r == target_color->r && pixel->g == target_color->g && pixel->b == target_color->b)
        return;

    pixel_t old_color = *pixel;

    // Set the color of the pixel to the target color
    *pixel = *target_color;


// Recursively call flood-fill for each of the pixel's 4 neighbors (top, bottom, left, and right)
    if (x > 0 && img->img[(y * img->w) + (x - 1)].r == old_color.r
              && img->img[(y * img->w) + (x - 1)].g == old_color.g
              && img->img[(y * img->w) + (x - 1)].b == old_color.b) {
        flood(img, x - 1, y, target_color);
    }
    if (x < img->w - 1 ) {
        if(  img->img[(y * img->w) + (x + 1)].r == old_color.r
                       && img->img[(y * img->w) + (x + 1)].g == old_color.g
                       && img->img[(y * img->w) + (x + 1)].b == old_color.b){
                        flood(img, x + 1, y, target_color);}
    }
    if (y > 0 && img->img[((y - 1) * img->w) + x].r == old_color.r
              && img->img[((y - 1) * img->w) + x].g == old_color.g
              && img->img[((y - 1) * img->w) + x].b == old_color.b) {
        flood(img, x, y - 1, target_color);
    }
    if (y < img->h - 1 && img->img[((y + 1) * img->w) + x].r == old_color.r
                       && img->img[((y + 1) * img->w) + x].g == old_color.g
                       && img->img[((y + 1) * img->w) + x].b == old_color.b) {
        flood(img, x, y + 1, target_color);
    }

    //especial case that covers when the index is (0,0)
    if(x==0 && y ==0){
    if(img->img[(y* img->w)+(x+1)].r == old_color.r &&img->img[(y* img->w)+(x+1)].g == old_color.g && img->img[(y* img->w)+(x+1)].b == old_color.b){
       img->img[(y* img->w)+(x+1)]= *pixel;
    }
    if(img->img[(y+1 *img->w)+x].r==old_color.r && img->img[(y+1 *img->w)+x].g==old_color.g && img->img[(y+1 *img->w)+x].b==old_color.b ){
        img->img[(y+1 *img->w)+x]= *pixel;
    }
}
 
 //* this recussion idea is partially inspired from chagpt4

 }