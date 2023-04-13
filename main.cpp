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
    cout << "What would you like to do? (Move, Look, Take, Map)"<< endl;
    cin >> temp;
    return temp;
}
    //checking movement function
string checkMove(string currentLocation, string direction, vector<Item> bag){
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
            if (bag.size() == 10){
                temp = "trollRoom";
            } else{
                temp = "none";
                cout << "You do not have all the relics! You may not enter.";
            }
        }else if (direction == "E"){
            temp = "bedRoom";
        }else if (direction == "S"){
            temp = "mainRoom";
        }else{
            temp = "none";
        }  
    }
    return temp;
}
    //troll fight intro function
void trollIntro(){
    cout << "Welcome to your final test!"<< endl
    << "A large ugly troll stands before you."<<endl
    << "You must defeat this troll to win the game!";
}
    //troll fight function
bool trollFight(){
    int playerHealth = 100;
    int trollHealth = 200;
    bool trollWine = false;

    while (true){
        string attackChoice;
        cout << "What would you like to do? (Sword_Attack, Throw_Item)"<< endl;
        cin >> attackChoice;
        if (attackChoice == "Sword_Attack"){
            trollHealth -= 50;
            cout << "You swing your awesome sword!" << endl;
        }else if (attackChoice == "Throw_Item"){
            cout << "Which item would you like to throw? (Wine, Match, Hammer, Book)"<< endl;
            cin >> attackChoice;
            if (attackChoice == "Book"){
                trollHealth -= 10;
                cout << "You throw your book. The troll now knows you're a nerd." << endl;
            }else if (attackChoice == "Hammer"){
                cout << "You throw your hammer. Hey, you could have made a worse choice." << endl;
                trollHealth -= 30;
            }else if (attackChoice == "Wine"){
                cout << "You splash some wine on the troll. I guess it's five o'clock somewhere." << endl;
                trollWine = true;
            }else if (attackChoice == "Match"){
                if (trollWine == true){
                    cout << "The troll, covered in subpar alcohol, bursts into flames. Clever. I never should have doubted you." << endl;
                    trollHealth = 0;
                }else {
                    trollHealth -= 5;
                    cout << "You toss a lit match, which is a little rude more than anything else." << endl;
                }
            }
        }
        if (trollHealth <= 0){
            return true;
        }
        cout << "The troll swings it's huge axe at you."<<endl;
        playerHealth -=25;
        if (playerHealth <= 0){
            return false;
        }        
    }
}
    //function for checking map
void mapArea(){
    cout << "*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*\n"
    << "*																																*\n"
    << "*																																*\n"
    << "*																																*\n"
    << "*																								*	*	*	*	*	*	*		*\n"
    << "*													*	*	*	*	*	*	*	*	*			*						*		*\n"
    << "*								*	*	*	*	*	*								*	*	*	*						*		*\n"
    << "*								*							Stairwell										bedroom		*		*\n"
    << "*								*		*	*	*	*								*	*	*	*						*		*\n"
    << "*								*		*			*	*	*		*	*	*	*	*			*						*		*\n"
    << "*			*	*	*	*	*	*		*	*	*			*		*							*	*	*	*	*	*	*		*\n"
    << "*			*									*		*	*		*	*	*	*	*	*	*									*\n"
    << "*			*									*		*									*	*	-	-	*	*				*\n"
    << "*			*									*		*									*					*				*\n"
    << "*			*				Troll room			*		*									*					*				*\n"
    << "*			*									*		*														|				*\n"
    << "*			*									*		*			Main Room							Shed	|	            *\n"
    << "*			*	*	*	*	*	*	*	*	*	*		*									*					*				*\n"
    << "*														*									*					*				*\n"
    << "*														*									*	*	-	-	*	*				*\n"
    << "*														*									*									*\n"
    << "*														*	*	*	*			*	*	*	*									*\n"
    << "*															mail																*\n"
    << "*															box																	*\n"
    << "*			*	*	*	*	*	*	*	*																						*\n"
    << "*			*																													*\n"
    << "*			*		Log shed																									*\n"
    << "*			*							*																						*\n"
    << "*			*	*	*	*	*	*	*	*																						*\n"
    << "*																																*\n"
    << "*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*";
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

    bool gameWin;

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
            futureLocation = checkMove(currentLocation, moveDirection, bag);
            if (futureLocation != "none"){
                currentLocation = futureLocation;
                futureLocation = "none";
                cout << "You moved!" << endl;
                lookAround(currentLocation, allItems, allRooms);
            } else{
                cout << "You cannot move that way." << endl;
            }
            if (currentLocation == "trollRoom"){
                trollIntro();
                break;
            }
        }
        if (input == "Map"){
            mapArea();
        } 
    }
    gameWin = trollFight();
    if (gameWin == true){
        cout << "Congrats! you have passed the test! Welcome to Zorktopia." <<endl;
    }else{
        cout << "The troll's axe lands squarely in your face. I guess you're dead now. Bummer."<<endl;
    }

}

