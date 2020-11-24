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
#include "jieya1313.h"
#include "judgeCircle657.h"
#include "replaceElements1299.h"
#include "permutation0807.h"
#include "ptr.h"
#include "erfen.h"
#include "subsets78.h"

#include <stdio.h>
#include <string>
#include <memory>
using namespace std;

int main()
{
	int select = 78;
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
	if (select == 1313)
	{
		vector<int>v = { 1,2,3,4 };
		vector<int>result= decompressRLElist(v);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << ",";
		}
	}
	if (select == 657)
	{
		string moves= "UD";
		bool result = judgeCircle(moves);
		cout << result;
	}
	if (select == 1299)
	{
		vector<int>arr = { 17,18,5,4,6,1 };
		replaceElements(arr);
	}
	if (select == 8070)
	{
		string s = "abc";
		vector<string>result=permutation(s);
		
		
	}
	if(select==222)
	{
		
		
		
			unique_ptr<Test> ptest(new Test("123"));
			ptest.release();
			return 0;
		
		
	}
	if (select == 333)
	{

			/* �׶� 1. auto_ptr ��C++11 ��������Ҫ���� p1 = p2, ���ƻ�ֵ����ı���Դ������Ȩ */
			/* unique_ptr ��ν���������? ��������ʾ����ֵ��ֵ�͹��� */
			unique_ptr<string> p1(new string("I 'm weifc"));
			unique_ptr<string> p2(new string("I 'm weikc"));
			printf("p1: %p\n", p1.get());
			printf("p2: %p\n", p2.get());

			/* ���һ��Ҫת��, ʹ�� move ����ֵת����ֵ */
			p1 = std::move(p2);
			printf("p1: %p\n", p1.get());
			printf("p2: %p\n", p2.get());

			/* p1 = p2; ��ֵ��ֵ��ֹ */
			unique_ptr<string> p3(new string("I 'm p3."));
			unique_ptr<string> p4(std::move(p3)); /* ��ֵ��������Ҳ����, ����ת����ֵ */

			/* �׶�2. �� STL ������ʹ�� auto_ptr �����ش����, ��Ϊ�����ڵ�Ԫ�ر���֧�ֿɸ���(copy constructable)
			�� �ɸ�ֵ (assignable). */
			vector<unique_ptr<string>> vu;
			unique_ptr<string> p5(new string("I 'm p5"));
			unique_ptr<string> p6(new string("I 'm p6"));

			vu.push_back(std::move(p3));
			vu.push_back(std::move(p4));

			cout << "va[0]: " << *vu[0] << endl;
			cout << "va[1]: " << *vu[1] << endl;

			// vu[0] = vu[1]; // unique_ptr ��֧��ֱ�Ӹ�ֵ, û�з���

			/* �׶� 3. auto_ptr ��֧�ֶ���������ڴ����, unique_ptr ֧�� */
			// ���� unique_ptr ֧�ֶ�������Ĺ���
			// auto_ptr<int[]> ai(new int[5]); // ������������
			unique_ptr<int[]> ui(new int[5]); // �Զ������ delete [] ����ȥ�ͷ�

			system("pause");
			
		

	}
	if (select == 78)
	{
		vector<int>nums = { 1,2,3 };
		vector<vector<int>>resu=subsets(nums);
		for (int i = 0; i < resu.size(); i++)
		{
			for (int j = 0; j < resu[i].size(); j++)
			{
				cout << resu[i][j] << ",";
			}
			cout << endl;
		}
	}
	return 1;
}