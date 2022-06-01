#include <iostream>
#include <cmath>
using namespace std;


float f(float x){
    return x*x*x + 3*x*x;
}

float fp(float x){
    return 3*x*x + 6*x;
}

int main(){
    float x;
    float permissible_error;
    cout<<"Enter the permissible error and a guess for x: ";
    cin>> permissible_error >> x;

    for(int i=0; i<50; i++){
        if(fp(x) != 0)
            x -= f(x)/fp(x);
        else{
            cout<<"Division by zero error!";
            return 1;
        }
        if(f(x)<permissible_error) break;
    }

    if(fabs(f(x))<permissible_error) cout<<"The root is: "<<x;
    else cout<<"No roots found within given error.";
}
