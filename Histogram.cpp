#include "Histogram.h"

Histogram::Histogram() {

}

Histogram::Histogram(Image image) {
  int height = image.get_height();
  int width = image.get_width();
  int factor = 6;
  vector< vector<int> > brightness(height, vector<int> (width));
  for(int i=0;i<height;i++) {
    for(int j=0;j<width;j++) {
      brightness[i][j] = (image.get_Color_x_y(i, j).get_red() + image.get_Color_x_y(i, j).get_green() + image.get_Color_x_y(i, j).get_blue())/3;
    }
  }
  vector<int> histogram(256, 0);
  for(int i=0;i<image.get_height();i++) {
    for(int j=0;j<image.get_width();j++) {
      histogram[brightness[i][j]]++;
    }
  }
  for(int i=5;i<251;i++) {
    int flag = 0;
    for(int j = 1; j<=5; j++) {
      if(histogram[i-j] > histogram[i] && histogram[i] <= histogram[i+j]) {
        continue;
      }
      else {
        flag = 1;
      }
    }
    if(flag == 0) {
      threshold.push_back(i);
    }
  }
  int h = 0;
  for(int i=0;i<histogram.size();i++) {
    h = max(h, histogram[i]);
  }
  h/=10;
  h++;
  Image histoImage(histogram.size(), h);
  for(int i=0;i<h;i++) {
    for(int j=0;j<histogram.size();j++) {
      histoImage.setColor(i, j, 255, 255, 255);
    }
  }
  for(int i=0;i<histogram.size();i++) {
    for(int j=0;j<histogram[i]/10;j++) {
      histoImage.setColor(h - j - 1, i, 0, 0, 0);
    }
  }
  ofstream out("output_task4_histogram.ppm");
  out<<"P3"<<endl;
  out<<histogram.size()<<" "<<h<<endl;
  out<<255<<endl;
  out<<histoImage;
}

Histogram::~Histogram() {

}

vector<int> Histogram::get_threshold() {
  return threshold;
}
