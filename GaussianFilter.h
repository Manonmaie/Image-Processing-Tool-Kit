#ifndef GaussianFilter_H_
#define GaussianFilter_H_

#include "Image.h"
#include <vector>
#include <iostream>

class GaussianFilter : public Image {
  public:
    GaussianFilter();
    GaussianFilter(Image& a);
    GaussianFilter(int w,int h);
    ~GaussianFilter();
    GaussianFilter(const GaussianFilter& other);
    void apply_gaussian();
    friend float get_saturation(Pixel& p);
    std::vector<Pixel*> local_maxima();
    bool is_max(int i,int j);
    friend bool is_in_24_neighbourhood(Pixel* p1,Pixel* p2);
    std::vector<Pixel*> neighbourhood_24_color();
    std::vector<Pixel*> neighbourhood_24(Pixel* p);
    bool is_valid_coor(int x,int y);
  private:
    static int const gauss_array[5][5];
};

#endif
//Color == overload
//Image constructor
