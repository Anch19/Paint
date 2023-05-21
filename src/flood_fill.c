#include "flood_fill.h"

#include <stdbool.h>
#include <stdlib.h>

#include "util.h"

void flood(image_t *img, int x, int y, pixel_t *target_color) {
    if (x < 0 || y < 0 || x >= img->w || y >= img->h) return;

    // NOT_IMPLEMENTED;
    // UNUSED(img);
    // UNUSED(x);
    // UNUSED(y);
    // UNUSED(target_color);
   

    pixel_t *pixel = &img->img[(y * img->w) + x];

    // If the pixel has the same color as the target color, return
    if (pixel->r == target_color->r && pixel->g == target_color->g && pixel->b == target_color->b) return;

    pixel_t original_color = *pixel;

    // Set the color of the pixel to the target color
    *pixel = *target_color;

    // Recursively call flood-fill for each of the pixel's 4 neighbors (top, bottom, left, and right)
    if (x > 0 && img->img[(y * img->w) + (x - 1)].r == original_color.r
              && img->img[(y * img->w) + (x - 1)].g == original_color.g
              && img->img[(y * img->w) + (x - 1)].b == original_color.b) {
        flood(img, x - 1, y, target_color);
    }
    if (x < img->w - 1 && img->img[(y * img->w) + (x + 1)].r == original_color.r
                       && img->img[(y * img->w) + (x + 1)].g == original_color.g
                       && img->img[(y * img->w) + (x + 1)].b == original_color.b) {
        flood(img, x + 1, y, target_color);
    }
    if (y > 0 && img->img[((y - 1) * img->w) + x].r == original_color.r
              && img->img[((y - 1) * img->w) + x].g == original_color.g
              && img->img[((y - 1) * img->w) + x].b == original_color.b) {
        flood(img, x, y - 1, target_color);
    }
    if (y < img->h - 1 && img->img[((y + 1) * img->w) + x].r == original_color.r
                       && img->img[((y + 1) * img->w) + x].g == original_color.g
                       && img->img[((y + 1) * img->w) + x].b == original_color.b) {
        flood(img, x, y + 1, target_color);
    }
}


