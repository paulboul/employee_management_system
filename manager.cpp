#include<iostream>
#include "manager.h"



Manager::Manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ܭӤH�T��
void Manager::showInfo() {
	cout << "���u�s��: " << this->m_Id
		<< "\t���u�m�W:  " << this->m_Name
		<< "\t�^��:   " << this->getDeptName()
		<< "\t�^��¾�d: ��������浹�����ȡA �åB�U�o���ȵ����u" << endl;
}

//��o�^��W��
string Manager::getDeptName() {
	return string("�g�z");
}
