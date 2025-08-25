#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    
    vector<int> v(N);
    
    for(int i=0;i<N;i++)
    {
        char c;
        cin >> c;
        
        if(c == 'H') v[i] = 1; // 햄버거 위치
        else v[i] = 0; // 사람 위치
    }
    
    for(int i=0;i<N;i++)
    {
        if(v[i] == 0)
        {
           // i를 기준으로 왼쪽 K만큼 검사 (다음 사람을 위해서 가장 왼쪽 부터 먹기)
            for(int j=i-K;j<i;j++){
                if(i - j > K) break;
                if(v[j] == 1) {
                    v[i] = 2; // 햄버거를 먹을 수 있는 사람은 2로 체크 
                    v[j] = 3; // 이미 먹은 햄버거는 3으로 체크
                    break;
                }
            }
            
            if(v[i] == 2) continue; // 왼쪽에서 햄버거를 먹을 수 있으면 오른쪽은 안 봐도 됨
            
            // i를 기준으로 오른쪽 K만큼 검사 
            for(int j=i+1;j<N;j++)
            {
                if(j - i > K) break;
                if(v[j] == 1) {
                    v[i] = 2; // 햄버거를 먹을 수 있는 사람은 2로 체크 
                    v[j] = 3; // 이미 먹은 햄버거는 3으로 체크 
                    break;
                }
            }
            
        }
    }
    
    int cnt = 0;
    for(int i=0;i<N;i++)
    {
        if(v[i] == 2) cnt++;
    }
    cout << cnt;
}