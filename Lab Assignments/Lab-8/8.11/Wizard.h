#ifndef __WIZARD_H__
#define __WIZARD_H__

#include <iostream>
#include "Character.h"

class Wizard : public Character {
    private:
        int rank;
    
    public:
        Wizard(const string &, double, double, int);
        int getRank() const;
        void attack(Character &) override;
};

#endif