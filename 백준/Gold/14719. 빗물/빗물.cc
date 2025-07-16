#include <iostream>

using namespace std;

int block[500][500];

int main(){
    int H, W;
    cin >> H >> W;
    
    for(int i=0;i<W;i++){
        int height;
        cin >> height;
        
        int tmp = H - 1;
        for(int j=0;j<height;j++){
            
            block[tmp][i] = 1;
            tmp--;
        }
    }
    
    
    // for(int i=0;i<H;i++){
    //     for(int j=0;j<W;j++)
    //     {
    //         cout << block[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    int count = 0;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(block[i][j] == 0) {
                bool is_block_left = false;
                bool is_block_right = false;
                
                // 왼쪽 검사
                for(int l=j-1;l>-1;l--){
                    if(block[i][l] == 1) 
                    {
                        is_block_left = true;
                        break;
                    }
                }
            
                // 오른쪽 검사
                for(int r=j+1;r<W;r++){
                    if(block[i][r] == 1) 
                    {
                        is_block_right = true;
                        break;
                    }
                }
                
                if(is_block_left && is_block_right) count++;
            }
        }
    }
    
    cout << count;
}