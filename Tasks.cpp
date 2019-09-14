#include "Tasks.h"

using namespace std;

vector<int> getInput(string s) {
  vector<int> l;
  for(int i=0;i<s.size();i++) {
    if(s[i] != ' ') {
      l.push_back(s[i]-'0');
    }
  }
  return l;
}

void IMT2016001(char* filename) {
  ifstream image;
  image.open(filename);
  ofstream filtered("output_task4_imt2016001.ppm");
  string mode;
  int h, w, max;
  image>>mode>>w>>h>>max;
  filtered<<mode<<endl;
  filtered<<w<<" "<<h<<endl;
  filtered<<max<<endl;
  Image tmp(w, h);
  image>>tmp;
  Segmentation seg(tmp);
  filtered<<seg;
  image.close();
  filtered.close();
}

void IMT2016029(char* filename) {
  int wt, ht, maxCol;
  std::string str;

  std::ifstream file;
  file.open(filename);
  file >> str;
  file >> wt >> ht;
  file >> maxCol;

  Image im = *(new Image(wt,ht));
  file >> im;
  file.close();

  // ScaledImage sc(wt, ht);
  // sc.createPI(im);
  ScaledImage sci(wt,ht);
  //Image sc();
  //sci.Images(im);

  std::ofstream outFile("output_task7_imt2016029.ppm");
  outFile << str << endl;
  outFile << wt << " " << ht << endl;
  outFile << maxCol << endl;
  outFile << sci.Images(im);
  outFile.close();
}

void IMT2016057(char* filename) {
  ifstream input;
  ofstream output1,output2;
  input.open(filename);
  string type;
  int w,h,max;
  input>>type>>w>>h;
  input>>max;
  Image *img = new Image(w,h);
  input>>(*img);
  xAxisReflection *xref = new xAxisReflection((*img));
  GaussianFilter *g = new GaussianFilter(*xref);
  output1.open("output_task3_imt2016057_gaussian.ppm");
  output1<<type<<"\n";
  output1<<w<<" "<<h<<"\n";
  output1<<max<<"\n";
  output1<<(*g);
  output2.open("output_task3_imt2016057.ppm");
  CompositeImage * res = new CompositeImage((*g),(*xref),0.6);
  output2<<type<<"\n";
  output2<<w<<" "<<h<<"\n";
  output2<<max<<"\n";
  output2<<(*res);
  input.close();
  output1.close();
  output2.close();
}

void IMT2016079(char* filename) {
  ifstream file(filename);
  string s;
  int width,height;
  int max_val;
  file >> s;
  file >> width >> height;
  file >> max_val;
  Image *I=new Image(width,height);
  file >> *I;
  task5(I);
}

void IMT2016099(char* filename) {
  ifstream i;
  i.open(filename);
  int w, h, max;
  string mode;
  i>>mode>>w>>h>>max;
  Image image(w, h);
  i>>image;
  Task2 t2(image);
  vector<Pixel> p = t2.get_blue_minima();
  Image r = t2.get_image_blue_minima(p);
  Image f = t2.gaussian(p, r);
  CompositeImage * res = new CompositeImage(image, f, 0.25);
  ofstream output;
  output.open("output_task2_imt2016099.ppm");
  output<<mode<<"\n";
  output<<w<<" "<<h<<"\n";
  output<<max<<"\n";
  output<<(*res);
  i.close();
  output.close();
}

void IMT2016118(char* filename) {
  ifstream file(filename);
  string s;
  int width,height;
  int max_val;
  file >> s;
  file >> width >> height;
  file >> max_val;
  Image *I=new Image(width,height);
  file >> *I;
  vector<int> threshold;
  vector<vector<int> > brightness;
  int *pixel_count= new int[256];
  int i,j,k;
  pixel_Count(I,pixel_count,&brightness);
  for(i=0; i<256; i++){
    if (check_threshold(I,i,pixel_count)){
    threshold.push_back(i);
    }
  }
  if(threshold.size() == 0){
    for(i=0; i<256; i++){
      if (is_threshold1(I,i,pixel_count)){
      threshold.push_back(i);
      }
    }
  }
  binary_conversion_image(&brightness, find_median(threshold));
  connected_components(&brightness);
  coloring_image(I,&brightness);
  ofstream out("output_task6_imt2016118.ppm");
  out<<"P3"<<endl;
  out<<I->get_width()<<" "<<I->get_height()<<endl;
  out<<255<<endl;
  out<<(*I);
  file.close();
  out.close();
}
