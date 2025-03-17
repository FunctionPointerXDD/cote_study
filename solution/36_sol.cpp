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

	int i, j;
	for (i = 1; i < n; ++i)
	{
		int tmp = arr[i];
		for (j = i - 1; j >= 0; --j)
		{
			//계속해서 tmp값과 비교하여 조건에 맞으면, 인접한 왼쪽 배열값을 오른쪽으로 옮겨 나간다.
			if (arr[j] > tmp)
				arr[j + 1] = arr[j];
			else
				break;
		}
		//여기서 j + 1 은 위에서 조건을 돌았다면, -1 이 어느 정도 적용된 상태이다. 
		//만약 한 번도 조건을 돌지 않고, 바로 break로 빠져나온다면, j + 1 은 i 와 같은 인덱스 값을 가지므로, 그대로 자기자신에게 대입하는 결과가 된다.
		arr[j + 1] = tmp;
	}

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';

    return 0;
}
