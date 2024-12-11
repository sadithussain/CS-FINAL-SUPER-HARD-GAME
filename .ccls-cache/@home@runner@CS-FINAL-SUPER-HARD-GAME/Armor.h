#ifndef ARMOR_H
#define ARMOR_H

#include <string>
using namespace std;

class Armor{
private:
string name;
int strength;
int health;

public:
Armor();
Armor(string NAME, int hp, int str);
string getName();
int getHealth();
int getStrength();
};
#endif
