#include <iostream>
#include <string>

using namespace std;

bool possible;

void first_rule(string input);
void second_rule(string input);
void third_rule(string input);

bool is_moEum(char c);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    
    cin >> input;
    while(input != "end") {
        possible = true;
        
        first_rule(input);
        second_rule(input);
        third_rule(input);
        
        if(possible == true) {
            cout << "<" << input << "> is acceptable.\n";
        } else {
            cout << "<" << input << "> is not acceptable.\n";
        }
        
        cin >> input;
    }
}

void first_rule(string input) {
    int moEum_count = 0;
    
    for(int i=0;i<input.length();i++){
        if(input[i] == 'a') moEum_count++;
        else if(input[i] == 'e') moEum_count++;
        else if(input[i] == 'i') moEum_count++;
        else if(input[i] == 'o') moEum_count++;
        else if(input[i] == 'u') moEum_count++;
    
    }
    
    if(moEum_count == 0) possible = false;
    return;
}

void second_rule(string input) {
    int count = 0;
    for(int i=1;i<input.length();i++){
        if(is_moEum(input[i-1]) == is_moEum(input[i])) count++;
        else count = 0;
        
        if(count == 2) {
            possible = false;
            return;
        }
    }
}

void third_rule(string input) {
    for(int i=1;i<input.length();i++){
        if(input[i-1] == input[i]) {
            if(input[i] != 'e' && input[i] != 'o') {
                possible = false;
                return;
            }
        }
    }
}



bool is_moEum(char c) {
    if(c == 'a') return true;
    else if (c == 'e') return true;
    else if (c == 'i') return true;
    else if (c == 'o') return true;
    else if (c == 'u') return true;
    else return false;
}