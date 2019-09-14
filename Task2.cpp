#include "Task2.h"
Task2::Task2(Image &ori){
  Image t(ori.get_width(),ori.get_height());
  Color temp;
  for(int i =0;i<ori.get_height();i++){
    for(int j=0;j<ori.get_width();j++){
      temp = ori.get_Color_x_y(i,j);
      t.setColor(i,ori.get_width()-j-1,temp.get_red(),temp.get_green(),temp.get_blue());
    }
  }
  A=t;
}
Image Task2::get_image(){
  return A;
}
vector<Pixel> Task2::get_blue_minima(){
  vector<Pixel> v;
  int count;
  // cout<<A.get_height()<<" "<<A.get_width()<<endl;
  for(int i=0;i<A.get_height();i++){
    for(int j=0;j<A.get_width();j++){
      count=0;
      if (i>0 && j>0 && A.get_Color_x_y(i-1,j-1).get_blue()>A.get_Color_x_y(i,j).get_blue()){
        count++;
      }
      if(i>0 && A.get_Color_x_y(i-1,j).get_blue()>A.get_Color_x_y(i,j).get_blue()){
        count++;
      }
      if(i>0 && j+1<A.get_width() && A.get_Color_x_y(i-1,j+1).get_blue()>A.get_Color_x_y(i,j).get_blue()){
        count++;
      }
      if(j>0 && A.get_Color_x_y(i,j-1).get_blue()>A.get_Color_x_y(i,j).get_blue()){
        count++;
      }
      if(j+1<A.get_width() && A.get_Color_x_y(i,j-1).get_blue()>A.get_Color_x_y(i,j).get_blue()){
        count++;
      }
      if(i+1<A.get_height() && j>0 && A.get_Color_x_y(i+1,j-1).get_blue()>A.get_Color_x_y(i,j).get_blue()){
        count++;
      }
      if(i+1<A.get_height() && A.get_Color_x_y(i+1,j).get_blue()>A.get_Color_x_y(i,j).get_blue()){
        count++;
      }
      if(i+1<A.get_height() && j+1<A.get_width() && A.get_Color_x_y(i+1,j+1).get_blue()>A.get_Color_x_y(i,j).get_blue()){
        count++;
      }
      // cout<<count<<endl;
      if(count==8){
        v.push_back(A.get_ptr()[i][j]);
      }
    }
  }
  // std::cout << v.size() << '\n';
  return v;
}
Image Task2::get_image_blue_minima(vector<Pixel> v){
  Image img(A.get_width(),A.get_height());
  for(int i=0;i<A.get_height();i++){
    for(int j=0;j<A.get_width();j++){
      img.setColor(i,j,0,0,0);
    }
  }
  int x,y;
  for(int i=0;i<v.size();i++){
    Color c(255,255,255);
    x = v[i].get_x();
    y = v[i].get_y();
    for(int k=-2;k<3;k++){
      for(int l=-2;l<3;l++){
        if(x+k>=0 && x+k<A.get_height() && y+l>=0 && y+l<A.get_width()){
          // cout<<x<<" "<<y<<endl;
          img.setColor(x+k,y+l,255,255,255);
        }
      }
    }
  }
  return img;
}
Image Task2::gaussian(vector<Pixel> v,Image img){
  int g[5][5] = {{1,4,7,4,1},
                 {4,16,26,16,4},
               {7,26,41,26,7},{4,16,26,16,4},{1,4,7,4,1}};
  for(int i=0;i<v.size();i++){
    int x = v[i].get_x();
    int y = v[i].get_y();
    int x1,x2,y1,y2;
    x1 = ((x-2)<0?0:(x-2));
    x2 = ((x-2)<0?(2-x):0);
    y1 = ((y-2)<0?0:(y-2));
    y2 = ((y-2)<0?(2-y):0);
    for(;x1<=x+2 && x1<img.get_height();x1++,x2++){
      int a_y = y1;
      int a_y1 = y2;
      for(;a_y<=y+2 && a_y<img.get_width();a_y++,a_y1++){
        int temp = int((255*g[x2][a_y1])/273);
        if(img.get_Color_x_y(x1,a_y1).get_red()!=255){
          temp+=img.get_Color_x_y(x1,a_y1).get_red();
          temp/=2;
        }
        img.setColor(x1,a_y,temp,temp,temp);
      }
    }
  }
  Image temp = img;

  return temp;
}
