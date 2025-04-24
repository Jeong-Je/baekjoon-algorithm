#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int left = 1;
    int right = *max_element(v.begin(), v.end());
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long cnt = 0;

        for (int i = 0; i < N; i++) {
            cnt += (v[i] / mid);
        }

        if (cnt >= M) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << '\n';
}
