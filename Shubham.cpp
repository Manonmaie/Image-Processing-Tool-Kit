#include "Shubham.h"

int take_brightness(Image *I,int i,int j){
  Color c=I->get_Color_x_y(i,j);
  int k=(c.get_red()+c.get_blue()+c.get_green())/3;
  return k;
}
bool check_threshold(Image *I,int n,int *pixel_count){
  if(n<5 || n>250){
    return false;
  }
  int i,count=0;
  for(i=1; i<=5; i++){
    if(pixel_count[n-i] > pixel_count[n] && pixel_count[n]<pixel_count[n+i]){
      count++;
    }
  }
  if(count==5){
    return true;
  }
  return false;
}
bool is_threshold1(Image *I,int n,int *pixel_count){
  if(n==0 || n==255){
    return false;
  }
  if(pixel_count[n-1] > pixel_count[n] && pixel_count[n]<=pixel_count[n+1]){
    return true;
  }
  return false;
}
void pixel_Count(Image *I,int *pixel_count, vector<vector<int> > *brightness){
  int i,j,k;
  for(i=0; i<256; i++){
    pixel_count[i]=0;
  }
  for(i=0; i<I->get_height(); i++){
    brightness->push_back(vector<int>());
    for(j=0; j<I->get_width(); j++){
      k = take_brightness(I,i,j);
      ((*brightness)[i]).push_back(k);
      pixel_count[k]++;
    }
  }
}

int find_median(vector<int> threshold){
  int size = threshold.size();
  if(size%2 == 0){
    int median_threshold = threshold[(size/2)-1] + threshold[size/2];
    return median_threshold;
  }
  return threshold[(size-1)/2];
}

void binary_conversion_image(vector<vector<int> > *brightness, int T){
  for(int i=0;i<(*brightness).size();i++){
    for(int j=0;j<(*brightness)[i].size();j++){
      if((*brightness)[i][j] < T){
        (*brightness)[i][j] = 0;
      }
      else{
        (*brightness)[i][j] = 1;
      }
    }
  }
}

void connected_components(vector<vector<int> > *brightness){
  int count = 0;
  for(int i=0;i<(*brightness).size();i++){
    for(int j=0;j<(*brightness)[i].size();j++){
      // First row first coloumn first element
      if((*brightness)[i][j] == 1 && i == 0 && j == 0){
        (*brightness)[i][j] = count++;
      }
      // First row First Row
      else if((*brightness)[i][j] == 1 && i == 0 && j > 0){
        if((*brightness)[i][j-1] != 0){
          (*brightness)[i][j] = (*brightness)[i][j-1];
        }
        else{
          (*brightness)[i][j] = count++;
        }
      }
      // First coloumn except First Element
      else if((*brightness)[i][j] == 1 && i != 0 && j == 0){
        if((*brightness)[i-1][j] != 0){
          (*brightness)[i][j] = (*brightness)[i-1][j];
        }
        else if((*brightness)[i-1][j+1] != 0){
          (*brightness)[i][j] = (*brightness)[i-1][j+1];
        }
        else{
          (*brightness)[i][j] = count++;
        }
      }
      // Last Coloumn Except First Element
      else if((*brightness)[i][j] == 1 && i > 0 && j == (*brightness)[i].size()-1){
        if((*brightness)[i-1][j] != 0){
          (*brightness)[i][j] = (*brightness)[i-1][j];
        }
        else if((*brightness)[i][j-1] != 0){
          (*brightness)[i][j] = (*brightness)[i][j-1];
        }
        else if((*brightness)[i-1][j-1] != 0){
          (*brightness)[i][j] = (*brightness)[i-1][j-1];
        }
        else{
          (*brightness)[i][j] = count++;
        }
      }
      // Rest 2D array
      else if((*brightness)[i][j] == 1 && i > 0 && j > 0 && i < (*brightness).size() && j < (*brightness)[i].size()-1){
        if((*brightness)[i-1][j] != 0){
          (*brightness)[i][j] = (*brightness)[i-1][j];
        }
        else if((*brightness)[i][j-1] != 0){
          (*brightness)[i][j] = (*brightness)[i][j-1];
        }
        else if((*brightness)[i-1][j-1] != 0){
          (*brightness)[i][j] = (*brightness)[i-1][j-1];
        }
        else if((*brightness)[i-1][j+1] != 0){
          (*brightness)[i][j] = (*brightness)[i-1][j+1];
        }
        else{
          (*brightness)[i][j] = count++;
        }
      }
    }
  }
}
void coloring_image(Image *I, vector<vector<int> > *brightness){
  Color red(255, 0, 0), green(0, 255, 0), blue(0, 0, 255), cyan(0, 255, 255), magenta(255,0,255), yellow(255,255,0),white(255,255,255),black(0,0,0);
  Color colors[8] = {black,red,green,blue,cyan,magenta,yellow,white};
  for (int i = 1; i < I-> get_height(); i++) {
    for (int j = 1; j < I->get_width(); j++) {
      if ((*brightness)[i][j] == 0) {
        I->setColor(i,j,colors[0]);
      }
      else if ((*brightness)[i][j]%7 == 0) {
        I->setColor(i,j,colors[1]);
      }
      else if ((*brightness)[i][j]%7 == 1) {
        I->setColor(i,j,colors[2]);
      }
      else if ((*brightness)[i][j]%7 == 2) {
        I->setColor(i,j,colors[3]);
      }
      else if ((*brightness)[i][j]%7 == 3) {
        I->setColor(i,j,colors[4]);
      }
      else if ((*brightness)[i][j]%7 == 4) {
        I->setColor(i,j,colors[5]);
      }
      else if((*brightness)[i][j]%7 == 5) {
        I->setColor(i,j,colors[6]);
      }
      else if((*brightness)[i][j]%7 == 6) {
        I->setColor(i,j,colors[7]);
      }
    }
  }
}
