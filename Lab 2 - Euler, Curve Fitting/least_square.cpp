#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float x, y, sumX = 0, sumY = 0, sumX2 = 0, sumXY = 0, sumLNY = 0, sumXLNY = 0;
    int n;
    cout<<"Enter the number of points, n: ";
    cin>>n;
    
    for(int i=0; i<n; i++){
        cout<<"Enter x"<<i+1<<" y"<<i+1<<": ";
        cin>> x>> y;
        sumX += x;
        sumY += y;
        sumX2 += x*x;
        sumXY += x*y;
        sumLNY += log(y);
        sumXLNY += x*log(y);
    }
    float del = n*sumX2 - sumX*sumX;
    float delA = sumY*sumX2 - sumXY*sumX;
    float delB = n*sumXY - sumX*sumY;

    float a = delA/del;
    float b = delB/del;
    cout<<"The required equation is: y="<<a<<"+"<<b<<"x"<<endl;
    return 0;
}