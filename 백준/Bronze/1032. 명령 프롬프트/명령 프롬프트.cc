// 1032 명령 프롬프트 (https://www.acmicpc.net/problem/1032)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    short N;
    cin >> N;
    
    vector<string> v(N+1);
    
    for(int i=0;i<N;i++){
        cin >> v[i];
    }

    int file_length = v[0].size();

    for(int i=0;i<file_length;i++){
        bool check = true;
        v[N].push_back(v[0][i]);

        for(int j=1;j<N;j++){
            if(v[j][i] != v[j-1][i]) {
                check = false;
                break;
            }
        }
        
        if(!check) {
            v[N][i] = '?';
        }
    }
    
    for(int i=0;i<file_length;i++){
        cout << v[N][i];
    }
}