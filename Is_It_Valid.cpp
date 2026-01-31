#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        queue<char> st;

        for (char c : s) {
            if (!st.empty() &&
               ((c == '1' && st.front() == '0') ||
                (c == '0' && st.front() == '1'))) {
                st.pop(); 
            } else {
                st.push(c);
            }
        }
        if (st.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

//input
// 10
// 0011
// 1010
// 1100
// 0101
// 0001
// 0111
// 0110
// 100101
// 1110010
// 0001011011
// // output
// YES
// YES
// YES
// YES
// NO
// NO
// YES
// YES
// NO
// YES
