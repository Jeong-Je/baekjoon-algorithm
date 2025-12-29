#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        string s;
        stack<char> stk;

        getline(cin, s);
        bool isBalance = true;

        if (s == ".") break;

        for (int i=0;i<s.size()-1;i++) {
            if (s[i] == '(' || s[i] == '[') stk.push(s[i]);
            else if (s[i] == ')' || s[i] == ']') {
                if (stk.empty()) isBalance = false;
                else {
                    if (s[i] == ')' && stk.top() == '(') {
                        stk.pop();
                    } else if (s[i] == ']' && stk.top() == '[') {
                        stk.pop();
                    } else {
                        isBalance = false;
                    }
                }
            }
        }

        if (isBalance && stk.empty()) {
            cout << "yes\n";
        }else {
            cout << "no\n";
        }
    }

}