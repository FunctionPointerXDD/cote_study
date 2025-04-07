/**
 * 80. 다익스트라 알고리듬 (하나의 시작점으로 부터 모든 정점의 최단 거리 구하는 알고리듬)
 * 
 * 가중치 방향그래프의 특정 정점에서 시작해서 모든 정점으로 가는데 최단경로를 효율적으로 계산하는 알고리듬이다.
 * 단, 가중치가 양수일 때만 적용된다.
 * 만약, 가중치가 동일하거나 없는 경우, BFS로 큐를 이용해서 풀이하는 것이 효율적이다.
 * 
 * 유명한 알고리즘이니 외워두자.
 * 이전에 나는 이것을 dfs를 사용해서 모든 경로에 대해서 거리비용을 계산하고
 * 그 중에서 최솟값을 찾았으나, 이는 조금 비효율적이다.
 * 
 * 알고리듬 설명
 * 1. 초기화: 시작 정점의 거리는 0으로 설정, 나머지 정점의 거리는 무한대로 초기화한다. (아래 코드에서는 dist배열을 사용)
 * 2. 아직 처리되지 않은 정점 중에서 간선 비용이 최소가 되는 정점을 뽑는다.(pop())
 * 3. 경로 갱신 (Relaxation): 선택한 정점을 기준으로 인접한 정점들의 거리를 확인하고, 
 *   현재 경로를 통해 더 짧은 경로로 갈 수 있다면 거리를 갱신한다.
 *   그리고 해당 경로를 우선순위 큐에 삽입한다.
 * 
 * 위 과정을 반복하면 모든 정점으로 가는 최단 경로를 O(E log V) 시간으로 찾을 수 있다. (또는 O((V+E) log V))
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>

using namespace std;


struct Edge {
	int v;
	int cost;

	Edge(int a, int b)
	{
		v = a;
		cost = b;
	}

	//최소 힙으로 설정
	bool operator<(const Edge& p) const
	{
		return cost > p.cost;
	}

};

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, m;
	cin >> n >> m;

	//인접리스트 형태로 그래프 자료를 받는다.
	vector<vector<pair<int, int>>> G(n + 1);

	int a, b, c;
	for (int i = 1; i <= m; ++i)
	{
		//a 와 b는 서로 연결된 정점, c는 간선비용
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		//문제에서 1번 정점으로 부터 모든 정점으로 가는 최단 경로를 찾는 다고 했으므로
		//방향 그래프로 만든다. (1번 정점 -> n번 정점)
		//만약 이러한 조건이 주어지지 않았다면 무방향도 가능하다.
	}

	/**
	 * 다익스트라 알고리듬에서 사용할 배열이다. 무한대로 초기화 해준다. 
	 * 배열의 인덱스를 정점 번호로 생각한다.
	 */
	vector<int> dist(n + 1, INT_MAX);

	// 우선순위 큐: 최소 힙으로 설정하고 1번 정점을 삽입한다. (비용은 0으로)
	priority_queue<Edge> Q;
	Q.push(Edge(1, 0));

	dist[1] = 0; // dist의 첫번째 정점도 0으로 초기화 한다. (1번 정점부터 시작하므로 비용은 당연히 0이다.)

	while(!Q.empty())
	{
		int cur = Q.top().v;	
		int cost = Q.top().cost;
		Q.pop();

		if(cost > dist[cur]) continue;
		//cost가 dist[cur]보다 큰 상황은 
		//이미 다른 최소 경로로 cur이라는 정점에 갔었다는 의미이다.
		//따라서 해당 경로에서 다른 인접 경로를 찾아봐도 갱신 될 것이 없다. --> 이해가 안되면 직접 그려보거나, 인강을 다시 한 버 듣자.

		for (size_t i = 0; i < G[cur].size(); i++)
		{
			int next = G[cur][i].first;
			int next_cost = cost + G[cur][i].second;

			//경로 갱신(relaxtion)
			if (dist[next] > next_cost)
			{
				dist[next] = next_cost;
				Q.push(Edge(next, next_cost));
			}
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		if (dist[i] != INT_MAX) 
			cout << i << " : " << dist[i] << '\n';
		else cout << i << " : impossible" << '\n';
	}
	return 0;
}
