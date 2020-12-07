#pragma once
#include <map>
#include "common.h"
bool isPossible(vector<int>& nums) {
	//map<int, int>numsMap;
	
		//numsMap记录nums中每个数字出现的次数，tail记录连续队列的队尾
		unordered_map<int, int>numsMap, tail;
		for (auto num : nums)
		{
			numsMap[num]++;
		}
		for (auto num : nums)
		{
			if (numsMap[num] == 0)
			{
				continue;
			}
			else if (numsMap[num] > 0 && tail[num - 1] > 0)
			{
				numsMap[num]--;
				tail[num - 1]--;
				tail[num]++;
				
			}
			else if (numsMap[num] > 0 && numsMap[num + 1] > 0 && numsMap[num + 2] > 0)
			{
				//三个连续的子序列
				numsMap[num]--;
				numsMap[num + 1]--;
				numsMap[num + 2]--;
				//结尾num+2的序列加一
				tail[num + 2]++;
			}
			else
			{
				return false;
			}
		}
	
	return true;
}
