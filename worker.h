#pragma once
#include<iostream>
using namespace std;
#include<string>


//���u��H��
class Worker {
public:


	//��ܭӤH�T��
	virtual void showInfo() = 0;
	//��o�^��W��
	virtual string getDeptName() = 0;
	//���u�W��
	int m_Id;
	//���u�m�W
	string m_Name;
	//�����s��
	int m_DeptId;
};

