#include<iostream>
#include<string>
using namespace std;
#include "workManager.h"

/*#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"*/

int main() {

	//測試代碼
	/*Worker* worker = NULL;
	worker = new Employee(1, "張萬隆", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "郭彥彤", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "張葦航", 3);
	worker->showInfo();
	delete worker;*/


	//實例化管理對象
	WorkerManager wm;

	int choice = 0;//存取用戶選項

	

	while (1) {
		//調用菜單成員函數
		wm.Show_Menu();
		cout << "請輸入你的選擇" << endl;
		cin >> choice;
		switch (choice) {

		case 0://退出管理系統
			wm.ExitSystem();
			break;
		case 1://增加員工
			wm.Add_Emp();
			break;
		case 2://顯示員工
			wm.Show_Emp();
			break;
		case 3://刪除員工
		 {	/*測試
				int ret = wm.IsExist(5);
				if (ret != -1) {
					cout << "員工存在" << endl;
				}
				else {
					cout << "員工不存在" << endl;
				}*/
			wm.Del_Emp();

			break;
		}
		case 4://修改員工
			wm.Mod_Emp();
			break;
		case 5://查詢員工
			wm.Find_Emp();
			break;
		case 6://按照編號排序
			wm.Sort_Emp();
			break;
		case 7://清空所有資料
			wm.Clean_File();
			break;
			
		default:
			system("cls");
			break;


		}





	}









	return 0;
}