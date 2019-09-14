#ifndef Sonal_H_
#define Sonal_H_

#include "Image.h"
#include "CompositeImage.h"
#include <iostream>
#include <vector>
using namespace std;

int get_brightness(Image *I,int i,int j);
bool is_threshold(Image *I,int n,int *pixel_count);
void pixel_Count(Image *I,int *pixel_count);
Image* reflection_about_y_axis(Image *I);
Image* reflection_about_x_axis(Image *I);
Image* ImageC(Image *I,int t1);
Image* ImageD(Image *I,int t2);
Image *histogram_image(int *pixel_count);
void task5(Image *I);

#endif
