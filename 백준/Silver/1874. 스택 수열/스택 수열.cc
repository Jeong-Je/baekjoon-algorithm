#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<char> result;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    stack<int> stack;

    int num = 1;
    for (int i = 0; i < n; i++) {
        int su = v[i];
        if (num <= su) {
            while (num <= su) {
                result.push_back('+');
                stack.push(num++);
            }

            result.push_back('-');
            stack.pop();           
        }
        else {
            int tmp = stack.top();
            stack.pop();

            if (tmp > su) {
                cout << "NO\n";
                return 0;
            }
            else {
                result.push_back('-');
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }    
}