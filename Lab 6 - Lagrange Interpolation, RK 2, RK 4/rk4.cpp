#include <iostream>
using namespace std;

// Function of slope
float f(float x, float y){
    return (3*x*x + x + 1/50);
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
    cout<<"("<<x0<<","<<y0<<"), ";
    // cout<<"("<<x0<<","<<y0<<"), ";
    for(int i=0; i<n; i++){
        // Finding out slope (m)
        float m1 = f(x0, y0);
        float m2 = f(x0+h/2, y0+m1*h/2);
        float m3 = f(x0+h/2, y0+m2*h/2);
        float m4 = f(x0+h, y0+m3*h);
        
        float m = (m1+2*m2+2*m3+m4)/6;

        y0 += h*m;
        x0 += h;
        // cout<<"("<<x0<<","<<y0<<"), ";
        cout<<"("<<x0<<","<<y0<<"), ";
    }
    return 0;
}