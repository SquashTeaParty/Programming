#pragma once
#include <string>

class Monster
{
    std::string* name;
    bool* alive;
    double* health;
    int* wins;

    bool Init(const std::string& newName, bool newAlive, double newHealth, int newWins);

public:
    // Construct
    Monster();
    Monster(const std::string& newName, bool newAlive, double newHealth, int newWins);

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

    // Methods
    void Deal_Damage(Monster& targ, double dmg);
};

// Funcs
void MakeMonster();
void MonsterFight(Monster& A, Monster& B);