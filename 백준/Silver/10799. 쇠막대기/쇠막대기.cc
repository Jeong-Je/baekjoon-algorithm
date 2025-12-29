#include <iostream>
#include <stack>

using namespace std;

int main() {
    int ans = 0;

    string s;
    cin >> s;

    stack<char> st;
    int stick = 0;
    for (int i=0;i<s.length();i++) {

        if (s[i] == '(') {
            stick++;
            st.push(s[i]);
        }
        // 레이저 끝나는 곳
        else if (s[i] == ')' && s[i-1] == '(') {
            stick--;
            st.pop();

            ans += stick;
        }
        // 막대기 끝나는 곳
        else if (s[i] == ')' && s[i-1] == ')') {
            stick--;
            st.pop();

            ans++;
        }
    }

    cout << ans;
}