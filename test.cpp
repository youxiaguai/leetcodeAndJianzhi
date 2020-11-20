#include "kuaipai.h"
#include <iostream>
#include "jiayouzhan134.h"
#include "dongtaihe1480.h"
#include "yidong283.h"
#include "chongpai1470.h"
#include "hao1512.h"
#include "candy1431.h"
#include "baoshi771.h"
#include "maxIn807.h"
using namespace std;

int main()
{
	int select = 807;
	if (select == 1)
	{
		vector<int> arr = { 6,1,2,7,9,3,4,5,10,8 };
		quickSort(0, 9, arr);
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		return 0;

	}
	if (select == 134)
	{
		vector<int>gas = { 1,2,3,4,3,2,4,1,5,3,2,4 };
		vector<int>cost = { 1,1,1,3,2,4,3,6,7,4,3,1 };
		int result = canCompleteCircuit(gas, cost);
		cout << result;
	}
	if (select == 1480)
	{
		vector<int>nums = { 1,2,3,4 };
		runningSum(nums);


	}
	if (select == 283)
	{
		vector<int>nums = { 0,1,0,3,12 };
		moveZeroes(nums);
		
	}
	if (select == 1470)
	{
		vector<int>nums = { 2,5,1,3,4,7 };
		vector<int>result = shuffle(nums, 3);
	}
	if (select == 1512)
	{
		vector<int>nums = { 1,2,3,1,1,3};
		int result = numIdenticalPairs(nums);
		cout << result;
	}
	if (select == 1431)
	{
		vector<int>candies = { 2,3,5,1,3 };
		int extraCandies = 3;
		kidsWithCandies(candies,extraCandies);
		
	}
	if (select == 771)
	{
		string J = "aA";
		string S = "aAAbbbb";
		int result = numJewelsInStones(J,S);
		cout << result;
	}
	if (select ==807)
	{
		vector<vector<int>>grid = { {3,0,8,4 },{2,4,5,7},{9,2,6,3},{0,3,1,0} };
		int result = maxIncreaseKeepingSkyline(grid);
		cout << result;
	
	}

	return 1;
}