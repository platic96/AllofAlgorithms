#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> coord;

bool isDominated(int x, int y) {
	//x���� �������� �ִ� �� �� ���� ���ʿ� �ִ� ���� ã�´�.
	map<int, int>::iterator it = coord.lower_bound(x);
	//�׷� ���� ������ (x,y)�� ��������� �ʴ´�.
	if (it == coord.end()) return false;
	//�� ���� x���� �����ʿ� �մ� �� �� ���� ���� �ִ� ���̹Ƿ�
	//(x,y)�� ��� ���� ����Ƿ��� �� ������ ����Ǿ�� �Ѵ�.
	return y < it->second;
}

void removeDominate(int x, int y) {
	map<int, int>::iterator it = coord.lower_bound(x);
	//(x,y)���� ���ʿ� �ִ� ���� ����.
	if (it == coord.begin()) return;
	--it;
	while (true)
	{
		//(x,y)�ٷ� ���ʿ� ���� ���� ã�´�
		//it�� ǥ���ϴ� ���� (x,y)�� ������� �ʴ´ٸ� ���� ����
		if (it->second > y) break;
		// ���� ���� �� �����Ƿ� it�� ����� �����Ѵ�
		if (it == coord.begin()) {
			coord.erase(it);
			break;
		}
		else
		{
			map<int, int>::iterator jt = it;
			--jt;
			coord.erase(it);
			it = jt;
		}
	}
}
// �� ��(x,y)�� �߰��Ǿ��� �� coord�� �����ϰ�,
// �ٸ� ���� ��������� �ʴ� ������ ������ ��ȯ�Ѵ�.
int registered(int x, int y) {
	//(x,y)�� �̹� ������ϴ� ��쿡�� �׳� (x,y)�� ������.
	if (isDominated(x, y)) return coord.size();
	// ������ �ִ� �� �� (x,y)�� �����ϴ� ������ �����.
	removeDominate(x, y);
	coord[x] = y;
	return coord.size();
}

//Treep�� ����
typedef int KeyType;

struct Node {
	// ��忡 ����� ����
	KeyType key;
	// �� ����� �켱����(priority)
	// �� ��带 ��Ʈ�� �ϴ� ����Ʈ���� ũ��(size)
	int priority, size;
	// �� �ڽ��� ����� ������
	Node *left, *right;
	// �����ڿ��� ���� �켱������ �����ϰ�, size�� left/right�� �ʱ�ȭ ��Ų��.
	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRighy(Node* newRight) { right = newRight; calcSize(); }
	//size ����� �����Ѵ�.
	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};

//�ɰ��� ����
typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, KeyType key) {
	if (root == NULL) return NodePair(NULL, NULL);

	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRighy(rs.first);
		return NodePair(root, rs.second);
	}

	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return	NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRighy(splitted.second);
		return node;
	}
	else if (node->key < root->key) {
		root->setLeft(insert(root->left, node));
	}
	else {
		root->setRighy(insert(root->left, node));
	}
}
// �߰��� ����
Node* merge(Node* a, Node* b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRighy(merge(a->right, b));
	return a;
}

Node* erase(Node* root, KeyType key) {
	if (root == NULL) return root;

	if (root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRighy(erase(root->right, key));
	return root;
}

//Ʈ������ k��° ���� ã��

Node* kth(Node* root, int k) {
	// ���� ����Ʈ���� ũ�⸦ �켱 ����Ѵ�.
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1) return root;
	return kth(root->right, k - leftSize - 1);
}

//x���� ���� ���� ����

int countLessThan(Node* root, KeyType key) {
	if (root == NULL) return 0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root ->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}

int n, shifted[50000];
int A[50000];

void solve() {
	Node* candidates = NULL;
	for (int i = 0; i < n; ++i) {
		candidates = insert(candidates, new Node(i + 1));
	}
	for (int i = n - 1; i >= 0; --i) {
		int larger = shifted[i];
		Node* k = kth(candidates, i + 1 - larger);
		A[i] = k->key;
		candidates = erase(candidates, k->key);
	}
}