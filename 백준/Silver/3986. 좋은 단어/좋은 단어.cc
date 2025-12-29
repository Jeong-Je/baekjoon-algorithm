#include <iostream>
#include <stack>

using namespace std;

bool is_good(string);

int main() {
    int N, ans = 0;
    cin >> N;

    for (int i=0;i<N;i++) {
        string s;
        cin >> s;

        if (is_good(s)) ans++;
    }

    cout << ans;
}

bool is_good(string s) {
    stack<char> st;
    for (int i=0;i<s.length();i++) {
        if (s[i] == 'A') {
            if (st.empty() == false && st.top() == 'A') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        else if (s[i] == 'B') {
            if (st.empty() == false && st.top() == 'B') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
    }

    if (st.empty()) return true;

    return false;
}