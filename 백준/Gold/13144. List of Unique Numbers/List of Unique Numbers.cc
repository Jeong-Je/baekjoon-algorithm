#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    vector<bool> check(100001, false);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 0;
    long long ans = 0;

    while (left < N) {
        while (right < N && !check[arr[right]]) {
            check[arr[right]] = true;
            right++;
        }

        ans += (right - left);

        check[arr[left]] = false;
        left++;
    }

    cout << ans;
}