#include <iostream>
#include <string>
#include "monster/monster.hpp"


using namespace std;

int main()
{
    Monster m1("Godzilla", true, 152.1, 0);
    Monster m2("Barsik", true, 0.5, 0);

    MonsterFight(m1, m2);
}