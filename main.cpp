/**
 * 52. Ugly Numbers
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

	int ugly = 1;

	int i = 2;
	while (1)
	{
		if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
		{
			ugly = i;
		}

	}



	return 0;
}
