#include "Character.h"

#include <string>
#include <iostream>

using namespace std;

Character::Character(string n, int h, int s){
  name = n;
  health = h;
  strength = s;
  potions = 2;
}

string Character::getName(){
  return name;
}

int Character::getHealth(){
  return health;
}

int Character::getStrength(){
  return strength;
}

void Character::setName(string n){
  name = n;
}

void Character::setHealth(int h){
  health = h;
}

void Character::setStrength(int s){
  strength = s;
}

void Character::equipWeapon(Weapon w){
  weapon = w;
}

void Character::equipArmor(Armor a){
  armor = a;
}

Weapon Character::getWeapon(){
  return weapon;
}

Armor Character::getArmor(){
  return armor;
}

void Character::refillHealth(){
  currentHealth = health;
  potions = 2;
}

bool Character::isDead(){
  return currentHealth <= 0;
}

void Character::takeDamage(int d){
  currentHealth -= d;
}

int Character::getCurrentHealth(){
  return currentHealth;
}

void Character::usePotion(){
  if(potions > 0){
    currentHealth = health;
    potions--;
  }
  else{
    cout << "You have no potions left." << endl;
  }
}

int Character::getPotions(){
  return potions;
}