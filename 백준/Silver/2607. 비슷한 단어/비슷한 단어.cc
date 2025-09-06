#include <iostream>

using namespace std;

int main()
{
    int N, ans = 0;
    cin >> N;
    
    string base;
    cin >> base;
    
    int base_alpha[26] = {0};
    
    for(int i=0;i<base.length();i++)
    {
        base_alpha[base[i] - 'A']++;
    }
    
    for(int i=1;i<N;i++)
    {
        string word;
        cin >> word;
        
        int word_alpha[26] = {0};
        
        for(int i=0;i<word.length();i++)
        {
            word_alpha[word[i] - 'A']++;
        }
        
        int diff = 0;
        for(int i=0;i<26;i++)
        {
            diff += abs(base_alpha[i] - word_alpha[i]);
        }
        
        
        if(diff == 0) ans++; // 정확히 같은 단어 구성 
        else if(diff == 1 && abs((int)base.length() - (int)word.length()) == 1) ans++; // 삽입|삭제 1회
        else if (diff == 2 && base.size() == word.size()) ans++; // 교체
    }
    
    
    cout << ans;
}