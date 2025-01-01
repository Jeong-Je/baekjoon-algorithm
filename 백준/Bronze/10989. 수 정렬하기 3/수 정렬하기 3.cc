/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    int count[10001] = { 0 };
    int number = 0;
    
    for(int i=1;i<=N;i++){
        cin >> number;
        count[number]++;
    }
    
    for(int i=0;i<=10000;i++){
        if(count[i] != 0){
            for(int j=0;j<count[i];j++){
                cout << i << "\n";
            }
        }
    }
}