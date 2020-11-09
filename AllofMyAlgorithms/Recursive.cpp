#include <iostream>
#include <vector>

using namespace std;

int sum(int n) {
	int ret = 0;
	for (int i = 0; i <= n; i++) {
		ret += i;
	}
	return ret;
}

int recursiveSum(int n) {
	if (n == 1) return 1;
	return n + recursiveSum(n-1);
}

void printPicked(vector<int>& picked) {
	for (auto i : picked.begin) {
		cout << i << endl;
	}
}

//��ø �ݺ��� ��ü�ϱ�
//n : ��ü ������ ��
//picked : ���ݱ��� �� ���ҵ��� ��ȣ
//toPick: �� �� ������ ��
//�� ��, ������ toPick���� ���Ҹ� ���� ��� ����� ����Ѵ�.
void pick(int n, vector<int>& picked, int toPick) {
	//���� ��� : �� �� ���Ұ� ���� �� �� ���ҵ��� ����Ѵ�.
	if (toPick == 0) { printPicked(picked); return; }
	//�� �� �ִ� ���� ���� ��ȣ�� ����Ѵ�.
	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

