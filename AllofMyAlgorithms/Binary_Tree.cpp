#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> coord;

bool isDominated(int x, int y) {
	//x보다 오른족에 있는 점 중 가장 왼쪽에 있는 점을 찾는다.
	map<int, int>::iterator it = coord.lower_bound(x);
	//그런 점이 없으면 (x,y)는 지배당하지 않는다.
	if (it == coord.end()) return false;
	//이 점은 x보다 오른쪽에 잇는 점 중 가장 위에 있는 점이므로
	//(x,y)가 어느 점에 지배되려면 이 점에도 지배되어야 한다.
	return y < it->second;
}

void removeDominate(int x, int y) {
	map<int, int>::iterator it = coord.lower_bound(x);
	//(x,y)보다 왼쪽에 있는 점이 없다.
	if (it == coord.begin()) return;
	--it;
	while (true)
	{
		//(x,y)바로 왼쪽에 오는 점을 찾는다
		//it가 표시하는 점이 (x,y)에 지배되지 않는다면 곧장 종료
		if (it->second > y) break;
		// 이전 점이 더 없으므로 it만 지우고 종료한다
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
// 새 점(x,y)가 추가되었을 때 coord를 갱신하고,
// 다른 점에 지배당하지 않는 점들의 개수를 반환한다.
int registered(int x, int y) {
	//(x,y)가 이미 지배당하는 경우에는 그냥 (x,y)를 버린다.
	if (isDominated(x, y)) return coord.size();
	// 기존에 있던 점 중 (x,y)에 집당하는 점들을 지운다.
	removeDominate(x, y);
	coord[x] = y;
	return coord.size();
}

//Treep의 구현
typedef int KeyType;

struct Node {
	// 노드에 저장된 원소
	KeyType key;
	// 이 노드의 우선순위(priority)
	// 이 노드를 루트로 하는 서브트리의 크기(size)
	int priority, size;
	// 두 자식의 노드의 포인터
	Node *left, *right;
	// 생성자에서 난수 우선순위를 생성하고, size와 left/right를 초기화 시킨다.
	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRighy(Node* newRight) { right = newRight; calcSize(); }
	//size 멤버를 갱신한다.
	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
}