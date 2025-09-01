#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++)
    {
        int N;
        cin >> N;
        
        vector<int> team_num(N+1, 0);
        vector<int> rank;
        vector<int> team_cnt(N+1, 0);
        vector<tuple<int, int, int>> team_score(N+1, {0, 0, 0});
        
        for(int i=0;i<N;i++)
        {
            int team;
            cin >> team;
            
            rank.push_back(team);
            team_num[team]++;
        }
        
        for(int i=1;i<=N;i++)
        {
            if(team_num[i] == 0) break;
            
            if(team_num[i] < 6)
            {
                for(int j=0;j<rank.size();j++)
                {
                    if(rank[j] == i)
                    {
                        rank.erase(rank.begin() + j);
                        j--;
                    }
                }
            }
        }
        
        for(int i=0;i<rank.size();i++)
        {
            if(team_cnt[rank[i]] > 3) {
                if(get<1>(team_score[rank[i]]) == 0) // 다섯번째 주자 기록 저장 
                {
                    get<1>(team_score[rank[i]]) = i+1;
                }
                continue;
            }
            
            team_cnt[rank[i]]++;
            
            get<0>(team_score[rank[i]]) += i + 1;
        }
        
        for(int i=1;i<=N;i++)
        {
            get<2>(team_score[i]) = i;
            
            if(get<0>(team_score[i]) == 0) get<0>(team_score[i]) = INT_MAX;
        }
        
        
        sort(team_score.begin(), team_score.end());
        
        cout << get<2>(team_score[1]) << "\n";
    }
}