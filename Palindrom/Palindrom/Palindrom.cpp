// Palindrom.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include<conio.h>
#include "Palindrom.h"

using namespace std;

bool isPalindromA(string word)//Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево(пустая строка является палиндромом).
{
	int len = word.length();
	
	for (int i = 0; i < len / 2; i++)
	{
		if (word[i] != word[word.length() - i -1 ])//пишу -1, т.к. i при каждом заходе делает +1
		{
			return false;
		}
	}
	return true;
	
}
bool isPalindromB(string word)
{
	string OriginWord = word;
	reverse(begin(word),end(word));//Меняет порядок следования элементов в диапазоне (first, last) на противоположный.
	if (word == OriginWord)
	{
		return true;
	}
	return false;
}
bool LengthStrings(const vector<string>& words)
{
	for (auto s : words)
	{
		if (s.size() > 100)
		{
			return true;
		}
	}
	return false;
}
vector<string> PalindromFilter(const vector<string>& words, int minLength)
{
		/*vector<string> result;//вектор для вывода
		
		for ( auto s : words)//перебираем все строки
		{
			if (isPalindromA(s) && s.size() >= minLength)//если строка является палиндором и больше или равна нужной длинны, то записываем в вектор для вывода
			{
				result.push_back(s);
			}
		}
		return result;//новый вектор*/
	vector<string> result;
	if (words.size() < 100 && !LengthStrings(words)) {//Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.
		for (const auto s : words)
		{
			if (isPalindromA(s) && s.size() >= minLength) {
				result.push_back(s);
			}
		}
	}
	return result;
	
}

int main()
{

	string str;
	/* vector<string> vec = { "abba", "omo", "tabbat","arbat" };
    vector<string> result;
	result = PalindromFilter(vec, 3);
	cout << "Vector result: ";
	for (auto i : result){cout << i << ",";} */
	vector<string> result = PalindromFilter(vector<string>{"abba", "omo", "tabbat", "arbat"}, 4);//выводим на экран палиндромы размера не меньше 4
	cout << "Vector result: ";
	for (auto str : result)
	{
		cout << str << ", ";
	}
	cout << "\nEnter the word: ";
	int ch=_getch();
	if (ch == 13) cout << "This is palindrom";// Пустая строка является палиндромом
	/* switch (ch) { case 13:cout << "Word is palindrom."; } */
	cin >> str;
	
	if (isPalindromB(str))
	{
		cout << "Word is palindrom.";
		
	}
	else
	{
		cout << "Word is not palindrom";
	}
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
