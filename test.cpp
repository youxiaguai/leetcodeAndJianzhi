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
#include "deckRevealedIncreasing950.h"
#include "smartPtr.h"
#include "combinationSum3216.h"
#include "combinationSum39.h"
#include "reconstructQueue406.h"
#include "Trie208.h"
#include "change518.h"
#include "calculate224.h"
#include "equationsPossible990.h"
#include "UnionFind.h"

#include <stdio.h>
#include <string>
#include <memory>
#include <stdio.h>
#include <sys/types.h>
#include <cstring>



//#include <unistd.h>
#include <stdlib.h>
using namespace std;





int main()
{
	int select = 990;
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
	if (select == 950)
	{
		vector<int>deck = { 17,13,11,2,3,5,7 };
		vector<int>res=deckRevealedIncreasing(deck);
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << ",";
		}
	}
	if (select == 111)
	{
		//pid_t pid = fork();
		char s[20] = "Yuanlijun";
		char res[20];
		string ss = "yuanlijun";
		int result=strlen(s);
		strcpy_s(res, s);
		cout << res<<","<<result;
	}
	if (select == 444)
	{
		for (int i = 0; i + 20; i--)
			cout << "hello" << endl;
	}
	if (select == 555)
	{
		int* i = new int(2);
		{
			SmartPtr<int> ptr1(i);
			{
				SmartPtr<int> ptr2(ptr1);
				{
					SmartPtr<int> ptr3 = ptr2;

					cout << *ptr1 << endl;
					*ptr1 = 20;
					cout << *ptr2 << endl;

				}
			}
		}
		system("pause");
	}
	if (select == 666)
	{
		vector<int> a = {1,2,3};
		cout << a.size() << "  " << a.capacity() << endl;
		//a.reserve(100);
		a.resize(50);
		for (int i = 0; i <a.size(); i++)
		{
			cout << a[i] << ",";
		}
		cout << endl;
		cout << a.size() << "  " << a.capacity() << endl;
		a.reserve(100);
		//50  100
		//a.resize(150);
		for (int i = 0; i < a.size(); i++)
		{
			cout << a[i] << ",";
		}
		cout << endl;
		cout << a.size() << "  " << a.capacity() << endl;
		//150  200
		a.reserve(50);
		cout << a.size() << "  " << a.capacity() << endl;
		//150  200
		a.resize(50);
		cout << a.size() << "  " << a.capacity() << endl;
		//50  200    
		
	}
	if (select == 39) {
		//combinationSum3(3, 7);
		Solution39 s;
		vector<int>candidates = { 2,3,6,7 };
		vector<vector<int>>ans;
		ans = s.combinationSum(candidates, 7);
		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = 0; j < ans[0].size(); j++)
			{
				cout << ans[i][j];
			}
		}
	}
	if (select == 406) {
		vector<vector<int>>people{ {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
		reconstructQueue( people);
		
	}
	if (select == 208)
	{
		Trie e;
		e.insert("ab");
		e.search("abc");
		e.search("ab");
		e.startsWith("abc");
		e.startsWith("ab");
		e.insert("ab");
		e.search("abc");
		e.startsWith("abc");
		e.insert("abc");
		e.search("abc");
		e.startsWith("abc");
		
	}
	if (select == 518) {
		int amount = 5;
		vector<int>coins = {1,2,5};
		change(amount, coins);
	}
	if (select == 224)
	{
		string s = "(1+(4+5+2)-3)+(6+8)";
		int result=calculate(s);
		cout << result;
	}
	if (select == 990)
	{
		string strp[] = { "a==b" ,"a!=b"};
		vector<string>equations(strp,strp+2);
		
		bool result;
		result = equationsPossible(equations);
		cout << result;
	}
	return 0;
}




