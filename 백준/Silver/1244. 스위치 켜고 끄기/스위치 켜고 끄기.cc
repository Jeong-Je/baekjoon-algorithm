#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void toggle(int i);

int main()
{
    int N, student_cnt;
    cin >> N;
    
    v.resize(N+1);
    
    for(int i=1;i<=N;i++)
    {
        cin >> v[i];
    }
    
    
    cin >> student_cnt;
    
    for(int i=0;i<student_cnt;i++)
    {
        int sex, switch_num;
        cin >> sex >> switch_num;
        
        if(sex == 1) // 남자 
        {
            // 받은 숫자의 배수만큼 스위치 토글 
            for(int j=switch_num;j<=N;j+=switch_num)
            {
                toggle(j);
            }
            
            
        } else // 여자 
        {
            int left = switch_num - 1;
            int right = switch_num + 1;
            toggle(switch_num);
            while(left > 0 && right <= N)
            {
                if(v[left] == v[right])
                {
                    toggle(left);
                    toggle(right);
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
        }
    }
    
    
    for(int i=1;i<=N;i++)
    {
        cout << v[i] << " ";
        if(i % 20 == 0) cout << "\n";
    }
}

void toggle(int i)
{
    if(v[i] == 1) v[i] = 0;
    else v[i] = 1;
}