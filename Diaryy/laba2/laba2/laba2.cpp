#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void Remove(int day, vector<vector<string>>& tfd, string& task) {
	for (int i = 0; i < tfd[day - 1].size(); i++) {
		if (tfd[day - 1][i] == task) {
			tfd[day - 1].erase(tfd[day - 1].begin() + i);
		}
	}
}
void Next_month(int& index, const vector<int>& dim, vector<vector<string>>& tfd) {
	index++;
	if (index > 11)index = 0;
	vector<vector<string>> NewMonth = tfd;//создает новый вектор и копирует в него старый
	int a = tfd.size();// размер старого вектора
	int b = dim[index];//размер нового вектора
	tfd.resize(b);//меняет размер(обрезает или дописывает пустые значения)
	const int e = b - 1;//переменная для определения индекса последнего дня в новом месяце
	if (a > b) {//если старый больше нового, то
		for (b; a > b; b++) {//перебирает все дни, которые не влезли с прошлого месяца
			tfd[e].insert(end(tfd[e]), begin(NewMonth[b]), end(NewMonth[b]));//все задачи из дня старого месяца дописывает в конец последнего дня нового месяца.Возвращает итератор на элемент, следующий за последним 

		}
	}
	NewMonth.clear();
}

void Task_display(int day, const vector<vector<string>>& tfd) {
	cout << tfd[day - 1].size();
	for (auto i : tfd[day - 1]) {//перебирает все задачи в конкретном дне
		cout << " " << i;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int oper;
	cout << "Введите количество операций:";
	cin >> oper;
	vector<int> days_in_months = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<vector<string>> task_for_day;//вектор в каждом дне месяца
	int index_of_month = 0;
	task_for_day.resize(days_in_months[index_of_month], {});//увеличивает вектор до количества дней в текущем месяце
	for (int i = 0; oper > i; i++) {
		string comand;
		int day;
		string task;
		cout << "Введите команду(NEXT,DUMP,ADD,REMOVE):";
		cin >> comand;
		if (comand == "NEXT") {
			Next_month(index_of_month, days_in_months, task_for_day);
		}
		else if (comand == "DUMP") {
			cin >> day;
			Task_display(day, task_for_day);
		}
		else if (comand == "ADD") {
			cin >> day >> task;
			task_for_day[day - 1].push_back(task);//вставка в конец дня(модификатор)
		}
		else if (comand == "REMOVE") {
			cin >> day >> task;
			Remove(day, task_for_day, task);
		}
	}
}
