#pragma once
#include "common.h"
	string defangIPaddr(string address)
	{
		string result="";
		for (int i = 0; i < address.size(); i++)
		{
			if (address[i]=='.')
			{
				result.append("[.]");

			}
			else
			{
				result += address[i];
			}
			

		}
		return result;
	}