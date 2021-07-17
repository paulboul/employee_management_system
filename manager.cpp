#include<iostream>
#include "manager.h"



Manager::Manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//顯示個人訊息
void Manager::showInfo() {
	cout << "員工編號: " << this->m_Id
		<< "\t員工姓名:  " << this->m_Name
		<< "\t崗位:   " << this->getDeptName()
		<< "\t崗位職責: 完成老闆交給的任務， 並且下發任務給員工" << endl;
}

//獲得崗位名稱
string Manager::getDeptName() {
	return string("經理");
}
