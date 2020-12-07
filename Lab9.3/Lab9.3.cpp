// Lab9.3.cpp
// �������� ���������
// ����������� ������ ��������
// ������ 24

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct Worker {
	int workerNum;
	string surname;
	string initials;
	string posada;
	int year;
	int salary;
};

void CreateTable(Worker* w, const int amount);

void PrintTable(Worker* w, const int amount);

void AddRow_PrintRow(Worker* w, const int amount);

void DeleteRow_PrintTable(Worker* w, const int amount);

void ChangeName(Worker* w, const int amount, int rownumber);

void ChangeInit(Worker* w, const int amount, int rownumber);

void ChangePosada(Worker* w, const int amount, int rownumber);

void ChangeYear(Worker* w, const int amount, int rownumber);

void ChangeSalary(Worker* w, const int amount, int rownumber);

void ChangeRowInf_PrintTable(Worker* w, const int amount);

void ChangeTable(Worker* w, const int amount);

void SortSurname(Worker* w, const int amount);

void SortSalary(Worker* w, const int amount);

void SortYear(Worker* w, const int amount);

void SortTableMenu(Worker* w, const int amount);

void ShowInfoWorker(Worker* w, const int amount);

void MainMenu(Worker* w, const int amount);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int workerAmount = 0, premenu = 0;

	do {
		cout << "������ ������� ��������: "; cin >> workerAmount;
		if (workerAmount < 1) {
			cout << "ʳ������ ���������� �� ���� ���� ������ ������!" << endl;
		}
	} while (workerAmount < 1);
	Worker* w = new Worker[workerAmount];

	do {
		cout << endl << endl;
		cout << "������� ��:" << endl;
		cout << " [1] - ��������� �������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> premenu;

		switch (premenu) {
		case 1:
			cout << endl << "�������� �������:" << endl;
			
			CreateTable(w, workerAmount);

			cout << endl << " ������� ������ ���������!" << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! ��� ������ ����� - ����� ��������� ������ ����!" << endl;
			break;
		}

		if (premenu == 1) {
			MainMenu(w, workerAmount);
		}
	} while (premenu != 0);

	return 0;
}

void CreateTable(Worker* w, const int amount) {
	for (int i = 0; i < amount; i++) {
		w[i].workerNum = i + 1;
		cout << "���������� � " << w[i].workerNum << ": " << endl;
		cin.get();
		cin.sync();
		cout << "   �������: "; getline(cin, w[i].surname);
		cout << "	�������: "; getline(cin, w[i].initials);
		cout << "	������: "; getline(cin, w[i].posada);

		do {
			cout << "	г� �������: "; cin >> w[i].year;
			if (w[i].year > 2020 || w[i].year < 2000)
				cout << "�� ����� ���������� �� ������� �� ������!" << endl;
		} while (w[i].year > 2020 || w[i].year < 2000);

		do {
			cout << "	��������: "; cin >> w[i].salary;
			if (w[i].salary > 100000)
				cout << "����� � ��������� ���� ���� ��������!" << endl;
			else if (w[i].salary < 5000)
				cout << "�� ����� �������� ������, �� �������� � �����!" << endl;
		} while (w[i].salary > 100000 || w[i].salary < 5000);

		cout << endl;
	}
}

void PrintTable(Worker* w, const int amount) {
	cout << "===================================================================================" << endl;
	cout << "| � | ������� ��������� | ������� | ������ ��������� | г� ��������� | �������� |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < amount; i++) {
		cout << "| " << left << w[i].workerNum << " ";
		cout << "| " << setw(18) << left << w[i].surname
			<< " | " << setw(8) << left << w[i].initials
			<< " | " << setw(16) << left << w[i].posada
			<< " | " << setw(13) << left << w[i].year
			<< " | " << setw(8) << left << w[i].salary
			<< " | " << endl;
	}

	cout << "===================================================================================" << endl << endl;
}

void AddRow_PrintRow(Worker* w, const int amount) {
	int rowplus, newAmount;
	do {
		cout << endl << "������ ������ ����� ������: "; cin >> rowplus;
		if (rowplus < 1)
			cout << "�� ���� ���� ������ ������ 1 �����!" << endl;
	} while (rowplus < 1);

	newAmount = amount + rowplus;

	Worker* k = new Worker[newAmount];

	for (int i = 0; i < amount; i++) {
		k[i].workerNum = w[i].workerNum;
		k[i].surname = w[i].surname;
		k[i].initials = w[i].initials;
		k[i].posada = w[i].posada;
		k[i].year = w[i].year;
		k[i].salary = w[i].salary;
	}

	for (int j = 1, i = amount; i < newAmount; j++, i++) {
		k[i].workerNum = amount + j;
		cout << "���������� � " << k[i].workerNum << ": " << endl;
		cin.get();
		cin.sync();
		cout << "   �������: "; getline(cin, k[i].surname);
		cout << "	�������: "; getline(cin, k[i].initials);
		cout << "	������: "; getline(cin, k[i].posada);

		do {
			cout << "	г� �������: "; cin >> k[i].year;
			if (k[i].year > 2020 || k[i].year < 2000)
				cout << "�� ����� ���������� �� ������� �� ������!" << endl;
		} while (k[i].year > 2020 || k[i].year < 2000);

		do {
			cout << "	��������: "; cin >> k[i].salary;
			if (k[i].salary > 100000)
				cout << "����� � ��������� ���� ���� ��������!" << endl;
			else if (k[i].salary < 5000)
				cout << "�� ����� �������� ������, �� �������� � �����!" << endl;
		} while (k[i].salary > 100000 || k[i].salary < 5000);

		cout << endl;
	}
	PrintTable(k, newAmount);
}

void DeleteRow_PrintTable(Worker* w, const int amount) {
	int deleteNum;

	do {
		cout << endl << "������ ����� �����, ���� ����� ��������: "; cin >> deleteNum;
		if (deleteNum > amount || deleteNum < 1)
			cout << "������ ����� �� ����!" << endl;
	} while (deleteNum > amount || deleteNum < 1);

	cout << "===================================================================================" << endl;
	cout << "| � | ������� ��������� | ������� | ������ ��������� | г� ��������� | �������� |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < amount; i++) {
		if (i + 1 != deleteNum) {
			cout << "| " << left << w[i].workerNum << " ";
			cout << "| " << setw(18) << left << w[i].surname
				<< " | " << setw(8) << left << w[i].initials
				<< " | " << setw(16) << left << w[i].posada
				<< " | " << setw(13) << left << w[i].year
				<< " | " << setw(8) << left << w[i].salary
				<< " | " << endl;
		}
	}

	cout << "===================================================================================" << endl << endl;
}

void ChangeName(Worker* w, const int amount, int rownumber) {
	cout << "������� �������: " << w[rownumber - 1].surname << endl;
	cout << "������ ���� �������: ";
	cin.get();
	cin.sync();
	getline(cin, w[rownumber - 1].surname);
	cout << "������� ������ ������!" << endl;
}

void ChangeInit(Worker* w, const int amount, int rownumber) {
	cout << "������ �������: " << w[rownumber - 1].initials << endl;
	cout << "������ ��� �������: ";
	cin.get();
	cin.sync();
	getline(cin, w[rownumber - 1].initials);
	cout << "������� ������ ������!" << endl;
}

void ChangePosada(Worker* w, const int amount, int rownumber) {
	cout << "������� ������: " << w[rownumber - 1].posada << endl;
	cout << "������ ���� ������: ";
	cin.get();
	cin.sync();
	getline(cin, w[rownumber - 1].posada);
	cout << "������ ������ ������!" << endl;
}

void ChangeYear(Worker* w, const int amount, int rownumber) {
	cout << "�������� �� ���������: " << w[rownumber - 1].year << endl;
	do {
		cout << "������ ����� �� ���������: "; cin >> w[rownumber - 1].year;
		if (w[rownumber - 1].year > 2020 || w[rownumber - 1].year < 2000) {
			cout << "�� ����� ���������� �� ������� �� ������!" << endl;
		}
	} while (w[rownumber - 1].year > 2020 || w[rownumber - 1].year < 2000);
	cout << "г� ��������� ������ ������!" << endl;
}

void ChangeSalary(Worker* w, const int amount, int rownumber) {
	cout << "������� ��������: " << w[rownumber - 1].salary << endl;
	do {
		cout << "������ ���� ��������: "; cin >> w[rownumber - 1].salary;
		if (w[rownumber - 1].salary > 100000)
			cout << "����� � ��������� ���� ���� ��������!" << endl;
		else if (w[rownumber - 1].salary < 5000)
			cout << "�� ����� �������� ������, �� �������� � �����!" << endl;
	} while (w[rownumber - 1].salary > 100000 || w[rownumber - 1].salary < 5000);
	cout << "�������� ������ ������!" << endl;
}

void ChangeRowInf_PrintTable(Worker* w, const int amount) {
	int rownumber,changemenu;
	do {
		cout << endl << "������ ����� �����, ���� ������� ����������: "; cin >> rownumber;
		if (rownumber < 1 || rownumber > amount) {
			cout << "������ ����� �� ����!" << endl;
		}
	} while (rownumber < 1 || rownumber > amount);

	do {
		cout << endl << endl;
		cout << "������� ��:" << endl;
		cout << " [1] - ������ �������" << endl;
		cout << " [2] - ������ �������" << endl;
		cout << " [3] - ������ ����� ������" << endl;
		cout << " [4] - ������ �� ���������" << endl;
		cout << " [5] - ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> changemenu;

		switch (changemenu) {
		case 1:
			ChangeName(w, amount, rownumber);
			break;
		case 2:
			ChangeInit(w, amount, rownumber);
			break;
		case 3:
			ChangePosada(w, amount, rownumber);
			break;
		case 4:
			ChangeYear(w, amount, rownumber);
			break;
		case 5:
			ChangeSalary(w, amount, rownumber);
			break;
		default:
			cout << "�� ����� ��������� ��������! ��� ������ ����� - ����� ��������� ������ ����!" << endl;
			break;
		}
	} while (changemenu != 1 && changemenu != 2 && changemenu != 3 && changemenu != 4 && changemenu != 5);
}

void ChangeTable(Worker* w, const int amount) {
	int changetablemenu = 0;

	do {
		cout << endl << endl;
		cout << "������� ��:" << endl;
		cout << " [1] - ������ ����� �� ������� �������" << endl;
		cout << " [2] - �������� ����� �� ������� �������" << endl;
		cout << " [3] - ���������� ���������� � ����� �� ������� �������" << endl << endl;
		cout << "������ ��������: "; cin >> changetablemenu;

		switch (changetablemenu) {
		case 1:
			AddRow_PrintRow(w, amount);
			break;
		case 2:
			DeleteRow_PrintTable(w, amount);
			break;
		case 3:
			ChangeRowInf_PrintTable(w, amount);
			break;
		default:
			cout << "�� ����� ��������� ��������! ��� ������ ����� - ����� ��������� ������ ����!" << endl;
			break;
		}
	} while (changetablemenu != 1 && changetablemenu != 2 && changetablemenu != 3);
}

void SortSurname(Worker* w, const int amount) {
	Worker help;
	for (int i0 = 0; i0 < amount - 1; i0++)
		for (int i1 = 0; i1 < amount - i0 - 1; i1++)
			if ((w[i1].surname > w[i1 + 1].surname)) {
				help = w[i1];
				w[i1] = w[i1 + 1];
				w[i1 + 1] = help;
			}
	cout << endl << "������� ������ �����������!" << endl;
}

void SortSalary(Worker* w, const int amount) {
	Worker help;
	for (int i0 = 0; i0 < amount - 1; i0++)
		for (int i1 = 0; i1 < amount - i0 - 1; i1++)
			if ((w[i1].salary < w[i1 + 1].salary)) {
				help = w[i1];
				w[i1] = w[i1 + 1];
				w[i1 + 1] = help;
			}
	cout << endl << "������� ������ �����������!" << endl;
}

void SortYear(Worker* w, const int amount) {
	Worker help;
	for (int i0 = 0; i0 < amount - 1; i0++)
		for (int i1 = 0; i1 < amount - i0 - 1; i1++)
			if ((w[i1].year < w[i1 + 1].year)) {
				help = w[i1];
				w[i1] = w[i1 + 1];
				w[i1 + 1] = help;
			}
	cout << endl << "������� ������ �����������!" << endl;
}

void SortTableMenu(Worker* w, const int amount) {
	int sorttablemenu;
	do {
		cout << endl << endl;
		cout << "������� ��:" << endl;
		cout << " [1] - ����������� �� ��������" << endl;
		cout << " [2] - ����������� �� ���������" << endl;
		cout << " [3] - ����������� �� ����� �������" << endl;
		cout << "������ ��������: "; cin >> sorttablemenu;

		switch (sorttablemenu) {
		case 1:
			SortSurname(w, amount);
			break;
		case 2:
			SortSalary(w, amount);
			break;
		case 3:
			SortYear(w, amount);
			break;
		default:
			cout << "�� ����� ��������� ��������! ��� ������ ����� - ����� ��������� ������ ����!" << endl;
			break;
		}
	} while (sorttablemenu != 1 && sorttablemenu != 2 && sorttablemenu != 3);
}

void ShowInfoWorker(Worker* w, const int amount) {
	string surname;
	bool answer = false;
	int neededIndex = 0;

	do {
		cout << "������ ������� ��������, ���������� ��� ����� ������� �������: ";
		cin.get();
		cin.sync();
		getline(cin, surname);
		
		for (int i = 0; i < amount; i++) {
			if (surname == w[i].surname) {
				answer = true;
				neededIndex = i;
			}
		}
		if (answer == false) {
			cout << "��������� � ����� �������� ���� � �������!" << endl;
		}
	} while (answer == false);

	cout << endl;
	cout << "===================================================================================" << endl;
	cout << "| � | ������� ��������� | ������� | ������ ��������� | г� ��������� | �������� |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "| " << left << w[neededIndex].workerNum << " ";
	cout << "| " << setw(18) << left << w[neededIndex].surname
		<< " | " << setw(8) << left << w[neededIndex].initials
		<< " | " << setw(16) << left << w[neededIndex].posada
		<< " | " << setw(13) << left << w[neededIndex].year
		<< " | " << setw(8) << left << w[neededIndex].salary
		<< " | " << endl;
	cout << "===================================================================================" << endl;
}

void MainMenu(Worker* w, const int amount) {
	int mainMenu = 0;
	
	do {
		cout << endl << endl;
		cout << "������� ��:" << endl;
		cout << " [1] - ������� ��������� �������" << endl;
		cout << " [2] - ���������� ��������� �������" << endl;
		cout << " [3] - ��������� �������" << endl;
		cout << " [4] - ������� ���������� ��� ����������� ���������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> mainMenu;

		switch (mainMenu) {
		case 1:
			PrintTable(w, amount);
			break;
		case 2:
			ChangeTable(w, amount);
			break;
		case 3:
			SortTableMenu(w, amount);
			break;
		case 4:
			ShowInfoWorker(w, amount);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! ��� ������ ����� - ����� ��������� ������ ����!" << endl;
			break;
		}
	} while (mainMenu != 0);
}