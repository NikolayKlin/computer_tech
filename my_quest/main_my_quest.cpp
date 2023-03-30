#include <iostream>
#include "my_quest.h"

int main()
{
    Board board;
    board.lines();
    int step = 0;
    int food = 0;
    
    
    cout << "Travelling between rooms damages you" << endl;
    while(board.player.health > 0){
        cout << "Player has" << board.player.health << " hp" << endl;
        board.next_step();
        cin >> step;
        switch(step){
            case 0:
                board.instruction();
                break;
            case 73:
                board.what_about_food();
                cin >> food;
                switch(food) {
                    case 1:
                        board.player.treatment(1);
                        board.current_location->bread -= 1;
                        break;
                    case 2:
                        board.player.treatment(2);
                        board.current_location->bananas -= 1;
                        break;
                    case -1:
                        cout << "You ate nothing" << endl;
                        break;
                    default:
                        cout << "Wrong choice" << endl;
                }
                
                break;
            default:
                if ( board.go_next_room(step)) {
                    board.player.get_damage(board.current_location->damage);
                }
                else {
                    cout << "Wrong choice" << endl;
                }
        }
        board.lines();
    }
    cout << "See you" << endl;
    }