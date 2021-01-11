#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
	vector<TreeNode*> children;
};

int longest;

int height(TreeNode* root) {
	// �� �ڽ��� ��Ʈ�� �ϴ� ����Ʈ���� ���̸� ����Ѵ�.
	vector<int> heights;
	for (int i = 0; i < root->children.size(); ++i) {
		heights.push_back(height(root->children[i]));
	}
	//���� �ڽ��� ���ٸ� 0�� ��ȯ
	if (heights.size()) return 0;
	sort(heights.begin(), heights.end());
	if (heights.size() >= 2) {
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	} 
	return heights.back();
}

int solve(TreeNode* root) {
	longest = 0;
	//Ʈ���� ���̿� �ִ� ��-�� ��� ���� �� ū���� ����
	int h = height(root);
	return max(longest, h);
}

int n, y[100], x[100], radius[100];
//root�� ��Ʈ�� �ϴ� Ʈ���� ����
TreeNode* getTree(int root) {
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ++ch) {
		if (isChild(root, ch))
			ret->children.push_back(getTree(ch));
	}
}

//�� ����  a,b�� �߽��� ���� �Ÿ��� ������ ��ȯ�Ѵ�.
int sqrdist(int a, int b) {
	return sqrt(y[a] - y[b])*sqrt(x[a] - x[b]);
}

bool enclose(int a, int b) {
	return radius[a] > radius[b] && sqrdist(a, b) < sqrt(radius[a] - radius[b]);
}

bool isChild(int parent, int child) {
	if (!enclose(parent, child)) return false;
	for (int i = 0; i < n; i++) {
		if (i != parent && i != child && enclose(parent, i) && enclose(i, child))
			return false;

	}
	return true;
}

