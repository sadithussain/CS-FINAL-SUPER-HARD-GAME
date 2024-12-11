#include "Armor.h"

#include <string>
using namespace std;

Armor::Armor(){
  name = "None";
  health = 0;
  strength = 0;
}

Armor::Armor(string NAME, int hp, int str){
  name = NAME;
  health = hp;
  strength = str;
}

string Armor::getName(){
  return name;
}

int Armor::getHealth(){
  return health;
}

int Armor::getStrength(){
  return strength;
}
