#pragma once
#include <map>
#include "common.h"
bool isPossible(vector<int>& nums) {
	//map<int, int>numsMap;
	
		//numsMap��¼nums��ÿ�����ֳ��ֵĴ�����tail��¼�������еĶ�β
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
				//����������������
				numsMap[num]--;
				numsMap[num + 1]--;
				numsMap[num + 2]--;
				//��βnum+2�����м�һ
				tail[num + 2]++;
			}
			else
			{
				return false;
			}
		}
	
	return true;
}
