#include "pch.h"
#include <iostream>
#include <string>
#include <map>

#include <vector>
using namespace std;

int main() {
	int Q;
	string command;
	string country;
	string capital;
	string old_capital;
	string old_country_name;
	string new_country_name;
	string out;
	map<string, string> m;
	vector<string> output;
	cin >> Q; //Вводим число запросов

	while (Q != 0) { //Проводим Q операций
		cin >> command; //Вводим команду
		if (command == "CHANGE_CAPITAL") {
			Q--;
			cin >> country;
			cin >> capital;

			if (m[country] == "") {
				m[country] = capital;
				output.push_back("Introduce new country " + country + " with capital " + capital);
			}
			else {
				if (m[country] != capital) {
					old_capital = m[country];
					m[country] = capital;
					output.push_back("Country " + country + " has changed its capital from " + old_capital + " to " + capital);
				}
				else {
					output.push_back("Country " + country + " hasn't changed its capital");
				}
			}
		}
		if (command == "RENAME") {
			Q--;
			cin >> old_country_name;
			cin >> new_country_name;
			if (old_country_name != new_country_name && m[old_country_name] != "") {
				m[new_country_name] = m[old_country_name];
				output.push_back("Country " + old_country_name + " with capital " + m[old_country_name] + " has been renamed to " + new_country_name);
			}
			else {
				output.push_back("Incorrect rename, skip");
			}
			m.erase(old_country_name);

		}
		if (command == "ABOUT") {
			Q--;
			cin >> country;
			if (m[country] != "") {
				output.push_back("Country " + country + " has capital " + m[country]);
			}
			else {
				m.erase(country);
				output.push_back("Country " + country + " doesn't exist");
			}
		}
		if (command == "DUMP") {
			Q--;
			if (m.size() != 0) {
				out = "";
				for (auto c : m) {
					if (out == "") {
						out = (c.first + "/" + c.second);
					}
					else {
						out += (" " + c.first + "/" + c.second);
					}
				}
				output.push_back(out);
			}
			else {
				output.push_back("There are no countries in the world");
			}
		}
	}
	for (string c : output) {
		cout << c << endl;
	}
	system("pause");
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
