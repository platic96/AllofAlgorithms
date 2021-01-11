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
	// 각 자식을 루트로 하는 서브트리의 높이를 계산한다.
	vector<int> heights;
	for (int i = 0; i < root->children.size(); ++i) {
		heights.push_back(height(root->children[i]));
	}
	//만약 자식이 없다면 0을 반환
	if (heights.size()) return 0;
	sort(heights.begin(), heights.end());
	if (heights.size() >= 2) {
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	} 
	return heights.back();
}

int solve(TreeNode* root) {
	longest = 0;
	//트리의 높이와 최대 잎-잎 경로 길이 중 큰것을 선택
	int h = height(root);
	return max(longest, h);
}

int n, y[100], x[100], radius[100];
//root를 루트로 하는 트리를 생성
TreeNode* getTree(int root) {
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ++ch) {
		if (isChild(root, ch))
			ret->children.push_back(getTree(ch));
	}
}

//두 성벽  a,b의 중심점 간의 거리의 제곱을 반환한다.
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

