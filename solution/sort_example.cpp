/**
 * 구조체 활용해서 정렬하기
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct Loc{
	int x, y, z;

	Loc(int a, int b, int c) 
	{
		x=a;
		y=b;
		z=c;
	}
	
	// 오름차순으로 정리 (t1 < t2)
	bool operator<(const Loc &param) const
	{
		if (this->x != param.x) return x < param.x;
		if (this->y != param.y) return y < param.y;
		if (this->z != param.z) return z < param.z;
		return false;
	}
};

int main(void)
{
	vector<Loc> vec;
	vec.push_back(Loc(2, 3, 5));
	vec.push_back(Loc(3, 6, 7));
	vec.push_back(Loc(2, 3, 1));
	vec.push_back(Loc(5, 2, 3));
	vec.push_back(Loc(3, 1, 6));

	sort(vec.begin(), vec.end());

	for (size_t i = 0; i < vec.size(); ++i)
		cout << vec[i].x << ' ' << vec[i].y << ' ' << vec[i].z << '\n';

	return 0;
}
