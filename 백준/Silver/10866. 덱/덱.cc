#include <iostream>
#include <deque>

using namespace std;


int main() {
    deque<int> myDeque;
    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_back") {
            int x;
            cin >> x;
            myDeque.push_back(x);
        }else if (cmd == "push_front") {
            int x;
            cin >> x;
            myDeque.push_front(x);
        }else if (cmd == "pop_back") {
            if (myDeque.empty()) {
                cout << "-1\n";
            }else {
                cout << myDeque.back() << '\n';
                myDeque.pop_back();
            }
        }else if (cmd == "pop_front") {
            if (myDeque.empty()) {
                cout << "-1\n";
            }else {
                cout << myDeque.front() << '\n';
                myDeque.pop_front();
            }
        }else if (cmd == "size") {
            cout << myDeque.size() << '\n';
        }else if (cmd == "empty") {
            if (myDeque.empty()) {
                cout << 1 << '\n';
            }else {
                cout << 0 << '\n';
            }
        }else if (cmd == "front") {
            if (myDeque.empty()) {
                cout << "-1\n";
            }
            else {
                cout << myDeque.front() << '\n';
            }
        } else if (cmd == "back") {
            if (myDeque.empty()) {
                cout << "-1\n";
            }
            else {
                cout << myDeque.back() << '\n';
            }
        }
    }
}
