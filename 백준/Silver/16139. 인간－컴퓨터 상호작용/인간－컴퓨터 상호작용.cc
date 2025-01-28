#include <string>
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    int cnt[27][200001] = {};
    
    cin >> str;
    
    cnt[str[0]-'a'][0] = 1;
    for(int i=1;i<str.size();i++){
        for(int j=0;j<27;j++){
            cnt[j][i] = cnt[j][i-1];
        }
        cnt[str[i]-'a'][i]++;
    }
    
    int N;
    cin >> N;
    
    char alpha;
    int l, r;
    for(int i=0;i<N;i++){
        cin >> alpha >> l >> r;
        if(l==0) {
            cout << cnt[alpha - 'a'][r]<< "\n";
        } else {
            cout << cnt[alpha - 'a'][r] - cnt[alpha - 'a'][l-1] << "\n";          
        }

    }
    
    return 0;
}