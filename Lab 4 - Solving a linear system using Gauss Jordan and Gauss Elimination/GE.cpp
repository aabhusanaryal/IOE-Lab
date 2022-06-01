#include <iostream>
#include <vector>
using namespace std;

void logArray(float **arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            cout<<arr[i][j]<<"\t";
            if(j==n-1) cout<<"|\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    // Array to store data
    float **arr;
    int n;
    cout<<"Enter the number of unknowns: ";
    cin>>n;
    // For n unknown, we need an augumented matrix of order (n)*(n+1)
    arr = new float*[n]; // arr is an array of n elements, each of which are a pointer to float (i.e array of float)
    for(int i=0; i<n; i++){
        arr[i] = new float(n+1);
        // Rows input
        int j;
        for(j=0; j<n+1; j++){
            // Columns input
            if(j==0) cout<<"Enter ";
            cout<<"a["<<i<<"]["<<j<<"]";
            if(j!=n) cout<<", ";
            else cout<<": ";
        }
        for(j=0; j<n+1; j++){
            // Columns input
            cin>>arr[i][j];
        }
    }

    cout<<"The entered augumented matrix is:"<<endl;
    logArray(arr, n);

    // Gauss Elim starts here
    // Converting the matrix to row echelon form (upper triangular)
    for(int j=0; j<n; j++){ // For each column
        for(int i=j+1; i<n; i++){ // For each row of the column
            if(arr[j][j]==0){
                cout<<"The pivot element is 0 so we can't move further!";
                return 1;
            }
            float ratio = arr[i][j]/arr[j][j];
            for(int k=0; k<n+1; k++){
                arr[i][k] -= ratio * arr[j][k];
            }
        }
    }

    cout<<"The upper triangular array is: "<<endl;
    logArray(arr, n);

    vector<float> x;
    x.push_back(arr[n-1][n]/arr[n-1][n-1]);
    cout<<"x"<<n-1<<": "<<arr[n-1][n]/arr[n-1][n-1]<<endl;

    for(int i=n-2; i>=0; i--){
        float sum = 0;
        int count = x.size();
        for(int j=i+1; j<=n; j++){
            sum += arr[i][j]*x[count-1];
            count--;
        }
        float sol = (arr[i][n] - sum)/arr[i][i];
        x.push_back(sol);
        cout<<"x"<<i<<": "<<sol<<endl;
    }
    return 0;
}