#ifndef Task2_H_
#define Task2_H_
#include <iostream>
#include <vector>
#include "Color.h"
#include "Image.h"
#include "Pixel.h"
#include "CompositeImage.h"
class Task2{
private:
  Image A;
public:
  Task2(Image &ori);
  Image get_image();
  vector<Pixel> get_blue_minima();
  Image get_image_blue_minima(vector<Pixel> v);
  Image gaussian(vector<Pixel> v,Image img);
};
#endif
