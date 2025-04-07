/**
 * map 사용법
 * key - value 관계를 형성한다. (키값은 중복 안됨)
 * key값 기준으로 오름차순 정렬됨 (내부적으로 red-black-tree사용)
 */
 #include <iostream>
 #include <fstream>
 #include <map>
 #include <string>

using namespace std;

 int main(void)
 {
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("input.txt"); // ex) string {book, cat, cat, dog ...}

	map<string, int> check; // <key, value>
	map<string, int>::iterator it; // iterator declare
	string str("");

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		check[str]++;
	}

	int max = -1;
	string res;
	for (it = check.begin(); it != check.end(); ++it)
	{
		//cout << it->first << ' ' << it->second << '\n';
		if (it->second > max)
		{
			max = it->second;
			res = it->first;
		}
	}
	cout << res << " : " << max << '\n';

	return 0;
 }
