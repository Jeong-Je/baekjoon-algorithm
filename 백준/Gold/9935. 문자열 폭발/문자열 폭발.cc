#include <iostream>
#include <string>

using namespace std;

int main(){
    string s, bomb, result;
    cin >> s >> bomb;
    
    int b_len = bomb.length();
    
    for(char c: s) {
        result.push_back(c);
        
        if(result.length() >= b_len && 
           result.compare(result.length() - b_len, b_len, bomb) == 0 ) {
            result.erase(result.length() - b_len, b_len);   
        }
    }
    
    if (result.empty()) cout << "FRULA";
    else cout << result;
}