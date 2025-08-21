#include <iostream>
#include <string>

using namespace std;

string str, str2;
void toggle(int i);

int main()
{
    int N, cnt = 0;
    cin >> N;
    
    cin >> str >> str2;
    string tmp = str;
    
    // 제일 앞 전구를 안 누르고 진행하는 경우 
    for(int i=1;i<N;i++)
    {
        // 자신의 앞 전구가 목표 전구와 다른 경우(자신이 바꿀 수 있는 마지막 기회)
        if(str[i-1] != str2[i-1])
        {
            cnt++;    
            toggle(i); 
        }
    }

    if(str == str2)
    {
        cout << cnt;
        return 0;
    }
    
    str = tmp;
    
    // 제일 앞 전구를 누르고 진행하는 경우 
    toggle(0);
    cnt = 1;
    for(int i=1;i<N;i++)
    {
        // 자신의 앞 전구가 목표 전구와 다른 경우(자신이 바꿀 수 있는 마지막 기회)
        if(str[i-1] != str2[i-1])
        {
            cnt++;    
            toggle(i); 
        }
    }
    
    if(str == str2) cout << cnt;
    else cout << -1;
}

void toggle(int i)
{
    if(i-1 > -1 && str[i-1] == '0') str[i-1] = '1';
    else if(i -1 > -1 && str[i-1] == '1') str[i-1] = '0';
    
    if(str[i] == '0') str[i] = '1';
    else if(str[i] == '1') str[i] = '0';
    
    if(str[i+1] == '0') str[i+1] = '1';
    else if(str[i+1] == '1') str[i+1] = '0';
}