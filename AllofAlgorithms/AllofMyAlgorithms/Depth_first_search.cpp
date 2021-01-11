#include "AllofHeader.h"

//�׷����� ���� ����Ʈ
vector<vector<int>> adj;
//�� ������ �湮�ߴ��� ���θ� ��Ÿ����.
vector<bool> visited;
//���� �켱 Ž���� ����

void dfs(int here) {
	cout << "DFS visits" << here << endl;
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
	//���̻� �湮�� ������ ������ ���ȣ�� �����ϰ� ���� ��������
}


//��� ������ �湮

void dfsAll() {
	//visited�� ��� valse�� �ʱ�ȭ.
	visited = vector<bool>(adj.size(), false);
	for (int i = 0; i < adj.size(); ++i)
		if (!visited[i])
			dfs(i);   
}