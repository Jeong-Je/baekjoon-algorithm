#include <iostream>
using namespace std;

bool number[1000001] = { true, true };


int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; i * j <= n; j++) {
            number[i * j] = true;
        }
    }

    for (int i = m; i <= n; i++)
        if (!number[i])cout << i << "\n";
    return 0;
}
