/**
 * 71. 송아지 찾기(BFS: 상태트리탐색)
 * 모든 위치를 정점이라고 생각하자.
 * 각 정점(위치)마다 3개의 이동할 정점이 존재한다.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int check[10001]; // 인덱스가 위치정보를 의미하고, 값은 해당 위치까지의 최소 이동 횟수이다.
int d[3] = {1, -1, 5};

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	int s, e;
	cin >> s >> e;

	queue<int> Q;
	int pos = 0;

	//1번 정점을 초기화
	Q.push(s);
	check[s] = 0; // 횟수 이므로 0부터 시작

	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		for (int i = 0; i < 3; ++i)
		{
			pos = x + d[i];
			if (pos <= 0 || pos > 10000) continue;
			if (pos == e)
			{
				cout << check[x] + 1 << endl;
				exit(0);
			}
			if (check[pos] == 0)
			{
				check[pos] = check[x] + 1;
				Q.push(pos);
			}
		}
	}

	return 0;
}

/** chatgpt가 제시하는 코드
 * visited[10001] 라는 벡터배열을 생성해서 체크용도로만 사용.
 * 그리고 큐에다가 위치와 이동횟수를 같이 저장. 
 */
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int bfs(int start, int target) {
//     vector<bool> visited(10001, false);
//     queue<pair<int, int>> q; // {현재 위치, 이동 횟수}
//     q.push({start, 0});
//     visited[start] = true;

//     while (!q.empty()) {
//         int pos = q.front().first;
//         int cnt = q.front().second;
//         q.pop();

//         if (pos == target) return cnt;

//         for (int next : {pos - 1, pos + 1, pos + 5}) {
//             if (next >= 0 && next <= 10000 && !visited[next]) {
//                 visited[next] = true;
//                 q.push({next, cnt + 1});
//             }
//         }
//     }

//     return -1; // 도달 불가능한 경우 (문제에 따라 처리)
// }

// int main() {
//     int start = 5, target = 14;
//     cout << "최소 이동 횟수: " << bfs(start, target) << endl;
//     return 0;
// }

