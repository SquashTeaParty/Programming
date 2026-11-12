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
        cerr << "Error: try harder next time\n";
        DeleteScene(s1);
        
        return -1;
    }

    switch (choice)
    {
        case(1) :
            c = Scene::Create("energy");
            break;

        case(2) :
            c = Scene::Create("alien");
            break;
    }
    
    if (auto* e = dynamic_cast<Energy*>(c)) {
        s1.SetEnergyTaste(e, "Original");
        s1.SetEnergySugar(e, false);
    } else if (auto* al = dynamic_cast<Alien*>(c)) {
        s1.SetAlienPlanet(al, "Nebiru");
        s1.SetAlienProbing(al, false);
    }

    s1.Add(a);
    s1.Add(b);
    s1.Add(c);

    s1.Attack(a, b);

    s1.Rumble();

    DeleteScene(s1);

    log("Info", "End");

    return 0;
}