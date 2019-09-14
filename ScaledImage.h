#ifndef ScaledImage_H_
#define ScaledImage_H_
#include "Image.h"
using namespace std;
class ScaledImage:public Image{
    public:
        ScaledImage();
        ~ScaledImage();
        ScaledImage(int wt, int ht);
        Image& Images(Image& i1);

};
#endif
