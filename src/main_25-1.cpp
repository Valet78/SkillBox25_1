// Задание 25.4.1. Симулятор проведения операций
#include "25.4-1.h"

int main() {
    std::setlocale(LC_ALL, "Russian_Russia.1251");
//    setlocale(LC_ALL, "Russian");
//    system("chcp 1251");

    double startX, startY, stopX, stopY;
    std::wstring comm;
    bool stop;
    int step = 1;
    twoPoint scalpCoord, sutureCoord;


    do{
        stop = true;
        system ("cls");
        std::wcout << L"Симулятор проведения операций." << std::endl;
        std::wcout << L"Укажите действия из нижеперечисленных:" << std::endl;
        std::wcout << L"\t\"scalpel\"  - подать скальпель;" << std::endl;
        std::wcout << L"\t\"hemostat\" - установить зажим;" << std::endl;
        std::wcout << L"\t\"tweezers\" - удержать пинцетом;" << std::endl;
        std::wcout << L"\t\"suture\"   - зашить разрез;" << std::endl;
        comm = inputComm(L"Ваши действия: ");
        comm = truncSpaces(comm);


        if(!(comm ==L"scalpel" || comm == L"tweezers" || comm == L"suture" || comm ==L"hemostat")) {
            std::wcout << L"Используйте только команды, указанные выше!" << std::endl;
            stop = false;

        } else {

            if (step == 1) {
                if (comm == L"scalpel") {

                    scalpCoord = askTwoPoint(L"Укажите через пробел координаты начала и конца разреза (x1 y1 x2 y2):");
                    instrScalpel(scalpCoord);

                    step++;
                } else {
                    std::wcerr << L"Для начала воспользуйтесь скальпелем (scalpel)." << std::endl;
                    stop = false;
                }

            } else if (step > 1) {
                if (comm == L"hemostat") {

                }


            }




    //                stop &= (comm == "suture" && scalpCoord.stop.x == );



        }

        system ("pause");
    } while (stop);
    //    std::wcout << L"Проверка кода вывода sdasdfas!" << std::endl;


//    std::wcout << as << std::endl;



    system("pause");
    return 0;
}

// *************************************
/*
// Отсечение пробелов в строке с двух сторон
std::string truncSpaces(std::string &inTxt) {
    inTxt = std::regex_replace(inTxt, std::regex("^\\s+"), "");
    inTxt = std::regex_replace(inTxt, std::regex("\\s+$"), "");
    return inTxt;
}




// Инструмент скальпель
twoPoint instrScalpel(double &stX, double &stY, double &fnX, double &fnY){
    twoPoint *sp = new twoPoint;
    sp->start.x = stX;
    sp->start.y = stY;
    sp->stop.x = fnX;
    sp->stop.y = fnY;
    std::wcout << L"Выполнен разрез из точки (" << std::to_wstring(sp->start.x) << L","
               << std::to_wstring(sp->start.y) << L") до точки ("
               << std::to_wstring(sp->stop.x) << L","
               << std::to_wstring(sp->stop.y) << L")" <<std::endl;
    return *sp;
}

// Инструмент зажим
onePoint instrHemostat(double &stX, double &stY){
    onePoint *hs;
    hs->x = stX;
    hs->y = stY;
    std::wcout << L"Выполнен зажим в точке (" << std::to_wstring(hs->x) << L","
               << std::to_wstring(hs->y) << L")" << std::endl;
    return *hs;
}

// Инструмент пинцет
onePoint instrTweezers(double &stX, double &stY){
    onePoint *tz;
    tz->x = stX;
    tz->y = stY;
    std::wcout << L"Выполнен перехват в точке (" << std::to_wstring(tz->x) << L","
               << std::to_wstring(tz->y) << L")" << std::endl;
    return *tz;
}

// Инструмент игла
twoPoint instrSuture(double &stX, double &stY, double &fnX, double &fnY){
    twoPoint *st;
    st->start.x = stX;
    st->start.y = stY;
    st->stop.x = fnX;
    st->stop.y = fnY;
    std::wcout << L"Наложены швы из точки (" << std::to_wstring(st->start.x) << L","
               << std::to_wstring(st->start.y) << L") до точки ("
               << std::to_wstring(st->stop.x) << L","
               << std::to_wstring(st->stop.y) << L")" <<std::endl;
    return *st;
}

// Ввод команды с проверкой
std::string inputText(std::wstring &&inTxt){
    std::string res;
    do{
        std::wcout << inTxt;
        std::getline(std::cin, res);

        if(res.empty()){
            std::wcerr <<L"Вы забыли ввести команду! Попробуйте снова." << std::endl;
        }

    } while(res.empty());

    return truncSpaces(res);
}

// Запрос координат двух точек
onePoint askOnePoint(std::wstring &&) {




}


// Запрос координат четырёх точек
twoPoint askTwoPoint(std::wstring &&) {




}
 */