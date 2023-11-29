#include "Wizard.h"

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) 
    : Character(WIZARD, name, health, attackStrength), rank(rank) { }

int Wizard::getRank() const { return rank; }

void Wizard::attack(Character &target) {
    double damageDealt = 0;
    if (target.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(target);
        damageDealt = attackStrength * (static_cast<double>(getRank()) / static_cast<double>(opp.getRank()));
    }
    else {
        damageDealt = attackStrength;
    }

    target.damage(damageDealt);
    cout << "Wizard " << getName() << " attacks " << target.getName() << " --- POOF!!" << endl
         << target.getName() << " takes " << damageDealt << " damage." << endl;
}