// Lab9.3.cpp
// Михайлов Олександр
// Опрацювання масиву структур
// Варіант 24

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
		cout << "Введіть кількість робітників: "; cin >> workerAmount;
		if (workerAmount < 1) {
			cout << "Кількість працівників не може бути меньше одного!" << endl;
		}
	} while (workerAmount < 1);
	Worker* w = new Worker[workerAmount];

	do {
		cout << endl << endl;
		cout << "Виберіть дію:" << endl;
		cout << " [1] - заповнити таблицю" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> premenu;

		switch (premenu) {
		case 1:
			cout << endl << "Заповніть таблицю:" << endl;
			
			CreateTable(w, workerAmount);

			cout << endl << " Таблиця успішно заповнена!" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! Слід ввести число - номер вибраного пункту меню!" << endl;
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
		cout << "Службовець № " << w[i].workerNum << ": " << endl;
		cin.get();
		cin.sync();
		cout << "   Прізвище: "; getline(cin, w[i].surname);
		cout << "	Ініціали: "; getline(cin, w[i].initials);
		cout << "	Посада: "; getline(cin, w[i].posada);

		do {
			cout << "	Рік прийому: "; cin >> w[i].year;
			if (w[i].year > 2020 || w[i].year < 2000)
				cout << "Ви ввели неможливий рік прийому на роботу!" << endl;
		} while (w[i].year > 2020 || w[i].year < 2000);

		do {
			cout << "	Зарплата: "; cin >> w[i].salary;
			if (w[i].salary > 100000)
				cout << "Навіть в директора немає такої зарплати!" << endl;
			else if (w[i].salary < 5000)
				cout << "Ви ввели зарплату меньше, ніж мінімальна в Україні!" << endl;
		} while (w[i].salary > 100000 || w[i].salary < 5000);

		cout << endl;
	}
}

void PrintTable(Worker* w, const int amount) {
	cout << "===================================================================================" << endl;
	cout << "| № | Прізвище службовця | Ініціали | Посада службовця | Рік прийняття | Зарплата |" << endl;
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
		cout << endl << "Введіть скільки рядків додати: "; cin >> rowplus;
		if (rowplus < 1)
			cout << "Не може бути додано меньше 1 рядка!" << endl;
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
		cout << "Службовець № " << k[i].workerNum << ": " << endl;
		cin.get();
		cin.sync();
		cout << "   Прізвище: "; getline(cin, k[i].surname);
		cout << "	Ініціали: "; getline(cin, k[i].initials);
		cout << "	Посада: "; getline(cin, k[i].posada);

		do {
			cout << "	Рік прийому: "; cin >> k[i].year;
			if (k[i].year > 2020 || k[i].year < 2000)
				cout << "Ви ввели неможливий рік прийому на роботу!" << endl;
		} while (k[i].year > 2020 || k[i].year < 2000);

		do {
			cout << "	Зарплата: "; cin >> k[i].salary;
			if (k[i].salary > 100000)
				cout << "Навіть в директора немає такої зарплати!" << endl;
			else if (k[i].salary < 5000)
				cout << "Ви ввели зарплату меньше, ніж мінімальна в Україні!" << endl;
		} while (k[i].salary > 100000 || k[i].salary < 5000);

		cout << endl;
	}
	PrintTable(k, newAmount);
}

void DeleteRow_PrintTable(Worker* w, const int amount) {
	int deleteNum;

	do {
		cout << endl << "Введіть номер рядка, який треба видалити: "; cin >> deleteNum;
		if (deleteNum > amount || deleteNum < 1)
			cout << "Такого рядка не існує!" << endl;
	} while (deleteNum > amount || deleteNum < 1);

	cout << "===================================================================================" << endl;
	cout << "| № | Прізвище службовця | Ініціали | Посада службовця | Рік прийняття | Зарплата |" << endl;
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
	cout << "Поточне прізвище: " << w[rownumber - 1].surname << endl;
	cout << "Введіть нове прізвище: ";
	cin.get();
	cin.sync();
	getline(cin, w[rownumber - 1].surname);
	cout << "Прізвище успішно змінено!" << endl;
}

void ChangeInit(Worker* w, const int amount, int rownumber) {
	cout << "Поточні ініціали: " << w[rownumber - 1].initials << endl;
	cout << "Введіть нові ініціали: ";
	cin.get();
	cin.sync();
	getline(cin, w[rownumber - 1].initials);
	cout << "Ініціали успішно змінено!" << endl;
}

void ChangePosada(Worker* w, const int amount, int rownumber) {
	cout << "Поточна посада: " << w[rownumber - 1].posada << endl;
	cout << "Введіть нову посаду: ";
	cin.get();
	cin.sync();
	getline(cin, w[rownumber - 1].posada);
	cout << "Посада успішно змінена!" << endl;
}

void ChangeYear(Worker* w, const int amount, int rownumber) {
	cout << "Поточний рік прийняття: " << w[rownumber - 1].year << endl;
	do {
		cout << "Введіть новий рік прийняття: "; cin >> w[rownumber - 1].year;
		if (w[rownumber - 1].year > 2020 || w[rownumber - 1].year < 2000) {
			cout << "Ви ввели неможливий рік прийому на роботу!" << endl;
		}
	} while (w[rownumber - 1].year > 2020 || w[rownumber - 1].year < 2000);
	cout << "Рік прийняття успішно змінено!" << endl;
}

void ChangeSalary(Worker* w, const int amount, int rownumber) {
	cout << "Поточна зарплата: " << w[rownumber - 1].salary << endl;
	do {
		cout << "Введіть нову зарплату: "; cin >> w[rownumber - 1].salary;
		if (w[rownumber - 1].salary > 100000)
			cout << "Навіть в директора немає такої зарплати!" << endl;
		else if (w[rownumber - 1].salary < 5000)
			cout << "Ви ввели зарплату меньше, ніж мінімальна в Україні!" << endl;
	} while (w[rownumber - 1].salary > 100000 || w[rownumber - 1].salary < 5000);
	cout << "Зарплата успішно змінена!" << endl;
}

void ChangeRowInf_PrintTable(Worker* w, const int amount) {
	int rownumber,changemenu;
	do {
		cout << endl << "Введіть номер рядка, який потрібно редагувати: "; cin >> rownumber;
		if (rownumber < 1 || rownumber > amount) {
			cout << "Такого рядка не існує!" << endl;
		}
	} while (rownumber < 1 || rownumber > amount);

	do {
		cout << endl << endl;
		cout << "Виберіть дію:" << endl;
		cout << " [1] - змінити прізвище" << endl;
		cout << " [2] - змінити ініціали" << endl;
		cout << " [3] - змінити назву посади" << endl;
		cout << " [4] - змінити рік прийняття" << endl;
		cout << " [5] - змінити зарплату" << endl << endl;
		cout << "Введіть значення: "; cin >> changemenu;

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
			cout << "Ви ввели помилкове значення! Слід ввести число - номер вибраного пункту меню!" << endl;
			break;
		}
	} while (changemenu != 1 && changemenu != 2 && changemenu != 3 && changemenu != 4 && changemenu != 5);
}

void ChangeTable(Worker* w, const int amount) {
	int changetablemenu = 0;

	do {
		cout << endl << endl;
		cout << "Виберіть дію:" << endl;
		cout << " [1] - додати рядок та вивести таблицю" << endl;
		cout << " [2] - вилучити рядок та вивести таблицю" << endl;
		cout << " [3] - редагувати інформацію у рядку та вивести таблицю" << endl << endl;
		cout << "Введіть значення: "; cin >> changetablemenu;

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
			cout << "Ви ввели помилкове значення! Слід ввести число - номер вибраного пункту меню!" << endl;
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
	cout << endl << "Таблиця успішно посортована!" << endl;
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
	cout << endl << "Таблиця успішно посортована!" << endl;
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
	cout << endl << "Таблиця успішно посортована!" << endl;
}

void SortTableMenu(Worker* w, const int amount) {
	int sorttablemenu;
	do {
		cout << endl << endl;
		cout << "Виберіть дію:" << endl;
		cout << " [1] - відсортувати за прізвищем" << endl;
		cout << " [2] - відсортувати за зарплатою" << endl;
		cout << " [3] - відсортувати за роком прийому" << endl;
		cout << "Введіть значення: "; cin >> sorttablemenu;

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
			cout << "Ви ввели помилкове значення! Слід ввести число - номер вибраного пункту меню!" << endl;
			break;
		}
	} while (sorttablemenu != 1 && sorttablemenu != 2 && sorttablemenu != 3);
}

void ShowInfoWorker(Worker* w, const int amount) {
	string surname;
	bool answer = false;
	int neededIndex = 0;

	do {
		cout << "Введіть прізвище службвця, інформацію про якого потрібно вивести: ";
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
			cout << "Службовця з таким прізвищем немає у таблиці!" << endl;
		}
	} while (answer == false);

	cout << endl;
	cout << "===================================================================================" << endl;
	cout << "| № | Прізвище службовця | Ініціали | Посада службовця | Рік прийняття | Зарплата |" << endl;
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
		cout << "Виберіть дію:" << endl;
		cout << " [1] - вивести початкову таблицю" << endl;
		cout << " [2] - корегувати початкову таблицю" << endl;
		cout << " [3] - сортувати таблицю" << endl;
		cout << " [4] - вивести інформацію про конкретного службовця" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> mainMenu;

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
			cout << "Ви ввели помилкове значення! Слід ввести число - номер вибраного пункту меню!" << endl;
			break;
		}
	} while (mainMenu != 0);
}