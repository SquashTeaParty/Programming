#include "monster.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

Monster::Monster() : name("none"), alive(false), health(0.), wins(0) {
    cout << "[Monster init\t name: " << name
         << ", alive: " << alive
         << ", health: " << health
         << ", wins: " << wins << "]\n";
}

Monster::Monster(const string& name, bool alive, double health, int wins)
    : name(name), alive(alive), health(health), wins(wins) {
    cout << "[Monster init\tname: " << name
         << ", alive: " << alive
         << ", health: " << health
         << ", wins: " << wins << "]\n";
}

void Monster::setName(const string& newName) {
    cout << "[setName\t" << name << ": " << name << " -> " << newName << "]\n";
    name = newName;
}
void Monster::setAlive(bool newAlive) {
    cout << "[setAlive\t" << name << ": " << alive << " -> " << newAlive << "]\n";
    alive = newAlive;
}
void Monster::setHealth(double newHealth) {
    cout << "[setHealth\t" << name << ": " << health << " -> " << newHealth << "]\n";
    health = newHealth;
}
void Monster::setWins(int newWins) {
    cout << "[setWins\t" << name << ": " << wins << " -> " << newWins << "]\n";
    wins = newWins;
}

string Monster::getName() const {
    cout << "[getName\t" << name << "]\n";
    return name;
}
bool Monster::getAlive() const {
    cout << "[getAlive\t" << name << ": " << alive << "]\n";
    return alive;
}
double Monster::getHealth() const {
    cout << "[getHealth\t" << name << ": " << health << "]\n";
    return health;
}
int Monster::getWins() const {
    cout << "[getWins\t" << name << ": " << wins << "]\n";
    return wins;
}

void MonsterFight(Monster& A, Monster& B) {
    cout << "[MonsterFight]\n";
    if (!A.getAlive() || !B.getAlive()) {
        cout << "One of the monsters is dead. Fight is invalid!\n";
        return;
    }

    double hpA = A.getHealth();
    double hpB = B.getHealth();
    string nameA = A.getName();
    string nameB = B.getName();
    int winsA = A.getWins();
    int winsB = B.getWins();

    if (hpA == hpB) {
        A.setHealth(0); B.setHealth(0);
        A.setAlive(false); B.setAlive(false);
        cout << "Both monsters died. No winner!\n";
    } else if (hpA > hpB) {
        A.setHealth(hpA - hpB);
        B.setHealth(0);
        B.setAlive(false);
        A.setWins(winsA + 1);
        cout << nameA << " won! Wins: " << winsA + 1 << "\n";
    } else {
        B.setHealth(hpB - hpA);
        A.setHealth(0);
        A.setAlive(false);
        B.setWins(winsB + 1);
        cout << nameB << " won! Wins: " << winsB + 1 << "\n";
    }
}