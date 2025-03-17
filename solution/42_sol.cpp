/**
 * 42. 이분검색
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
    //freopen("input.txt", "rt", stdin);
    int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	//binary search
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == m)	
		{
			cout << mid + 1 << endl;
			break;
		}
		else if (arr[mid] > m)
			high = mid - 1;
		else if (arr[mid] < m)
			low = mid + 1;
	}

	return 0;
}
