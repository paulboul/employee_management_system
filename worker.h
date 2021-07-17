#pragma once
#include<iostream>
using namespace std;
#include<string>


//員工抽象類
class Worker {
public:


	//顯示個人訊息
	virtual void showInfo() = 0;
	//獲得崗位名稱
	virtual string getDeptName() = 0;
	//員工名稱
	int m_Id;
	//員工姓名
	string m_Name;
	//部門編號
	int m_DeptId;
};

