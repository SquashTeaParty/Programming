#include <iostream>
#include <string>
#include "scene/scene.hpp"
#include "monster/monster.hpp"
#include "monster/alien/alien.hpp"
#include "monster/energy/energy.hpp"

using namespace std;

int main() {
    Scene s1("Earth");

    cout << "\n---- Make a Monster ----\n";
    
    Energy* a = new Energy("GG", true, 2., 0, "Original", false);
    Alien* b = new Alien("Elon", true, 2., 0, "Nibiru", true);
    Monster* c = nullptr;
    int choice = 0;

    cout <<   "[1] Energy"
         << "\n[2] Alien"
         << "\nChoice: ";

    cin >> choice;
    if(choice != 1 && choice != 2) {
        cerr << "Error: try harder next time\n";
        return -1; 
    }
    switch (choice) 
    {
        case(1) :
            c = new Energy("Tornado", true, 2., 0, "Original", true);
            break;

        case(2) :
            c = new Alien("Elon", true, 14., 3, "Nebiru", false);
            break;
    }

    s1.Add(a);
    s1.Add(b);
    s1.Add(c);

    s1.Rumble();

    for(int i=0; i < s1.size(); i++) {
        delete s1.unit_[i];
    }
}