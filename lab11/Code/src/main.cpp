#include <iostream>
#include <string>
#include "log/log.hpp"
#include "scene/scene.hpp"
#include "monster/monster.hpp"
#include "monster/alien/alien.hpp"
#include "monster/energy/energy.hpp"

using namespace std;

// Tmp func
void DeleteScene(Scene& s)
{
    //log("Info", "Scene delete start");
    for (int i = 0; i < s.size(); ++i)
        delete s.unit_[i];
    //log("Info", "Scene delete end");
}

int main() {
    log("Info", "Start");

    try {
            Scene s1("Earth");

        Monster* a = Scene::Create("energy");
        Monster* b = Scene::Create("alien");
        Monster* c = nullptr;

        s1.SetEnergyTaste(a, "Tornado");
        s1.SetEnergySugar(a, true);
        s1.SetAlienPlanet(b, "Nibiru");
        s1.SetAlienProbing(b, true);

        cout << "\n---- Make a Monster ----\n";
        cout << "[1] Energy\n"
             << "[2] Alien\n"
             << "Choice: ";
        int choice = 0;
        cin >> choice;
        if (choice != 1 && choice != 2) {
            throw MonsterError("invalid monster type choice: " + std::to_string(choice));
        }

        cout << "\n\tEnter name: ";
        std::string name;
        cin >> name;

        cout << "\tEnter health [0, 10000]: ";
        double health = 0.0;
        cin >> health;

        cout << "\tEnter wins [>=0]: ";
        int wins = 0;
        cin >> wins;

        cout << "\tIs alive? [1/0]: ";
        int aliveInt = 1;
        cin >> aliveInt;
        bool alive = (aliveInt != 0);

        switch (choice)
        {
            case 1: {
                cout << "\tEnter taste: ";
                std::string taste;
                cin >> taste;

                cout << "\tHas sugar? [1/0]: ";
                int sugarInt = 1;
                cin >> sugarInt;
                bool sugar = (sugarInt != 0);

                c = new Energy(name, alive, health, wins, taste, sugar);
                s1.SetEnergyTaste(c, taste);
                s1.SetEnergySugar(c, sugar);
                break;
            }
            case 2: {
                cout << "\tEnter planet: ";
                std::string planet;
                cin >> planet;

                cout << "\tIs probing? [1/0]: ";
                int probingInt = 1;
                cin >> probingInt;
                bool probing = (probingInt != 0);

                c = new Alien(name, alive, health, wins, planet, probing);
                s1.SetAlienPlanet(c, planet);
                s1.SetAlienProbing(c, probing);
                break;
            }
        }

        s1.Add(a);
        s1.Add(b);
        s1.Add(c);

        s1.Attack(a, b);

        s1.Rumble();

        DeleteScene(s1);
    }

    catch (const MonsterError& e)                   { std::cerr << "[MonsterError] " << e.what() << "\n"; }
    catch (const std::out_of_range& e)              { std::cerr << "[out_of_range] " << e.what() << "\n"; }
    catch (const std::invalid_argument& e)          { std::cerr << "[invalid_argument] " << e.what() << "\n"; }
    catch (...)                                     { std::cerr << "[unknown error]\n"; }

    log("Info", "End");

    return 0;
}