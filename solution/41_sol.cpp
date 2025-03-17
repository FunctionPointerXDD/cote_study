/**
 * 41. 연속된 자연수의 합
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
    //freopen("input.txt", "rt", stdin);
    int n;
	cin >> n;

	int i;
	int cnt = 0;
	int seq = 1;
	int tmp = n;

	n--;
	while (n > 0)
	{
		seq++;
		n -= seq;
		if (n % seq == 0)
		{
			int div = n / seq;
			for (i = 1; i < seq; ++i)
				cout << i + div << " + ";

			cout << i + div << " = " << tmp << '\n';
			cnt++;
		}
	}
	cout << cnt << endl;

	/**
	 * 15개의 사과가 있고, 이것을 바구니 2개에 1씩 차이가 나는 연속된 개수로 담고자 한다면, 
	 * 첫번재 바구니에 1개를 넣고, 2번째 바구니에 2개를 넣으면 남은 사과의 개수는 12개이다.
	 * 이 때, 12개의 사과를 총 바구니의 수 2로 나누어 주면 6개로 정확히 나누어 떨어진다.
	 * 그리고 이것을 각각 넣어주면 7개, 8개 사과가 바구니의 나누어 담겨지게 된다.
	 * 같은 방식으로 바구니의 개수를 하나씩 늘리면서 각 바구니 마다 1씩 차이나는 연속된 숫자로 삽입한 후,
	 * 바구니의 개수로 나누어 떨어진다는 것이 확인되면, 연속된 숫자의 합으로 나타내는 것이 가능한 것이다.
	 */

	return 0;
}
