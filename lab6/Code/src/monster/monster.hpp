#pragma once
#include <string>

class Monster
{
    std::string* name_;
    bool*        alive_;
    double*      health_;
    int*         wins_;

    static void validate(const std::string& name, bool alive, double health, int wins);

    void cleanup() noexcept;

public:
    // Construct
    Monster();
    Monster(const std::string& name, bool alive, double health, int wins);

    // Copy
    Monster(const Monster& other);
    Monster& operator=(const Monster& other);
    
    // Move
    Monster(Monster&& other) noexcept;
    Monster& operator=(Monster&& other) noexcept;

    // Destructor
    ~Monster() noexcept;

    // Vars check
    bool validName(const std::string& name);
    bool validHealth(double health);
    bool validWins(int wins);

    // Set & Get
    void setName(const std::string& name);
    void setAlive(bool alive);
    void setHealth(double health);
    void setWins(int wins);

    std::string getName() const;
    bool        isAlive() const noexcept;
    double      getHealth() const noexcept;
    int         getWins() const noexcept;

    // Methods
    void Deal_Damage(Monster& targ, double dmg);
};

// Funcs
void MonsterFight(Monster& A, Monster& B);