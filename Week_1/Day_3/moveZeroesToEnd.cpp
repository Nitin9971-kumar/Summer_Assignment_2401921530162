#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,data;
    vector<int>arr;
    cout << "Enter no.of elmeents : " << endl;
    cin >> n;

    cout << "Enter array elments : " << endl;
    for(int i=0;i<n;i++){
        cin >> data;
        arr.push_back(data);
    }

    int j = 0;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j++;
        }
    }

    cout << "After zeroes to moving end : " << endl;
    for(int value : arr)
        cout << value << " ";
    cout << endl;

    return 0;
}
