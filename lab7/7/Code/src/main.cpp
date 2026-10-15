/*
    Выпонил:
        Студент группы: ПМИ-251
        Илалов Всеволод Маркович
        
    Что делает:
        Создает двух монстров и заставляет их сражаться
        
    На входе:
        Входные данные
    
    На выходе:
        Результат выполнения программы
*/
#include <iostream>
#include <cmath>
#include <memory>
#include <string>
#include "figure/figure.hpp"

using namespace std;

int main()
{
    cout    << "Pick figure:\n"
            << "\t[1] Circle\n"
            << "\t[2] Rectangle\n"
            << "Choice: ";

    int choice;
    cin >> choice;
    if (choice != 1 && choice != 2) {
        cerr << "Erorr: next time try harder\n"; 
        return -1; 
    }

    unique_ptr<Figure> fig = nullptr;
    switch(choice)
    {
        case(1) :
            cout << "Enter radius value: ";

            double radius;
            cin >> radius;

            fig = make_unique<Circle>(abs(radius));

            break;

        case(2) :
            cout << "Enter width value: ";

            double width;
            cin >> width;

            cout << "Enter length value: ";

            double length;
            cin >> length;

            fig = make_unique<Rectangle>(abs(width),abs(length));
            
            break;
    }

    cout << "Area = " << fig->calcArea() << "\n";
}