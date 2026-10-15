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
#include <string>
#include "monster/monster.hpp"
#include "monster/alien/alien.hpp"
#include "monster/energy/energy.hpp"

using namespace std;

int main() {
    cout << "---- Early ----\n";
    {
        Monster m("Godzilla", true, 152.1, 1488);
        Alien a("Zik", true, 150.0, 12, "idk", true);
        Energy e("Gorrila", true, 109.99, 3, "Original", false);

        m.Arrival();
        a.Arrival();
        e.Arrival();
    }

    cout << "\n---- Late ----\n";
    Monster* p = nullptr;
    int choice = 0;

    cout <<   "[1] Monster"
         << "\n[2] Alien"
         << "\nChoice: ";

    cin >> choice;
    if(choice != 1 && choice != 2) {
        cerr << "Error: try harder next time\n";
        return -1; 
    }
    switch (choice) 
    {
        case(1) :
            p = new Monster("Clown", true, 2., 0);
            break;

        case(2) :
            p = new Alien("Elon", true, 14., 3, "Nebiru", false);
            break;
    }

    p->Arrival();

    delete p;
}