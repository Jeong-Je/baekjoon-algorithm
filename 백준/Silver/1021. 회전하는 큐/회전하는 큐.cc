#include <iostream>

using namespace std;

static int dq[1000];

int front();
void pop_front();

void left_move();
void right_move();

int size();

int head = 1;
int tail;

int main(){
    int N, M;
    cin >> N >> M;
    
    tail = N;
    
    for(int i=1;i<=N;i++)
        dq[i] = i;

    
    int cnt = 0;
    for(int i=0;i<M;i++){
        int a;
        cin >> a;
        
        int idx;
        for(int j=head;j<=tail;j++){
            if(dq[j] == a){
                idx = j - head;
            }
        }
        
        if(idx <= size() / 2){
            while(1){
                if(front() == a) {
                    pop_front();
                    //cout << "pop\n";
                    break;
                }
                cnt++;
                //cout << "left!\n";
                left_move();                
            }
        } else {
            while(1){
                if(front() == a) {
                    pop_front();
                    //cout << "pop\n";
                    break;
                }
                cnt++;
                //cout << "right!\n";
                right_move();               
            }
        }
        //cout << cnt << endl;
    }
    cout << cnt;
}


int front() {
    return dq[head];
}

void pop_front() {
    head++;
}

void left_move(){
    dq[++tail] = dq[head];
    head++;
    /*
    for(int i=head;i<=tail;i++){
        cout << dq[i] << " ";
    }
    cout << endl;
    */
}

int size(){
    return tail - head + 1;
}

void right_move(){
    int tmp = dq[tail];
    for(int i=tail-1; i >= head; i--){
        int j = i+1;
        dq[j] = dq[i];
    }
    dq[head] = tmp;
    /*
    for(int i=head;i<=tail;i++){
        cout << dq[i] << " ";
    }
    cout << endl;
    */
}