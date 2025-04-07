/**
 * 81. 밸만-포드 알고리듬 (최단 거리 구하는 알고리듬)
 * 모든 정점을 무한대로 초기화하고, 시작 정점만 0으로 초기화 한다.
 * 각각의 간선 비용을 해당 간선의 도착 정점(배열 인덱스)에 저장한다.
 * 배열을 계속 처음 부터 순회하면서 갱신될 수 있는지 파악하고, 업데이트한다.
 * 정점의 수(n) - 1 만큼 순회하면 출발 정점으로 부터 모든 정점으로 가는 최단거리를 얻게 된다.
 * 그러나 음의 사이클이 존재할 수가 있는데, 이는 n-1 이상 순회를 해서 갱신 여부로 파악할 수 있다.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

// 간선 비용을 저장할 배열 (시작 정점을 제외하고 무한대로 초기화 한다.)
int dist[101];

 struct Edge {
	int u; //출발 
	int v; //도착
	int w; // u -> v 로 갈 때 드는 간선 비용(거리)

	Edge() : u(0), v(0), w(0) {}
	Edge(int a, int b, int c) : u(a), v(b), w(c) {}
 };

 int main(void)
 {
	freopen("input.txt", "rt", stdin);
	int n, m;
	cin >> n >> m;

	vector<Edge> G;

	int a, b, c;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		G.push_back(Edge(a, b, c));
		//G[i] = Edge(a, b, c);
	}

	for (int i = 1; i <= n; ++i)
		dist[i] = INT_MAX;

	int start, end;
	cin >> start >> end;
	dist[start] = 0; //출발 정점 0으로 초기화

	//n(정점의 개수) - 1 번 만큼 갱신을 시도한다. (relaxation)
	for (int i = 0; i < n - 1; ++i)
	{
		for (size_t j = 0; j < G.size(); ++j)
		{
			int u = G[j].u; // 출발
			int v = G[j].v; // 도착
			int w = G[j].w; // 간선 비용

			//갱신 조건
			if (dist[u] != INT_MAX && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}
	
	// 음의 사이클 검출:
	// n-1 번 이상 갱신을 시도했는데 개선이 가능한 부분이 나온다면
	// 그것은 그래프에서 음의 사이클이 존재한다는 의미이다.
	for (size_t j = 0; j < G.size(); ++j)
	{
			int u = G[j].u;
			int v = G[j].v;
			int w = G[j].w;
			if (dist[u] != INT_MAX && dist[u] + w < dist[v])
			{
				cout << -1 << endl;
				return 0;
			}
	}

	cout << dist[end] << endl;

	return 0;
 }