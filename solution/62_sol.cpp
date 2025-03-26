/**
 * 62. 병합정렬 (merge sort)
 * 후위 순회 방식으로 트리를 뻗을 수 있는데 까지 뻗은 후, 정렬하고 돌아오면서 합침.
 * 정렬 속도는 Nlog(N) -> 트리 레벨마다 모든 배열을 순회 (N) * 2개씩 나누어서 순차적으로 병합되므로 log_2(N)
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int n;
int arr[100];
int tmp[100];

//lt is min arr idx and rt is max arr idx.
void divide(int lt, int rt)
{
	int mid;
	int p1, p2, p3; // use array index

	//exit condition!
	if (lt < rt)
	{
		mid = (lt + rt) / 2;
		divide(lt, mid);
		divide(mid + 1, rt);

		p1 = lt; //first left idx
		p2 = mid + 1; //first right idx
		p3 = lt; // for copy idx

		/**
		 *  arr: [1|4|3|7]
		 *        ^   ^ 
		 *        p1  p2
		 * 
		 *  tmp: [0|0|0|0] 
		 * 		  ^
		 * 		  p3
		 */
		
		//tmp라는 임시배열에 오름차순으로 정렬에서 집어넣는다.
		while (p1 <= mid && p2 <= rt)
		{
			if (arr[p1] > arr[p2])
				tmp[p3++] = arr[p2++]; 
			else
				tmp[p3++] = arr[p1++];
		}
		//남는 경우 처리...
		while (p1 <= mid)
			tmp[p3++] = arr[p1++];
		while (p2 <= rt)
			tmp[p3++] = arr[p2++];
		
		//정렬된 임시배열을 원본 데이터에 복사.
		for (int i = lt; i <= rt; ++i)
			arr[i] = tmp[i];
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	divide(0, n - 1);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	cout << endl;

    return 0;
}
