/**
 * 38. Inversion Sequence
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

	vector<int> inv(n);
	vector<int> arr(n);

    for (int i = 0; i < n; ++i)
	{
	    cin >> inv[i];
	}

	//뒤에서 부터 순차적으로 채워나가면 쉽다. 
	//왜냐면 뒤에 있는 inversion 숫자가 가장 크고
	//자기 보다 큰 수가 없어서 반드시 0이다.

	int i, j;
	for (i = n; i > 0; --i)
	{
		arr[i - 1] = i;
		int gt = inv[i - 1]; 
		for (j = i - 1; j + 1 < n; ++j)
		{
			if (gt <= 0)
				break;
			arr[j] = arr[j + 1];
			gt--;
		}
		arr[j] = i;
	}

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';

    return 0;
}


// 선생님 풀이
// int main() {
// 	freopen("input.txt", "rt", stdin);
// 	int n, i, j, pos;
// 	scanf("%d", &n);
// 	vector<int> is(n+1), os(n+1);
// 	for(i=1; i<=n; i++){
// 		scanf("%d", &is[i]);
// 	}
// 	for(i=n; i>=1; i--){
// 		pos=i;
// 		for(j=1; j<=is[i]; j++){
// 			os[pos]=os[pos+1];
// 			pos++;
// 		}
// 		os[pos]=i;
// 	}
// 	for(i=1; i<=n; i++){
// 		printf("%d ", os[i]);
// 	}	
// 	return 0;
// }
