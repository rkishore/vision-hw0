#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
  int dst_index = -1;
  
  printf("Image characteristics, c=%d, w=%d, h=%d\n", im.c, im.w, im.h);

  if (!((c < im.c) && (x < im.w) && (y < im.h)))
    {

      printf("Invalid dimensions passed in. Clamping where needed\n");
      if ((c < 0) || (c > im.c))
	{
	  printf("Invalid c = %d\n", c);
	  if (c > im.c)
	    c = im.c - 1;
	  else if (c < 0)
	    c = 0;
	  printf("Updated c = %d\n", c);
	}

      if ((x < 0) || (x > im.w))
	{
	  printf("Invalid x = %d\n", x);
	  if (x > im.w)
	    x = im.w - 1;
	  else if (x < 0)
	    x = 0;
	  printf("Updated x = %d\n", x);
	}

      if ((y < 0) || (y > im.h))
	{
	  printf("Invalid y = %d\n", y);
	  if (y > im.h)
	    y = im.h - 1;
	  else if (y < 0)
	    y = 0;
	  printf("Updated y = %d\n", y);
	}
      
    }
  
  dst_index = (c * (im.w * im.h)) + (x * im.h) + (y);
  
  /*
    int i,j,k;
    for(k = 0; k < im.c; ++k){
    for(j = 0; j < im.h; ++j){
    for(i = 0; i < im.w; ++i){
    dst_index = i + im.w*j + im.w*im.h*k;
    //int src_index = k + c*i + c*w*j;
    printf("c=%d,x=%d,y=%d, dst_index=%d, data=%0.1f\n", k, i, j, dst_index, im.data[dst_index]);
    }
    }
    }
  */
  
  dst_index = (c * (im.w * im.h)) + (y * im.w) + (x);
  printf("c=%d,x=%d,y=%d, dst_index = %d, pixel value: %0.1f\n", c, x, y, dst_index, im.data[dst_index]);
  // ptr1 = (float *)(im.data + c);
  return im.data[dst_index];

}

void set_pixel(image im, int x, int y, int c, float v)
{
    // TODO Fill this in
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    // TODO Fill this in
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    // TODO Fill this in
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
