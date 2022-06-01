#include <iostream>
#include <iomanip>
#include<math.h>
using namespace std;

enum aug{
   left=0, full, right
};


void log(float **arr, int n, aug p){
    int leftLimJ, rightLimJ;
    if(p == aug::left) {leftLimJ=0; rightLimJ = n;}
    else if(p == aug::right) {leftLimJ=n; rightLimJ = n+1;}
    else if(p == aug::full) {leftLimJ=0; rightLimJ = n+1;}
    
    for(int i=0; i<n; i++){
        cout<<"|\t";
        for(int j=leftLimJ; j<rightLimJ; j++){
            if(p == aug::full && j==n) cout<<"|\t";
            cout<<fixed<<setprecision(2)<<arr[i][j]<<"\t";
        }
        cout<<"|"<<endl;
    }
    cout<<endl;
}


int main(){
    int deg, n;
    cout<<"Enter the degree of polynomial and the number of input points: ";
    cin>> deg>>n;
    
    // Taking inputs for given points
    float *x = new float[n];
    float *y = new float[n];
    for(int i=0; i<n; i++){
        cout<<"Enter x["<<i<<"] and y["<<i<<"]: ";
        cin>>x[i]>>y[i];
    }

    // Creating the required augumented matrix
    float **matrix = new float*[deg+1];
    for(int i=0; i<deg+1; i++){
        matrix[i] = new float[deg+2];
        for(int j=0; j<deg+2; j++){
            float c = 0;
            for(int k=0; k<n; k++){
                if(j<=deg)  c += pow(x[k], i+j);
                else c+= pow(x[k],i)*y[k];
            }
            matrix[i][j] = c;
        }
    }

    // Logging the array:
    cout<<"The augumented matrix is:"<<endl;
    log(matrix, deg+1, aug::full);

    // Performing Gauss Jordan to solve the augumented matrix
    n = deg+1;
    for(int j=0; j<n; j++){ // For each column
        for(int i=0; i<n; i++){ // For each row of the column
            if(i==j) continue;
            if(matrix[j][j]==0){
                cout<<"ERROR!"<<endl;
                log(matrix, n, aug::full);
                cout<<"The pivot element is 0 so we can't proceed further!";
                return 1;
            }
            float ratio = matrix[i][j]/matrix[j][j];
            for(int k=0; k<n+1; k++){
                matrix[i][k] -= ratio * matrix[j][k];
            }
        }
    }

    cout<<"The final array is: "<<endl;
    log(matrix, n, aug::full);

    cout<<"Finally, the required polynomial is:\n";
    for(int i=0; i<n; i++){ // Looping over rows
        float coeff = matrix[i][n]/matrix[i][i]; // Soln is coeff/diag element
        cout<<"y = "<<coeff<<"x^"<<i;
        if(i!=n-1)cout<<" + ";
    }
}