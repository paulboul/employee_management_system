#include<iostream>
#include<string>
using namespace std;
#include "workManager.h"

/*#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"*/

int main() {

	//���եN�X
	/*Worker* worker = NULL;
	worker = new Employee(1, "�i�U��", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "���ۧ�", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "�i����", 3);
	worker->showInfo();
	delete worker;*/


	//��Ҥƺ޲z��H
	WorkerManager wm;

	int choice = 0;//�s���Τ�ﶵ

	

	while (1) {
		//�եε�榨�����
		wm.Show_Menu();
		cout << "�п�J�A�����" << endl;
		cin >> choice;
		switch (choice) {

		case 0://�h�X�޲z�t��
			wm.ExitSystem();
			break;
		case 1://�W�[���u
			wm.Add_Emp();
			break;
		case 2://��ܭ��u
			wm.Show_Emp();
			break;
		case 3://�R�����u
		 {	/*����
				int ret = wm.IsExist(5);
				if (ret != -1) {
					cout << "���u�s�b" << endl;
				}
				else {
					cout << "���u���s�b" << endl;
				}*/
			wm.Del_Emp();

			break;
		}
		case 4://�ק���u
			wm.Mod_Emp();
			break;
		case 5://�d�߭��u
			wm.Find_Emp();
			break;
		case 6://���ӽs���Ƨ�
			wm.Sort_Emp();
			break;
		case 7://�M�ũҦ����
			wm.Clean_File();
			break;
			
		default:
			system("cls");
			break;


		}





	}









	return 0;
}