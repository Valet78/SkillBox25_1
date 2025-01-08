#pragma once

#include <iostream>
#include <locale>
#include <ctime>
#include <regex>
#include <vector>
//#include <istream>


// Глобальные переменные
struct onePoint{
    double x, y;
};
struct twoPoint{
    onePoint start, stop;
};


// Функции
std::wstring truncSpaces(std::wstring &);       // Отсечение пробелов в строке с двух сторон
std::wstring inputComm(std::wstring &&);        // Ввод команды с проверкой
std::wstring inputText(std::wstring &);         // Ввод текста с проверкой
onePoint askOnePoint(std::wstring &&);          // Запрос координат двух точек
twoPoint askTwoPoint(std::wstring &&);          // Запрос координат четырёх точек
void instrScalpel(twoPoint &);                  // Инструмент скальпель
void instrHemostat(onePoint &);                 // Инструмент зажим
void instrTweezers(onePoint &);                 // Инструмент пинцет
void instrSuture(twoPoint &);                   // Инструмент игла
bool validDoubleNum(std::wstring &);            // Проверка правильности ввода числа double