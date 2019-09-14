#ifndef Shubham_H_
#define Shubham_H_

#include "Image.h"
#include "Color.h"
#include "Pixel.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int take_brightness(Image *I,int i,int j);
bool check_threshold(Image *I,int n,int *pixel_count);
bool is_threshold1(Image *I,int n,int *pixel_count);
void pixel_Count(Image *I,int *pixel_count, vector<vector<int> > *brightness);
int find_median(vector<int> threshold);
void binary_conversion_image(vector<vector<int> > *brightness, int T);
void connected_components(vector<vector<int> > *brightness);
void coloring_image(Image *I, vector<vector<int> > *brightness);

#endif
