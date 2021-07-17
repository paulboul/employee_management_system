#include "workManager.h"


WorkerManager::WorkerManager() {

	//1.��󤣦s�b
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//Ū���
	if (!ifs.is_open()) {
		cout << "��󤣦s�b" << endl;

		//��l���ݩ�
		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;
		//��l�Ƥ��O�_����
		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	}

	//2.���s�b�A�ƾڬ���
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//��󬰪�
		cout << "��󬰪�" << endl;

		//��l���ݩ�
		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;
		//��l�Ƥ��O�_����
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.���s�b�A�åB�O���ƾ�
	int num = this->get_EmpNum();
	cout << "���u�H�Ƭ�: " << num << endl;
	this->m_EmpNum = num;


	//�}�P�Ŷ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//�N��󤤪��ƾڡA�s��}�C��
	this->init_Emp();

	//����
	/*for (int i = 0; i < this->m_EmpNum; i++) {
		cout << "���u�s��: " << this->m_EmpArray[i]->m_Id
			<< " " << "���u�m�W: " << this->m_EmpArray[i]->m_Name
			<< " " << "�����s��: " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/


	
}
int WorkerManager::get_EmpNum() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>dId) {
		//�έp�H���ܶq
		num++;


	}
	return num;

}
void WorkerManager::Add_Emp() {
	cout << "�п�J�[�J���u�ƶq: " << endl;

	int addNum = 0;//�O�s�Τ��J�ƶq
	cin >> addNum;

	if (addNum > 0) {
		//�K�[
		//�p��s�K�[�Ŷ��j�p

		int newSize = this->m_EmpNum + addNum;//�s�Ŷ��j�p=��Ӭ����H��+�s�W�H��

		//�}�P�s�Ŷ�
		Worker **newSpace=new Worker* [newSize];

		//�N��ӪŶ��U�ƾڡA������s�Ŷ��U
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}


		//�K�[�s�ƾ�
		for (int i = 0; i < addNum; i++) {
			int id;//���u�s��
			string name;//���u�m�W
			int dSelect;//�������

			cout << "�п�J�� " << i + 1 << "�ӷs���u�s��" << endl;
			cin >> id;

			cout << "�п�J�� " << i + 1 << "�ӷs���u�m�W" << endl;
			cin >> name;

			cout << "�п�ܸӭ��u�^��: " << endl;
			cout << "1. ���q���u" << endl;
			cout << "2. �g�z" << endl;
			cout << "3. ����" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;

			default:

				break;
			}
			//�N�Ыح��u¾�d,�O�s��}�C��
			newSpace[this->m_EmpNum + i] = worker;


		}
		//����즳�Ŷ�
		delete[] this->m_EmpArray;

		//���s�Ŷ������V
		this->m_EmpArray = newSpace;

		//��s�s�����u�H��
		this->m_EmpNum = newSize;

		//��s���u�H�Ƥ�����
		this->m_FileIsEmpty = false;

		//���ܲK�[���\
		cout << "���\�K�[" << addNum << "�W�s���u" << endl;

		//�O�s�ƾڨ���
		this->save();
	


	}
	else {
		cout << "��J���~" << endl;
	}

	//�����N���A�M�̦^����
	system("pause");
	system("cls");



}
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//�g���

	//�N�C�ӤH���ƾڼg�J����
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//�������
	ofs.close();


}
//��l�ƭ��u
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;

		if (dId == 1) {//���q���u
			worker = new Employee(id, name, dId);
		
		}
		if (dId == 2) {//�g�z
			worker = new Manager(id, name, dId);

		}
		if (dId == 3) {//����
			worker = new Boss(id, name, dId);

		}
		this->m_EmpArray[index] = worker;
		index++;

	}
	ifs.close();


}



WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i] != NULL) {
				delete this->m_EmpArray[i];
			}
		
			
		}
		delete this->m_EmpArray;
		this->m_EmpArray = NULL;
		
	}

}
void WorkerManager::Show_Menu() {
	cout << "**************************************" << endl;
	cout << "**********�w��ϥΤ��q�޲z�t��*********" << endl;
	cout << "*********** 0.�h�X�޲z�{�� ***********" << endl;
	cout << "*********** 1.�W�[���u�T�� ***********" << endl;
	cout << "*********** 2.��ܭ��u�T�� ***********" << endl;
	cout << "*********** 3.�R�����u�T�� ***********" << endl;
	cout << "*********** 4.�ק���u�T�� ***********" << endl;
	cout << "*********** 5.�d�߭��u�T�� ***********" << endl;
	cout << "*********** 6.���ӽs���Ƨ� ***********" << endl;
	cout << "*********** 7.�M�ũҦ���� ***********" << endl;
	cout << endl;


}
void WorkerManager::ExitSystem() {
	cout << "�w��U���ϥ�" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Show_Emp() {

	//�P�_���O�_����
	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ΰO������" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			//�Q�Φh�A�եα��f
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//�R�����u
void WorkerManager::Del_Emp() {

	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ά�������" << endl;
	}
	else {

		cout << "�п�J�Q�n�R�����u�s��:" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1) {//�������u�s�b�A�åB�n�R����index��m�W�����u
			
			//�ƾګe��
			for (int i = 0; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}	

			this->m_EmpNum--;//��s���u�H��
			//�ƾڦP�B��s����
			this->save();
			cout << "�R�����\" << endl;


		}
		else {
			cout << "�R�����ѡA�������u" << endl;
		}

	}
	system("pause");
	system("cls");

}

//�P�_���u�O�_�s�b�A�p�G�s�b�N��^�}�C������m�A���s�b�N��^-1
int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			//�����u
			index = i;

			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp(){

	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ά�������" << endl;
	}
	else {
		cout << "�п�J�ק���u�s��" << endl;
		int id;
		cin>> id;

		int ret=this->IsExist(id);

		if (ret != -1) {//�������u�s�b�A�åB�n�ק���u�ƾ�
			
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�d��: " << id << " �����u�A�п�J�s���u�s��: " << endl;
			cin >> newId;

			cout << "�п�J�s���m�W: " << endl;
			cin >> newName;

			cout << "�п�J�s���^��: " << endl;
			cout << "1. ���q���u" << endl;
			cout << "2. �g�z" << endl;
			cout << "3. ����" << endl;

			cin >> dSelect;
			Worker* worker = NULL;

			switch (dSelect) {

			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;

			default:
				break;
			}
			//��s�ƾ�
			this->m_EmpArray[ret] = worker;

			cout << "�ק令�\" << endl;

			//�O�s����
			this->save();



		}
		else {
			cout << "�ק異�ѡA�������u" << endl;
		}

	}

	system("pause");
	system("cls");
}
//�d����u
void  WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ά�������" << endl;
	}
	else {

		cout << "�п�J�d�䪺�覡: " << endl;
		cout << "1. ���ӭ��u�s���d�� " << endl;
		cout << "2. ���ӭ��u�m�W�d�� " << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {//���ӽs���d��

			int id;
			cout << "�п�J�d����u�s��" << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1) {//�������u�s�b�A�åB�n�d����u�ƾ�
				
				cout << "�d�䦨�\�A�ӰT���p�U: " << endl;
				this->m_EmpArray[ret]->showInfo();


			}
			else {
				cout << "�d�䥢�ѡA�d�L���H" << endl;
			}


		}
		else if (select == 2) {//���өm�W�d��
			cout << "�п�J�d����u�m�W" << endl;
			string name;
			cin >> name;

			//�[�J�P�_�O�_�d�쪺�лx
			bool flag = false;//�q�{�����
			

			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i] ->m_Name== name) {
					cout << "�d�䦨�\�A���u�s����: "
						<< this->m_EmpArray[i]->m_Id 
						<< "���ӰT���p�U:" << endl;

					flag = true;
					
					this->m_EmpArray[i]->showInfo();
					


				}
			}
			if (flag == false) {
				cout << "�d�䥢�ѡA�d�L���H" << endl;
			}

		}
		else {
			cout << "��J���~" << endl;
		}


	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp() {

	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ά�������" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ܱƧǤ覡: " << endl;
		cout << "1. ���ӭ��u�s���i��ɧ�" << endl;
		cout << "2. ���ӭ��u�s���i�歰��" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++) {
			int minOrMax = i;//�n���̤p�� �� �̤j�ȤU��

			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) {//�ɧ�

					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}

				}
				else {//����
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
			}
			//�P�_�@�}�l�{�w �̤p�ȩγ̤j�� �O���O �p�⪺ �̤p�ȩγ̤j�ȡA�p�G���O�A�N�洫�ƾ�
			if (i != minOrMax) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "�ƧǦ��\!�Ƨǫ᪺���G��: " << endl;
		this->save();
		this->Show_Emp();
		
			
	}
}

//�M�Ť��
void WorkerManager::Clean_File() {
	
	cout << "�T�{�M�Ŷ�?" << endl;
	cout << "1. �T�w? " << endl;
	cout << "2. ��^" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {

		//�M�Ť��
		ofstream ofs(FILENAME, ios::trunc);//�R����󭫷s�Ы�

		ofs.close();
		
		//�R����Ϫ��C�ӭ��u��H
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//�R����ϰ}�C���w
			delete [] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;

		}
		cout << "�M�Ŧ��\!" << endl;

		

	}

	system("pause");
	system("cls");
}