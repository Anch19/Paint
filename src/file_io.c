#include "file_io.h"

#include <assert.h>
#include <stdlib.h>
#include<string.h>
#include "util.h"

int image_read(image_t *img, FILE *fin)
{

    int width = 0;
    int height = 0;
    char p[3];
    int max_value;

    fscanf(fin, "%s %d %d %d", p, &width, &height, &max_value);
    if( strcmp(p,"P3")!=0 ||  width<=0 ||  height<=0|| max_value!=255  ){ 
    
        // fclose(fin);
        // exit(EXIT_FAILURE);
        return -1;
    }
    

    pixel_t *pixel = malloc( width * height * sizeof(pixel_t));
    if(pixel==NULL){
        printf("memory not allocated");
        return -1;
    }

    for (int i = 0; i < (width * height); i++)
    {
        if (fscanf(fin, "%d %d %d ", &pixel[i].r, &pixel[i].g, &pixel[i].b) != 3)
        {
            // fclose(fin);
            free(pixel);
            return -1;
        }

        if (pixel[i].r < 0 || pixel[i].r > 255 || pixel[i].g < 0 || pixel[i].g > 255 || pixel[i].b < 0 || pixel[i].b > 255)
        {
            free(pixel);
            return -1;
        }
    }
    if (!feof(fin))
    {
        // fclose(fin);
        free(pixel);
        return -1;
    }

    img->w = width;
    img->h = height;
    img->img = pixel;
    return 0;
}

void image_write(const image_t *img, FILE *fout)
{
    fprintf(fout, "P3\n");
    fprintf(fout, "%d %d\n", img->w, img->h);
    fprintf(fout, "255\n");

    for (int i = 0; i < img->h * img->w; ++i)
    {
        fprintf(fout, "%d %d %d ", img->img[i].r, img->img[i].g, img->img[i].b);

}
}

void image_free(image_t *img)
{
    if (img->img != NULL)
    {
        free(img->img);
    }
    img->w = img->h = 0;
    img->img = NULL;
}
