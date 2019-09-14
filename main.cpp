#include "Tasks.h"

using namespace std;

int main(int argc, char* argv[]) {
  if(argc != 2) {
    cout<<"Wrong imput format"<<endl;
    cout<<"Usage : <executable> <input filename.ppm>"<<endl;
    return 0;
  }
  string input;
  cout<<"Our group task ID combination is: 2, 3 ,4 ,5, 6, 7"<<endl;
  getline(cin, input);
  vector<int> ip = getInput(input);
  for(int i=0;i<ip.size();i++) {
    switch(ip[i]) {
      case 2:
        try {
          IMT2016099(argv[1]);
        }
        catch(int e) {
          cout<<"An exception occured in task 2 " << e << endl;
        }
        break;
      case 3:
        try {
          IMT2016057(argv[1]);
        }
        catch(int e) {
          cout<<"An exception occured in task 3 " << e << endl;
        }
        break;
      case 4:
        try {
          IMT2016001(argv[1]);
        }
        catch(int e) {
          cout<<"An exception occured in task 4 " << e << endl;
        }
        break;
      case 5:
        try {
          IMT2016079(argv[1]);
        }
        catch(int e) {
          cout<<"An exception occured in task 5 " << e << endl;
        }
        break;
      case 6:
        try {
          IMT2016118(argv[1]);
        }
        catch(int e) {
          cout<<"An exception occured in task 6 " << e << endl;
        }
        break;
      case 7:
        try {
          IMT2016029(argv[1]);
        }
        catch(int e) {
          cout<<"An exception occured in task 7 " << e << endl;
        }
        break;
      default:
        cout<<"Not a valid input";
    }
  }
  return 0;
}
