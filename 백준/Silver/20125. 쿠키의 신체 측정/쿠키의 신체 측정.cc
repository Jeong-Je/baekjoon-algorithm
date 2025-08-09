#include <iostream>

using namespace std;

char arr[1001][1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    bool head_find = false;
    bool heart_find = false;
    bool waist_find = false;
    int head_column, head_row;
    int heart_column, heart_row;
    int left_arm_size = -1, right_arm_size = -1;
    int left_leg_size = 0, right_leg_size = 0;
    int waist_size = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> arr[i][j];
            if(arr[i][j] == '*' && head_find == false) {
                head_find = true;
                head_column = j;
                head_row = i;
            }
            
            
            if(head_find && j == head_column && i != head_row && heart_find == false) {
                heart_find = true;
                heart_row = i;
                heart_column = j;
            }
            
            if(head_find && arr[i][j] == '*' && heart_find == false) left_arm_size++;
            if(heart_find && arr[i][j] == '*' && i == heart_row) right_arm_size++;
            if(heart_find && i != heart_row && j == heart_column && arr[i][j] == '*') 
            {
                waist_size++; waist_find = true;
            }
            
            if(waist_find && j == heart_column - 1 && arr[i][j] == '*') {
                left_leg_size++;
            }
            if(waist_find && j == heart_column + 1 && arr[i][j] == '*') right_leg_size++;
        }
    }
    
    
    cout << heart_row << " " << heart_column << "\n";
    cout << left_arm_size << " " << right_arm_size << " " << waist_size << " " << left_leg_size << " " << right_leg_size;
}