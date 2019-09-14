#ifndef Histogram_H_
#define Histogram_H_

#include "Image.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

class Histogram {
  public:
    Histogram();
    Histogram(Image image);
    ~Histogram();
    vector<int> get_threshold();
  private:
    vector<int> histogram;
    vector<int> threshold;
};

#endif
