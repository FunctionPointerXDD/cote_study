/**
 * 58. 이진트리 깊이우선탐색(DFS)
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;

struct dfs
{
	int n;
	dfs *left;
	dfs *right;
};

void preOrder(struct dfs *node)
{
	if (node == 0) return;

	cout << node->n << ' ';
	preOrder(node->left);
	preOrder(node->right);
}

void inOrder(struct dfs *node)
{
	if (node == 0) return;

	inOrder(node->left);
	cout << node->n << ' ';
	inOrder(node->right);
}

void postOrder(struct dfs *node)
{
	if (node == 0) return;

	postOrder(node->left);
	postOrder(node->right);
	cout << node->n << ' ';
}

int main(void)
{
    //freopen("input.txt", "rt", stdin);

	dfs *node = new dfs[7];

	for (int i = 0; i < 7; ++i)
	{
		node[i].n = i + 1;
		node[i].left = 0;
		node[i].right= 0;
	}

	node[0].left = &node[1];
	node[0].right = &node[2];
	node[1].left = &node[3];
	node[1].right = &node[4];
	node[2].left = &node[5];
	node[2].right = &node[6];

	preOrder(node);
	cout << '\n';
	inOrder(node);
	cout << '\n';
	postOrder(node);
	cout << '\n';

	delete []node;
    return 0;
}