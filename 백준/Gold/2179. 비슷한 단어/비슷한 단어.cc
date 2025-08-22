#include <iostream>
#include <string>
#include <vector>

using namespace std;

int str_cmp(const string &a, const string &b) {
    int cnt = 0;
    int len = min(a.size(), b.size());
    for(int i=0; i<len; i++) {
        if(a[i] == b[i]) cnt++;
        else break;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<string> v(N);
    for(int i=0;i<N;i++) {
        cin >> v[i];
    }
    
    int max_len = 0;
    string ans1, ans2;
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            int cnt = str_cmp(v[i], v[j]);
            if(cnt > max_len) { // 같은 길이는 무시
                max_len = cnt;
                ans1 = v[i];
                ans2 = v[j];
            }
        }
    }
    
    cout << ans1 << "\n" << ans2;
}
