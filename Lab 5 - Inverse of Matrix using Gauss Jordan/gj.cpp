#include <iostream>
#include <iomanip>
using namespace std;

enum aug{
    left=0, right, full
};

void logArray(float **arr, int n, aug p){
    int leftLimJ, rightLimJ;
    if(p == aug::left) {leftLimJ=0; rightLimJ = n;}
    else if(p == aug::right) {leftLimJ=n; rightLimJ = 2*n;}
    else if(p == aug::full) {leftLimJ=0; rightLimJ = 2*n;}
    
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
    float **matrix;
    int n;
    cout<<"Enter the order of the matrix, n: ";
    cin>>n;

    matrix = new float*[n];

    // Taking left side of the matrix as input
    for(int i=0; i<n; i++){
        matrix[i] = new float(2*n); // The aug matrix is of order (n)x(2n)
        for(int j=0; j<n; j++){ // We only take the left side of the aug matrix as input
            // Columns input
            if(j==0) cout<<"Enter ";
            cout<<"a["<<i<<"]["<<j<<"]";
            if(j!=n-1) cout<<", ";
            else cout<<": ";
        }
        for(int j=0; j<n; j++){
            // Columns input
            cin>>matrix[i][j];
        }
    }

    // Generating an identity matrix on the right side
    for(int i=0; i<n; i++){
        for(int j=n; j<2*n; j++){
            matrix[i][j] = ((i == j-n)?  1: 0); // Diag is 1, others 0
        }
    }
    cout<<"The entered matrix is:"<<endl;
    logArray(matrix, n, aug::left);

    // Gauss Jordan Logic starts here
    for(int j=0; j<n; j++){ // For each column
        for(int i=0; i<n; i++){ // For each row of the column
            if(i==j) continue;
            if(matrix[j][j]==0){
                cout<<"ERROR!"<<endl;
                logArray(matrix, n, aug::full);
                cout<<"The pivot element is 0 so we can't proceed further!";
                return 1;
            }
            float ratio = matrix[i][j]/matrix[j][j];
            for(int k=0; k<2*n; k++){
                matrix[i][k] -= ratio * matrix[j][k];
            }
        }
    }

    // Converting the diagonal matrix to identity matrix
    for(int i=0; i<n; i++){
        float tempDiag = matrix[i][i];
        for(int j=0; j<2*n; j++){
            matrix[i][j] /= tempDiag;
        }
    }
    cout<<"The inverse of entered matrix is: "<<endl;
    logArray(matrix, n, aug::right);
    return 0;
}