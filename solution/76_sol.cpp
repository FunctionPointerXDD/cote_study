/**
 * 76. 이항계수 (메모이제이션)
 * n개의 원소 중 r개의 원소를 뽑아서 만들 수 있는 부분집합을 구하는 문제다. ( nCr )
 * 여기서는 dfs방법을 사용하되 메모이제이션을 통해서 최적화를 한다. (동적 프로그래밍)
 * 이항계수를 구하는 알고리즘은 다음과 같다.
 *  nCr == <n-1 C n-1> + <n-1 C n>
 *  예를 들어 5_C_3 == 4_C_2 + 4_C_3 
 * 	--> 왜 그런지 기억이 안나면 검색해서 알아보자.
 * 
 *  이 논리를 하위 콤비네이션에도 재귀적으로 적용하다 보면,
 *   n == r 또는 r == 0 인 경우가 나오는데 이때는 무조건 1이므로 이것을 리턴한다.
 *  리턴된 모든 1을 계속 더해가면 조합의 개수가 나온다.
 * 
 *  여기서 더 최적화를 하려면,
 *  하위 콤비네이션 중 중복되는 콤비네이션이 있으면
 *  미리 저장해서 바로 리턴하는 방법을 사용한다.
 */
 #include <iostream>
 #include <algorithm>
 #include <vector>
 
 using namespace std;

int dp[21][21]; //먼저 계산한 것을 저장해 둔다.

int dfs(int n, int r)
{
	if (dp[n][r] > 0) return dp[n][r];
	if (r == 0 || n == r) return 1;	
	else return dp[n][r] = dfs(n - 1, r - 1) + dfs(n - 1, r);
}

 int main(void)
 {
	int n, r;
	int res;
	cin >> n >> r;

	res = dfs(n, r);

	cout << res << endl;
	return 0;
 }

// 내가 안보고 처음에 풀이한 방식
// 모든 경우의 수에서 원소가 3번 체크 된지를 일일히 확인함.
//  int arr[21];
//  int n, r;
//  int cnt;

//  void dfs(int v)
//  {
// 	if (v == n + 1)
// 	{
// 		int tmp = 0;
// 		for (int i = 1; i <= n; ++i)
// 		{
// 			if (arr[i] != 0)
// 				tmp++;
// 		}
// 		if (tmp == r)
// 			cnt++;

// 		return;
// 	}
// 	arr[v] = 1;
// 	dfs(v + 1);
// 	arr[v] = 0;
// 	dfs(v + 1);
//  }
