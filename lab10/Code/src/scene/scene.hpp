#pragma once
#include "../log/log.hpp"
#include <string>
#include <vector>
#include <cstddef>
#include "../monster/monster.hpp"
#include "../monster/alien/alien.hpp"
#include "../monster/energy/energy.hpp"

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
        static Monster* Create(const std::string& type);

    // Methods
        void Rumble();
        void Attack(Monster* Attacker, Monster* Target);

// Set Monster's vars
    void SetAlienPlanet(Monster* m, const std::string& planet);
    void SetAlienProbing(Monster* m, bool probing);

    void SetEnergyTaste(Monster* m, const std::string& taste);
    void SetEnergySugar(Monster* m, bool sugar);
};