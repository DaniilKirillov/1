#include <iostream>
#include <string>
#include <algorithm>
#define AND &&
using namespace std;


// Расстояние Левенштейна


int m(char s1, char s2)
{
	if (s1 == s2) return 0;
	else return 1;
}


int D(int i, int j, string s1, string s2)
{
	if (i == 0 AND j == 0) return 0;
	else if (i == 0 AND j != 0) return j;
	else if (i != 0 AND j == 0) return i;
	else if (i > 0 AND j > 0)
	{
		return min(min(D(i, j - 1, s1, s2) + 1, D(i - 1, j, s1, s2) + 1), (D(i - 1, j - 1, s1, s2) + m(s1[i - 1], s2[j - 1])));
	}
}


int LevensteinDistance(string& s1, string& s2)
{
	int N = s1.size();
	int M = s2.size();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			D(i, j, s1, s2);
		}
	}
	return D(N, M, s1, s2);
}

int main()
{
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	cout << LevensteinDistance(s1, s2);
	return 0;
}