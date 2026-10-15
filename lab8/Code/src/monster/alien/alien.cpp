#include "alien.hpp"
#include <iostream>

// Clean
    void Alien::cleanup_alien() noexcept
    {
        delete planet_;  planet_  = nullptr;
        delete probing_; probing_ = nullptr;
    }

// Constuct
    Alien::Alien()
        : Monster(), planet_(nullptr), probing_(nullptr)
    {
        try {
            planet_  = new std::string("Aboba");
            probing_ = new bool(false);
            std::cout << "[Alien init\t planet: " << *planet_ << ", probing: " << *probing_ << "]\n";
        }
        catch (...) {
            cleanup_alien();
            throw;
        }
    }

    Alien::Alien(const std::string& name, bool alive, double health, int wins, const std::string& planet, bool probing)
        : Monster(name, alive, health, wins), planet_(nullptr), probing_(nullptr)
    {
        try {
            planet_  = new std::string(planet);
            probing_ = new bool(probing);
            std::cout << "[Alien init\t planet: " << *planet_ << ", probing: " << *probing_ << "]\n";
        }
        catch (...) {
            cleanup_alien();
            throw;
        }
    }

// Copy
    Alien::Alien(const Alien& other)
        : Monster(other), planet_(nullptr), probing_(nullptr)
    {
        try {
            planet_  = new std::string(*other.planet_);
            probing_ = new bool(*other.probing_);
        }
        catch (...) {
            cleanup_alien();
            throw;
        }
    }

    Alien& Alien::operator=(const Alien& other)
    {
        if (this == &other) return *this;

        std::string* newPlanet  = nullptr;
        bool*        newProbing = nullptr;

        try {
            newPlanet  = new std::string(*other.planet_);
            newProbing = new bool(*other.probing_);
        }
        catch (...) {
            delete newPlanet;
            delete newProbing;
            throw;
        }

        Monster::operator=(other);
        cleanup_alien();

        planet_  = newPlanet;
        probing_ = newProbing;

        return *this;
    }

// Move
    Alien::Alien(Alien&& other) noexcept
        : Monster(std::move(other)), planet_(other.planet_), probing_(other.probing_)
    {
        other.planet_  = nullptr;
        other.probing_ = nullptr;
    }

    Alien& Alien::operator=(Alien&& other) noexcept
    {
        if (this == &other) return *this;

        Monster::operator=(std::move(other));
        cleanup_alien();

        planet_  = other.planet_;
        probing_ = other.probing_;

        other.planet_  = nullptr;
        other.probing_ = nullptr;

        return *this;
    }

// Destruct
    Alien::~Alien() noexcept
    {
        std::cout << "[Alien " << getName() << " deleted]\n";
        cleanup_alien();
    }

// Setters
    void Alien::setPlanet(const std::string& planet)
    {
        std::cout << "[setPlanet\t" << *planet_ << " -> " << planet << "]\n";
        *planet_ = planet;
    }

    void Alien::setProbing(bool probing)
    {
        std::cout << "[setProbing\t" << *probing_ << " -> " << probing << "]\n";
        *probing_ = probing;
    }

// Getters
    std::string Alien::getPlanet() const           { return *planet_; }
    bool        Alien::isProbing() const noexcept  { return *probing_; }


// Methods
    void Alien::Arrival() const {
        std::cout << "[Arrival: Alien]\n";
        if(isProbing()){
            std::cout << getName() << " from " << getPlanet() << " arrived and ready to probe!\n";
        } else {
            std::cout << getName() << " from " << getPlanet() << " arrived and not ready to probe!\n";
        }
    }
    