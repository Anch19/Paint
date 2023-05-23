#include "flood_fill.h"

#include <stdbool.h>
#include <stdlib.h>

#include "util.h"


// void flood(image_t *img, int x, int y, pixel_t *target_color)
//  {
//     if (x < 0 || y < 0 || x >= img->w || y >= img->h)
//          return;

//     pixel_t *pixel = &img->img[(y * img->w) + x];

//     // If the pixel has the same color as the target color, return
//     if (pixel->r == target_color->r && pixel->g == target_color->g && pixel->b == target_color->b)
//         return;

//     pixel_t old_color = *pixel;

//     // Set the color of the pixel to the target color
//     *pixel = *target_color;


// // Recursively call flood-fill for each of the pixel's 4 neighbors (top, bottom, left, and right)
//     if (x > 0 && img->img[(y * img->w) + (x - 1)].r == old_color.r
//               && img->img[(y * img->w) + (x - 1)].g == old_color.g
//               && img->img[(y * img->w) + (x - 1)].b == old_color.b) {
//         flood(img, x - 1, y, target_color);
//     }
//     if (x < img->w - 1 ) {
//         if(  img->img[(y * img->w) + (x + 1)].r == old_color.r
//                        && img->img[(y * img->w) + (x + 1)].g == old_color.g
//                        && img->img[(y * img->w) + (x + 1)].b == old_color.b){
//                         flood(img, x + 1, y, target_color);}
//     }
//     if (y > 0 && img->img[((y - 1) * img->w) + x].r == old_color.r
//               && img->img[((y - 1) * img->w) + x].g == old_color.g
//               && img->img[((y - 1) * img->w) + x].b == old_color.b) {
//         flood(img, x, y - 1, target_color);
//     }
//     if (y < img->h - 1 && img->img[((y + 1) * img->w) + x].r == old_color.r
//                        && img->img[((y + 1) * img->w) + x].g == old_color.g
//                        && img->img[((y + 1) * img->w) + x].b == old_color.b) {
//         flood(img, x, y + 1, target_color);
//     }

//     //especial case that covers when the index is (0,0)
//     if(x==0 && y ==0){
//     if(img->img[(y* img->w)+(x+1)].r == old_color.r &&img->img[(y* img->w)+(x+1)].g == old_color.g && img->img[(y* img->w)+(x+1)].b == old_color.b){
//        img->img[(y* img->w)+(x+1)]= *pixel;
//     }
//     if(img->img[(y+1 *img->w)+x].r==old_color.r && img->img[(y+1 *img->w)+x].g==old_color.g && img->img[(y+1 *img->w)+x].b==old_color.b ){
//         img->img[(y+1 *img->w)+x]= *pixel;
//     }
// }
 
//  //* this recussion idea is partially inspired from chagpt4

//  }
// typedef struct {
//     int x, y;
// } Stack_structure;

// void flood(image_t *img, int x, int y, pixel_t *target_color) {
//     // Check if the pixel is inside the image
//     if (x < 0 || y < 0 || x >= img->w || y >= img->h) return;

//     pixel_t *pixel = &img->img[(y * img->w) + x];
//     pixel_t original_color = *pixel;

//     // If the pixel has the same color as the target color, return
//     if (pixel->r == target_color->r && pixel->g == target_color->g && pixel->b == target_color->b) return;

//     // Initialize stack
//     Stack_structure *stack = malloc(img->w * img->h * sizeof(Stack_structure));
//     int stackSize = 0;

//     // Push the starting Stack_structure onto the stack
//     stack[stackSize++] = (Stack_structure) {x, y};

//     while (stackSize > 0) {
//         Stack_structure p = stack[--stackSize];

//         pixel = &img->img[(p.y * img->w) + p.x];
//         *pixel = *target_color;

//         if (p.x > 0 && img->img[(p.y * img->w) + (p.x - 1)].r == original_color.r
//                   && img->img[(p.y * img->w) + (p.x - 1)].g == original_color.g
//                   && img->img[(p.y * img->w) + (p.x - 1)].b == original_color.b) {
//             stack[stackSize++] = (Stack_structure) {p.x - 1, p.y};
//         }
//         // And so on for the other directions...

//         // Remember to check if stackSize exceeds allocated size and reallocate if needed.
//     }

//     free(stack);
// }

typedef struct {
    int a, b;
} Stack_structure;

void flood(image_t *img, int x, int y, pixel_t *target_color) {
    // Check if the pixel is inside the image
    if (x < 0 || y < 0 || x >= img->w || y >= img->h) return;

    pixel_t *pixel = &img->img[(y * img->w) + x];
    pixel_t original_color = *pixel;

    // If the pixel has the same color as the target color, return
    if (pixel->r == target_color->r && pixel->g == target_color->g && pixel->b == target_color->b) return;

    // Initialize stack
    int stackCapacity = img->w * img->h;
    Stack_structure *stack = malloc(stackCapacity * sizeof(Stack_structure));
    if(stack==NULL){
        printf("memory not allocated");
    }
    int stackSize = 0;

    // Push the starting Stack_structure onto the stack
    Stack_structure startingpoints;
    startingpoints.a = x;
    startingpoints.b = y;

    stack[stackSize]= startingpoints;
    stackSize++;

      // these are direction array which will check for pixels in alll four direction
      int X_direction[] = {-1, 1, 0, 0};
     int Y_direction[] = {0, 0, -1, 1};

    while (stackSize > 0) {
        Stack_structure p = stack[--stackSize];

        pixel = &img->img[(p.b * img->w) + p.a];  // we get to the current pixel which is just popped out of the stack 
        *pixel = *target_color;                    // and change its color to the target color

      

        for(int i = 0; i < 4; i++) {
            int newdirection_x = p.a + X_direction[i];
            int newdirection_y = p.b + Y_direction[i];
            
            // Check if the new position is inside the image
            if (newdirection_x < 0 || newdirection_y < 0 || newdirection_x >= img->w || newdirection_y >= img->h) continue;

            // Check if the pixel color at the new position matches the original color
            if (img->img[(newdirection_y * img->w) + newdirection_x].r == original_color.r
                  && img->img[(newdirection_y * img->w) + newdirection_x].g == original_color.g
                  && img->img[(newdirection_y * img->w) + newdirection_x].b == original_color.b) {

                // Check if stackSize exceeds allocated size and reallocate if needed
                if (stackSize >= stackCapacity) {
                    stackCapacity *= 2;
                    stack = realloc(stack, stackCapacity * sizeof(Stack_structure));
                    if(stack ==NULL){
                        printf("memory not allocated");
                    }
                }

                stack[stackSize++] = (Stack_structure) {newdirection_x, newdirection_y};
            }
        }
    }

    free(stack);
}
