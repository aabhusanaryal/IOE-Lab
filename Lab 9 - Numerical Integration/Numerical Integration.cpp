#include <iostream>
#include <cmath>
using namespace std;

float f(float x){
    return x;
}

int main(){
    bool useFunction;
    float x0, xn, h, *x, *y;
    int n;

    cout<<"Enter the limits of integration, x0 and xn: ";
    cin>> x0>>xn;
    cout<<"Enter the number of intervals, n: "; 
    cin>>n;
    cout<<"Press 1 to use predefined function and press 0 to give input points: ";
    cin>>useFunction;

    x = new float[n+1];
    y = new float[n+1];
    h = (xn-x0)/n;

    // Populating x and y arrays
    for(int i=0; i<n+1; i++){
        x[i] = x0+h*i;
        if(!useFunction){
            // Taking user input if the user doesn't wish to use predefined function
            cout<<"Enter y(x"<<i<<") = y("<<x[i]<<") = ";
            cin>>y[i];
        }
        else{
            // Using predefined function to populate the array
            y[i] = f(x[i]);
        }
    }

    // Logging out the x and y arrays
    // for(int i=0; i<n+1; i++){
    //     cout<<"("<<x[i]<<" , "<<y[i]<<")\n";
    // }

    // =======================================================
    cout<<"Trapezoid:\n";
    // Main trapezoid logic
    float sum = 0;
    for(int i=0; i<n+1; i++){
        int scale = (i ==0 || i ==n)? 1:2;
        sum += scale*y[i];
    }
    float soln = sum*h/2;
    cout<<"The area under the given curve is: "<<soln<<endl;
    // =======================================================


    // =======================================================
    cout<<"Simpson 1/3:\n";
    // Main Simpson 1/3 logic
    sum = 0;
    for(int i=0; i<n+1; i++){
        int scale = (i ==0 || i ==n)? 1:(i%2 == 0? 2: 4);
        sum += scale*y[i];
    }
    soln = sum*h/3;
    cout<<"The area under the given curve is: "<<soln<<endl;
    // =======================================================

    // =======================================================
    cout<<"Simpson 3/8:\n";
    // Main Simpson 3/8 logic
    sum = 0;
    for(int i=0; i<n+1; i++){
        int scale = (i ==0 || i ==n)? 1:(i%3 == 0? 2: 3);
        sum += scale*y[i];
    }
    soln = sum*3*h/8;
    cout<<"The area under the given curve is: "<<soln<<endl;
    // =======================================================
}