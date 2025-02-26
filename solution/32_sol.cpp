/**
 * 32. 선택정렬 (오름차순)
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
		int idx = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[idx] > arr[j])
				idx = j;
		}
		if (idx != i)
		{
			int tmp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = tmp;
		}
	}
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';

    return 0;
}
