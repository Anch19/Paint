#include "flood_fill.h"

#include <stdbool.h>
#include <stdlib.h>

#include "util.h"

// setting up a stack structure
typedef struct
{
    int a, b;
} Stack_structure;

void flood(image_t *img, int x, int y, pixel_t *target_color)
{

    if (x < 0 || y < 0 || x >= img->w || y >= img->h)
        return;

    pixel_t *pixel = &img->img[(y * img->w) + x];
    pixel_t original_color = *pixel;

    if (pixel->r == target_color->r && pixel->g == target_color->g && pixel->b == target_color->b)
        return;

    int stackCapacity = img->w * img->h;
    Stack_structure *stack = malloc(stackCapacity * sizeof(Stack_structure));
    if (stack == NULL)
    {
        printf("memory not allocated");
    }
    int stackSize = 0;

    Stack_structure startingpoints;
    startingpoints.a = x;
    startingpoints.b = y;

    stack[stackSize] = startingpoints;
    stackSize++;

    // these are direction array which will check for pixels in alll four direction
    int X_direction[] = {-1, 1, 0, 0};
    int Y_direction[] = {0, 0, -1, 1};

    while (stackSize > 0)
    {
        Stack_structure p = stack[--stackSize];

        pixel = &img->img[(p.b * img->w) + p.a]; // we get to the current pixel which is just popped out of the stack
        *pixel = *target_color;                  // and change its color to the target color

        for (int i = 0; i < 4; i++)
        {
            int newdirection_x = p.a + X_direction[i]; // assigning the adjacent pixels coordinates
            int newdirection_y = p.b + Y_direction[i];

            if (newdirection_x < 0 || newdirection_y < 0 || newdirection_x >= img->w || newdirection_y >= img->h)
                continue;
            // if the adjacent pixels are found of the origina color then pushing them on stack to paint
            if (img->img[(newdirection_y * img->w) + newdirection_x].r == original_color.r && img->img[(newdirection_y * img->w) + newdirection_x].g == original_color.g && img->img[(newdirection_y * img->w) + newdirection_x].b == original_color.b)
            {

                if (stackSize >= stackCapacity)
                {
                    stackCapacity *= 2;
                    stack = realloc(stack, stackCapacity * sizeof(Stack_structure));
                    if (stack == NULL)
                    {
                        printf("memory not allocated");
                    }
                }

                stack[stackSize++] = (Stack_structure){newdirection_x, newdirection_y};
            }
        }
    }

    free(stack);
}
//IMPORTANT THIS CODE HAS FEW PARTS WHICH ARE THE IDEAS OF CHATGPT , ESPECCIALY MAKING AN ARRAY FOR 4 DIRECTIONS & THE IDEA OF USING A STACK WAS INSPIRED FROM WIKIPEDIA
