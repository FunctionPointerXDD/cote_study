/**
 * 75. 최대 수입 스케줄링(priority_queue 응용문제)
 * 어려우니 천천히 보자.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


// struct Plan {
// 	int m;
// 	int d;
// };

// //날짜 오름차순 풀이
// bool cmp(const Plan &p1, const Plan &p2)
// {
// 	return p1.d < p2.d;
// }

// int main(void)
// {
// 	freopen("input.txt", "rt", stdin);	
// 	int n, m, d;
// 	cin >> n;

// 	vector<Plan> plan;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		cin >> m >> d;
// 		plan.push_back({m ,d});
// 	}

// 	sort(plan.begin(), plan.end(), cmp);

// 	priority_queue<int, std::vector<int>, std::greater<int> > pQ; // min_heap
// 	for (size_t i = 0; i < plan.size(); ++i)
// 	{
// 		pQ.push(plan[i].m);
// 		if (static_cast<int>(pQ.size()) > plan[i].d)
// 			pQ.pop();// 일정 상 불가능한 가장 싼 강연을 제거
// 			// 예를 들어, pQ 사이즈가 2이면 총 강연할 것이 2개임.
// 			// 그런데 기한이 1일이면 포기해야 할 강의가 생김.
// 			// 여기서 수입(m)을 기준으로 최소힙을 사용하고 있기 때문에
// 			// pop()을 하면 포기해야 할 강의 중 가장 싼 강의를 포기하게됨!
// 	}

// 	int sum = 0;
// 	while (!pQ.empty())
// 	{
// 		sum += pQ.top();
// 		pQ.pop();
// 	}

// 	cout << sum << endl;
// 	return 0;
// }

//날짜 내림차순 풀이
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
	return a.second > b.second;
}

int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n, m, d;
	cin >> n;

	vector<pair<int, int> > vec;
	for (int i = 0; i < n; ++i)
	{
		cin >> m >> d;
		vec.push_back(make_pair(m, d));
	}

	//먼 기한부터 순서대로 정렬
	sort(vec.begin(), vec.end(), cmp);

	priority_queue<int> pQ; //max_heap
	int deadline = vec[0].second;
	int sum = 0;
	int j = 0;

	//최대 기한인 날짜 부터 스케줄을 잡는다. 
	//그리고 각 기한 동안 우선순위 큐에 삽입하다가 기한이 변경되면, 
	//그 동안 삽입되었던 큐 중 최대 값을 더하고, pop 한다.
	//최대 기한 동안 우선순위 큐에 집어 넣은 값들을 차례대로 더하면
	//최대 수입을 얻을 수 있다.
	//그런데 이 부분은 구현 난이도가 좀 어렵다..
	for (int i = deadline; i > 0; i--)
	{
		while (j < n)
		{
			if (vec[j].second < i) break;
			pQ.push(vec[j++].first);
		}
		if (!pQ.empty())
		{
			sum += pQ.top();
			pQ.pop();
		}
	}

	cout << sum << endl;
	return 0;
}
