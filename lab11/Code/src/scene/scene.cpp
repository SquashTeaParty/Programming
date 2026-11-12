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

    Monster* Scene::Create(const std::string& type)
    {
        if (type == "alien")   return new Alien();
        if (type == "energy")  return new Energy();

        throw MonsterError("unknown monster type: " + type);
    }


// Methods
    void Scene::Rumble()
    {
        //log("Info", "Start");
        if (unit_.empty()) {
            std::cout << "The scene is empty!\n";
            return;
        }
        for (Monster* m : unit_) {
            if(m->isAlive()) m->Arrival();
        }
        //log("Info", "End");
    }

    void Scene::Attack(Monster* Attacker, Monster* Target)
    {
        if (!Attacker || !Target) return;
        Attacker->Deal_Damage(*Target, 100.0);
    }

// Set Monster's vars
    void Scene::SetAlienPlanet(Monster* m, const std::string& planet)
    {
        if (auto* a = dynamic_cast<Alien*>(m))
            a->setPlanet(planet);
    }
    void Scene::SetAlienProbing(Monster* m, bool probing)
    {
        if (auto* a = dynamic_cast<Alien*>(m))
            a->setProbing(probing);
    }

    void Scene::SetEnergyTaste(Monster* m, const std::string& taste)
    {
        if (auto* e = dynamic_cast<Energy*>(m))
            e->setTaste(taste);
    }
    void Scene::SetEnergySugar(Monster* m, bool sugar)
    {
        if (auto* e = dynamic_cast<Energy*>(m))
            e->setSugar(sugar);
    }