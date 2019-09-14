#ifndef Image_H_
#define Image_H_

#include "Pixel.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Image {
  public:
    Image();
    Image(int w, int h);
    ~Image();
    Image(const Image& other);
    int get_width() const;
    int get_height() const;
    Color get_Color_x_y(int x, int y) const;
    Pixel **get_ptr();
    void setColor(int i, int j, int r, int g, int b);
    void setColor(int i, int j, Color c);
    Image& operator=(Image const &other);
    friend Image operator+(Image const &image1, Image const &image2);
    friend Image operator*(float const &f, Image const &image);
    friend istream& operator>>(istream &is, Image &image);                      // Handle the header part by yourself
    friend ostream& operator<<(ostream &os, Image &image);
  protected:
    int width, height;
    Pixel **ptr;
};

#endif
