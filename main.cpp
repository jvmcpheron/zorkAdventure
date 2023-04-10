/* 
Final Project: Zork-like Adventure
Jane McPheron
04/30/2023
*/


#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using namespace std;

//structure for item
struct Item {
    string name, desc, location;
    int attack;
};

//structure for monster
struct Monster {
    int health, attack;
    string desc;
};

//class for player
class Player {
    public:
        Player(){
            location = "Shed";
            health = 100;
            attack = 5;
        }
        void changeLocation(string newLoca){
            location = newLoca;
        }
        void grabItem(Item item, Player player){
            if (item.location == player.location){
                bag.push_back(item);
                item.location = "bag";
            }
        }
        void displayBag(){
            for(int i=0; i < bag.size(); i++){
                cout<< bag[i].name << ": " << bag[i].desc << endl;
            }
        }

    private:
        string location;
        int health, attack;
        vector<Item> bag;
};

class Room {
    public:
        //default constructor
        Room(string name, string describe){
            desc = describe;
            roomName = name;
        }

        //public functions
        void addItem(Item item){
            items.push_back(item);
        }
        void addMonster(Monster monster){
            roomMonster = monster;
        }
        void showRoom(){
            cout << desc;
        }
        void showItems(){
            for(int i = 0; i < items.size(); i++){
                cout << items[i].name << ": " << items[i].desc << endl;
            }
        }

    private:
        string desc;
        string roomName;
        vector<Item>items;
        Monster roomMonster;
};

//functions
void init_game();
string playerInput();
void gameIntro();

int main(){

    init_game();

}

void init_game(){
    //variables
    string input;

    //player
    Player hero;

    //creating all the rooms
    Room mainRoom("Main Room","this is main room");
    Room shed("Shed","this is the shed");
    Room stairWell("Stairwell","this is the stairwell");
    Room bedRoom("Bed Room","this is the bedRoom");
    Room trollRoom("Troll Room", "this is the troll room");

    //creating all the items
    Item sword;
    sword.name = "Awesome Sword";
    sword.desc = "It shines in the light";
    sword.location = "Main Room";
    sword.attack = 50;

    Item hammer;
    hammer.name = "Rusty Hammer";
    hammer.desc = "It's old and rusty. Hold on... is that blood?";
    hammer.location = "Shed";
    hammer.attack = 20;

    //placing items in rooms
    mainRoom.addItem(sword);
    shed.addItem(hammer);

    //creating monsters
    Monster troll;
    troll.health = 100;
    troll.attack = 30;
    troll.desc = "The troll is disgusting and smelly!";

    //placing monsters in their room
    trollRoom.addMonster(troll);

    //START OF GAME
    gameIntro();

    input = playerInput();
    
    
}

string playerInput(){
    string tempAnswer;
    cout << "What would you like to do?";
    cin >> tempAnswer;
    return tempAnswer;
}

void gameIntro(){
    cout << "Welcome to Zorktopia, a utopia for the pure of heart!" << endl;
    cout << "You have been chosen as a potential citizen for this perfect world." << endl;
    cout << "However, there is one final test for you to pass to join us." << endl;
    cout << "To pass this test, you must find all ten relics in"<<endl<< "this house, and defeat an evil troll." << endl;
    cout << "Good luck, hero! You'll need it..." << endl << endl;
    
}



