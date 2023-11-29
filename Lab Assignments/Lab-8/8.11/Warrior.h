#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include <iostream>
#include "Character.h"

class Warrior : public Character {
    private:
        string allegiance;
    
    public:
        Warrior(const string &, double, double, const string &);
        const string & getAllegiance() const;
        void attack(Character &) override;
};

#endif