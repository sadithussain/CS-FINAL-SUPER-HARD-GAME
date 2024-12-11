#include "Character.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

//We used the replit autofill ai to generate this code for us, we couldn't figure out how to clear terminal
void clearTerminal(){
  cout << "\033[2J\033[0;0H";
}

//we wanted a cool typing effect, so we used information from stack overflow
void typeEffect(const string& text) {
  int delay = 1; 
    for (char c : text) {
        cout << c << flush; // Print character and flush the output
        this_thread::sleep_for(chrono::milliseconds(delay)); // Delay
    }
    cout << endl; // Move to the next line after typing
}

void fight(Character& player, Character& enemy){
  int input;

  srand(time(0));
  bool crit;
  
  player.refillHealth();
  enemy.refillHealth();
  cout << "You: " << player.getHealth() << " HP" << endl;
  cout << "Enemy: " << enemy.getHealth() << " HP" << endl;
  cout << endl;
  if(player.getPotions() == 1){
    cout << "You have " << player.getPotions() << " potion." << endl;
  }
  else{
    cout << "You have " << player.getPotions() << " potions." << endl;
  }
  cout << endl;
  
  while(true){
    crit = (rand() % 100) < player.getWeapon().getLuck(); //if you get lucky, you'll hit a crit

    while(true){
      cout << "What will you do?" << endl;
      cout << "1. Attack" << endl;
      cout << "2. Use Potion" << endl;
      cout << endl;

      cin >> input;
      if(input != 1 && input != 2){
        cout << "Invalid input, try again." << endl;
        cout << endl;
        continue;
      }
      else if(input == 2 && player.getPotions() == 0){
        cout << "You have no potions left." << endl;
        cout << endl;
        continue;
      }
      else{
        break;
      }
    }

    if(input == 1){
      int damage;
  
      if(crit) {
        damage = player.getStrength() + player.getWeapon().getDamage() * 2;
        cout << "You hit a critical strike!\n";
      } 
      else {
        damage = player.getStrength() + player.getWeapon().getDamage();
      }
      
      cout << "You attack " << enemy.getName() << " for " << damage << " damage" << endl;
      cout << endl;
  
      enemy.takeDamage(damage);
  
      
      if(enemy.isDead()){
        clearTerminal();
        cout << "You defeated " << enemy.getName() << "!" << endl;
        cout << "       _      _                   \n      (_)    | |                  \n__   ___  ___| |_ ___  _ __ _   _ \n\\ \\ / / |/ __| __/ _ \\| '__| | | |\n \\ V /| | (__| || (_) | |  | |_| |\n  \\_/ |_|\\___|\\__\\___/|_|   \\__, |\n                             __/ |\n                            |___/ \n" << endl;
        return;
      }
    }
    else if(input == 2){
      player.usePotion();
      cout << "You used a potion, you are now at maximum health!" << endl;
      cout << endl;
    }
    
    bool attack = (rand() % 100) < 35;

    if (attack) {
      cout <<  enemy.getName() << " attacks you for " << enemy.getStrength() << " damage" << endl;
      cout << endl;
      player.takeDamage(enemy.getStrength());
      cout << endl;
    }

    if(player.isDead()){
      cout << enemy.getName() << " defeated you!" << endl;
      cout << endl;
      typeEffect("You have died and were unable to escape the dungeon ... will anyone ever be able to escape this nightmare?");
      cout << "\n     _       __           _   \n    | |     / _|         | |  \n  __| | ___| |_ ___  __ _| |_ \n / _` |/ _ \\  _/ _ \\/ _` | __|\n| (_| |  __/ ||  __/ (_| | |_ \n \\__,_|\\___|_| \\___|\\__,_|\\__|\n";
      cout << endl;
      return;
    }

    cout << "You: " << player.getCurrentHealth() << " HP" << endl;
    cout << "Enemy: " << enemy.getCurrentHealth() << " HP" << endl;
    cout << endl;
  }
}

int main() {
  /*you are a person trying  to escape a dungeon. there are 5 levels to this dungeon, each one containg a boss. you have to fight the boss to escape. you have a weapon, and a luck level.
*/

  string name;
  string answer;
  //cout << "What is your name, warrior?" << endl;
  typeEffect("What is your name, warrior?");
  getline(cin, name);
  Character player(name, 100, 10);
  
  clearTerminal();

  typeEffect("Greetings, " + player.getName() +"! You are currently in the bottom most floor of this dungeon. Now, if you want to escape, you must defeat the 5 great guards who protect each floor. Are you up for the challange?\n");
  
  //cout << "Greetings, " << name << "! You are currently in the bottom most floor of this dungeon. Now, if you want to escape, you must defeat the 5 great guards who protect each floor. Are you up for the challange?" << endl;

  cin >> answer;

  clearTerminal();
  
  if (answer == "yes" || answer == "Yes"){
    typeEffect("Very well! Take this rusty sword to fight the guards. After defeating the guards, you can pick up their weapons. The first guard is just down that hallway. Good luck brave warrior, we are all counting on you!\n\n");
    this_thread::sleep_for(chrono::milliseconds(500));
  }
  else{
    cout << "Well then ... I hope someone is up for this task." << endl;
    return 0;
  }
  Character firstBoss("Rehan Kazi", 100, 30);
  Weapon rustySword("Rusty Sword", 10, 10);
  player.equipWeapon(rustySword);
  cout << endl;
  cout << "You have equipped the " << player.getWeapon().getName() << "!" << endl;
  cout << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "You have encountered the first guard!" << endl;
  cout << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  typeEffect("Rehan Kazi : Hey, you! You trying to sneak pass me? Not on my watch!\n\n");
  cout << "Get ready! Your about to fight the first guard!" << endl;
  cout << endl;
  cout << "First boss: " << firstBoss.getName() << endl << "Health: " << firstBoss.getHealth() << endl << "Strength: " << firstBoss.getStrength() << endl;
  fight(player, firstBoss);

  if(player.isDead()){
    //ENTER ASCII ART FOR DEFEAT
    return 0;
  }
  
  typeEffect("Nice job! You defeated the first guard! Now, you can pick up his weapon. It's a shiny sword. It's a bit heavy, but it's better than nothing. You can use it to fight the second guard!\n\n");
  Weapon shinySword("Shiny Sword", 20, 25);
  player.equipWeapon(shinySword);
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "You have equipped the " << player.getWeapon().getName() << "!" << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << player.getWeapon().getName() << " damage: " << player.getWeapon().getDamage() << endl;
  cout << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  typeEffect("(You make your way up the flight of stairs to the second floor. You see the guard sleeping, you try to sneak past. *snap* You step on a twig!)\n\n");
  Character secondBoss("Sadit", 200, 40);
  typeEffect("Sadit : Hmm, you're not from around here are you? You're not supposed to be here. Get out of here!\n\n");
  cout << "Get ready! Your about to fight the second guard!" << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "Second boss: " << secondBoss.getName() << endl << "Health: " << secondBoss.getHealth() << endl << "Strength: " << secondBoss.getStrength() << endl;
    fight(player, secondBoss);;

    if(player.isDead()){
      //ENTER ASCII ART FOR DEFEAT
      return 0;
    }
  
  cout << "Nice job! You defeated the second guard! Now, you can pick up his weapon. It's a gold sword! It's really shiny and sharp! This will defintely make the third boss fight easier!\n\n" << endl;
  Weapon goldSword("Gold Sword", 35, 35);
  player.equipWeapon(goldSword);
  cout << "You have equipped the " << player.getWeapon().getName() << "!" << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << player.getWeapon().getName() << " damage: " << player.getWeapon().getDamage() << endl;
  cout << "Your halfway there! Onto the third boss!" << endl;
  typeEffect("Sadit : You were strong, but the third boss is much stronger than me. Ha Ha Ha !\n\n");
  typeEffect("(You make your way up the flight of stairs to the third floor. There's two guards?)\n\n");
  typeEffect("Twin #1: You must be the one causing trouble here! This is the end of your road " + player.getName() + "! \n\n");
  Character thirdBoss("Sherpa Twins", 400, 50);
  typeEffect("Twin #2 : You want trouble? Make it double! We the Sherpa Twins will take you down! Fusion!\n\n");
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "Get ready! Your about to fight the third boss!" << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "Third boss: " << thirdBoss.getName() << endl << "Health: " << thirdBoss.getHealth() << endl << "Strength: " << thirdBoss.getStrength() << endl;
  fight(player, thirdBoss);;

  if(player.isDead()){
    //ENTER ASCII ART FOR DEFEAT
    return 0;
  }
  
  cout << "Nice job! You defeated the third guard!" << endl;
  Weapon diamondSword("Diamond Sword", 50, 50);
  player.equipWeapon(diamondSword);
  typeEffect(player.getName() + " : You're stronger than I thought! I'm impressed. I'll give you this " + player.getWeapon().getName() + " I'm sure you'll be able to defeat the fourth boss! I don't know why but I feel like you can change this place! I wish you all the best! \n\n");
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "You have equipped the " << player.getWeapon().getName() << "!" << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  typeEffect("(They were stronger than you thought! You make your way up the flight of stairs to the fourth floor. There's the 4th guard!)\n\n");
  
  Character fourthBoss("The Guard", 600, 40);
  typeEffect("Guard : You shall not pass.");
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "Get ready! Your about to fight the fourth guard!" << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "Fourth boss: " << fourthBoss.getName() << endl << "Health: " << fourthBoss.getHealth() << endl << "Strength: " << fourthBoss.getStrength() << endl;
  fight(player, fourthBoss);;

  if(player.isDead()){
    //ENTER ASCII ART FOR DEFEAT
    return 0;
  }
  cout << "Nice job! You defeated the fourth guard!" << endl;
  typeEffect("Guard : I can't believe it, master will be dissapointed in me. How shameful!");
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "You recieved the Dragon Sword!" << endl;
  Weapon dragonSword("Dragon Sword", 100, 45);
  player.equipWeapon(dragonSword);
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "You have equipped the " << player.getWeapon().getName() << "!" << endl;
  cout << player.getWeapon().getName() << " damage: " << player.getWeapon().getDamage() << endl;

  typeEffect("(The last and final boss. You shake as you approach the end of the steps. There he is. The final boss. The dragon. The one that has been terrorizing the dungeon for centuries)\n\n");

  this_thread::sleep_for(chrono::milliseconds(600));

  typeEffect("The Dragon: You, you're the first one to try to defeat me. I will not let you pass. You will have to fight me. You will not win. I, Proton, shall defeat you.\n\n");

  this_thread::sleep_for(chrono::milliseconds(600));

  typeEffect("You: Proton, I will defeat you and escape this dungeon!\n\n");
  this_thread::sleep_for(chrono::milliseconds(600));

  cout << "Get ready! Your about to fight the final boss!" << endl;
  this_thread::sleep_for(chrono::milliseconds(600));

  Character finalBoss("Proton", 1500, 25);
  cout << "Final boss: " << finalBoss.getName() << endl << "Health: " << finalBoss.getHealth() << endl << "Strength: " << finalBoss.getStrength() << endl;
  fight(player, finalBoss);;

  if(player.isDead()){
    //ENTER ASCII ART FOR DEFEAT
    return 0;
  }

  typeEffect("Proton: Its not possible, how could you defeat me wanderer.");
    this_thread::sleep_for(chrono::milliseconds(600));
  typeEffect("You recieved the Doom Sword!");
  this_thread::sleep_for(chrono::milliseconds(600));
  Weapon doomSword("Doom Sword", 300, 45);
  player.equipWeapon(doomSword);
  cout << "You have equipped the " << player.getWeapon().getName() << "!" << endl;
  cout << player.getWeapon().getName() << " damage: " << player.getWeapon().getDamage();
  this_thread::sleep_for(chrono::milliseconds(600));
  typeEffect("You: My name is " + player.getName() + " and with this victory, I shall be free from this dungeon.");
  this_thread::sleep_for(chrono::milliseconds(600));
  typeEffect("(You approach the dungeon doors. The light from outside shines through the cracks.");
  this_thread::sleep_for(chrono::milliseconds(600));
  typeEffect("Proton: You think you've escaped the nightmare, but this is only the beginning. There are monsters outside, those you'll never beat.");
    this_thread::sleep_for(chrono::milliseconds(600));
  typeEffect("(You open the doors and see giants walking around, beasts roaming around, and many more foes.");
  this_thread::sleep_for(chrono::milliseconds(600));
  typeEffect("You: So be it.");

  
  

  
  
  
}