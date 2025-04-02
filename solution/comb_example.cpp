/**
 * 조합 구하기 (nCr)
 */
 #include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;

 int n, r;
 int check[20];

void dfs(int s, int depth)
{
    if (depth == r)
    {
        for (int i = 0; i < depth; ++i)
            cout << check[i] << ' ';
        cout << endl;
        return;
    }
    else
    {
        for (int i = s; i < n; ++i)
        {
            check[depth] = i;
            dfs(i + 1, depth + 1);
        }
    }
}

 int main(void)
 {
    //freopen("input.txt", "rt", stdin); // (5 , 3)
    cin >> n >> r;
    dfs(0, 0);
    return 0;
 }
