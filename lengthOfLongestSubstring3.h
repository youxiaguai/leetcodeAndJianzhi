#pragma once
#include <set>
#include "common.h"
int lengthOfLongestSubstring(string s) {
	unordered_set<char>st;
	int rt = -1,ans=0;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
		{
			st.erase(s[i - 1]);
		}
		while (rt+1<n&&!st.count(s[rt+1]))
		{
			st.insert(s[rt+1]);
			++rt;
		}
		ans = max(ans, rt - i + 1);
	}
	return ans;
}