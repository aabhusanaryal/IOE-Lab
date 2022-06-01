#include <iostream>
#include <cmath>
using namespace std;

float f(float x){
    return x*x+10*x+5;
}

int main(){
    // Taking inputs: 'a' and 'b' as intervals; 'e' as permissible error
    float a, b, e;
    float precision = 0.005;
    cout<<"Enter a, b and e: ";
    cin>> a >> b >> e;

    const int MAX_ITERS = 2 * (log10(fabs(a - b)) - log10(e)) / log10(2) + 1;
    // Checking if the root is not in the given interval
    // If f(a) and f(b) have same sign, the root is not in the interval

    if(f(a)*f(b) > 0){ // f(a)*f(b) is +ve iff f(a) and f(b) have same sign
        cout<<"No root exist for the given function in the given interval."<<endl;
    }

    else if(f(a)*f(b) < precision && f(a)*f(b) > -precision){ // if f(a) or f(b) ~ 0
        if(f(a) < precision && f(a) > -precision){ // if f(a) ~ 0
            cout<<a<<" is the required root.";
        }
        if(f(b) < precision && f(b) > -precision){ // if f(a) ~ 0
            cout<<b<<" is the required root.";
        }
    }

    else{ // Neither a nor b is the root, but at least one root exist in the interval a to b
        // Main bisection logic starts here:
        float c;
        int i;
        for(i=0; i<MAX_ITERS; i++){
            c = ((a*f(b)-b*f(a))/(f(b)-f(a)));
            if(f(a)*f(c) > 0){ // if f(a) and f(c) are of same sign
                a=c;
            }
            else b=c;
            if(abs(f(c))<e) break;
        }
        if(i<=MAX_ITERS-1)
            cout<<c<<"  is the required root. No of iterations = "<<i+1;
        else{
            cout<<"Error: TIMEOUT!";
            return 1;
        }
    }
    return 0;
}