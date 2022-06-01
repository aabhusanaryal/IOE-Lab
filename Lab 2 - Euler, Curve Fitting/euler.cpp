#include <iostream>
using namespace std;

// Function of slope
float f(float x, float y){
    return x+y;
}

int main(){
    // cout<<"Function: 1"<<endl;
    // Taking user inputs
    float x0, y0, xn;
    int n;
    cout<<"Enter x0, y0, xn and n: ";
    cin>> x0>>y0>>xn>>n;

    // Setting h=interval
    const float h=(xn-x0)/n;

    cout<<"The points on the required curve are: "<< endl;
    cout<<"("<<x0<<","<<y0<<")\n";
    // cout<<"("<<x0<<","<<y0<<"), ";
    for(int i=0; i<n; i++){
        y0 += h*f(x0, y0);
        x0 += h;
        // cout<<"("<<x0<<","<<y0<<"), ";
        cout<<"("<<x0<<","<<y0<<")\n";
    }
    return 0;
}