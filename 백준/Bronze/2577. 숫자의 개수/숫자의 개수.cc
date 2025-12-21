#include <iostream>

using namespace std;

int freq[10];

int main()
{
    int a, b, c, mul;
    cin >> a >> b >> c;
    
    mul = a * b * c;
    
    string mul_s = to_string(mul);
    
    
    for(int i=0;i<mul_s.size();i++)
    {
        freq[mul_s[i] - '0']++;
    }
    
    
    for(int i=0;i<10;i++){
        cout << freq[i] << "\n";
    }
}