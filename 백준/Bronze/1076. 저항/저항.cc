#include <iostream>

using namespace std;

int main(){
    string color[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
    long long result = 1;
    
    string res;
    int mem[3];
    
    for(int i=0;i<3;i++){
        cin >> res;
        for(int j=0;j<10;j++){
            if(res == color[j]) {
                mem[i] = j;
            }
        }
    }
    
    result = mem[0] * 10 + mem[1];
    
    for(int i=0;i<mem[2];i++){
        result *= 10;
    }
    
    cout << result;
    
}