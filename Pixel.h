#ifndef Pixel_H_
#define Pixel_H_

#include "Color.h"
#include <fstream>

using namespace std;

class Pixel {
  public:
    Pixel();
    Pixel(int p, int q, Color col);
    ~Pixel();
    Pixel(const Pixel& other);
    Color get_color() const;

    // While using set_color() which is provided here, it will only set the color in that Pixel
    // You will have to manually handle the setting of location of Pixel using set_x_y()
    // Much easier/cleaner interfaces are provided in Image class(which does both the above functions)
    void set_color(int r, int g, int b);
    void set_color(Color c1) ;
    void set_x_y(int x1, int y1);

    int get_x() const;
    int get_y() const;
    friend Pixel operator+(Pixel const &pixel1, Pixel const &pixel2);
    friend Pixel operator*(float const &f, Pixel &pixel);
    Pixel& operator=(Pixel const &other);
    friend ostream& operator<<(ostream &os, Pixel &c);
  private:
    int x, y;
    Color c;
};

#endif
