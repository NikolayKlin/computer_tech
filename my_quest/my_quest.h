#include <iostream>
#include <vector>
#include <locale.h>
#include <ctime>
using namespace std;
int ROOM_NUMBER = 1;


class Player{
    public:
        int health = 10;
        void get_damage(int damage){
            
            cout << "Damage: " << damage << endl;
            health -= damage;
            if (health <= 0) {
                you_died();
            }
        }
        
        int get_health(){
            return health;
        }
        void you_died(){
            cout << "You died";
        }
        void treatment(int treat){
            cout << "You ate something" << endl;
            cout << "You were healed by " << treat << " hp" << endl;
            health += treat;
        }
};
class Room {
    public:
        int number_room; // номер комнаты
        Room *previous;// предыдущая комната
        vector <Room *> rooms;// компнаты, которые можно выбрать
        int bread;
        int bananas;
        int damage;
        Room(int number_room = 3, Room *previous = nullptr){
            this->number_room = number_room;
            this->previous = previous;
            srand( time(0) );
            int rand_room = 1 + rand()%10;
            for (int i = 0; i < rand_room; i++){
                this->rooms.push_back(nullptr);
            }
            this->bread = 1 + rand()%3;
            this->bananas = rand()%3;
            this->damage = rand()%10;
        }

        int get_number_room(){
            return number_room;
        }
           
};
class Board{
    public:
        Player player;
        Room *current_location;
        Board () {
            this->current_location = new Room(ROOM_NUMBER ++);
            board_hi_words();
        }
        ~Board(){
            delete_all_rooms(current_location);
        }
        void delete_all_rooms(Room* room);
        bool go_next_room(int number_room);
        void next_step();
        void board_hi_words();
        void instruction();
        void what_about_food();
        void lines();
};
