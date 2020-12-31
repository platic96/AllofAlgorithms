#include <iostream>
#include <list>

using namespace std;

void josephus(int n, int k) {
	list<int> survivor;
	for (int i = 0; i < n; i++) {
		survivor.push_back(i);
	}
	list<int>::iterator kill = survivor.begin();

	while (n>2)
	{
		kill = survivor.erase(kill);
		if (kill == survivor.end()) kill = survivor.begin();
		--n;
		for (int i = 0; i < k - 1; i++) {
			++kill;
			if (kill == survivor.end()) kill = survivor.begin();
		}
	}
	cout << survivor.front() << " " << survivor.back() << endl;
}