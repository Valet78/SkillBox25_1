// Файл с функциями

#include "25.4-1.h"

// Отсечение пробелов в строке с двух сторон
std::wstring truncSpaces(std::wstring &inTxt) {
//    inTxt.replace(inTxt, std::wregex(L"^\\s+"), "");
    inTxt = std::regex_replace(inTxt, std::wregex(L"^\\s+"), L"");
    inTxt = std::regex_replace(inTxt, std::wregex(L"\\s+$"), L"");
    return inTxt;
}

// Инструмент скальпель
void instrScalpel(twoPoint &inTP){
    std::wcout << L"Выполнен разрез из точки (" << std::to_wstring(inTP.start.x) << L","
               << std::to_wstring(inTP.start.y) << L") до точки ("
               << std::to_wstring(inTP.stop.x) << L","
               << std::to_wstring(inTP.stop.y) << L")" <<std::endl;
}

// Инструмент зажим
void instrHemostat(onePoint &inOP){
    std::wcout << L"Выполнен зажим в точке (" << std::to_wstring(inOP.x) << L","
               << std::to_wstring(inOP.y) << L")" << std::endl;
}

// Инструмент пинцет
 void instrTweezers(onePoint &inOP){
     std::wcout << L"Выполнен перехват в точке (" << std::to_wstring(inOP.x) << L","
               << std::to_wstring(inOP.y) << L")" << std::endl;
}

// Инструмент игла
void instrSuture(twoPoint &inTP){
     std::wcout << L"Наложены швы из точки (" << std::to_wstring(inTP.start.x) << L","
               << std::to_wstring(inTP.start.y) << L") до точки ("
               << std::to_wstring(inTP.stop.x) << L","
               << std::to_wstring(inTP.stop.y) << L")" <<std::endl;
}

// Ввод команды с проверкой
std::wstring inputComm(std::wstring &&inTxt){
    std::wstring res;
    do{
        std::wcout << inTxt;
        std::getline(std::wcin, res);

        if(res.empty()){
            std::wcerr <<L"Вы забыли ввести команду! Попробуйте снова." << std::endl;
        }

    } while(res.empty());

    return truncSpaces(res);
}

// Ввод текста с проверкой
std::wstring inputText(std::wstring &inTxt) {
    std::wstring res;
    do{
        std::wcout << inTxt;
        std::getline(std::wcin, res);

        if(res.empty()){
            std::wcerr <<L"Вы забыли ввести координаты! Попробуйте снова." << std::endl;
        }

    } while(res.empty());

    return truncSpaces(res);
}

// Запрос координат двух точек
onePoint askOnePoint(std::wstring &&inTxt) {
    onePoint tempPoint;
    bool valid = false;
    std::wstring tmpTxt;
    std::vector <std::wstring> substr;

    do{
        std::wstring coordTxt = inputText(inTxt);
        std::wstringstream ss(coordTxt);
        substr.clear();

        while(std::getline(ss, tmpTxt, L' ')){
            substr.push_back(tmpTxt);
        }

        if(substr.size() == 2) {
            valid = true;

            for (auto sub : substr){
                valid &= validDoubleNum(sub);
            }
        }

        if(!valid){
            std::wcerr << L"Введены неверные данные! Попробуйте снова." << std::endl;
        }

    } while (!valid);

    tempPoint.x = std::stod(substr[0]);
    tempPoint.y = std::stod(substr[1]);

    return tempPoint;
}

// Запрос координат четырёх точек
twoPoint askTwoPoint(std::wstring &&inTxt) {
    twoPoint tempPoint;
    bool valid = false;
    std::wstring tmpTxt;
    std::vector <std::wstring> substr;

    do{
        std::wstring coordTxt = inputText(inTxt);
        std::wstringstream ss(coordTxt);
        substr.clear();

        while(std::getline(ss, tmpTxt, L' ')){
            substr.push_back(tmpTxt);
        }

        if(substr.size() == 4) {
            valid = true;

            for (auto sub : substr){
                valid &= validDoubleNum(sub);
            }
        }

        if(!valid){
            std::wcerr << L"Введены неверные данные! Попробуйте снова." << std::endl;
        }

    } while (!valid);

    tempPoint.start.x = std::stod(substr[0]);
    tempPoint.start.y = std::stod(substr[1]);
    tempPoint.stop.x = std::stod(substr[2]);
    tempPoint.stop.y = std::stod(substr[3]);

    std::wcout << L"It`s OK!!! - " << std::to_wstring(tempPoint.start.x + tempPoint.stop.x) << std::endl;

    return tempPoint;
}

// Проверка правильности ввода числа double
bool validDoubleNum(std::wstring &inTxt) {
    bool valid = true;
    int num = 0;

    for(auto ch : inTxt){

        if(ch == '.' && num == 0) {
            valid &= true;
            num++;
        } else if(ch >= '0' && ch <= '9'){
            valid &= true;
        } else {
            valid &= false;
        }
    }

    return valid;
}