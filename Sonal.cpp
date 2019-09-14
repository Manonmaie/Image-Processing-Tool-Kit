#include "Sonal.h"

int get_brightness(Image *I,int i,int j){
  Color c=I->get_Color_x_y(i,j);
  int k=(c.get_red()+c.get_blue()+c.get_green())/3;
  return k;
}
bool is_threshold(Image *I,int n,int *pixel_count){
  if(n<5 || n>250){
    return false;
  }
  int i,count=0;
  for(i=1; i<=5; i++){
    if(pixel_count[n-i]>pixel_count[n] && pixel_count[n]<pixel_count[n+i]){
      count++;
    }
  }
  if(count==5){
    return true;
  }
  return false;
}
void pixel_Count(Image *I,int *pixel_count){
  int i,j,k;
  for(i=0; i<255; i++){
    pixel_count[i]=0;
}
  for(i=0; i<I->get_height(); i++){
    for(j=0; j<I->get_width(); j++){
      k=get_brightness(I,i,j);
      pixel_count[k]++;
    }
  }
}
Image* reflection_about_y_axis(Image *I){
  Image *Im=new Image(I->get_width(),I->get_height());
  int i,j;
  Pixel **p=I->get_ptr();
  for(i=0; i<I->get_height(); i++){
    for(j=0; j<I->get_width(); j++){
      Im->setColor(i,j,p[i][I->get_width()-j-1].get_color());
    }
  }
  return Im;
}
Image* reflection_about_x_axis(Image *I){
  Image *Im=new Image(I->get_width(),I->get_height());
  int i,j;
  Pixel **p=I->get_ptr();
  for(i=0; i<I->get_height(); i++){
    for(j=0; j<I->get_width(); j++){
      Im->setColor(i,j,p[I->get_height()-i-1][j].get_color());
    }
  }
  return Im;
}
Image* ImageC(Image *I,int t1){
  Image *Image_C=new Image(I->get_width(),I->get_height());
  int i,j,k;
  for(i=0; i<I->get_height(); i++){
    for(j=0; j<I->get_width(); j++){
      k=get_brightness(I,i,j);
      if(k<t1){
        Image_C->setColor(i,j,0,0,255);
      }
      else{
        Image_C->setColor(i,j,255,255,255);
      }
    }
  }
  return Image_C;
}
Image* ImageD(Image *I,int t2){
  Image *Image_D=new Image(I->get_width(),I->get_height());
  int i,j,k;
  for(i=0; i<I->get_height(); i++){
    for(j=0; j<I->get_width(); j++){
      k=get_brightness(I,i,j);
      if(k<t2){
        Image_D->setColor(i,j,255,255,0);
      }
      else{
        Image_D->setColor(i,j,255,255,255);
      }
    }
  }
  return Image_D;
}
Image *histogram_image(int *pixel_count){
  int i,max_y=-1;
  int j;
  for(i=0; i<256; i++){
    if(pixel_count[i]>max_y){
      max_y=pixel_count[i];
    }
  }
  max_y++;
  Image *h=new Image(max_y,max_y);
  for(i=0; i<256; i++){
    for(j=0; j<=pixel_count[i]; j++){
      h->setColor(max_y-j-1,i,0,0,0);
    }
  }
//  Image *H=reflection_about_x_axis(h);
  return h;
}
void task5(Image *I){
  vector<int> threshold;
  int *pixel_count= new int[256];
  int i,j,k;
  pixel_Count(I,pixel_count);
  // Image *histogram=histogram_image(pixel_count);
  for(i=0; i<255; i++){
  //  cout << i  << " -> " << pixel_count[i] << endl;
  if (is_threshold(I,i,pixel_count)){
    threshold.push_back(i);
    // cout << i << endl;
  }
}
  Image *Image_C,*Image_D;
  if(threshold.size()>0){
    Image_C=ImageC(I,threshold[0]);
  }
  else{
    Image_C=reflection_about_y_axis(I);
  }


  if(threshold.size()>1){
    Image_D=ImageD(I,threshold[1]);
  }
  else{
    Image_D=reflection_about_x_axis(I);
  }
  //cout << *histogram;
  // cout << *Image_C;
  ofstream fout("output_task5.ppm");
  CompositeImage compImage(*Image_C, *Image_D, 0.2);
  string mode = "P3";
  int h = compImage.get_height();
  int w = compImage.get_width();
  int max = 255;
  fout<<mode<<endl;
  fout<<w<<" "<<h<<endl;
  fout<<max<<endl;
  fout<<compImage;
  fout.close();
  //cout << *Image_D;
}
