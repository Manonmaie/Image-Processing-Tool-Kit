#include "Segmentation.h"
#include <iostream>

using namespace std;

Segmentation::Segmentation() {

}

Segmentation::Segmentation(Image image):
  Image(image) {
  int colors[6][3];
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      colors[i][j] = 0;
    }
  }
  for(int i=3;i<6;i++) {
    for(int j=0;j<3;j++) {
      colors[i][j] = 255;
    }
  }
  for(int i=0;i<3;i++) {
    colors[i][i] = 255;
  }
  for(int i=0;i<3;i++) {
    colors[3+i][2-i] = 0;
  }
  Histogram h(image);
  vector<int> threshold = h.get_threshold();
  int size = threshold.size();
  if(size != 0) {
    for(int i=0;i<height;i++) {
      for(int j=0;j<width;j++) {
        int brightness = (image.get_Color_x_y(i, j).get_red() + image.get_Color_x_y(i, j).get_green() + image.get_Color_x_y(i, j).get_blue())/3;
        for(int k=0;k<size;k++) {
          if(brightness < threshold[k]) {
            if(k < 6) {
              setColor(i, j, colors[k][0], colors[k][1], colors[k][2]);
            }
            else {
              setColor(i, j, 0, 0, 0);
            }
            break;
          }
        }
        if(brightness > threshold[size-1]) {
          if(size < 6) {
            setColor(i, j, colors[size][0], colors[size][1], colors[size][2]);
          }
          else {
            setColor(i, j, 0, 0, 0);
          }
        }
      }
    }
  }
  else {
    Reflection& ref = *(new Reflection(image));
    for(int i=0;i<height;i++) {
      for(int j=0;j<width;j++) {
        ptr[i][j] = ref.get_ptr()[i][j];
      }
    }
  }
  Image tmp(this->get_width(), this->get_height());
  for(int i=0;i<height;i++) {
    for(int j=0;j<width;j++) {
      tmp.setColor(i, j, ptr[i][j].get_color());
    }
  }
  CompositeImage composite_image(image, tmp, 0.4);
  for(int i=0;i<height;i++) {
    for(int j=0;j<width;j++) {
      ptr[i][j] = composite_image.get_ptr()[i][j];
    }
  }
}

Segmentation::~Segmentation() {

}
