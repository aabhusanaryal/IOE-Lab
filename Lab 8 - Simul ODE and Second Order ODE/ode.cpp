#include <iostream>
using namespace std;

enum ODE{
    simul=0, secondOrder
};
bool selection;

// y' = f1(x,y,z)
float f1(float x, float y, float z){
    if(selection == ODE::simul)
        return x;
    return z;
}
// z' = f2(x,y,z)
float f2(float x, float y, float z){
    if(selection == ODE::simul)
        return x;
    return -x*z-y;
}

int main(){

    cout<<"Press 0 if you want to solve simulODE or press 1 if you want to solve second order ODE:";
    cin>>selection;
    float x0, y0, z0, xn, yp0;
    int n;
    if(selection == ODE::simul){
        cout<<"Enter x0, y0, z0, xn and n: ";
        cin>> x0>>y0>>z0>>xn>>n;
    }
    else{
        cout<<"Enter x0, y0, y'0, xn and n: ";
        cin>> x0>>y0>>yp0>>xn>>n;
        z0 = yp0;
    }
    

    // Setting h=interval
    const float h=(xn-x0)/n;

    cout<<"The points on the required curve are: "<< endl;
    cout<<"("<<x0<<","<<y0<<","<<z0<<")\n";
    // cout<<"("<<x0<<","<<y0<<"), ";
    for(int i=0; i<n; i++){
        // Finding out slope (m)
        float k1 = h*f1(x0, y0, z0);
        float l1 = h*f2(x0, y0, z0);
        float k2 = h*f1(x0+h/2, y0+k1/2, z0+l1/2);
        float l2 = h*f2(x0+h/2, y0+k1/2, z0+l1/2);
        float k3 = h*f1(x0+h/2, y0+k2/2, z0+l2/2);
        float l3 = h*f2(x0+h/2, y0+k2/2, z0+l2/2);
        float k4 = h*f1(x0+h, y0+k3, z0+l3);
        float l4 = h*f2(x0+h, y0+k3, z0+l3);
        
        float k = (k1+2*k2+2*k3+k4)/6;
        float l = (l1+2*l2+2*l3+l4)/6;
        // cout<<"K1: "<<k1<<" K2: "<<k2<<" K3: "<<k3<<" K4: "<<k4<<endl;
        // cout<<"l1: "<<l1<<" l2: "<<l2<<" l3: "<<l3<<" l4: "<<l4<<endl<<endl;
        // cout<<"K: "<<k<<" L:"<< l<<endl;
        y0 += k;
        z0 += l;
        x0 += h;
        cout<<"("<<x0<<","<<y0<<","<<z0<<")\n";

    }
    return 0;
}