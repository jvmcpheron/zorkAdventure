#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using namespace std;

//class for item
class Item {
    public:
        //default constructor
        Item(bool check, string describe){
            treasure = check;
            desc = describe;
        }

        //public functions
        void showItem(){
            cout << desc;
        }
    private:
        bool treasure;
        string desc;
};

class Room {
    public:
        //default constructor
        Room(string describe){
            desc = describe;
            items;
        }

        //public functions
        void addItem(Item item){
            items.push_back(item);
        }
        void showRoom(){
            cout << desc;
        }
        void showItems(){
            for(int i = 0; i < items.size(); i++){
                items[i].showItem();
            }
        }

    private:
        string desc;
        vector<Item>items;
};

void init_game();

int main(){
    init_game();
    

}

void init_game(){
    Room livingRoom("this is living room");
    Room diningRoom("this is dining room");

    Item sword(true, "it is a shiny sword");

    livingRoom.addItem(sword);

    livingRoom.showRoom();
    livingRoom.showItems();



}