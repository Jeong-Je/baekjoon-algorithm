/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

char board[2000][2000];
int n, m, k;

int check(char color);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    
    cout << min(check('B'), check('W'));

    return 0;
}

int check(char color) {
    int value, pSum[n + 1][m + 1];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!((i + j) % 2)) value = board[i][j] != color;
			else value = board[i][j] == color;
			
			pSum[i + 1][j + 1] = pSum[i][j + 1] + pSum[i + 1][j] - pSum[i][j] + value;
		}
	}
	
	
	
	int tmp, result = 100000000;
	
	for (int i = 0; i <= n - k; i++) {
		for (int j = 0; j <= m - k; j++) {
			tmp = pSum[i + k][j + k] - pSum[i][j + k] - pSum[i + k][j] + pSum[i][j];
			result = (tmp < result) ? tmp : result;
		}
	}
	
	return result;
}