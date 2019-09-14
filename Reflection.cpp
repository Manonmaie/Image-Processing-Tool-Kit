#include "Reflection.h"
#include <iostream>

Reflection::Reflection() {

}

Reflection::Reflection(Image &image):
  Image(image.get_width(), image.get_height())  {
  int w = image.get_width();
  int h = image.get_height();
  for(int i=0;i<h;i++) {
    for(int j=0;j<=w/2;j++) {
      Pixel tmp = image.get_ptr()[i][j];
      ptr[i][j] = image.get_ptr()[i][width-j-1];
      ptr[i][width-j-1] = tmp;
    }
  }
}

Reflection::~Reflection() {

}
