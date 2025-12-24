#include <iostream>
#include <list>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        list<char> l;
        list<char>::iterator it = l.begin();

        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            // 왼쪽 커서 
            if (s[i] == '<')
            {
                if (it != l.begin())
                {
                    it--;
                }
            }
            // 오른쪽 커서 
            else if (s[i] == '>')
            {
                if (it != l.end())
                {
                    it++;
                }
            }
            // 백 스페이스 
            else if (s[i] == '-')
            {
                if (it != l.begin())
                {
                    it--;
                    it = l.erase(it);
                }
            }
            // 문자 입력 
            else
            {
                l.insert(it, s[i]);
            }
        }

        for (char c : l)
        {
            cout << c;
        }
        cout << "\n";
    }
}

/*
2
<<BP<A>>Cd- 
ThIsIsS3Cr3t
*/