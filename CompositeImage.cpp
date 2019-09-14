#include "CompositeImage.h"
#include <iostream>

CompositeImage::CompositeImage() {

}

CompositeImage::CompositeImage(Image a, Image b, float alpha):
  Image(a.get_width(), a.get_height()) {
    if(a.get_width() == b.get_width() && a.get_height() == b.get_height()) {
      for(int i=0;i<height;i++) {
        for(int j=0;j<width;j++) {
          ptr[i][j] = alpha*(a.get_ptr()[i][j]) + (1-alpha)*(b.get_ptr()[i][j]);
        }
      }
    }
    else {
      return;
    }
}

CompositeImage::~CompositeImage() {

}

CompositeImage::CompositeImage(const CompositeImage& other):
  Image(other.get_width(), other.get_height()) {
    for(int i=0;i<height;i++) {
      for(int j=0;j<width;j++) {
        ptr[i][j] = other.ptr[i][j];
      }
    }
}
