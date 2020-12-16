#pragma once
#include "common.h"
string intToRoman(int num) {
	vector<string>gewei = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
	vector<string>shiwei = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	vector<string>baiwei = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	vector<string>qianwei = {"","M","MM","MMM"};

	string out = qianwei[num / 1000];
	out += baiwei[(num%1000) / 100];
	out += shiwei[(num%1000%100) / 10];
	out += gewei[(num % 1000 % 100) % 10];
	return out;

}