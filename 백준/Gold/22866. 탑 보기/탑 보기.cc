#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>


using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> h(N + 1);
	vector<int> cnt(N + 1), nearest(N + 1, INT_MAX);

	for (int i = 1; i <= N; i++) {
		cin >> h[i];
	}

	stack<int> st;
	for (int i = 1; i <= N; i++) {
		while (!st.empty() && h[st.top()] <= h[i]) st.pop();
		if (!st.empty()) {
			cnt[i] += st.size();
			nearest[i] = st.top();
		}
		st.push(i);
	}

	while (!st.empty())st.pop();

	for (int i = N; i >= 1; i--) {
		while (!st.empty() && h[st.top()] <= h[i]) st.pop();
		if (!st.empty()) {
			cnt[i] += st.size();

			if (nearest[i] == INT_MAX) nearest[i] = st.top();
			else if (abs(i - nearest[i]) > abs(i - st.top()))
				nearest[i] = st.top();
		}
		st.push(i);
	}

	for (int i = 1; i <= N; i++) {
		cout << cnt[i];
		if (cnt[i] > 0) cout << " " << nearest[i];
		cout << "\n";
	}
}
