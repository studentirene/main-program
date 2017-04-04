#include<iostream>
#include<iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
int main () {
srand(time(0));
int n, k, l;
cout<<"Vvedite poryadok matric A, B, CSS:"<<endl;
cin>>n;
int a[n][n], b[n][n], css[n][n];
for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
                a[i][j]=0;}}
for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
                b[i][j]=0;}}
for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){k=rand()%2; l=rand()%2;
        if(i+k < n){ if(j+l < n) {
                a[i+k][j+l]=50-(rand()%100);}}}}
for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){k=rand()%2; l=rand()%2;
        if(i+k < n){ if(j+l < n) {
                b[i+k][j+l]=50-(rand()%100);}}}}
for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
                css[i][j]=a[i][j]+b[i][j];}}
cout<<"Matrix A:"<<endl;
for(int i=0; i<n; i++){
        cout<<endl;
        for(int j=0; j<n; j++){
                cout<<setw(3)<<a[i][j];}}
cout<<endl<<endl<<endl;
cout<<"Matrix B:"<<endl;
for(int i=0; i<n; i++){
        cout<<endl;
        for(int j=0; j<n; j++){
                cout<<setw(3)<<b[i][j];}}
cout<<endl<<endl<<endl;
cout<<"Matrix CSS(result A+B):"<<endl;
for(int i=0; i<n; i++){
        cout<<endl;
        for(int j=0; j<n; j++){
                cout<<setw(3)<<css[i][j];}}
cout<<endl;
system("pause");    
return 0;   
}
