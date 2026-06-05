#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s;
    cout << "Enter string : " << endl;
    getline(cin >> ws,s);

    int left = 0;
    int right = s.size()-1;

    while(left <= right){
        swap(s[left],s[right]);
        left++;
        right--;
    }

    cout << "After reversing string : " << endl;
    cout << s << endl;

    return 0;
}
