#ifndef Color_H_
#define Color_H_

#include <ostream>

using namespace std;

class Color {
  public:
    Color();
    Color(int r, int g, int b);
    ~Color();
    Color(const Color& other);
    void set_red(int x);
    void set_green(int x);
    void set_blue(int x);
    int get_red() const;
    int get_green() const;
    int get_blue() const;
    Color& operator=(Color const &other);
    friend Color operator+(Color const &color1, Color const &color2);
    friend ostream& operator<<(ostream &os, Color &c);
    friend bool operator==(Color c1, Color c2);
  private:
    int red, green, blue;
};

#endif
