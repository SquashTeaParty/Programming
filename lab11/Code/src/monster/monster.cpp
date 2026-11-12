#include "monster.hpp"
#include <iostream>
#include <stdexcept>

// Validate
    void Monster::validate(const std::string& name, bool alive, double health, int wins)
    {
        if (name.empty())                           throw std::invalid_argument("name must be set");
        if (health < 0.0 || health > 10000.0)       throw std::out_of_range("health must be in [0.0, 10000.0]");
        if (wins < 0)                               throw MonsterError("wins can't be negative");
        //if (!alive && health > 0.0)                 throw MonsterError("dead monster must have zero health"); 
    }

// Clean
    void Monster::cleanup() noexcept
    {
        delete name_;   name_   = nullptr;
        delete alive_;  alive_  = nullptr;
        delete health_; health_ = nullptr;
        delete wins_;   wins_   = nullptr;
    }

// Constuct
    Monster::Monster()
        : name_(nullptr), alive_(nullptr), health_(nullptr), wins_(nullptr)
    {
        try {
            name_   = new std::string("Unknown");
            alive_  = new bool(true);
            health_ = new double(1.0);
            wins_   = new int(0);
        }
        catch (...) {
            cleanup();
            throw;
        }
    }
    Monster::Monster(const std::string& name, bool alive, double health, int wins)
        : name_(nullptr), alive_(nullptr), health_(nullptr), wins_(nullptr)
    {
        validate(name, alive, health, wins);

        try {
            name_   = new std::string(name);
            alive_  = new bool(alive);
            health_ = new double(health);
            wins_   = new int(wins);
        }
        catch (...) {
            cleanup();
            throw;
        }
    }

// Copy
    Monster::Monster(const Monster& other)
        : name_(nullptr), alive_(nullptr), health_(nullptr), wins_(nullptr)
    {
        try {
            name_   = new std::string(*other.name_);
            alive_  = new bool(*other.alive_);
            health_ = new double(*other.health_);
            wins_   = new int(*other.wins_);
        }
        catch (...) {
            cleanup();
            throw;
        }
    }
    Monster& Monster::operator=(const Monster& other)
    {
        if (this == &other) return *this;

        std::string* newName   = nullptr;
        bool*        newAlive  = nullptr;
        double*      newHealth = nullptr;
        int*         newWins   = nullptr;

        try {
            newName   = new std::string(*other.name_);
            newAlive  = new bool(*other.alive_);
            newHealth = new double(*other.health_);
            newWins   = new int(*other.wins_);
        }
        catch (...) {
            delete newName; 
            delete newAlive; 
            delete newHealth; 
            delete newWins;

            throw;
        }

        cleanup();
        name_   = newName;
        alive_  = newAlive;
        health_ = newHealth;
        wins_   = newWins;

        return *this;
    }

// Move
    Monster::Monster(Monster&& other) noexcept
        : name_(other.name_), alive_(other.alive_), health_(other.health_), wins_(other.wins_)
    {
        other.name_ = nullptr;
        other.alive_ = nullptr;
        other.health_ = nullptr;
        other.wins_ = nullptr;
    }
    Monster& Monster::operator=(Monster&& other) noexcept
    {
        if (this == &other) return *this;
        cleanup();
        name_   = other.name_;
        alive_  = other.alive_;
        health_ = other.health_;
        wins_   = other.wins_;
        other.name_ = nullptr;
        other.alive_ = nullptr;
        other.health_ = nullptr;
        other.wins_ = nullptr;

        return *this;
    }

// Destruct
    Monster::~Monster() noexcept
    {
        cleanup();
    }

// Vars check
    bool Monster::validName(const std::string& name)
    {
        if (name.empty()) {
            std::cerr << "[Error: name must be set]\n";
            return false;
        }
            return true;
    }
    bool Monster::validHealth(double health)
    {
        if (health < 0 || health > 10000) {
            std::cerr << "[Error: health must be in [0.0, 10000.0]]\n";
            return false;
        }
            return true;
    }
    bool Monster::validWins(int wins)
    {
        if (wins < 0) {
            std::cerr << "[Error: wins can't be negative]\n";
            return false;
        }
            return true;
    }

// Setters
    void Monster::setName(const std::string& name)
    {
        if(validName(name)) {
            *name_ = name;
        }
    }
    void Monster::setAlive(bool alive)
    {
        // if (!alive) {
        //     *health_ = 0.0;
        // } else if (*health_ <= 0.0) {
        //     *health_ = 1.0;
        // }
        *alive_ = alive;
    }
    void Monster::setHealth(double health)
    {
        if (validHealth(health)) {
            *health_ = health;
        }
    }
    void Monster::setWins(int wins)
    {
        if (validWins(wins)) {
            *wins_ = wins;
        }
    }

// Getters
    std::string Monster::getName() const                { return *name_; }
    bool        Monster::isAlive()  const noexcept      { return *alive_; }
    double      Monster::getHealth() const noexcept     { return *health_; }
    int         Monster::getWins()  const noexcept      { return *wins_; }

// Methods
    void Monster::Deal_Damage(Monster& targ, double dmg) const
    {
        log("Info", targ.getName() + " health: " + std::to_string(targ.getHealth()) + " --> " + std::to_string(std::max(0.0, targ.getHealth() - dmg)) );
        targ.setHealth(std::max(0.0, targ.getHealth() - dmg));
    }

    void Monster::Arrival() const {
        // Maybe will be needed?
    }

// Funcs
    void MonsterFight(Monster& A, Monster& B) {
        // Probably will not be needed
    }