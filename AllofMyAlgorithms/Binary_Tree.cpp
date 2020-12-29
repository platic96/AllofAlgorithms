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
}