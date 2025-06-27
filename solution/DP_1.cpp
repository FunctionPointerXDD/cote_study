/**
 * DP_1. 네트워크 선 자르기 (Bottom-Up)
 * 
 * 선을 1과 2의 길이로 자를 수 있는 경우의 수를 구한다. (이 때 자르는 위치도 고려한다.)
 * 길이가 1인 선을 자를 수 있는 경우의 수는 1가지 이다. (당연)
 * 길이가 2인 선을 자를 수 있는 경우의 수는 1+1, 2 -> 이렇게 2가지이다.
 * 길이가 3인 선을 자를 수 있는 경우의 수는 1+2, 2+1, 1+1+1 이렇게 3가지다.
 *   --> 이를 자세히 보면 하나의 자르는 위치를 기준으로 길이가 2인 것과 길이가 1인 것으로 나뉜다.
 *    ---> 따라서 길이가 2인 경우의 수와 1인 경우의 수의 합으로 볼 수 있다.
 * 이를 점화식으로 표현하면, 
 *  ==> f(n) = f(n-2) + f(n-1)
 * 
 * 동적 프로그래밍 중에서 (bottom-up)방식이라고 볼 수 있다.
 */

 #include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>

 using namespace std;

 int dy[60];

 int main(void)
 {
	int n;	
	cin >> n;
	dy[1] = 1;
	dy[2] = 2;
	for (int i = 3; i <= n; ++i)
		dy[i] = dy[i - 2] + dy[i - 1];

	cout << dy[n] << endl;
	return 0;
 }
