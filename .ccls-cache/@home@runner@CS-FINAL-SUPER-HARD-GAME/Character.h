#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include "Armor.h"

#include <string>

using namespace std;

class Character{
private:
  string name;
  int health;
  int currentHealth;
  int strength;
  
  Weapon weapon;
  Armor armor;

  int potions;
public:
  Character(string n, int h, int s);

  string getName();
  int getHealth();
  int getStrength();

  void setName(string n);
  void setHealth(int h);
  void setStrength(int s);

  void equipWeapon(Weapon w);
  void equipArmor(Armor a);

  Weapon getWeapon();
  Armor getArmor();

  void refillHealth();
  bool isDead();
  void takeDamage(int d);
  int getCurrentHealth();

  void usePotion();
  int getPotions();
};

#endif