#include "Weapon.h"

#include <string>
using namespace std;

Weapon::Weapon(){
  name = "None";
  damage = 0;
  luck = 0;
}

Weapon::Weapon(string NAME, int DAMAGE, int LUCK) {
  name = NAME;
  damage = DAMAGE;
  luck = LUCK;
}

string Weapon::getName(){
  return name;
}

int Weapon::getDamage(){
  return damage;
}

int Weapon::getLuck(){
  return luck;
}