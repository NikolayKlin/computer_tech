#include <iostream>
#include <vector>
#include "my_quest.h"
using namespace std;

void Board::board_hi_words(){
            cout << "Welcome to my quest"<< endl;
            cout << "You are in the room: " << current_location->number_room << endl;
            cout << "Good luck" << endl;
        }
        
void Board::go_next_room(int number_room){
    if(number_room == -1){
                if(current_location->previous == nullptr) {
                    cout << "There is no way backwards" << endl;
                }
                else{
                    current_location = current_location->previous;
                }
            }
            else if(number_room <= 0 || number_room > current_location->rooms.size()) {
                cout << "No such a room" << endl;
                cout << "Try again" << endl;
            }
            else{
                if (current_location->rooms[number_room] == nullptr) {
                    current_location->rooms[number_room] = new Room(ROOM_NUMBER++, current_location);
                }
                
                current_location = current_location->rooms[number_room];
                
            }
        }
void Board::next_step(){
            cout << "Choose the way" << endl;
            cout << "You can go to one of N = " << current_location->rooms.size() << " rooms" << endl;
            if (current_location->previous != nullptr) {
                cout << "You can go to the previous room" << endl;
            }
            else{
                cout << "There is no way backwards" << endl;
            }
            cout << "To see the instruction enter 0" << endl;
            
        }
void Board::instruction(){
            cout << "From any room you can get to other rooms" << endl;
            cout << "You can enter room number:" << endl;
            cout << "From one to N" << endl;
            cout << "To go to the previous room enter -1" << endl;
            cout << "Enter 73 to check room loot" << endl;  
        }
void Board::what_about_food(){
            cout << "There are:" << endl;
            cout << "Bread: " << current_location->bread << endl;
            cout << "Bananas: " << current_location->bananas << endl;
        }
void Board::lines(){
    cout << endl;
    cout << endl;
    cout << endl;
}
        