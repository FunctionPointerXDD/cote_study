/**
 * 77. 친구인가? (Union&Find Algorithm)
 * 유명한 자료구조 & 알고리듬이니 외워두자...
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * union-find 자료구조는 인덱스가 노드의 고유번호를 의미하고, (idx == node)
 * 각 인덱스 배열의 값은 해당 노드의 부모 노드를 의미한다. (unf[idx] == parent_node)
 * 초기에는 인덱스와 값이 일치하기 때문에 자기 자신만을 갖는 집합이 형성된다. 
 *  ex) {1}, {2}, {3} ...
 * 
 * Union 함수로 여러개의 노드들을 엮으면서 트리구조를 형성한다.
 * 여기서 생성되는 트리구조는 서로 분리되어 있을 수도 있다.
 * 만약 두 개의 노드의 서로 다른 루트(부모)노드를 가진다면 두 노드는 연결되어 있지 않다.
 * 반대로 서로 같은 루트(부모)노드를 가진다면 두 노드는 연결되어 있다.
 */


// 각 인덱스와 해당 배열의 값이 일치하도록 초기화 한다.
int unf[1001];

// v노드의 루트 노드를 반환한다. 
int Find(int v)
{
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]); // 경로 압축
	// 경로 압축을 하면, 부모 노드에서 한 단계 아래로 자식들이 일렬로 붙는다.
	// 즉, 반드시 부모로 부터 노드의 깊이가 최대 2로 고정된다.
}

/** << Union 함수 >> 
 * a노드와 b노드의 각 부모 노드를 찾은 다음,
 * 일치하지 않으면, a노드를 b노드의 자식으로 만든다.
 * (여기서 최적화를 더하면, 둘 중 트리의 깊이가 낮은 쪽에 자식을 생성한다.
 * 그러면 트리의 균형이 적절히 유지되는데 여기서는 구현하지 않았다.)
 */
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b)
		unf[a] = b; // a번 노드는 b번 노드의 자식이 된다. a --> b
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		unf[i] = i;

	int v1, v2;
	for (int i = 1; i <= m; ++i)
	{
		cin >> v1 >> v2;
		Union(v1, v2);
	}
	
	int f1, f2;
	cin >> f1 >> f2;
	if (Find(f1) == Find(f2))
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;

	return 0;
}


// 처음 내가 풀이했던 방식..
// 그냥 양방향 그래프를 구현한뒤 dfs로 친구가 연결되어 있는지 찾았다.
// int n, m;
// int f1, f2;

// int check[1001];

// void dfs(int v, std::vector<vector<int>> &vec)
// {
// 	if (v == n + 1) return;
// 	if (v == f2)
// 	{
// 		cout << "YES" << endl;
// 		exit(0);
// 	}
// 	for (size_t i = 0; i < vec[v].size(); ++i)
// 	{
// 		if (check[vec[v][i]] == 0)
// 		{
// 			check[vec[v][i]] = 1;
// 			dfs(vec[v][i], vec);
// 			check[vec[v][i]] = 0;
// 		}
// 	}
// }

// int main(void)
// {
// 	//freopen("input.txt", "rt", stdin);
// 	cin >> n >> m;

// 	vector<vector<int>> vec(n + 1);

// 	int v1, v2;
// 	for (int i = 1; i <= m; ++i)
// 	{
// 		cin >> v1 >> v2;
// 		vec[v1].push_back(v2);
// 		vec[v2].push_back(v1);
// 	}

// 	cin >> f1 >> f2;

// 	dfs(f1, vec);
// 	cout << "NO" << endl;
// 	return 0;
// }
