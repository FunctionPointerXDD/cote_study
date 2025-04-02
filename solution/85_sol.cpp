/**
 * 85. 수식만들기(DFS활용)
 * 연산자를 그래프에 정점으로 생각한다.
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int op[4]; // +, -, *, /
int seq[100];
int n;

int _max = -2147483648;
int _min = 2147483647;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int _div(int a, int b) { return a / b; }

int (*fp[4])(int, int) = {add, sub, mul, _div};
// 함수 포인터 안쓰고 그냥 if (op[0] > 0).. if(op[1] > 0) .. 이런식으로
// if문 4개 사용해서 똑같은 형식으로 처리해도 된다. (num인자로 넘길 때만, 각각 연산에 맞게 처리하면 됨. )
// -> 성능 상으로도 차이 없어 보임. (오히려 함수 포인터 주소값 찾느라 시간 걸릴수도...)
// 대신 유지 보수 및 미관상 좋음.

void dfs(int v, int num)
{
	if (v == n)
	{
		if (_max < num) _max = num;
		if (_min > num) _min = num;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (op[i] > 0)
		{
			op[i]--;
			dfs(v + 1, fp[i](num, seq[v]));
			op[i]++;
		}
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	for (int i = 0; i < 4; ++i)
		cin >> op[i];

	//첫번째 숫자를 먼저 삽입한다.
	dfs(1, seq[0]);

	cout << _max << endl;
	cout << _min << endl;

	return 0;
}
