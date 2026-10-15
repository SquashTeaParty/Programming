#include "monster.hpp"
#include <iostream>
#include <string>

using namespace std;

// Init
Monster::Monster()
    : name(new string("none")), alive(new bool(false)), health(new double(0.)), wins(new int(0)) {
    cout << "[Monster init\t name: " << *name
         << ", alive: " << *alive
         << ", health: " << *health
         << ", wins: " << *wins << "]\n";
}
Monster::Monster(const string& newName, bool newAlive, double newHealth, int newWins)
    : name(new string(newName)), alive(new bool(newAlive)), health(new double(newHealth)), wins(new int(newWins)) {
    cout << "[Monster init\tname: " << *name
         << ", alive: " << *alive
         << ", health: " << *health
         << ", wins: " << *wins << "]\n";
}    
Monster::Monster(const string& newName)
    : name(new string(newName)), alive(new bool(true)), health(new double(1.0)), wins(new int(0)) {
    cout << "[Monster init\tname: " << *name
         << ", alive: " << *alive
         << ", health: " << *health
         << ", wins: " << *wins << "]\n";
}
Monster::Monster(const string& newName, double newHealth)
    : name(new string(newName)), alive(new bool(true)), health(new double(newHealth)), wins(new int(0)) {
    cout << "[Monster init\tname: " << *name
         << ", alive: " << *alive
         << ", health: " << *health
         << ", wins: " << *wins << "]\n";
}

// Destruct
Monster::~Monster() {
    cout << "[Monster " << *name << " deleted]\n";
    delete name;
    delete alive;
    delete health;
    delete wins;
}


// Set
void Monster::setName(const string& newName) {
    cout << "[setName\t" << *name << ": " << *name << " -> " << newName << "]\n";
    *name = newName;
}
void Monster::setAlive(bool newAlive) {
    cout << "[setAlive\t" << *name << ": " << *alive << " -> " << newAlive << "]\n";
    *alive = newAlive;
}
void Monster::setHealth(double newHealth) {
    cout << "[setHealth\t" << *name << ": " << *health << " -> " << newHealth << "]\n";
    *health = newHealth;
}
void Monster::setWins(int newWins) {
    cout << "[setWins\t" << *name << ": " << *wins << " -> " << newWins << "]\n";
    *wins = newWins;
}

// Get
string Monster::getName() const {
    cout << "[getName\t" << *name << "]\n";
    return *name;
}
bool Monster::isAlive() const {
    cout << "[isAlive\t" << *name << ": " << *alive << "]\n";
    return *alive;
}
double Monster::getHealth() const {
    cout << "[getHealth\t" << *name << ": " << *health << "]\n";
    return *health;
}
int Monster::getWins() const {
    cout << "[getWins\t" << *name << ": " << *wins << "]\n";
    return *wins;
}

// Methods
void Monster::Deal_Damage(Monster& targ, double dmg) {
    double tHp = targ.getHealth();
    string tName = targ.getName();
    cout << "[Deal damage " << *name << " -> " << tName <<"]\n";
    targ.setHealth(max(0.0, tHp - dmg));
}


// Funcs
void MonsterFight(Monster& A, Monster& B) {
    cout << "[MonsterFight]\n";

    double hpA = A.getHealth();
    double hpB = B.getHealth();

    if (!A.isAlive() || !B.isAlive()) {
        cout << "One of the monsters is dead. Fight is invalid!\n";
        return;
    }
    if (!hpA || !hpB) {
        cout << "One of the monsters is fainted. Fight is invalid!\n";
        return;
    }

    string nameA = A.getName();
    string nameB = B.getName();

    A.Deal_Damage(B, hpA);
    B.Deal_Damage(A, hpB);

    hpA = A.getHealth();
    hpB = B.getHealth();

    int winsA = A.getWins();
    int winsB = B.getWins();

    if (hpA == hpB) {
        cout << "Both monsters have fainted. No winner!\n";
    } else if (hpA > hpB) {
        A.setWins(winsA + 1);
        cout << nameA << " won! Wins: " << winsA + 1 << "\n";
    } else {
        B.setWins(winsB + 1);
        cout << nameB << " won! Wins: " << winsB + 1 << "\n";
    }
}