#include "piece.h"
#include <iostream>
#include <string>
#include "legalMoves.cpp"

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

void piece::setPiece(bool color, string t){
    wb = color;
    type = t;
    if(wb == false){
        if(type == "p"){
            point = 1;
            imag = "♙";
        }
        if(type == "h"){
            point = 3;
            imag = "♘";
        }
        if(type == "b"){
            point = 3;
            imag = "♗";
        }
        if(type == "r"){
            point = 5;
            imag = "♖";
        }
        if(type == "q"){
            point = 9;
            imag = "♕";
        }
        if(type == "k"){
            point = 100;
            imag = "♔";
        }
    }
    if(wb == true){
        if(type == "p"){
            point = 1;
            imag = "☗";
        }
        if(type == "h"){
            point = 3;
            imag = "♞";
        }
        if(type == "b"){
            point = 3;
            imag = "♝";
        }
        if(type == "r"){
            point = 5;
            imag = "♜";
        }
        if(type == "q"){
            point = 9;
            imag = "♛";
        }
        if(type == "k"){
            point = 100;
            imag = "♚";
        }
    }
}

void piece::move(int xPos, int yPos){
    setMoves(this, x, y); //adds moves to the variable posMv in the format a1
    char xLet = char(xPos + 96);
    string move = xLet + to_string(yPos);
    bool validMove = false;
    for (int i=0;i<posMv.size(); i++) {
        if (posMv.at(i) == move) {
            board.moveTile(x, y, NULL);//make original tile null
            x = xPos;
            y = yPos;
            board.moveTile(xPos, yPos, this);//move piece to new tile
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
