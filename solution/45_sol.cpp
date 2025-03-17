/**
 * 45. 공주 구하기
 * 특정 숫자 k 를 받으면, 원을 돌면서 k 만큼 카운팅 될 때 마다, 해당하는 인덱스의 왕자가 제외된다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    //freopen("input.txt", "rt", stdin);

	int n, k;
	cin >> n >> k;

	vector<int> arr(n);

	int cnt = 0;
	int i = 0;
	int prince = n;

	//dirty bit 방식을 이용한다.
	while (1)
	{
		if (i >= n) 
			i = 0;
 		if (arr[i] == 0)
			cnt++;
		if (cnt == k)
		{
			arr[i] = 1;
			cnt = 0;
			prince--;
			if (prince == 0)
				break;
		}
		i++;
	}
	cout << i + 1 << endl; 

	return 0;
}
