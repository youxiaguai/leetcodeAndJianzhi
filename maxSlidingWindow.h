#pragma once
#include "common.h"
#include <list>
#include <queue>
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	MonotonicQueue window;
	vector<int>li;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i < k - 1)
		{
			window.push(nums[i]);
		}
		else
		{
			//���ڿ�ʼ��ǰ�ƶ�
			//������Ԫ��
			window.push(nums[i]);
			//����ǰ�����е����Ԫ�ؼ�����
			li.push_back(window.max());
			window.pop(nums[i - k + 1]);
			
		}
	}
	
	return li;
}
class MonotonicQueue
{
public:
	MonotonicQueue();
	void push(int n);
	int max();
	void pop(int n);
	~MonotonicQueue();
	    
private:
	list<int>l;
		
};

MonotonicQueue::MonotonicQueue()
{

}

inline void MonotonicQueue::push(int n)
{
	while (!l.empty()&&l.back()<n)
	{
		l.pop_back();
	}
	l.push_back(n);
}

inline int MonotonicQueue::max()
{
	return l.front();
}

inline void MonotonicQueue::pop(int n)
{
	if (n == l.front())
	{
		l.pop_front();
	}
}

MonotonicQueue::~MonotonicQueue()
{
}