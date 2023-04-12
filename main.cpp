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


//structures
struct Item {
   string name, desc, location;
   int attack;
};
struct Room {
    string name, desc;
};

//FUNCTIONS
    //intro
void gameIntro(){
   cout << "Welcome to Zorktopia, a utopia for the pure of heart!" << endl;
   cout << "You have been chosen as a potential citizen for this perfect world." << endl;
   cout << "However, there is one final test for you to pass to join us." << endl;
   cout << "To pass this test, you must find all ten relics in"<<endl<< "this house, and defeat an evil troll." << endl;
   cout << "Good luck, hero! You'll need it..." << endl << endl;
}
    //loading in all items
vector<Item> loadItems(){
    vector<Item> temp;

    Item sword;
    sword.name = "Sword";
    sword.desc = "It shines in the light.";
    sword.location = "mainRoom";
    sword.attack = 50;
    temp.push_back(sword);

    Item hammer;
    hammer.name = "Hammer";
    hammer.desc = "It's old and rusty. Hold on... is that blood?";
    hammer.location = "shed";
    hammer.attack = 20;
    temp.push_back(hammer);

    Item matches;
    matches.name = "Matchbook";
    matches.desc = "A pack of ten matches that can be lit to ignite a small flame.";
    matches.location = "mainRoom";
    matches.attack = 50; 
    temp.push_back(matches);

    Item wine;
    wine.name = "Wine";
    wine.desc = "A bottle of wine, opened, but still mostly full.";
    wine.location = "mainRoom";
    wine.attack = 50; 
    temp.push_back(wine);

    Item book;
    book.name = "Book";
    book.desc = "A book filled with words, sadly it isn't in a language you understand.";
    book.location = "mainRoom";
    book.attack = 0;
    temp.push_back(book);

    Item shovel;
    shovel.name = "Shovel";
    shovel.desc ="An old, rusty shovel that has seen better days.";
    shovel.location = "shed";
    shovel.attack = 20;
    temp.push_back(shovel);

    Item logs;
    logs.name = "Logs";
    logs.desc = "Some large logs.";
    logs.location = "shed";
    logs.attack = 10;
    temp.push_back(logs);

    Item leaflet;
    leaflet.name = "Leaflet";
    leaflet.desc = "The leaflet reads \"FORCLOSED\", how forboding...";
    leaflet.location = "shed";
    leaflet.attack = 0;
    temp.push_back(leaflet);

    Item lantern;
    lantern.name = "Lantern";
    lantern.desc ="An old rusty lantern, with a candle that hasn't been lit in years.";
    lantern.location = "bedRoom";
    lantern.attack = 0;
    temp.push_back(lantern);

    Item coin;
    coin.name = "Coin";
    coin.desc = "A shiny coin of a foreign currency! How lucky.";
    coin.location = "bedRoom";
    coin.attack = 0;
    temp.push_back(coin);

    return temp;
}
    //loading in all rooms
vector<Room> loadRooms(){
    vector<Room> temp;

    Room shed;
    shed.name = "shed";
    shed.desc = "This is a musty old shed that smells of death. Let's not stick around too long.";
    temp.push_back(shed);


    return temp;

}
    vector<Item> temp;
        //display items in bags
void displayItems(string location, vector<Item> items){
    for(int i = 0; i < items.size(); i++){
        if (items[i].location == location){
            cout << items[i].name << ": " << items[i].desc << endl;
        }
    }
}
    //look at room function
void lookAround(string currentLocation, vector<Item> items, vector<Room> allRooms){
    cout << "You are in the " << currentLocation <<endl;
    for (int i = 0; i < allRooms.size(); i++){
        if (currentLocation == allRooms[i].name){
            cout << allRooms[i].desc <<endl;
        }
    }
    cout << "Items Here:" << endl;
    displayItems(currentLocation, items);

}
    //get input function
string userInput(){
    string temp;
    cout << "What would you like to do?"<< endl;
    cin >> temp;
    return temp;
}
    //checking movement function
string checkMove(string currentLocation, string direction){
    string temp;
    if (currentLocation == "shed"){
        if (direction == "W"){
            temp = "mainRoom";
        }else{
            temp = "none";
        }
    }else if (currentLocation == "mainRoom"){
        if (direction == "N"){
            temp = "stairWell";
        }else if (direction == "E"){
            temp = "shed";
        }
        else{
            temp = "none";
        }
    }else if (currentLocation == "bedRoom"){
        if (direction == "W"){
            temp = "stairWell";
        }else{
            temp = "none";
        }
    }else if (currentLocation == "stairWell"){
        if (direction == "W"){
            temp = "trollRoom";
        }else if (direction == "E"){
            temp = "bedRoom";
        }else{
            temp = "none";
        }  
    }else if (currentLocation == "trollRoom"){
        if (direction == "E"){
            temp = "stairWell";
        }else{
            temp = "none";
        }
    }
    return temp;
}

//game
int main(){
    //VARIABLES
    vector<Item> allItems;
    vector<Item> bag;
    vector<Room> allRooms;

    string currentLocation = "shed";
    string input;
    string itemTake;
    string moveDirection;
    string futureLocation = "none";

    //initializing items
    allItems = loadItems();
    //initializing rooms
    allRooms = loadRooms();

    //game intro 
    gameIntro();
    lookAround(currentLocation, allItems, allRooms);

    //gameplay 
    while (true){
        input = userInput();
        if (input == "Look"){
            lookAround(currentLocation, allItems, allRooms);
        }
        if (input == "Take"){
            cout << "Which item?"<< endl;
            cin >> itemTake;
            for (int i = 0; i < allItems.size(); i++){
                if (allItems[i].name == itemTake){
                    if (allItems[i].location == currentLocation){
                        allItems[i].location = "bag";
                        bag.push_back(allItems[i]);
                    }else{
                        cout << "That item isn't here.";
                    }
                }
            }
            cout << "Your bag currently holds " << bag.size() << " item(s)." <<endl;
            displayItems("bag", bag);

        }
        if (input == "Move"){
            cout << "What direction? (N,S,E,W)" << endl;
            cin >> moveDirection;
            futureLocation = checkMove(currentLocation, moveDirection);
            if (futureLocation != "none"){
                currentLocation = futureLocation;
                futureLocation = "none";
                cout << "You moved!" << endl;
                lookAround(currentLocation, allItems, allRooms);
            } else{
                cout << "You cannot move that way." << endl;
            }
        } 
    }

}

