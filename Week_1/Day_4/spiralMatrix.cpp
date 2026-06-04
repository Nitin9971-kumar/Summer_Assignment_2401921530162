#include<iostream>
#include<vector>
using namespace std;

void printSpiralMatrix(vector<vector<int>>&arr,int n){
    int left = 0;
    int right = n-1;
    int top = 0;
    int bottom = n-1;

    while(left <= right && top <= bottom){
        for(int i = left;i<=right;i++)
            cout << arr[top][i] << " ";
        top++;

        for(int i = top;i<=bottom;i++)
            cout << arr[i][right] << " ";
        right--;

        if(top <= bottom){
            for(int i=right;i>=left;i--)
                cout << arr[bottom][i] << " ";
            bottom--;
        }

        if(left <= right){
            for(int i=bottom;i>=top;i--)
                cout << arr[i][left] << " ";
            left++;
        }
    }
}
int main(){
    int n;
    cout << "Enter size : " << endl;
    cin >> n;

    vector<vector<int>>arr(n,vector<int>(n));
    cout << "enter matrix elements : " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    }

    printSpiralMatrix(arr,n);
    return 0;
}
