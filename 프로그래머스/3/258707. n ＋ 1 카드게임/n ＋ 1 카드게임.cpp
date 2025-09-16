#include <bits/stdc++.h>
using namespace std;

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    int answer = 0;
    int idx = n / 3; // 초기 패를 뽑고 나서의 인덱스

    // 초기 패 세팅
    unordered_set<int> hand(cards.begin(), cards.begin() + n/3);
    vector<int> pool; // 뽑아온 카드 저장소

    while (true) {
        answer++;
        
        if(idx == n) break;
        
        // 이번 라운드 시작할 때, 카드 2장 뽑기
        if (idx < n) pool.push_back(cards[idx++]);
        if (idx < n) pool.push_back(cards[idx++]);
        

        bool used = false;

        // 1) 내 패만으로 (n+1) 쌍 확인
        for (int x : hand) {
            if (hand.count(n+1-x)) {
                hand.erase(x);
                hand.erase(n+1-x);
                used = true;
                break;
            }
        }

        // 2) 내 패 + pool 조합
        if (!used && coin > 0) {
            for (int x : hand) {
                auto it = find(pool.begin(), pool.end(), n+1-x);
                if (it != pool.end()) {
                    hand.erase(x);
                    pool.erase(it);
                    coin--;
                    used = true;
                    break;
                }
            }
        }

        // 3) pool + pool 조합
        if (!used && coin >= 2) {
            bool found = false;
            for (int i=0; i<pool.size(); i++) {
                for (int j=i+1; j<pool.size(); j++) {
                    if (pool[i] + pool[j] == n+1) {
                        pool.erase(pool.begin()+j);
                        pool.erase(pool.begin()+i);
                        coin -= 2;
                        used = true;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }

        if (!used) break; // 더 이상 못 버티면 게임 종료
    }

    return answer;
}
