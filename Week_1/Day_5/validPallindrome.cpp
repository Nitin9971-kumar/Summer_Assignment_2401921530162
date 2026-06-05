#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    
    cout << "Enter string : " << endl;
    getline(cin >> ws, s);

    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
            ans.push_back(ch);
        }
        else if (ch >= 'a' && ch <= 'z') {
            ans.push_back(ch);
        }
        else if (ch >= '0' && ch <= '9') {
            ans.push_back(ch);
        }
    }

    int left = 0;
    int right = ans.size() - 1;

    while (left <= right) {
        if (ans[left] != ans[right]) {
            cout << "Not Palindrome";
            return 0;
        }

        left++;
        right--;
    }

    cout << "Palindrome";

    return 0;
}
