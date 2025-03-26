/**
 * 55. 기차운행(stack 응용)
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;


int main(void)
{
    //freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<int> arr(5000);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	stack<int> st;
	string str("");
	int order = 1;
	int i = 0;


	while (1)
	{
		if (i == n)
			break;

		st.push(arr[i++]);
		str += 'P';

		while (!st.empty() && st.top() == order)
		{
			st.pop();
			order++;
			str += 'O';
		}
	}
	if (st.empty())
		cout << str << endl;
	else
		cout << "impossible" << endl;

    return 0;
}