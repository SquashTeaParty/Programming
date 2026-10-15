#include <iostream>
#include <string>
#include "monster/monster.hpp"
#include "monster/alien/alien.hpp"
#include "monster/energy/energy.hpp"

using namespace std;

int main()
{
    // cout << "--------------------------------------\n\tMonster Fight\n--------------------------------------\n\n";
    // MakeMonster();
    Monster m1("Godzilla", true, 152.1, 1488);


    Alien m2;
    Energy m3;

    MonsterFight(m1, m2);
    MonsterFight(m1, m3);
    m1.Deal_Damage(m1, 666.0);
}
