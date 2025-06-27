/**
 * DP_2. 네트워크 선 자르기 (Top-Down)
 * 
 * 총 길이에서 1만큼 자르거나 2만큼 자를 때 남는 길이를 재귀적으로 추적한다.
 * 그리고 더 이상 자를 수 없는 경우, 되돌리면서 경우의 수를 카운트한다.
 * ==> DFS (재귀와 메모이제이션을 활용한다.)
 */

 #include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>

 using namespace std;

 int dy[60];

 int dfs(int v)
 {
	if (dy[v] > 0) return dy[v]; // 메모이제이션을 활용 (트리가 뻗을 때 미리 구해진 정점은 바로 리턴된다. Edge-Cut) --> v가 클수록 속도가 매우 향상된다.
	if (v == 1 || v == 2) return v;

	return dy[v] = dfs(v - 2) + dfs(v - 1);
 }

 int main(void)
 {
	int n;	
	cin >> n;

	int res = dfs(n);

	cout << res << endl;
	return 0;
 }
