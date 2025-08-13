#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    stack<int> stk;
    int count = 0;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        // 현재 높이가 스택 top보다 작으면 pop하면서 카운트
        while (!stk.empty() && stk.top() > y) {
            stk.pop();
            count++;
        }

        // 현재 높이가 스택 top보다 크면 push
        if (stk.empty() || stk.top() < y) {
            if (y > 0) stk.push(y);
        }
    }

    // 남은 높이 pop
    while (!stk.empty()) {
        stk.pop();
        count++;
    }

    cout << count << "\n";
    return 0;
}
