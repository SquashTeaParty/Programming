#include "monster.hpp"
#include <iostream>
#include <string>
#include <limits>

bool Monster::Init(const std::string& newName, bool newAlive, double newHealth, int newWins) {
    if (newName.empty()) {
        std::cerr << "\t[Error:\tname must be set]\newName";
        return false;
    }
    if (newHealth < 0.0 || newHealth > 10000.0) {
        std::cerr << "\t[Error:\thealth must be more than 0.0 and less than 10000.0]\newName";
        return false;
    }
    if (newWins < 0) {
        std::cerr << "\t[Error:\twin count can't be negative]\newName";
        return false;
    }
    if (!newAlive && newHealth > 0.0) {
        std::cerr << "\t[Error:\tdeads must not be healthy]\newName";
        return false;
    }

    if (!name)      name = new std::string;
    if (!alive)     alive = new bool;
    if (!health)    health = new double;
    if (!wins)      wins = new int;

    *name   = newName;
    *alive  = newAlive;
    *health = newHealth;
    *wins   = newWins;
    return true;
}

// Construct
Monster::Monster()
    : name(nullptr), alive(nullptr), health(nullptr), wins(nullptr) 
{
    if (!Init("Unknown", true, 1.0, 0)) std::cout << "[Monster can't be created]\n";
    else                                std::cout << "[Monster init\t name: " << *name
                                                  << ", alive: " << *alive
                                                  << ", health: " << *health
                                                  << ", wins: " << *wins << "]\n";
}
Monster::Monster(const std::string& newName, bool newAlive, double newHealth, int newWins)
    : name(nullptr), alive(nullptr), health(nullptr), wins(nullptr) 
{
    if (!Init(newName, newAlive, newHealth, newWins)) std::cout << "[Monster can't be created]\n";
    else                                              std::cout << "[Monster init\t name: " << *name
                                                                << ", alive: " << *alive
                                                                << ", health: " << *health
                                                                << ", wins: " << *wins << "]\n";
}

// Destruct
Monster::~Monster() {
    std::cout << "[Monster " << *name << " deleted]\n";
    delete name;
    delete alive;
    delete health;
    delete wins;
}


// Set
void Monster::setName(const std::string& newName) {
    if (!Init(newName, *alive, *health, *wins)) std::cout << "[New name can't be set]\n";
    else                                        std::cout << "[setName\t" << *name << ": " << *name << " -> " << newName << "]\n";
}
void Monster::setAlive(bool newAlive) {
    if (!Init(*name, newAlive, *health, *wins)) std::cout << "[New alive value can't be set]\n";
    else                                        std::cout << "[setAlive\t" << *name << ": " << *alive << " -> " << newAlive << "]\n";
}
void Monster::setHealth(double newHealth) {
    if (!Init(*name, *alive, newHealth, *wins)) std::cout << "[New health value can't be set]\n";
    else                                        std::cout << "[setHealth\t" << *name << ": " << *health << " -> " << newHealth << "]\n";
}
void Monster::setWins(int newWins) {
    if (!Init(*name, *alive, *health, newWins)) std::cout << "[New wins value can't be set]\n";
    else                                        std::cout << "[setWins\t" << *name << ": " << *wins << " -> " << newWins << "]\n";
}

// Get
std::string Monster::getName() const {
    std::cout << "[getName\t" << *name << "]\n";

    return *name;
}
bool Monster::isAlive() const {
    std::cout << "[isAlive\t" << *name << ": " << *alive << "]\n";

    return *alive;
}
double Monster::getHealth() const {
    std::cout << "[getHealth\t" << *name << ": " << *health << "]\n";

    return *health;
}
int Monster::getWins() const {
    std::cout << "[getWins\t" << *name << ": " << *wins << "]\n";

    return *wins;
}

// Methods
void Monster::Deal_Damage(Monster& targ, double dmg) {
    double tHp = targ.getHealth();
    std::string tName = targ.getName();

    std::cout << "[Deal damage " << *name << " -> " << tName <<"]\n";
    targ.setHealth(std::max(0.0, tHp - dmg));
}


// Funcs
void MakeMonster() {
    std::cout << "Make your monster!\n";

    std::string name;
    std::cout << "\tName: ";
    std::cin >> name;
    while(name.empty()){
        std::cin.clear();        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "+";
}

void MonsterFight(Monster& A, Monster& B) {
    std::cout << "[MonsterFight]\n";

    double hpA = A.getHealth();
    double hpB = B.getHealth();

    if (!A.isAlive() || !B.isAlive()) {
        std::cout << "One of the monsters is dead. Fight is invalid!\n";
        return;
    }
    if (!hpA || !hpB) {
        std::cout << "One of the monsters is fainted. Fight is invalid!\n";
        return;
    }

    std::string nameA = A.getName();
    std::string nameB = B.getName();

    A.Deal_Damage(B, hpA);
    B.Deal_Damage(A, hpB);

    hpA = A.getHealth();
    hpB = B.getHealth();

    int winsA = A.getWins();
    int winsB = B.getWins();

    if (hpA == hpB) {
        std::cout << "Both monsters have fainted. No winner!\n";
    } else if (hpA > hpB) {
        A.setWins(winsA + 1);
        std::cout << nameA << " won! Wins: " << winsA + 1 << "\n";
    } else {
        B.setWins(winsB + 1);
        std::cout << nameB << " won! Wins: " << winsB + 1 << "\n";
    }
}