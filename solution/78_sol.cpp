/**
 * 78. 원더랜드 (Kruskal MST 알고리듬 : Union&Find 활용)
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>

using namespace std;

struct MST {
	int a, b, c;

	bool operator<(const MST &p) const
	{
		return this->c < p.c;
	}
};

int arr[101];
int cost = 0;

int Find(int v)
{
	if (arr[v] == v) return v;
	else return arr[v] = Find(arr[v]);
}

void Union(int a, int b, int c)
{
	a = Find(a);
	b = Find(b);
	if (a != b)
	{
		arr[a] = b;
		cost += c;
	}
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);
	int v, e;	
	cin >> v >> e;

	//init arr
	for (int i = 1; i <= v; ++i)
		arr[i] = i;

	vector<MST> vec(e + 1);
	for (int i = 1; i <= e; ++i)
		cin >> vec[i].a >> vec[i].b >> vec[i].c;

	//간선의 비용을 기준으로 오르차순 정렬
	sort(vec.begin(), vec.end());
	
	//최소 비용이 드는 간선부터 연결해 나간다.
	//그리고 서로 독립된 집합일 때 마다 해당 간선의 비용의 추가한다.
	for (int i = 1; i <= e; ++i)
		Union(vec[i].a, vec[i].b, vec[i].c);

	cout << cost << endl;
	return 0;
}
