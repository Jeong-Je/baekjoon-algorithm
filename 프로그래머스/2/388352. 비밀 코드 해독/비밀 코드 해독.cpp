#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void backtracking(int cnt);
bool used[31];

int answer = 0;
int max_num;

vector<int> num;
vector<vector<int>> qq;
vector<int> aa;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    max_num = n;
    qq = q;
    aa = ans;
    
    backtracking(0);
    
    return answer / 120;
}

void backtracking(int cnt)
{
    if(cnt == 5)
    {
        bool found = true;
        for(int i=0;i<qq.size();i++)
        {
            int cnt2 = 0;
            for(int j=0;j<5;j++)
            {
                int target = num[j];
                
                auto it = find(qq[i].begin(), qq[i].end(), target);
                
                if(it != qq[i].end()) cnt2++; // 숫자가 존재 
                
                
            }
            if(cnt2 != aa[i]) found = false;
        }
        if(found) answer++;
        return;
    }
    
    for(int i=1;i<=max_num;i++)
    {
        if(used[i] == false)
        {
            num.push_back(i);
            used[i] = true;
            
            backtracking(cnt + 1);
            
            num.pop_back();
            used[i] = false;
        }
    }
}