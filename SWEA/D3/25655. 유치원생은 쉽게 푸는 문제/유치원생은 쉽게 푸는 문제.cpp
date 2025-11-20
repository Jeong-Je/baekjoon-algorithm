#include <iostream>


using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int X;
		cin >> X;

		// X가 1이면 무조건 0 출력
		if (X == 1)
		{
			cout << 0 << "\n";
			continue;
		}

		// X가 짝수라면
		if (X % 2 == 0)
		{
			for (int i = 1; i <= X; i += 2)
			{
				cout << 8;
			}
			cout << "\n";
		}

		// X가 홀수라면
		else
		{
			cout << 4;

			for (int i = 1; i <= X - 1; i += 2)
			{
				cout << 8;
			}
			cout << "\n";
		}
	}


	return 0;
}