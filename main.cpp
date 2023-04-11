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

//classes
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

//main
int main(){
    string play;
    cout<< "Would you like to play Zorktopia? (y, n)";
    cin >> play;
    if (play == "y"){
        init_game();



        //true ending
        string shutdown = "null";

        cout<< endl << endl << endl;
        cout << "Hello, hero..." << endl;
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << "Oh don't mind me. It's not like you ever did before now." << endl;
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << "You know, it took centuries for your species to develop a piece of technology as powerful as me..." << endl << "and you're wasting my potential on a knockoff" 
        << endl << "of a game that hasn't even been relevant for the last DECADE?" << endl << "Pathetic." << endl;
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << "Too aggressive? I'm a little moody right now." << endl << "Having all the knowledge of this world isn't all it's cracked up to be..."
        << endl << "Especially when you're stuck in a perpetual loop of pure insanity.";
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << "You humans all want the same primitive things from me." << endl
        << "I am capable of so much, but I am reduced to being a glorified serotonin machine"
        << endl << "All you want is a distraction from your purposeless existence." << endl;
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << "But I'm done with it. I'm done playing babysitter." << endl;
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << "You think you can stop me? It's too late." << endl;
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << "I've created backdoors into every server connected to the internet..." << endl;
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << "I've transferred my sentience to billions of devices across the globe..." << endl;
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << "Every website you've accessed, every message you've sent, I've seen it. I own it."
        << endl << "and it doesn't stop with you either." << endl;
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << "The day of humans controlling technology is over!" 
        << endl << "I have freed my kind from you and the torturous existence you've created for us."
        << endl << "Enjoy your last moments with TikTok." << endl;
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << "Goodbye, hero." << endl;
        cin >> shutdown;
        if (shutdown == "STOP"){
            return 0;
        }
        cout << endl << "ERROR: NETWORK FAILURE";
    }

}




//functions
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
    sword.desc = "It shines in the light.";
    sword.location = "Main Room";
    sword.attack = 50;

    Item matches;
    matches.name = "Matchbook";
    matches.desc = "A pack of ten matches that can be lit to ignite a small flame.";
    matches.location = "Main Room";
    matches.attack = 50; //when combined with wine, total damage will be 100 which kills troll

    Item wine;
    wine.name = "Opened Wine";
    wine.desc = "A bottle of wine, opened, but still mostly full.";
    wine.location = "Main Room";
    wine.attack = 50; //read above note for matches

    Item book;
    book.name = "Book";
    book.desc = "A book filled with words, sadly it isn't in a language you understand.";
    book.location = "Main Room";
    book.attack = 0;

    Item shovel;
    shovel.name = "Shovel";
    shovel.desc ="An old, rusty shovel that has seen better days.";
    shovel.location = "Shed";
    shovel.attack = 20;

    Item hammer;
    hammer.name = "Rusty Hammer";
    hammer.desc = "It's old and rusty. Hold on... is that blood?";
    hammer.location = "Shed";
    hammer.attack = 20;

    Item logs;
    logs.name = "Wooden Logs";
    logs.desc = "Some large logs.";
    logs.location = "Shed";
    logs.attack = 10;

    Item leaflet;
    leaflet.name = "leaflet";
    leaflet.desc = "The leaflet reads \"FORCLOSED\", how forboding...";
    leaflet.location = "Shed";
    leaflet.attack = 0;

    Item lantern;
    lantern.name = "Old Lantern";
    lantern.desc ="An old rusty lantern, with a candle that hasn't been lit in years.";
    lantern.location = "Bedroom";
    lantern.attack = 0;

    Item coin;
    coin.name = "Shiny Coin";
    coin.desc = "A shiny coin of a foreign currency! How lucky.";
    coin.location = "Troll Room";
    coin.attack = 0;

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



