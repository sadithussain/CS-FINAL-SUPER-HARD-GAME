#ifndef ARMOR_H
#define ARMOR_H

#include <string>
using namespace std;

class Armor{
private:
string name;
int luck;
int strength;
int health;

public:
Armor();
Armor(string NAME, int hp, int LUCK, int str);
string getName();
int getHealth();
int getStrength();
int getLuck();
void equipArmor();
}
