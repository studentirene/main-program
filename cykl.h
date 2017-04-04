#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int main()
 { 	
ofstream myfile;
  myfile.open ("example.txt");
   	int i;
 	float F,b=3.85,d,pi=3.14,d1=-2.3,d2=0.01,dd=0.33;
 	for(d=d1;d<=d2;d+=dd)
 	{F=pow(b+d,1/3)*(1/tan(pi/(d+0.15)));
 	myfile<<cout<<"\n F="<<F<<"  d="<<d;
 	}
	myfile.close();
	return 0;
}
