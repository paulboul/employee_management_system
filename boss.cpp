#include<iostream>
#include "boss.h"



Boss::Boss(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ܭӤH�T��
void Boss::showInfo() {
	cout << "���u�s��: " << this->m_Id
		<< "\t���u�m�W:  " << this->m_Name
		<< "\t�^��:   " << this->getDeptName()
		<< "\t�^��¾�d: �޲z���q�Ҧ��ư�" << endl;
}

//��o�^��W��
string Boss::getDeptName() {
	return string("����");
}