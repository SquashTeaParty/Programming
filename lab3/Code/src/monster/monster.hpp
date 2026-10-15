#pragma once
#include <string>

class Monster
{
    std::string* name;
    bool* alive;
    double* health;
    int* wins;

public:
    // Init
    Monster();
    Monster(const std::string& name);
    Monster(const std::string& name, double health);
    Monster(const std::string& name, bool alive, double health, int wins);

    // Destruct
    ~Monster();

    // Set
    void setName(const std::string& newName);
    void setAlive(bool newAlive);
    void setHealth(double newHealth);
    void setWins(int newWins);

    // Get
    std::string getName() const;
    bool isAlive() const;
    double getHealth() const;
    int getWins() const;

    // Funcs
    void Deal_Damage(Monster& targ, double dmg);
};

void MonsterFight(Monster& A, Monster& B);