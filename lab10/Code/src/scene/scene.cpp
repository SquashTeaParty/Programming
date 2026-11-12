#include <iostream>
#include <algorithm>
#include "scene.hpp"

// Constructor
    Scene::Scene()
        : environment_(new std::string("Unknown")) {}

    Scene::Scene(const std::string& env)
        : environment_(new std::string(env)) {}

// Destructor
    Scene::~Scene() noexcept
    {
            unit_.clear();
            delete environment_; environment_ = nullptr;
    }
    
// Total units count
    std::size_t Scene::size() const noexcept { return unit_.size(); }

// Set/Get
    void        Scene::SetEnvironment(const std::string& env) { *environment_ = env; }
    std::string Scene::GetEnvironment() const noexcept        { return *environment_; }

// Unit
    void Scene::Add(Monster* m)    { unit_.push_back(m); }
    void Scene::Remove(Monster* m) { unit_.erase(std::remove(unit_.begin(), unit_.end(), m), unit_.end()); }


// Methods
    void Scene::Rumble()
    {
        if (unit_.empty()) {
            std::cout << "The scene is empty!\n";
            return;
        }
        for (Monster* m : unit_) {
            m->Arrival();
        }
    }

    void Scene::Attack(Monster* Attacker, Monster* Target)
    {
        if (!Attacker || !Target) return;
        Attacker->Deal_Damage(*Target, 100.0);
    }