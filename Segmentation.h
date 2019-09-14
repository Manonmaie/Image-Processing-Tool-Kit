#ifndef Segmentation_H_
#define Segmentation_H_

#include "Histogram.h"
#include "CompositeImage.h"
#include "Reflection.h"

class Segmentation : public Image {
  public:
    Segmentation();
    Segmentation(Image image);
    ~Segmentation();
};

#endif
