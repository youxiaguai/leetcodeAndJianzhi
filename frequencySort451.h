#pragma once
#include "common.h"

string frequencySort(string s) {
	unordered_map<char, int>smap;
	for (const auto& ch:s)
	{
		smap[ch]++;
	}
	
	sort(s.begin(), s.end(), [&](const auto& a, const auto& b) {
		return smap[a] > smap[b] || (smap[a] == smap[b] && a < b);
	});
	return s;
	

}