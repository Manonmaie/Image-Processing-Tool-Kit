#include <iostream>
#include <vector>
#include <string>
#include "ScaledImage.h"
#include "CompositeImage.h"
using namespace std;
#include <sstream>

ScaledImage::ScaledImage()  {}

ScaledImage::ScaledImage(int wt, int ht):	Image(wt, ht)	{

}

ScaledImage::~ScaledImage() {}

Image& ScaledImage::Images(Image& i1){
        
        int width=i1.get_width();
        int height=i1.get_height();
        

        Image i2(width,height);
        Image i3(width,height);
        Image i4(width,height);
        Image i5(width,height);
        if(width%2==1){width--;}
        if(height%2==1){height--;}
        // cout<<i5.get_width()<<endl;
        // cout<<i5.get_height()<<endl;
        
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                i2.setColor(i,j,255,255,255);
                i3.setColor(i,j,255,255,255);
                i4.setColor(i,j,255,255,255);
                i5.setColor(i,j,255,255,255);
                  }
        }
         int i=0;
         int j=0;
        

            for(i=0;i<get_height()/2;i++){
                for(j=0;j<get_width()/2;j++){
                    i2.setColor(i,j,i1.get_Color_x_y(2*i,2*j));
                }
            }
           








         for(i=0;i<i1.get_height()/2;i++){
              for(j=0;j<i1.get_width()/2;j++){
                  Color c=i2.get_Color_x_y(i,j);
                  i3.setColor(i,i1.get_width()-j-1,c);
                  }
          }
         

           for(i=0;i<i1.get_height()/2;i++){
              for(j=0;j<i1.get_width()/2;j++){
                  Color c=i3.get_Color_x_y(i,j+(i1.get_width()/2));
                  i4.setColor(i1.get_height()-i-1,j+(i1.get_width()/2),c);
                  }
          }
          
        
          for(i=0;i<i1.get_height()/2;i++){
              for(j=0;j<i1.get_width()/2;j++){
                 //cout<<i<<" "<<j<<endl;
            Color c = i4.get_Color_x_y(i+(i1.get_height()/2),j+(i1.get_width()/2));
//                 // cout<<"tmp\n";
//                 // cout<<i+(i1.get_width()/2)<<" "<<i1.get_width()/2-j-1<<endl;
             i5.setColor(i+(i1.get_height()/2),i1.get_width()/2-j-1,c);
//                 //  i5.setColor(j+(i1.get_width()/2),i1.get_height()/2-j-1,c);
               }
//                 //  cout<<endl;
          }
        
            i1=CompositeImage(CompositeImage(i2,i3,0.5),CompositeImage(i4,i5,0.5),0.5);

        



      for(i=0;i<i1.get_height();i++){
          for(j=0;j<i1.get_width();j++){
              if(i<i1.get_width()/4 || i>3*(i1.get_width())/4 || j<i1.get_height()/4 || j>3*(i1.get_height())/4){
                  i1.setColor(i,j,255,255,255);
                  }
          }
      }
      
   
    return i1;
}
