#include <iostream>
#include <list>


using namespace std;


int main()
{
    list<char> L;
    
    string s;
    cin >> s;
    
    for(int i=0;i<s.size();i++)
    {
        L.push_back(s[i]);
    }
    
    list<char>::iterator it = L.end();
    
    int M;
    cin >> M;
    
    for(int i=0;i<M;i++)
    {
        char cmd;
        cin >> cmd;
        
        if(cmd == 'L')
        {
            if(it != L.begin()) it--;
        }
        else if(cmd == 'D')
        {
            if(it != L.end()) it++;
        }
        else if(cmd == 'B')
        {
            if(it != L.begin())
            {
                it--;
                it = L.erase(it);
            }
            
            
           
        }
        else
        {
            char c;
            cin >> c;
            
            L.insert(it, c);
        }
    }
    
    
    for(auto c: L)
    {
        cout << c;
    }
}