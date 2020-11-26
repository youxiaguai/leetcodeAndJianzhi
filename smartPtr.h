#pragma once
#include "common.h"
template <typename T>
class SmartPtr;

template <typename T>
//基础对象类
class Point
{
public:
	Point(int xVal = 0, int yVal = 0) :x(xVal), y(yVal) { }
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int xVal) { x = xVal; }
	void setY(int yVal) { y = yVal; }

private:
	int x, y;

};
template <typename T>
//辅助类用以封装使用计数与基础对象指针。
class U_Ptr
{
private:

	//该类成员访问权限全部为private，因为不想让用户直接使用该类
	friend class SmartPtr<T>; //定义智能指针类为友元，因为智能指针类需要直接操纵辅助类
	//构造函数的参数为基础对象的指针
	U_Ptr(T* ptr) :p(ptr), count(1) { }
	~U_Ptr() { delete p; }

	int count;
	T* p;
};
//智能指针类
template <typename T>
class SmartPtr
{
public:
	SmartPtr(T* ptr) :rp(new U_Ptr<T>(ptr)) { }

	SmartPtr(const SmartPtr<T>& sp) :rp(sp.rp) { ++rp->count; }

	SmartPtr& operator=(const SmartPtr<T>& rhs) {//重载赋值操作符
		++rhs.rp->count;//首先将右操作数引用计数加1，
		if (--rp->count == 0)//然后将引用计数减1，可以应对自赋值
			delete rp;
		rp = rhs.rp;
		return *this;
	}
	T& operator *()        //重载*操作符  
	{
		return *(rp->p);
	}
	T* operator ->()       //重载->操作符  
	{
		return rp->p;
	}
	~SmartPtr() {
		if (--rp->count == 0)//当引用计数减为0时，删除辅助类对象指针，从而删除基础对象
			delete rp;
		else
			cout << "还有" << rp->count << "个指针指向基础对象" << endl;
	}

private:
	U_Ptr<T>* rp;//辅助类对象指针
};