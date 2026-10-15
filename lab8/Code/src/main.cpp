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
    cout << "\n---- Make a Monster ----\n";
    
    Energy* e = new Energy("GG", true, 2., 0, "Original", false);
    Monster* p = nullptr;
    int choice = 0;

    cout <<   "[1] Energy"
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
            p = new Energy("Tornado", true, 2., 0, "Original", true);
            break;

        case(2) :
            p = new Alien("Elon", true, 14., 3, "Nebiru", false);
            break;
    }

    p->Arrival();
    e->Arrival();

    MonsterFight(*p, *e);

    delete p;
}