#include <iostream>
#include <cstring>
using namespace std;

bool A[101];
bool B[101];

int main()
{
	int T;
	cin >> T;


	for (int test_case = 1; test_case <= T; test_case++)
	{
		memset(A, false, sizeof(A));
		memset(B, false, sizeof(B));

		int A_size, B_size;
		cin >> A_size >> B_size;

		for (int i = 0; i < A_size; i++)
		{
			int num;
			cin >> num;

			A[num] = true;
		}

		for (int i = 0; i < B_size; i++)
		{
			int num;
			cin >> num;

			B[num] = true;
		}

		// A와 B의 크기가 같은 경우 '=' 인지 '?' 인지 확인
		if (A_size == B_size)
		{
			bool is_same = true;
			for (int i = 1; i <= 100; i++)
			{
				if ((A[i] == true && B[i] == false) || (A[i] == false && B[i] == true))
				{
					cout << "?\n";
					is_same = false;
					break;
				}
			}


			if (is_same)
			{
				cout << "=\n";
			}
		}

		// A의 크기가 B의 크기보다 큰 경우 '>' 인지 '?' 인지 확인 
		else if (A_size > B_size)
		{
			bool is_partial = true;
			for (int i = 1; i <= 100; i++)
			{
				// B가 가진 원소를 A가 가지지 못하는 경우 B는 A의 부분 집합이 될 수 없음 
				if (B[i] == true && A[i] == false)
				{
					cout << "?\n";
					is_partial = false;
					break;
				}
			}

			if (is_partial)
			{
				cout << ">\n";
			}

		}

		// B의 크기가 A의 크기보다 큰 경우 '<' 인지 '?' 인지 확인

		else if (A_size < B_size)
		{
			bool is_partial = true;
			for (int i = 1; i <= 100; i++)
			{
				if (A[i] == true && B[i] == false)
				{
					cout << "?\n";
					is_partial = false;
					break;
				}
			}

			if (is_partial)
			{
				cout << "<\n";
			}

		}
	}
}