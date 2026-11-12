#pragma once
#include <string>
#include <vector>
#include <cstddef>
#include "../monster/monster.hpp"

class Scene
{
    std::string*          environment_;
    
public:
    
    std::vector<Monster*> unit_;

    // Constructor
        Scene();
        Scene(const std::string& env);

    // Destructor
        ~Scene() noexcept;

    // Total units count
        std::size_t size() const noexcept;

    // Set/Get
        void        SetEnvironment(const std::string& env);
        std::string GetEnvironment() const noexcept;

    // Unit
        void Add(Monster* unit);
        void Remove(Monster* unit);

    // Methods
        void Rumble();
        void Attack(Monster* Attacker, Monster* Target);
};