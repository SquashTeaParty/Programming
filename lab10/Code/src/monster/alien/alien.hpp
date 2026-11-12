#pragma once
#include "monster.hpp"
#include <string>

class Alien : public Monster
{
    std::string* planet_;
    bool*        probing_;

    void cleanup_alien() noexcept;

public:
    // Construct
        Alien();
        Alien(const std::string& name, bool alive, double health, int wins, const std::string& planet, bool probing);

    // Copy
        Alien(const Alien& other);
        Alien& operator=(const Alien& other);

    // Move
        Alien(Alien&& other) noexcept;
        Alien& operator=(Alien&& other) noexcept;

    // Destructor
        ~Alien() noexcept override;

    // Set & Get
        void setPlanet(const std::string& planet);
        void setProbing(bool probing);

        std::string getPlanet()  const;
        bool        isProbing()  const noexcept;

    // Methods
        void Arrival() const override;
};
