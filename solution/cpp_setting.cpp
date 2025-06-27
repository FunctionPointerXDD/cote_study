/**
 * 입출력 속도 향상시키기 + etc ...
 */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include <bits/stdc++.h> // GNU GCC에서 제공하는 비공식 헤더이다.
// 여기서는 적용이 안되는데 이유를 잘 모르겠다. 
// 프로그래머스에서 사용할 수 있다. (이것을 사용하면 왠만한 라이브러리는 전부 사용 가능하다.)
// 컴파일 타임은 조금 오래 걸린다. (그러나 대부분 컴파일 타임을 시험이나 대회에서 측정하지는 않는다.)

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false); // 입출력 속도가 빨라진다. (C 라이브러리와 연동을 끊는다?)
	cin.tie(0); // 추가적인 속도 향상 옵션

	freopen("input.txt", "rt", stdin);
	int n, min = 2147483647;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		if (a[i]<min) min=a[i];
	cout << min;
	return 0;
}