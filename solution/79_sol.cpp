/**
 * 79. 원더랜드(Prim MST 알고리듬: priority_queue 활용)
 * 특정 정점에서 시작해서 인접한 간선을 통해 정점들을 연결해나간다. (-> 인접 리스트 그래프 사용)
 * 이 때, 간선의 비용이 최소가 되는 곳의 정점을 우선순위로 정해서 이어간다. (-> 우선순위 큐)
 */
 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <queue>

 using namespace std;

 // 갔던 정점 체크 용도
 int check[101];

 //using priority_queue
 struct Prim{
	int v;
	int cost;

	Prim(int a, int b)
	{
		v = a;
		cost = b;
	}

	//priority_queue에서는 (t1 > t2)가 참일 때 최소 힙이 된다.
	bool operator<(const Prim& p) const
	{
		return this->cost > p.cost;
	}
 };

 int main(void)
 {
	//freopen("input.txt", "rt", stdin);

	int n, e;
	cin >> n >> e;

	vector<vector<pair<int, int>>> vec(n + 1);
	// pair에는 정점과 비용이 같이 들어간다.

	int a, b, c;
	for (int i = 1; i <= e; ++i)
	{
		cin >> a >> b >> c;
		vec[a].push_back({b, c});
		vec[b].push_back({a, c});
		//무방향 그래프로 만든다.
	}

	int res = 0;
	priority_queue<Prim> Q;
	Q.push(Prim(1, 0)); // 1번 정점부터 시작 (간선은 존재하지 않으므로 비용은 0)

	while (!Q.empty())
	{
		int v = Q.top().v;
		int cost = Q.top().cost;
		Q.pop();

		// 연결된 모든 정점을 가보고 체크한 후 큐에 집어넣는 것이 아니라
		// 현재 정점만 체크하고 우선순위 큐에 집어넣은 후 나중에 우선순위에서 나오는 정점을 체크한다.
		// 이러한 점 때문에 BFS로 최단 거리 문제를 푸는 것과 차이가 있다.
		if (check[v] == 0)
		{
			check[v] = 1;
			res += cost; //정점으로 가는 간선의 비용을 더해준다.
			for (size_t i = 0; i < vec[v].size(); ++i)
				Q.push(Prim(vec[v][i].first, vec[v][i].second));
		}
	}
	cout << res << endl;
	return 0;
 }
