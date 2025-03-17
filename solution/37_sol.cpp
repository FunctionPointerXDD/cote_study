/**
 * 37. Least Recently Used (카카오 캐시 문제 변형) -> 삽입 정렬 응용
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(void)
{
    //freopen("input.txt", "rt", stdin);
    int s, n;
    std::cin >> s >> n;

    std::vector<int> cache(s);
	std::vector<int> work(n);

    for (int i = 0; i < n; ++i)
	    std::cin >> work[i];

	for (int i = 0; i < n; ++i)
	{
		int tmp = work[i];
		int idx = -1;
		for (int j = 0; j < s; ++j)
		{
			if (cache[j] == tmp)
			{
				idx = j;
				break;
			}
		}

		//cache miss
		if (idx < 0)
		{
			for (int j = s - 1; j > 0; --j)
				cache[j] = cache[j - 1];
		}
		else //cache hit
		{
			for (int j = idx; j > 0; --j)
				cache[j] = cache[j - 1];
		}
		cache[0] = tmp;
	}

	for (int i = 0; i < s; ++i)
		std::cout << cache[i] << ' ';

    return 0;
}
