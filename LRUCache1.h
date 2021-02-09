#pragma once
#include "common.h"
struct DoubleLinked
{
	int key, val;
	DoubleLinked* pre;
	DoubleLinked* next;
	DoubleLinked() :key(0), val(0), pre(nullptr), next(nullptr) {}
	DoubleLinked(int k, int v) :key(k), val(v), pre(nullptr), next(nullptr) {}
};
class LRUCache
{
public:
	LRUCache(int c_capacity); 
	void addLast(DoubleLinked* x);
	
	void remove(DoubleLinked* x);
	
	DoubleLinked* removeFirst();
	
	int getSize();
	
	int get(int key);
	
	void put(int key, int value);
	
	~LRUCache();

private:
	unordered_map<int, DoubleLinked*>cache;
	DoubleLinked* head;
	DoubleLinked* tail;
	int size;
	int capacity;
		
};

LRUCache::LRUCache(int c_capacity)
{
	capacity = c_capacity;
	head = new DoubleLinked();
	tail = new DoubleLinked();
	head->next = tail;
	tail->pre = head;
	size = 0;
}

void LRUCache::addLast(DoubleLinked* x)
{
	x->pre = tail->pre;
	x->next = tail;
	tail->pre->next = x;
	tail->pre = x;
}
void LRUCache::remove(DoubleLinked* x)
{
	x->pre->next = x->next;
	x->next->pre = x->pre;
}
void LRUCache::put(int key, int value)
{
	
		if (!cache.count(key))
		{
			DoubleLinked* node = new DoubleLinked(key, value);
			cache[key] = node;
			addLast(node);
			++size;
			if (size > capacity)
			{
				DoubleLinked*removed= removeFirst();
				int deletedKey = removed->key;
				cache.erase(deletedKey);
				delete(removed);
				--size;
			}
		}
		else
		{
			DoubleLinked* node = cache[key];
			node->val = value;
			remove(node);
			addLast(node);


		}

	
}
int LRUCache::get(int key)
{
	
		if (!cache.count(key))
		{
			return -1;
		}
		DoubleLinked* node = cache[key];
		remove(node);
		addLast(node);
		return node->val;

	
}
int LRUCache::getSize()
{
	return capacity;
}
DoubleLinked* LRUCache::removeFirst()
{
	if (head->next == tail)
	{
		return nullptr;
	}
	DoubleLinked* node = head->next;
	remove(node);
	return node;
}
LRUCache::~LRUCache()
{
}