#include <iostream>
using namespace std;

int main(){
    // Taking points as input
    int n;
    cout<<"Enter the number of points given: ";
    cin>>n;

    float x[n], y[n];
    for(int i=0; i<n; i++){
        cout<<"Enter x["<<i<<"] y["<<i<<"]: ";
        cin>>x[i]>>y[i];
    }

    // xp is the value at which the polynomial is to be evaluated
    // i.e. we are finding y(xp)
    float xp;
    cout<<"Enter the value of x at which y(x) is to be evaluated: ";
    cin>>xp;

    // Main logic for Lagrange's Method
    float sum = 0;
    for(int i=0; i<n; i++){
        float product = 1;
        for(int j=0; j<n; j++){
            if(i!=j)
                product *= (xp-x[j])/(x[i]-x[j]);
        }
        sum += y[i] * product;
    }
    if(abs(sum)<0.000001) sum = 0;
    // Displaying result
    cout<<endl<<"RESULT: x["<<xp<<"] = "<<sum<<endl<<endl;

    for(int i=0; i<n; i++){
        cout<<"("<<x[i]<<","<<y[i]<<"), ";
    }
    return 0;
}