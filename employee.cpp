#include "employee.h"
#include<iostream>
using namespace std;

Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//顯示個人訊息
void Employee::showInfo() {
	cout << "員工編號: " << this->m_Id
		<< "\t員工姓名:  " << this->m_Name
		<< "\t崗位:   " << this->getDeptName()
		<< "\t崗位職責: 完成經理交給的任務" << endl;
}

//獲得崗位名稱
string Employee::getDeptName() {
	return string("員工");
}

