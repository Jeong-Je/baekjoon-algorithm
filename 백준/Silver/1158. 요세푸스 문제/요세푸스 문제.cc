#include <iostream>
#include <list>

using namespace std;


int main()
{
	int N, K;
	cin >> N >> K;

	list<int> l;

	for (int i = 1; i <= N;i++)
	{
		l.push_back(i);
	}


	list<int>::iterator it = l.begin();

	int cnt = 1;
	cout << "<";
	while (l.empty() == false)
	{
		if (cnt == K)
		{
			if (l.size() == 1)
			{
				cout << *it;
			}
			else
			{
				cout << *it << ", ";
			}
			it = l.erase(it);
			cnt = 1;

			if (it == l.end()) it = l.begin();
		}

		else
		{
			cnt++;
			it++;

			if (it == l.end()) it = l.begin();
		}
	}
	cout << ">";
}