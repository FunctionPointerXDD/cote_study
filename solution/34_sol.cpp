/**
 * 34. 버블정렬
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
	    cin >> arr[i];

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			// 서로 인접한 원소끼리 비교해가면서 정렬하는 것이 버블정렬이다.
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}

    return 0;
}
