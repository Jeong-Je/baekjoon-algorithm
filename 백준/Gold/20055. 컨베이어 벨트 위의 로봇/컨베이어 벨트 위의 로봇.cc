#include <iostream>
#include <deque>
using namespace std;

int durability[201];
bool robot_exist[201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= 2 * N; i++) {
        cin >> durability[i];
    }

    int step = 0;
    int zero_count = 0;

    while (zero_count < K) {
        step++;

        // 1. 벨트와 로봇 회전
        int last_durability = durability[2 * N];
        for (int i = 2 * N; i >= 2; i--) {
            durability[i] = durability[i - 1];
            robot_exist[i] = robot_exist[i - 1];
        }
        durability[1] = last_durability;
        robot_exist[1] = false;
        robot_exist[N] = false; // 내리는 위치

        // 2. 로봇 이동
        for (int i = N - 1; i >= 1; i--) {
            if (robot_exist[i] && !robot_exist[i + 1] && durability[i + 1] > 0) {
                robot_exist[i] = false;
                robot_exist[i + 1] = true;
                durability[i + 1]--;
                if (durability[i + 1] == 0) zero_count++;
            }
        }
        robot_exist[N] = false; // 내리는 위치

        // 3. 로봇 올리기
        if (!robot_exist[1] && durability[1] > 0) {
            robot_exist[1] = true;
            durability[1]--;
            if (durability[1] == 0) zero_count++;
        }
    }

    cout << step;
}
