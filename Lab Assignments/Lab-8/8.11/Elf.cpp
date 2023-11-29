#include "Elf.h"

Elf::Elf(const string &name, double health, double attackStrength, const string &familyName) 
    : Character(ELF, name, health, attackStrength), familyName(familyName) { }

const string & Elf::getFamilyName() const { return familyName; }

void Elf::attack(Character &target) {
    if (target.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(target);
        if (opp.getFamilyName() == getFamilyName()) {
            cout << "Elf " << getName() << " does not attack Elf " << opp.getName() << '.' << endl
                 << "They are both members of the " << getFamilyName() << " family." << endl;
            return;
        }
    }
    double damageDealt = (health / MAX_HEALTH) * attackStrength;
    target.damage(damageDealt);
    cout << "Elf " << getName() << " shoots an arrow at " << target.getName() << " --- TWANG!!" << endl 
         << target.getName() << " takes " << damageDealt << " damage." << endl;
}