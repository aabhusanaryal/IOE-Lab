#include <iostream>
#include <cmath>
using namespace std;

float* mmult(float **A, float *X, int n){
    // Takes in a nxn matrix A and a nx1 vector X and returns AX
    float *temp = new float[n];
    for(int i=0; i<n; i++){
        float sum=0;
        for(int j=0; j<n; j++){
            sum+=A[i][j]*X[j];
        }
        temp[i] = sum;
    }
    return temp;
}

float max(float *Z, int n){
    int max = Z[0];
    for(int i=1; i<n; i++){
        if(abs(Z[i]) > abs(max)) max = Z[i];
    }
    return max;
}

float *difference(float *A, float *B, int n){
    // Returns A-B
    float *temp = new float[n];
    for(int i=0; i<n; i++){
        temp[i] = A[i]-B[i];
    }
    return temp;
}

float *scale(float *Z, int n, float scalar){
    // Scales the given matrix Z of order nx1 by a factor of scalar
    float *temp = new float[n];
    for(int i=0; i<n; i++){
        temp[i] = Z[i]*scalar;
    }
    return temp;
}

int main(){
    // Taking inputs for the dimension of matrix A, the matrix A itself, and Permissible err E
    int n;
    float **A, e;
    cout<<"Enter the order of matrix A and the permissible err, e: ";
    cin>>n>>e;
    A = new float*[n];
    float *X = new float[n];
    for(int i=0; i<n; i++){
        // Setting the initial guess for eigen vector
        X[i] = 1;
        // Populating A
        A[i] = new float[n];
        for(int j=0; j<n; j++){
            cout<<"Enter A["<<i<<"]["<<j<<"]: ";
            cin>>A[i][j];
        }
    }
    float *mult = mmult(A, X, n);
    cout<<"[";
    for(int i =0; i<n; i++){
        cout<<mult[i]<<", ";
    }
    cout<<"]";
    cout<<"MAX: "<<max(mult, n)<<endl;
   
    float *Z = new float[n];
    float *Y = new float[n];
    float *diff = new float[n];
    float lambda;
    int currErr;
    
    float test[3] = {0.0584415, 0.0681819, 0.0487013};
    // cout<<"D: "<<max(test, 3);
    // Power Method iteration starts here:
    for(int i=0; currErr<=e && i<=10; i++){
        Z = mmult(A, X, n);
        lambda = max(Z, n);
        Y = scale(Z, n, 1/lambda); // Setting Y = Z/lambda
        diff = difference(Y, X, n);
        // Logging diff starts
        cout<<"[";
        for(int i =0; i<n; i++){
            cout<<diff[i]<<", ";
        }
        cout<<"]";
        // Logging diff ends
        currErr = max(diff, n);
        cout<<"ERR: "<<max(diff, n)<<endl;
        X = Y;
    }
    cout<<"Lambda: "<<lambda;
}