#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
  int dst_index = -1;
  
  //printf("get_pixel: Image characteristics, c=%d, w=%d, h=%d\n", im.c, im.w, im.h);

  if (!((c < im.c) && (x < im.w) && (y < im.h)))
    {
      
      //printf("get_pixel: Invalid dimensions passed in. Clamping where needed\n");
      if ((c < 0) || (c > im.c))
	{
	  //printf("get_pixel: Invalid c = %d\n", c);
	  if (c > im.c)
	    c = im.c - 1;
	  else if (c < 0)
	    c = 0;
	  //printf("get_pixel: Updated c = %d\n", c);
	}

      if ((x < 0) || (x > im.w))
	{
	  //printf("get_pixel: Invalid x = %d\n", x);
	  if (x > im.w)
	    x = im.w - 1;
	  else if (x < 0)
	    x = 0;
	  //printf("get_pixel: Updated x = %d\n", x);
	}

      if ((y < 0) || (y > im.h))
	{
	  //printf("get_pixel: Invalid y = %d\n", y);
	  if (y > im.h)
	    y = im.h - 1;
	  else if (y < 0)
	    y = 0;
	  //printf("get_pixel: Updated y = %d\n", y);
	}
      
    }
    
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
  // printf("get_pixel: c=%d,x=%d,y=%d, dst_index = %d, pixel value: %0.1f\n", c, x, y, dst_index, im.data[dst_index]);

  return im.data[dst_index];

}

void set_pixel(image im, int x, int y, int c, float v)
{
  // TODO Fill this in
  int dst_index = -1;
  
  //printf("set_pixel: Image characteristics, c=%d, w=%d, h=%d\n", im.c, im.w, im.h);

  if ((c < im.c) && (x < im.w) && (y < im.h))
    {
      dst_index = (c * (im.w * im.h)) + (y * im.w) + (x);
      //printf("set_pixel: c=%d,x=%d,y=%d, dst_index = %d, old pixel value: %0.1f, new value: %0.1f\n", c, x, y, dst_index, im.data[dst_index], v);
      im.data[dst_index] = v;
    }
  else
    {
      printf("set_pixel: Invalid dimensions passed in. Returning without doing anything\n");
      return;
    }
  
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
