#pragma once
#include<iostream>
using namespace std;

#include "worker.h"

class Manager :public Worker {

public:


	Manager(int id, string name, int did);

	//顯示個人訊息
	virtual void showInfo();

	//獲得崗位名稱
	virtual string getDeptName();

};


