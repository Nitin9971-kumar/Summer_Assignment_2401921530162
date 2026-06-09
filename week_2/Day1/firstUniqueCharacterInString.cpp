#include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    int freq[26] = {0};

    for(int i = 0; i < s.size(); i++)
        freq[s[i] - 'a']++;

    for(int i = 0; i < s.size(); i++) {
        if(freq[s[i] - 'a'] == 1)
            return i;
    }

    return -1;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int ans = firstUniqChar(s);

    cout << "Index of first non-repeating character: " << ans << endl;

    return 0;
}
