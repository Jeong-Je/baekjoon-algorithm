#include <iostream>
using namespace std;

int N;
char op_result[8];
char op[3] = { ' ', '+', '-' };

bool isZero();
void dfs(int cnt);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        dfs(0);
        cout << "\n";
    }
}

void dfs(int cnt) {
    if (cnt == N - 1) {
        if (isZero()) {
            for (int i = 1; i <= N; i++) {
                cout << i;
                if (i < N) cout << op_result[i - 1];
            }
            cout << "\n";
        }
        return;
    }

    for (int i = 0; i < 3; i++) {
        op_result[cnt] = op[i];
        dfs(cnt + 1);
    }
}

bool isZero() {
    int sum = 0;
    int num = 1;
    char sign = '+';

    for (int i = 0; i < N - 1; i++) {
        if (op_result[i] == ' ') {
            num = num * 10 + (i + 2);
        } else {
            if (sign == '+') sum += num;
            else sum -= num;

            sign = op_result[i];
            num = i + 2;
        }
    }

    if (sign == '+') sum += num;
    else sum -= num;

    return sum == 0;
}
