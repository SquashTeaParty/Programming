#include "energy.hpp"
#include <iostream>

// Clean
    void Energy::cleanup_energy() noexcept
    {
        delete taste_; taste_ = nullptr;
        delete sugar_; sugar_ = nullptr;
    }

// Constuct
    Energy::Energy()
        : Monster(), taste_(nullptr), sugar_(nullptr)
    {
        try {
            taste_ = new std::string("Original");
            sugar_ = new bool(true);
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
        }
        catch (...) {
            cleanup_energy();
            throw;
        }
    }

// Copy
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

// Move
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

// Destruct
    Energy::~Energy() noexcept
    {
        cleanup_energy();
    }

// Setters
    void Energy::setTaste(const std::string& taste)
    {
        *taste_ = taste;
    }

    void Energy::setSugar(bool sugar)
    {
        *sugar_ = sugar;
    }

// Getters
    std::string Energy::getTaste() const          { return *taste_; }
    bool        Energy::hasSugar() const noexcept { return *sugar_; }


// Methods
    void Energy::Arrival() const {
        if(hasSugar()){
            std::cout << getTaste() << " " << getName() << " arrived and ready to cause heart attacks!\n";
        } else {
            std::cout << getTaste() << " no sugar " << getName() << " arrived and ready to cause heart attacks!\n";
        }
    }
