#include <iostream>
using namespace std;
#define n 3
int main(){
    // Array to store data
    float arr[n][n+1];
    for(int i=0; i<n; i++){
        int j;
        cout<<"Enter"<<n*(n+1)<<" elements: ";
        for(j=0; j<n+1; j++){
            cin>>arr[i][j];
        }
    }
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){ 
            if(i==j) continue;
            if(arr[j][j]==0){
                cout<<"ERROR!"<<endl;
                return 1;
            }
            float ratio = arr[i][j]/arr[j][j];
            for(int k=0; k<n+1; k++){
                arr[i][k] -= ratio * arr[j][k];
            }
        }
    }

    cout<<"Soln: ";
    for(int i=0; i<n; i++){ // Looping over rows
        float sol = arr[i][n]/arr[i][i]; // Soln is coeff/diag element
        cout<<sol;
        if(i!=n-1)cout<<",\t";
    }
    return 0;
}