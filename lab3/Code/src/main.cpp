#include <iostream>
#include <string>
#include "monster/monster.hpp"

using namespace std;

int main()
{
    Monster m1;
    m1.setName("Godzilla");
    m1.setAlive(true);
    m1.setHealth(152.1);
    m1.setWins(1488);


    Monster m2("zillaGod", 125.1);

    MonsterFight(m1, m2);

    // m1.Deal_Damage(m1, 666.0);
}
