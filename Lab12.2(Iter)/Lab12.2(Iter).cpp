// Lab12.2(Iter).cpp
// Михайлов Олександр
// Опрацювання лінійного однонаправленого списку
// Варіант 24

#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem {
	Elem* link;
	Info info;
};

void push(Elem* &top, Info value) {
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = top;
	top = tmp;
}

Info pop(Elem*& top) {
	Elem* tmp = top->link;
	Info value = top->info;
	delete top;
	top = tmp;
	return value;
}

void ElemAmount(int& amount) {
	do {
		cout << " Введіть кількість елементів: "; cin >> amount;
		if (amount < 1) {
			cout << " Кількість має бути не меньше 1!" << endl;
		}
	} while (amount < 1);
}

void SumElemNumPositiveInfo(int value, int elemnum, int& result) {
	if (value > 0) {
		result += elemnum;
	}
}

void EnterValues(Elem*& top, int amount, int& result) {
	int value;
	for (int i = 1; i <= amount; i++) {
		cout << " Введіть значення інформаційного поля в елементі №" << i << " : "; cin >> value;
		SumElemNumPositiveInfo(value, i, result);
		push(top, value);
	}
}

void DeleteAndPrint(Elem*& top) {
	cout << endl << endl;
	cout << " Значення: ";
	while (top != NULL) {
		cout << pop(top) << " ";
	}
	cout << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* top = NULL;

	int amount = 0, result = 0;

	ElemAmount(amount);
	EnterValues(top, amount, result);
	DeleteAndPrint(top);
	cout << " Сума елементів списку із додатними значеннями інформаційного поля: " << result << endl;

	return 0;
}