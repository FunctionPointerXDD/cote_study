/**
 * 52. Ugly Numbers
 * 2, 3, 5 로만 인수를 가지도록 포인터 3개를 만들어서 해결하면 좋다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int min_number(int n1, int n2, int n3)
{
	int min = 2147483647;
	if (min > n1)
		min = n1;
	if (min > n2)
		min = n2;
	if (min > n3)
		min = n3;
	return min;
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);	
	int n;
	scanf("%d", &n);

	vector<int> arr(1501);
	arr[1] = 1;
	int p1, p2, p3;
	p1 = p2 = p3 = 1; //init idx

	int n1, n2, n3;
	int min;
	int i;
	for (i = 2; i <= n; i++)
	{
		n1 = arr[p1] * 2;
		n2 = arr[p2] * 3;
		n3 = arr[p3] * 5;
		min = min_number(n1, n2, n3);
		if (min == n1)	
			p1++;
		if (min == n2)	
			p2++;
		if (min == n3)	
			p3++;
		arr[i] = min;
	}
	cout << arr[n] << endl;

	return 0;
}
