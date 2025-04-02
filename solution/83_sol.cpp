/**
 * 83. 복면산 (SEND + MORE = MONEY) <MS인터뷰>
 *  -> 순열(permutaion)을 사용한다.
 *  사용된 알파벳: D, E, M, N, O, R, S, Y -> 총 8개
 *       a[8] -->[0, 1 ,2, 3, 4, 5, 6, 7];
 *  -> 숫자 (0 ~ 9) 까지 10개의 숫자로 부터 나올 수 있는 경우의 수를 전부 계산한다.
 */
 #include <iostream>
 using namespace std;
 int check[10];
 int a[8];

 int send()
 {
	return a[6] * 1000 + a[1] * 100 + a[3] * 10 + a[0];
 }

 int more()
 {
	return a[2] * 1000 + a[4] * 100 + a[5] * 10 + a[1];
 }

 int money()
 {
	return a[2] * 10000 + a[4] * 1000 + a[3] * 100 + a[1] * 10 + a[7]; 
 }

 void dfs(int depth)
 {
	if (depth == 8)
	{
		if (send() + more() == money())
		{
			if (a[6] == 0 || a[2] == 0) return; //5자리 수가 나올 수 없으므로 리턴

			printf("   %d %d %d %d\n", a[6], a[1], a[3], a[0]);
			printf(" + %d %d %d %d\n", a[2], a[4], a[5], a[1]);
			printf(" -----------\n");
			printf(" %d %d %d %d %d\n", a[2], a[4], a[3], a[1], a[7]);
		}
	}

	// 0 ~ 9 까지 숫자 대입
	for (int i = 0; i < 10; ++i)
	{
		if (check[i] == 0)
		{
			check[i] = 1;
			a[depth] = i;
			dfs(depth + 1);
			check[i] = 0;
		}
	}
 }

 int main(void)
 {
	dfs(0); // depth를 0부터 시작한다. 3개가 선택되었다는 것을 쉽게 표현하기 위해서다.

	return 0;
 }