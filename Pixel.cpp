#include "Pixel.h"
#include <iostream>

Pixel::Pixel() {

}

Pixel::Pixel(int p, int q, Color col) {
  x = p;
  y = q;
  c = col;
}

Pixel::~Pixel() {

}

Pixel::Pixel(const Pixel& other) {
  x = other.x;
  y = other.y;
  c = other.c;
}

Color Pixel::get_color() const{
  return c;
}

void Pixel::set_color(int r, int g, int b) {
  c.set_red(r);
  c.set_green(g);
  c.set_blue(b);
}

void Pixel::set_color(Color c1) {
  c = c1;
}

void Pixel::set_x_y(int x1, int y1) {
  x = x1;
  y = y1;
}

int Pixel::get_x() const{
  return x;
}

int Pixel::get_y() const{
  return y;
}

Pixel operator+(Pixel const &pixel1, Pixel const &pixel2) {
  if(pixel1.get_x() == pixel2.get_x() && pixel1.get_y() == pixel2.get_y()) {
    Color tmp_color = pixel1.get_color() + pixel2.get_color();
    Pixel p(pixel1.get_x(), pixel1.get_y(), tmp_color);
    return p;
  }
}

Pixel operator*(float const &f, Pixel &pixel) {
  Color old_color = pixel.get_color();
  int new_r = f*old_color.get_red();
  int new_g = f*old_color.get_green();
  int new_b = f*old_color.get_blue();
  if(new_r > 255)
    new_r = 255;
  if(new_g > 255)
    new_g = 255;
  if(new_b > 255)
    new_b = 255;
  Pixel p(pixel.get_x(),pixel.get_y(),Color(new_r, new_g, new_b));
  return p;
}

Pixel& Pixel::operator=(Pixel const &other) {
  x = other.x;
  y = other.y;
  c = other.c;
  return (*(this));
}

ostream& operator<<(ostream &os, Pixel &p) {
  os<<p.c;
  return os;
}
