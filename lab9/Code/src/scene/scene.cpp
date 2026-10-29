#include <iostream>
#include <algorithm>
#include "scene.hpp"

// Constructor
    Scene::Scene()
        : environment_(new std::string("Unknown"))
    {
        std::cout << "[Scene init\t environment: " << *environment_ << "]\n";
    }

    Scene::Scene(const std::string& env)
        : environment_(new std::string(env))
    {
        std::cout << "[Scene init\t environment: " << *environment_ << "]\n";
    }

// Destructor
    Scene::~Scene() noexcept
    {
        std::cout << "[Scene deleted]\n";
            unit_.clear();
            delete environment_; environment_ = nullptr;
    }

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