#include<iostream>
#include "boss.h"



Boss::Boss(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//顯示個人訊息
void Boss::showInfo() {
	cout << "員工編號: " << this->m_Id
		<< "\t員工姓名:  " << this->m_Name
		<< "\t崗位:   " << this->getDeptName()
		<< "\t崗位職責: 管理公司所有事務" << endl;
}

//獲得崗位名稱
string Boss::getDeptName() {
	return string("老闆");
}