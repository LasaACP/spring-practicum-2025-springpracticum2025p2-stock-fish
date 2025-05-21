#include "board.h"
#include <iostream>
#include <string>
using namespace std; 


 tile::tile(){
     imag = NULL;
     wb = false;
     occupied = false;
     thePiece = NULL;
}

void tile::setTile(const char* i, bool color, bool oc){
    imag = i;
    wb = color;
    occupied = oc;
}

void tile::tilePiece(bool color, char t){
    string s = {t};
    thePiece->setPiece(color, s);
    imag = thePiece->imag;
    occupied = true;
}

 Board::Board(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            bor[i][j].thePiece = new piece(this);
            if((j+i)%2 != 1){
                bor[i][j].setTile("⬜",true,false);
            }
            else{
                bor[i][j].setTile("⬛",true,false);
            }
        }
    }
    bor[0][0].tilePiece(false, 'r');
    bor[0][1].tilePiece(false, 'h');
    bor[0][2].tilePiece(false, 'b');
    bor[0][3].tilePiece(false, 'q');
    bor[0][4].tilePiece(false, 'k');
    bor[0][5].tilePiece(false, 'b');
    bor[0][6].tilePiece(false, 'h');
    bor[0][7].tilePiece(false, 'r');
    
    
    bor[7][0].tilePiece(true, 'r');
    bor[7][1].tilePiece(true, 'h');
    bor[7][2].tilePiece(true, 'b');
    bor[7][3].tilePiece(true, 'q');
    bor[7][4].tilePiece(true, 'k');
    bor[7][5].tilePiece(true, 'b');
    bor[7][6].tilePiece(true, 'h');
    bor[7][7].tilePiece(true, 'r');
    
    for(int i = 0; i < 8; i++){
        bor[1][i].tilePiece(false, 'p');
        bor[6][i].tilePiece(true, 'p');
    }



}

tile Board::getTile(int x, int y){
    return bor[y][x];
}

void Board::printBoard(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << bor[i][j].imag << " ";
        }
        cout << endl;
    }
}

void Board::moveTile(int x, int y, piece* newPiece){
    bor[y][x].thePiece = newPiece;
}

