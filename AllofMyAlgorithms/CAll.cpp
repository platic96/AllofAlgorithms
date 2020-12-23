#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

struct Juga
{
	double m_iOpen;
	double m_iHigh;
	double m_iLow;
	double m_iClose;
	double m_iAdj_Close;
	double m_iVolume;
	double m_iX;
	double m_iY;
};

int main() {

	ifstream data;
	string tmp;
	list<string> count;
	int i = 0;
	data.open("Huendae_juga.csv", ios::in);
	if (data.fail()) {
		return (cout << "해당 경로에 위치하는 파일이 존재하지 않습니다." << endl) && 0;
	}
	while (getline(data, tmp))
	{
		stringstream c(tmp);
		string tt;
		
		while (getline(c, tt, ',')) {
			count.push_back(tt);
		}
		i++;
	}
	Juga* juga = new Juga[i];
	list <string>::iterator it = count.begin();
	for (int n = 0; n < i-1; ++n)
	{
		if (*it == "null") {
			for (int m = 0; m < 8; ++m)
				*it++;
			continue;
		}
		juga[n].m_iOpen = stod(*it++);
		juga[n].m_iHigh = stod(*it++);
		juga[n].m_iLow = stod(*it++);
		juga[n].m_iClose = stod(*it++);
		juga[n].m_iAdj_Close = stod(*it++);
		juga[n].m_iVolume = stod(*it++);
		juga[n].m_iX = stod(*it++);
		juga[n].m_iY = stod(*it++);
	}
	/*Juga** juga = new Juga*[i];
	for (int j = 0; j < i; ++j)
		juga[j] = new Juga[8];*/
	data.close();

	return 0;
}