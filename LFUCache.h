#pragma once
#include "common.h"
#include <set>
struct Node
{
	int key;
	int value;
	int freq;
	Node(int _key,int _value,int _freq) :key(_key),value(_value),freq(_freq) {}
};



class LFUCache
{
public:
	LFUCache(int capacity);
	
	int get(int key);
	void put(int key, int value);
private:
	//记录LFU缓存的最大容量
	int capacity;
	//key->value的映射
	unordered_map<int, list<Node>::iterator>Keys;
	
	unordered_map<int, list<Node>>freqs;
	//记录出现最小的频次
	int minFreq;
	
};

