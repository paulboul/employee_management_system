#include "employee.h"
#include<iostream>
using namespace std;

Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//��ܭӤH�T��
void Employee::showInfo() {
	cout << "���u�s��: " << this->m_Id
		<< "\t���u�m�W:  " << this->m_Name
		<< "\t�^��:   " << this->getDeptName()
		<< "\t�^��¾�d: �����g�z�浹������" << endl;
}

//��o�^��W��
string Employee::getDeptName() {
	return string("���u");
}

