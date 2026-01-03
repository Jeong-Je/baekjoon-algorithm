#include <iostream>

using namespace std;

int arr[100001];
int state[100001];

void run(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int t=0;t<T;t++) {
        int N;
        cin >> N;

        for (int i=1;i<=N;i++) {
            cin >> arr[i];
            state[i] = 0;
        }

        for (int i=1;i<=N;i++) {
            if (state[i] == 0) run(i);
        }

        int cnt = 0;
        for (int i=1;i<=N;i++) {
            if (state[i] != -1) cnt++;
        }

        cout << cnt << '\n';
    }
}

void run(int start) {
    int cur = start;
    while (true) {
        state[cur] = start;
        cur = arr[cur];

        if (state[cur] == start) {
            while (state[cur] != -1) {
                state[cur] = -1;
                cur = arr[cur];
            }
            return;
        }
        else if (state[cur] != 0) {
            return;
        }
    }
}