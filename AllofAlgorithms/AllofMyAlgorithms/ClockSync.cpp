#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

const int button = 10;
const int clock_count = 16;


bool switch_link[button][clock_count] = {
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};

bool areAligned(const vector<int>& clock) {
	for (size_t i = 0; i < clock.size(); i++) {
		if (clock.at(i) != 12)
			return false;
	}
	return true;
}

void change(vector<int>& clock,int switch_num) {
	for (int i = 0; i < clock.size(); i++) {
		if (switch_link[switch_num][i]==true) {
			clock.at(i) += 3;
			if (clock.at(i) == 15)
				clock.at(i) = 3;
		}

	}
}

int Solved(vector<int>& clock, int switch_num){
	if (switch_num == button) return areAligned(clock)? 0: 9999;
	int ret = 9999;
	for (int i = 0; i < 4; i++) {
		ret = min(ret, i + Solved(clock, switch_num + 1));
		change(clock,switch_num);
	}
	return ret;
}

void main() {
	vector<int> clock;
	int c,str;

	cin >> c;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < 16; j++) {
			cin >> str;
			clock.push_back(str);
		}
		cout << Solved(clock, 0) << endl;

		clock.clear();
	}

}