#pragma once
#include "common.h"
template <typename T>
class SmartPtr;

template <typename T>
//����������
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
//���������Է�װʹ�ü������������ָ�롣
class U_Ptr
{
private:

	//�����Ա����Ȩ��ȫ��Ϊprivate����Ϊ�������û�ֱ��ʹ�ø���
	friend class SmartPtr<T>; //��������ָ����Ϊ��Ԫ����Ϊ����ָ������Ҫֱ�Ӳ��ݸ�����
	//���캯���Ĳ���Ϊ���������ָ��
	U_Ptr(T* ptr) :p(ptr), count(1) { }
	~U_Ptr() { delete p; }

	int count;
	T* p;
};
//����ָ����
template <typename T>
class SmartPtr
{
public:
	SmartPtr(T* ptr) :rp(new U_Ptr<T>(ptr)) { }

	SmartPtr(const SmartPtr<T>& sp) :rp(sp.rp) { ++rp->count; }

	SmartPtr& operator=(const SmartPtr<T>& rhs) {//���ظ�ֵ������
		++rhs.rp->count;//���Ƚ��Ҳ��������ü�����1��
		if (--rp->count == 0)//Ȼ�����ü�����1������Ӧ���Ը�ֵ
			delete rp;
		rp = rhs.rp;
		return *this;
	}
	T& operator *()        //����*������  
	{
		return *(rp->p);
	}
	T* operator ->()       //����->������  
	{
		return rp->p;
	}
	~SmartPtr() {
		if (--rp->count == 0)//�����ü�����Ϊ0ʱ��ɾ�����������ָ�룬�Ӷ�ɾ����������
			delete rp;
		else
			cout << "����" << rp->count << "��ָ��ָ���������" << endl;
	}

private:
	U_Ptr<T>* rp;//���������ָ��
};