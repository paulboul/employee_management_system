#pragma once
#include<iostream>
using namespace std;
//�����Y��󭫽�
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFIle.txt"
class WorkerManager {
public:
	
	WorkerManager();//�غc�l

	void Show_Menu();//�i�ܵ��

	void ExitSystem();//�h�X�t��

	//�������u�H��
	int m_EmpNum;

	//���u�}�C���w
	Worker** m_EmpArray;

	//�K�[���u
	void Add_Emp();

	//�O�s���
	void save();

	//�P�_���O�_����
	bool m_FileIsEmpty;

	//��l�ƭ��u
	void init_Emp();

	//�έp��󤤤H��
	int get_EmpNum();

	//��ܭ��u
	void Show_Emp();

	//�R�����u
	void Del_Emp();

	//�P�_���u�O�_�s�b�A�p�G�s�b�N��^�}�C������m�A���s�b�N��^-1
	int IsExist(int id);

	//�ק���u
	void Mod_Emp();

	//�d����u
	void Find_Emp();

	//���ӽs���Ƨǭ��u
	void Sort_Emp();

	//�M�Ť��
	void Clean_File();



	~WorkerManager();//�Ѻc�l

};
