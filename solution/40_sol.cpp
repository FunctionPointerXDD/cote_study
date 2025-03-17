/**
 * 40. 교집합 (투포인트 알고리즘)
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

    cin >> n;
	vector<int> vec1(n);
	for (int i = 0; i < n; ++i)
		cin >> vec1[i];
	sort(vec1.begin(), vec1.end());

    cin >> m;
	vector<int> vec2(m);
	for (int i = 0; i < m; ++i)
		cin >> vec2[i];
	sort(vec2.begin(), vec2.end());
	//미리 정렬해야 투포인터 알고리즘을 적용 가능!

	int min = n < m ? n : m;
	vector<int> res(min); // push_back 으로 값을 삽입하는 것 보다 미리 할당된 공간에 값을 삽입하는 것이 훨씬 빠르다. (reserve 보다 더 빠름!)

	int i = 0, j = 0, k = 0;
	while (i < n && j < m)
	{
		if (vec1[i] == vec2[j])
		{
			res[k++] = vec1[i];
			i++;
			j++;
		}

		//최적화 하는 부분!
		//두 배열의 값이 비슷해 지도록 조정
		//이를 통해서 이중 for문을 사용안해도 됨!
		if (vec1[i] > vec2[j])
			j++;
		else if (vec1[i] < vec2[j])
			i++;
	}
	
	for (int i = 0; i < k; ++i)
		cout << res[i] << ' ';

	return 0;
}
