#include "Warrior.h"

Warrior::Warrior(const string &name, double health, double attackStrength, const string &allegiance) 
    : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) { }

const string & Warrior::getAllegiance() const { return allegiance; }

void Warrior::attack(Character &target) {
    if (target.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(target);
        if (opp.getAllegiance() == getAllegiance()) {
            cout << "Warrior " << getName() << " does not attack Warrior " << opp.getName() << '.' << endl
                 << "They share an allegiance with " << getAllegiance() << '.' << endl;
            return;
        }
    }
    double damageDealt = (health / MAX_HEALTH) * attackStrength;
    target.damage(damageDealt);
    cout << "Warrior " << getName() << " attacks " << target.getName() << " --- SLASH!!" << endl 
         << target.getName() << " takes " << damageDealt << " damage." << endl;
}