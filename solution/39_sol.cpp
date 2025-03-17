/**
 * 39. 두 배열 합치기
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(void)
{
    //freopen("input.txt", "rt", stdin);
    int n, m;

    cin >> n;
	vector<int> vec1(n);
	for (int i = 0; i < n; ++i)
		cin >> vec1[i];

    cin >> m;
	vector<int> vec2(m);
	for (int i = 0; i < m; ++i)
		cin >> vec2[i];

	vector<int> res(n + m);

	int i = 0, j = 0, k = 0;
	int left, right;
	while (1)
	{
		if (i == n || j == m)
			break;
			
		left = vec1[i];
		right = vec2[j];
		if (left < right)
			res[k++] = vec1[i++];
		else if (left >= right)
			res[k++] = vec2[j++];
	}

	if (i == n)
	{
		while (k < n + m)
		 res[k++] = vec2[j++];
	}
	else
	{
		while (k < n + m)
			res[k++] = vec1[i++];
	}


	for (int i = 0; i < n + m; ++i)
		cout << res[i] << ' ';

	return 0;
}
