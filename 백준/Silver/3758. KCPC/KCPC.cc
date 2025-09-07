#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(tuple<int, int, int, int> &v1, tuple<int, int, int, int> &v2)
{
    // 점수 높은 순으로 정렬 
    if(get<0>(v1) != get<0>(v2)) return get<0>(v1) > get<0>(v2);
    
    // 제출 회수 적은 순으로 정렬
    if(get<1>(v1) != get<1>(v2)) return get<1>(v1) < get<1>(v2);
    
    // 마지막 제출이 빠른 순으로 정렬
    return get<2>(v1) < get<2>(v2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++)
    {
        int N, K, ID, M;
        cin >> N >> K >> ID >> M;
        
        vector<vector<int>> v(N+1, vector<int>(K+1, 0));
        vector<tuple<int, int, int, int>> table(N+1, {0, 0, 0, 0});
        
        for(int i=1;i<=M;i++)
        {
            int team, problem, score;
            cin >> team >> problem >> score;
            
            get<1>(table[team])++; // 제출 횟수 카운트
            get<2>(table[team]) = i; // 제출 인덱스 저장
            
            get<3>(table[team]) = team; // 원래 인덱스 저장 (밑에서 정렬하면 원래 인덱스 사라지기 때문)
            
            // 최종 점수 갱신 
            if(v[team][problem] < score) 
            {
                get<0>(table[team]) -= v[team][problem];
                v[team][problem] = score;
                get<0>(table[team]) += v[team][problem];
            }
        }
        
        // 정렬 
        sort(table.begin() + 1, table.end(), cmp);
        
        for(int i=1;i<=N;i++)
        {
            if(get<3>(table[i]) == ID) 
            {
                cout << i << "\n";
                break;
            }
        }
    }
}