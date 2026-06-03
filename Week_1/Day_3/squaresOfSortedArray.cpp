#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout << "Enter no.of elements : " << endl;
    cin >> n;


    vector<int>arr(n);
    cout << "Enter array elements : " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int>ans(n);

    int left = 0;
    int right = n-1;
    int index = n-1;

    while(left <= right){
        if(abs(arr[left]) > abs(arr[right])) {
            ans[index] = arr[left] * arr[left];
            left++;
        }
        else{
            ans[index] = arr[right] * arr[right];
            right--;
        }
        index--;
    }

    cout << "After sorting of squares : " << endl;
    for(int value : ans)
        cout << value << " ";
    cout << endl;

    return 0;
}
