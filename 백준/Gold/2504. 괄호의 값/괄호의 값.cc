#include <iostream>
#include <stack>

using namespace std;

int main() {
    int ans = 0;

    string s;
    cin >> s;

    int sum = 0; // 더해질 값
    int num = 1; // 곱해질 값

    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            num *= 2;

            st.push(s[i]);
        }
        else if (s[i] == '[') {
            num *= 3;

            st.push(s[i]);
        }
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i-1] == '[') {
                sum += num;
            }
            num /= 3;
            st.pop();

        } else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }

            if (s[i-1] == '(') {
                sum += num;
            }
            num /= 2;
            st.pop();
        }
    }

    if (st.empty()) {
        cout << sum;
    } else {
        cout << 0;
    }
}