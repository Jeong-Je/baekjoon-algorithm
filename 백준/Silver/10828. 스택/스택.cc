// https://www.acmicpc.net/problem/10828
#include <iostream>

using namespace std;

int arr[10000];
int top = -1;

void push(int num){
    arr[++top] = num;
}

int pop(){
    if(top != -1){
        return arr[top--];
    } else {
        return -1;
    }
}

int size(){
    return top+1;
}

bool empty(){
    if(top == -1) return true;
    else return false;
}

int top_cmd(){
    if(top!=-1) {
        return arr[top];
    } else {
        return -1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++){
        string cmd;
        int num;
        cin >> cmd;
        
        if(cmd == "push") {
            cin >> num;
            push(num);
        } else if (cmd == "pop"){
            cout << pop() << "\n";
        } else if (cmd == "size"){
            cout << size() << "\n";
        } else if (cmd == "empty") {
            cout << empty() << "\n";
        } else { // top
            cout << top_cmd() << "\n";
        }
    }
}