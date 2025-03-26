/**
 * 59. 부분집합(DFS)
 * 노드의 깊이를 부분집합의 원소로 생각한다. (깊이는 1부터 시작하므로 1이 첫번째 원소)
 * 왼쪽으로 갈때는 해당 깊이의 원소가 존재한다고 체크(1), 오른쪽은 원소가 비었다고 체크한다(0).
 * 노드의 깊이가 총 원소의 개수 + 1 이 되는 경우, 체크된 원소를 출력하고 리턴한다.
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;


void dfs(size_t depth, std::vector<int> arr)
{
	if (depth == arr.size())
	{
		size_t i = 1;
		while (i < arr.size())
		{
			if (arr[i] != 0)
				cout << i << ' ';
			i++;
		}
		cout << '\n';
		return;
	}

	arr[depth] = 1;	
	dfs(depth + 1, arr);
	arr[depth] = 0;
	dfs(depth + 1, arr);
}

int main(void)
{
    //freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;

	//이해하기 쉽게 배열의 1번 인덱스를 첫번째 원소로 잡는다. (0번 인덱스는 무시)
	vector<int> arr(n + 1);

	dfs(1, arr);

    return 0;
}