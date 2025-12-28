#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, L;
    cin >> N >> L;

    deque<pii> dq;

    for (int i = 0; i < N; i++) {
        int now;
        cin >> now;

        while (dq.size() && dq.back().first >= now) {
            dq.pop_back();
        }

        dq.push_back({now, i});

        if (dq.front().second <= i - L) {
            dq.pop_front();
        }

        cout << dq.front().first << ' ';
    }
}