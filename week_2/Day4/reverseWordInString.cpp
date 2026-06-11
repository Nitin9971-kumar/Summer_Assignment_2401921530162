#include <iostream>
#include <string>
using namespace std;

void reverseString(string &temp) {
    int start = 0;
    int end = temp.size() - 1;

    while (start < end) {
        swap(temp[start++], temp[end--]);
    }
}

string reverseWords(string s) {
    string temp = "";
    string ans = "";

    for (int i = 0; i < s.size(); i++) {

        while (i < s.size() && s[i] != ' ') {
            temp.push_back(s[i]);
            i++;
        }

        reverseString(temp);
        ans += temp;

        if (i < s.size())
            ans += " ";

        temp = "";
    }

    return ans;
}

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    string result = reverseWords(s);

    cout << "Output: " << result << endl;

    return 0;
}
