/**
 * 47. 봉우리
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int map[52][52];

int dx[4] = {0, 0, 1, -1}; // east, west, south, north  -> south 는 아래로 가는 것이 +1 이 맞음.
int dy[4] = {1, -1, 0, 0};

int main(void)
{
	freopen("input.txt", "rt", stdin);	
	int n, i, j, k;
	int cnt = 0;
	int flag = 0;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			flag = 0;
			for (k = 0; k < 4; k++)
			{
				if (map[i][j] <= map[i + dx[k]][j + dy[k]])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0) cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}

// 나의 풀이법 --> if 문을 4번 도는 것은 위와 같으므로 효율면에서는 차이 없음.
// int main(void)
// {
//     //freopen("input.txt", "rt", stdin);

// 	int num;
// 	cin >> num;
// 	int **vec = new int*[num];
// 	for (int i = 0; i < num; ++i)
// 		vec[i] = new int[num];
	
// 	for (int i = 0; i < num; ++i)
// 	{
// 		for (int j = 0; j < num; ++j)
// 			cin >> vec[i][j];
// 	}

// 	int high = 0;
// 	int e, w, n ,s;
// 	for (int i = 0; i < num; ++i)
// 	{
// 		for (int j = 0; j < num; ++j)
// 		{
// 			int pivot = vec[i][j];
// 			if (j + 1 < num)
// 				e = vec[i][j + 1];
// 			else e = 0;

// 			if (j > 0)
// 				w = vec[i][j - 1];
// 			else w = 0;

// 			if (i > 0)
// 				n = vec[i - 1][j];
// 			else n = 0;

// 			if (i + 1 < num)
// 				s = vec[i + 1][j];
// 			else s = 0;

// 			if (pivot > e && pivot > w && pivot > n && pivot > s)
// 				high++;
// 		}
// 	}

// 	cout << high << endl;

// 	for (int i = 0; i < num; ++i)
// 		delete []vec[i];
// 	delete []vec;
// 	return 0;
// }
