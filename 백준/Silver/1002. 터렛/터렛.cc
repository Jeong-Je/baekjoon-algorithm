#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    double x1, y1, x2, y2, r1, r2;
    
    cin >> t;
    
    for(int i=0;i<t;i++){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 -y1 ,2));
        
        
        if(x1 == x2 && y1 == y2 && r1 == r2){ // 두 원이 정확히 겹치는 경우
            cout << "-1\n";
        } else if(abs(r2-r1) == distance || r1+r2 == distance) { // 두 원이 접하는 경우
            cout << "1\n";
        } else if(abs(r2-r1) < distance && distance < r1+r2) {
            cout <<"2\n";
        } else {
            cout << "0\n";
        }
    
    }
    
    
}