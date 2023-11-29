#ifndef __ELF_H__
#define __ELF_H__

#include <iostream>
#include "Character.h"

class Elf : public Character {
    private:
        string familyName;
    
    public:
        Elf(const string &, double, double, const string &);
        const string & getFamilyName() const;
        void attack(Character &) override;
};

#endif