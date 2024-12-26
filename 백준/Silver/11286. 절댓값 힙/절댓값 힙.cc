/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int a, int b){
        int a_abs = abs(a);
        int b_abs = abs(b);
        if(a_abs == b_abs){
            return a > b;
        } else{
            return a_abs > b_abs;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    priority_queue<int, vector<int>, cmp> MyQueue;
    
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        int input;
        cin >> input;
        
        if(input == 0){
            if(MyQueue.empty()){
                cout <<"0\n";
            } else {
                cout << MyQueue.top() << "\n";
                MyQueue.pop();
            }
        } else {
            MyQueue.push(input);
        }
    }

    return 0;
}