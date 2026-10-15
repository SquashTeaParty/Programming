#pragma once
#include "monster.hpp"
#include <string>

class Energy : public Monster
{
    std::string* taste_;
    bool*        sugar_;

    void cleanup_energy() noexcept;

public:
    // Constructor
    Energy();
    Energy(const std::string& name, bool alive, double health, int wins, const std::string& taste, bool sugar);
    
    // Copy
    Energy(const Energy& other);
    Energy& operator=(const Energy& other);

    // Move
    Energy(Energy&& other) noexcept;
    Energy& operator=(Energy&& other) noexcept;

    // Destructor
    ~Energy() noexcept;

    // Set & Get
    void setTaste(const std::string& taste);
    void setSugar(bool sugar);

    std::string getTaste() const;
    bool        hasSugar() const noexcept;
};
