/**
 * 36. 삽입정렬 (Insert Sort)
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
