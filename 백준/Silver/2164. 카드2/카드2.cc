// 2164

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() != 1) {
		q.pop(); //제일 앞 카드 버리고

		//그 다음 카드 제일 뒤로
		q.push(q.front());
		q.pop();
	}

	cout << q.front();

	return 0;
}