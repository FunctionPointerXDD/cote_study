/**
 * 35. Special Sort (google interview)
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
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[i] > 0 && arr[j] < 0)
			{
				// 순서를 유지하면서 정렬하려면, 인접한 배열부터 차례대로 교환하면 된다.
				int idx = j;
				while (i != idx)
				{
					int tmp = arr[idx - 1];
					arr[idx - 1] = arr[idx];
					arr[idx] = tmp;
					idx--;
				}
				break;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}

    return 0;
}
