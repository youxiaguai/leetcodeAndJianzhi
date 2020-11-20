#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int lower_boundAndupper_bound()
{
	vector<int> ve(8, 0);
	for (int i = 0; i < 8; i++)
	{
		ve[i] = i;
	}
	auto low = lower_bound(ve.begin(), ve.end(), 3)-ve.begin();
	int upp = upper_bound(ve.begin(), ve.end(), 3) - ve.begin();
	cout<<low<<endl;
	cout << upp << endl;
	return 0;
}