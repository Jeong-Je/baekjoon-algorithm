#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void hanoi(int n, int from, int to, int via) {
    if (n == 1) {
        cout << from << " " << to << '\n';
        return;
    }
    hanoi(n - 1, from, via, to);
    cout << from << " " << to << '\n';
    hanoi(n - 1, via, to, from);
}

int main() {
    int N;
    cin >> N;

    string count = to_string(pow(2, N));
    count = count.substr(0, count.find('.'));
    count[count.size() - 1] -= 1;

    cout << count << "\n";

    // N이 20 이하면 경로 출력
    if (N <= 20)
        hanoi(N, 1, 3, 2);

    return 0;
}
