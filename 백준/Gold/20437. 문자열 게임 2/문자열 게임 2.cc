#include <iostream>
#include <string>
#include <limits.h>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--) {
        string W; 
        int K;
        cin >> W >> K;
        
        vector<int> alphabet_count(26);
        for(int i=0;i<W.length();i++){
            ++alphabet_count[W[i] - 'a'];
        }
        
        int answer3 = INT_MAX;
        int answer4 = -1;
        
        for(int i=0;i<W.length();i++){
            if(alphabet_count[W[i] - 'a'] < K) continue;
            
            int cnt = 0;
            for(int j=i;j<W.length();j++){
                if(W[i] == W[j]) cnt++;
                
                if(cnt == K) {
                    answer3 = min(answer3, j - i + 1);
                    answer4 = max(answer4, j - i + 1);
                    break;
                }
                
            }
            
        }
        if(answer3 == INT_MAX || answer4 == -1) cout << -1 << "\n";
        else cout << answer3 << " " << answer4 << "\n";
    }
    

}