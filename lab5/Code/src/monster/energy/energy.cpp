#include "energy.hpp"
#include <iostream>

void Energy::cleanup_energy() noexcept
{
    delete taste_; taste_ = nullptr;
    delete sugar_; sugar_ = nullptr;
}

Energy::Energy()
    : Monster(), taste_(nullptr), sugar_(nullptr)
{
    try {
        taste_ = new std::string("Original");
        sugar_ = new bool(true);
        std::cout << "[Energy init\t taste: " << *taste_ << ", sugar: " << *sugar_ << "]\n";
    }
    catch (...) {
        cleanup_energy();
        throw;
    }
}

Energy::Energy(const std::string& name, bool alive, double health, int wins, const std::string& taste, bool sugar)
    : Monster(name, alive, health, wins), taste_(nullptr), sugar_(nullptr)
{
    try {
        taste_ = new std::string(taste);
        sugar_ = new bool(sugar);
        std::cout << "[Energy init\t taste: " << *taste_ << ", sugar: " << *sugar_ << "]\n";
    }
    catch (...) {
        cleanup_energy();
        throw;
    }
}

Energy::Energy(const Energy& other)
    : Monster(other), taste_(nullptr), sugar_(nullptr)
{
    try {
        taste_ = new std::string(*other.taste_);
        sugar_ = new bool(*other.sugar_);
    }
    catch (...) {
        cleanup_energy();
        throw;
    }
}

Energy& Energy::operator=(const Energy& other)
{
    if (this == &other) return *this;

    std::string* newTaste = nullptr;
    bool*        newSugar = nullptr;

    try {
        newTaste = new std::string(*other.taste_);
        newSugar = new bool(*other.sugar_);
    }
    catch (...) {
        delete newTaste;
        delete newSugar;
        throw;
    }

    Monster::operator=(other);
    cleanup_energy();
    
    taste_ = newTaste;
    sugar_ = newSugar;

    return *this;
}

Energy::Energy(Energy&& other) noexcept
    : Monster(std::move(other)), taste_(other.taste_), sugar_(other.sugar_)
{
    other.taste_ = nullptr;
    other.sugar_ = nullptr;
}

Energy& Energy::operator=(Energy&& other) noexcept
{
    if (this == &other) return *this;

    Monster::operator=(std::move(other));
    cleanup_energy();

    taste_ = other.taste_;
    sugar_ = other.sugar_;

    other.taste_ = nullptr;
    other.sugar_ = nullptr;

    return *this;
}

Energy::~Energy() noexcept
{
    std::cout << "[Energy " << getName() << " deleted]\n";
    cleanup_energy();
}

void Energy::setTaste(const std::string& taste)
{
    std::cout << "[setTaste\t" << *taste_ << " -> " << taste << "]\n";
    *taste_ = taste;
}

void Energy::setSugar(bool sugar)
{
    std::cout << "[setSugar\t" << *sugar_ << " -> " << sugar << "]\n";
    *sugar_ = sugar;
}

std::string Energy::getTaste() const          { return *taste_; }
bool        Energy::hasSugar() const noexcept { return *sugar_; }
