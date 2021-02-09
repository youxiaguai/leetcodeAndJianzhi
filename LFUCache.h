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
	//��¼LFU������������
	int capacity;
	//key->value��ӳ��
	unordered_map<int, list<Node>::iterator>Keys;
	
	unordered_map<int, list<Node>>freqs;
	//��¼������С��Ƶ��
	int minFreq;
	
};

