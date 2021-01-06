#pragma once
#include "common.h"
bool isIsomorphic(string s, string t) {
	
	unordered_map<char, char>sTotp;
	unordered_map<char, char>tTos;
	
	for (int i = 0; i < s.size(); i++)
	{
		char sh = s[i], th = t[i];
		if ((sTotp.count(sh)&&sTotp[sh]!=th)&&(tTos.count(th)&&tTos[th]!=sh))
		{
			return false;
		}
		sTotp[sh] = th;
		tTos[th] = sh;
	}
	return true;
}