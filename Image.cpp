#include "Image.h"

using namespace std;

Image::Image() {
  width = 0;
  height = 0;
  ptr = NULL;
}

Image::Image(int w, int h) {
  width = w;
  height = h;
  Color white(255, 255, 255);
  ptr = new Pixel*[height];
  for(int i=0;i<height;i++) {
    ptr[i] = new Pixel[width]();
  }
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      ptr[i][j] = Pixel(j, i, white);
    }
  }
}

Image::~Image() {

}

Image::Image(const Image& other) {
  width = other.width;
  height = other.height;
  ptr = new Pixel*[height];
  for(int i=0;i<height;i++) {
    ptr[i] = new Pixel[width]();
  }
  for(int i=0;i<height;i++) {
    for(int j=0;j<width;j++) {
      ptr[i][j] = other.ptr[i][j];
    }
  }
}

int Image::get_width() const{
  return width;
}

int Image::get_height() const{
  return height;
}

Color Image::get_Color_x_y(int x, int y) const{
  return ptr[x][y].get_color();
}

Pixel** Image::get_ptr() {
  return ptr;
}

void Image::setColor(int i, int j, int r, int g, int b) {
  ptr[i][j].set_color(r, g, b);
  ptr[i][j].set_x_y(j, i);
}

void Image::setColor(int i, int j, Color c) {
  ptr[i][j].set_color(c);
  ptr[i][j].set_x_y(j, i);
}

Image& Image::operator=(Image const &other) {
  height = other.height;
  width = other.width;
  ptr = new Pixel*[height];
  for(int i=0;i<height;i++) {
    ptr[i] = new Pixel[width]();
  }
  for(int i=0;i<height;i++) {
    for(int j=0;j<width;j++) {
      ptr[i][j] = other.ptr[i][j];
    }
  }
  return *(this);
}

Image operator+(Image const &image1, Image const &image2) {
  if(image1.get_width() == image2.get_width() && image1.get_height() == image2.get_height()) {
    int w1 = image1.get_width();
    int h1 = image1.get_height();
    Image result(w1, h1);
    for(int i=0;i<result.get_height();i++) {
      for(int j=0;j<result.get_width();j++) {
        int new_r = image1.get_Color_x_y(i, j).get_red() + image2.get_Color_x_y(i, j).get_red();
        int new_g = image1.get_Color_x_y(i, j).get_green() + image2.get_Color_x_y(i, j).get_green();
        int new_b = image1.get_Color_x_y(i, j).get_blue() + image2.get_Color_x_y(i, j).get_blue();
        if(new_r > 255)
          new_r = 255;
        if(new_g > 255)
          new_g = 255;
        if(new_b > 255)
          new_b = 255;
        result.setColor(i, j, new_r, new_g, new_b);
      }
    }
    return result;
  }
}

Image operator*(float const &f, Image const &image) {
  Image tmp_image(image.get_width(), image.get_height());
  for(int i=0;i<image.get_height();i++) {
    for(int j=0;j<image.get_width();j++) {
      int new_r = f*(image.ptr[i][j].get_color().get_red());
      int new_g = f*(image.ptr[i][j].get_color().get_green());
      int new_b = f*(image.ptr[i][j].get_color().get_blue());
      if(new_r > 255)
        new_r = 255;
      if(new_g > 255)
        new_g = 255;
      if(new_b > 255)
        new_b = 255;
      cout<<new_r<<" "<<new_g<<" "<<new_b<<endl;
      tmp_image.setColor(i, j, new_r, new_g, new_b);
    }
  }
  return tmp_image;
}

istream& operator>>(istream &is, Image &image) {
  for(int i=0;i<image.height;i++) {
    for(int j=0;j<image.width;j++) {
      int r, g, b;
      is>>r>>g>>b;
      image.setColor(i, j, r, g, b);
    }
  }
  return is;
}

ostream& operator<<(ostream &os, Image &image) {
  Pixel **p = image.get_ptr();
  for(int i=0;i<image.height;i++) {
    for(int j=0;j<image.width;j++) {
      os<<p[i][j]<<" ";
    }
    os<<endl;
  }
  return os;
}
