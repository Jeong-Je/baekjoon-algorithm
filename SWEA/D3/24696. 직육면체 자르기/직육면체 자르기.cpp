#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;


	for (int test_case = 1; test_case <= T; test_case++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
		{
			cout << "1\n";
		}
		else

		{
			cout << "2\n";
		}
	}

	return 0;
}