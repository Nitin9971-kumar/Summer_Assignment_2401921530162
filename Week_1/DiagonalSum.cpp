#include<iostream>
#include<vector>
using namespace std;

int matrixDiagonalSum(vector<vector<int>>&arr,int n){
    int sum = 0;

    for(int i=0;i<n;i++){
        sum = sum + arr[i][i];
        sum = sum + arr[i][n-1-i];
    }

    if(n%2 != 0)
        sum = sum - arr[n/2][n/2];

    return sum;
}
int main(){
    int n;
    vector<vector<int>>arr(n,vector<int>(n));

    cout << "enter size of matrix : (matrix should be square )" << endl;
    cin >> n;

    cout << "Enter matrix elements : " << endl;
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    int sum = matrixDiagonalSum(arr,n);
    cout << "Diagonal sum : " << sum << endl;

    return 0;
}
