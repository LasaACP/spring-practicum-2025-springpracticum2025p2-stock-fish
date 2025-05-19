#include "piece.h"
#include <iostream>
#include <string>
using namespace std; 

piece::piece(){
    wb = false;
    x = 0;
    y = 0;
    point = 0;
    moved = false;
    type = "";
    for (int i=0; i<27; i++){
        posMv.push_back("");
    }
    
}

void piece::setPiece(bool color, int xPos, int yPos, string t){
    wb = color;
    x = xPos;
    y = yPos;
    type = t;
}

void piece::move(int xPos, int yPos){
    setMoves(type, x, y); //adds moves to the variable posMv in the format a1
    char xLet = char(xPos + 96);
    string move = xLet + to_string(yPos);
    bool validMove = false;
    for (int i=0;i<posMv.size(); i++) {
        if (posMv.at(i) == move) {
            [board].moveTile(x, y, NULL);//make original tile null
            x = xPos;
            y = yPos;
            [board].moveTile(xPos, yPos, [piece])//move piece to new tile
            validMove = true;
            break;
        }
    }
    if (!validMove) {
        cout << "That move is not valid"<< endl;
    }
}

void piece::addMove(int xPos, int yPos){
    char xLet = char(xPos + 96);
    string move = xLet + to_string(yPos);
    
    for (int i=0;i<posMv.size(); i++) {
        if (posMv.at(i) == "") {
            posMv.at(i) = move;
            break;
        }
    }
}