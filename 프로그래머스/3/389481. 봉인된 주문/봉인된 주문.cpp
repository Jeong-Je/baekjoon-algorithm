#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(string, string);
void front_deletion_num(long long &n);
long long find_num(string);
string find_string(long long);

vector<string> banss;

string solution(long long n, vector<string> bans) {
    banss = bans;
    sort(banss.begin(), banss.end(), cmp);
        
    front_deletion_num(n);
    
    return find_string(n);
}

string find_string(long long n)
{
    // 1. 길이 결정
    int L = 1;
    long long pow26 = 26;
    long long prefix = 0;

    while (true) {
        if (n <= prefix + pow26) break;
        prefix += pow26;
        pow26 *= 26;
        L++;
    }

    // 2. 같은 길이 내 인덱스 (0-based)
    long long idx = n - prefix - 1;

    // 3. 26진수 변환해서 문자열 생성
    string result(L, 'a');
    for (int i = L - 1; i >= 0; i--) {
        result[i] = 'a' + (idx % 26);
        idx /= 26;
    }

    return result;
}

void front_deletion_num(long long &n)
{
    for(int i=0;i<banss.size();i++)
    {
        long long num = find_num(banss[i]);
        if(num <= n) n++;
        if(num > n) return;
    }
    
    return;
}

long long find_num(string a)
{
    int len = a.size();
    
    long long prefix = 0;
    long long pow26 = 26;
    
    for(int k=1;k<len;k++)
    {
        prefix += pow26;
        pow26 *= 26;
    }
    
    long long val = 0;
    for(char c : a)
    {
        val = val * 26 + (c - 'a');
    }
    
    val++;
    
    return prefix + val;
}

bool cmp(string a, string b)
{
    if(a.length() != b.length())
        return a.length() < b.length();
    
    return a < b;
}