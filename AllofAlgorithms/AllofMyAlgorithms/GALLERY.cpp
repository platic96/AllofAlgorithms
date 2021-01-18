#include "AllofHeader.h"

int V;
vector<int> adj[100000];
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
//���ݱ��� ��ġ�� ī�޶��� �� ��
int installed;
//here�� ���� ���� �켱 Ž���� �ϰ�, here�� ������ ��ȯ�Ѵ�.
int dfs(int here) {
	visited[here] = true;
	int children[3] = { 0,0,0 };
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!visited[there])
			++children[dfs(there)];
	}
	//�ڼ� ��� �� ���õ��� �ʴ� ��尡 ���� ��� ī�޶� ��ġ.
	if (children[UNWATCHED]) {
		++installed;
		return INSTALLED;
	}
	//�ڼ� ��� �� ī�޶� ��ġ�� ��尡 ���� ��� ��ġ�� �ʿ䰡 ����.
	if (children[INSTALLED]) {
		return WATCHED;
	}
	return UNWATCHED;
}
//�׷����� �����ϴµ� �ʿ��� ī�޶��� �ּ� ���� ��ȯ.
int installCamera() {
	installed = 0;
	visited = vector<bool>(V, false);
	for (int i = 0; i < V; ++i) {
		if (!visited[i] && dfs(i) == UNWATCHED)
			++installed;
	}
	return installed;
}