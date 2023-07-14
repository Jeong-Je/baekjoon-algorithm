// 1018
#include <iostream>
using namespace std;

int compare(char a[][8], char** b, int n,int m) {
	int cnt = 0;
	for(int i=0;i<8;i++)
		for (int j = 0; j < 8; j++)
			if (a[i][j] != b[n + i][m + j])cnt++;
	
	return cnt;
}

int main() {
	int n, m,result=64;
	cin >> n>> m;
	char white_first[8][8] = {
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'}
	};

	char black_first[8][8] = {
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
	};

	char** board = new char*[n];
	for (int i = 0; i < n; i++)
		board[i] = new char[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}


	int wb, bb;
	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
			wb = compare(white_first, board, i, j);
			bb = compare(black_first, board, i, j);
			if(wb < result || bb< result)
				wb < bb ? result = wb : result = bb;
		}
	}

	cout << result;



	for (int i = 0; i < n; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}