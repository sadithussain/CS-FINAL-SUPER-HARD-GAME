#ifndef WEAPON_H
#define WEAPON_H

#include <string>
using namespace std;

class Weapon{
private:
  string name;
  int damage;
  int luck;

public:
  Weapon();
  Weapon(string NAME, int DAMAGE, int LUCK);
  string getName();
  int getDamage();
  int getLuck();
};

#endif