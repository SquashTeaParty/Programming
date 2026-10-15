#pragma once
#include <string>

class Monster
{
    std::string name;
    bool alive;
    double health;
    int wins;

public:
    // Init
    Monster();
    Monster(const std::string& name, bool alive, double health, int wins);

    // Set
    void setName(const std::string& newName);
    void setAlive(bool newAlive);
    void setHealth(double newHealth);
    void setWins(int newWins);

    // Get
    std::string getName() const;
    bool getAlive() const;
    double getHealth() const;
    int getWins() const;
};

void MonsterFight(Monster& A, Monster& B);