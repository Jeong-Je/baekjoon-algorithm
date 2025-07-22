#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    
    int ptr = 0;
    for(int num=1;num<=29000;num++){
        string num_to_string = to_string(num);
        
        for(int i=0; i<num_to_string.length();i++) {
            if(str[ptr] == num_to_string[i]) {
                ptr++;
            }
            
            if(ptr == str.length()) {
                cout << num;
                return 0; 
            }
        }
    }
}