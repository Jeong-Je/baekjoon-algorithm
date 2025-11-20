#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		double sum = 0;
		for (int i = 0; i < 10; i++)
		{
			int num;
			cin >> num;
			sum += num;
		}
		double avg = sum / 10;
		cout << "#" << test_case << " " << round(avg) << "\n";
	}
}