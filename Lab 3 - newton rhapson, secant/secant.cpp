#include<iostream>
#include<cmath>
using namespace std;

#define isDifferenceZero(a, b)(fabs((a)-(b))<=0.00001)
#define TIMEOUT 100
#define ERR 0.0000001

float f(float x){
    return x*x*x + 3*x*x -5;
}

int main(){
    float a, b, c;
    cout<<"Enter two points x0 and x1: ";
    cin>>a>>b;
    for(int i=0; i<TIMEOUT; i++){
        if(!isDifferenceZero(f(b), f(a))){ // if f(b) - f(a) != 0
            c = (a*f(b)-b*f(a))/(f(b)-f(a));
            a=b;
            b=c;
            // cout<<"("<<a<<", "<<b<<", "<<c<<", "<<fabs(f(c))<<")"<<endl;
            if(fabs(f(c))<ERR) break;
        }
        else{
            cout<<"Div by zero error!";
            return 1;
        }
    }
    if(fabs(f(c))<ERR) cout<<"The root is: "<<c;
    else cout<<"No roots found within given error.";
}