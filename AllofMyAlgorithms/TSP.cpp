#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000;

using namespace std;

int n;
double dist[MAX][MAX];

double shortestPath(vector<vector<int>>& path, vector<bool>& visited,double currentLength) {
	if(path.size() == n)
		return currentLength + dist[path[]][]
}