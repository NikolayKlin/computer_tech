#include <iostream>
#include "my_quest.h"

int main()
{
    
    Board board;
    int step = 0;
    board.next_step();
    while(true){
        cin >> step;
        switch(step){
            case 0:
                board.instruction();
                break;
            case 73:
                board.what_about_food();
                break;
            default:
                board.go_next_room(step);
        }
        board.lines();
        board.next_step();
    }