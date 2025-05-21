
#ifndef LEGALMOVE_CPP
#define LEGALMOVE_CPP

#include "piece.h"
#include "board.h"
#include "iostream"

board board;

void movesRook(piece * p, int x, int y){
    int x1 = x + 1;
    while(x1 < 8){
        if(board.bor[x1][y].occupied){
            p->addMove(x1, y);
        }else if(board.bor[x1][y].thePiece->wb != p->wb){
            p->addMove(x1, y);
            break;
        }else{//if piece is same color
            break;
        }
        x1++;
    }
    x1 = x-1;
    while(x1 >= 0){
        if(board.bor[x1][y].occupied){
            p->addMove(x1, y);
        }else if(board.bor[x1][y].thePiece->wb != p->wb){
            p->addMove(x1, y);
            break;
        }else{//if piece is same color
            break;
        }
        x1--;
    }

    int y1 = y+1;
    while(y1 < 8){
        if(board.bor[x][y1].occupied){
            p->addMove(x, y1);
        }else if(board.bor[x][y1].thePiece->wb != p->wb){
            p->addMove(x, y1);
            break;
        }else{//if piece is same color
            break;
        }
        y1++;
    }

    y1 = y-1;
    while(y1 >= 0){
        if(board.bor[x][y1].occupied){
            p->addMove(x, y1);
        }else if(board.bor[x][y1].thePiece->wb != p->wb){
            p->addMove(x, y1);
            break;
        }else{//if piece is same color
            break;
        }
        y1--;
    }

    
}

void movesPawn(piece * p, int x, int y){
    if(p->wb = 0){
        if(y == 7){//should've promoted
            return;
        }
        if(board.bor[x][y+1].occupied){
            p->addMove(x, y+1);
            if(y == 1 && board.bor[x][y+2].occupied){
                p->addMove(x, y+2);
            }
        }
        if(!board.bor[x+1][y+1].occupied && board.bor[x+1][y+1].thePiece->wb != p->wb){
            p->addMove(x+1, y+1);
        }
        if(!board.bor[x-1][y+1].occupied && board.bor[x-1][y+1].thePiece->wb != p->wb){
            p->addMove(x-1, y+1);
        }

        //en passant
        if(y==4 && !board.bor[x+1][y].occupied && board.bor[x+1][y].thePiece->wb == 1 && board.bor[x+1][y].thePiece->type == "pawn"){
            p->addMove(x+1, y+1);
        }
        if(y==4 && !board.bor[x-1][y].occupied && board.bor[x-1][y].thePiece->wb == 1 && board.bor[x-1][y].thePiece->type == "pawn"){
            p->addMove(x-1, y+1);
        }
    }else{//if pawn is black
        if(y == 0){//should've promoted
            return;
        }
        if(board.bor[x][y-1].occupied){
            p->addMove(x, y-1);
            if(y == 6 && board.bor[x][y-2].occupied){
                p->addMove(x, y-2);
            }
        }
        if(!board.bor[x+1][y-1].occupied && board.bor[x+1][y-1].thePiece->wb != p->wb){
            p->addMove(x+1, y-1);
        }
        if(!board.bor[x-1][y-1].occupied && board.bor[x-1][y-1].thePiece->wb != p->wb){
            p->addMove(x-1, y-1);
        }

        //en passant
        if(y==3 && !board.bor[x+1][y].occupied && board.bor[x+1][y].thePiece->wb == 0 && board.bor[x+1][y].thePiece->type == "pawn"){
            p->addMove(x+1, y-1);
        }
        if(y==3 && !board.bor[x-1][y].occupied && board.bor[x-1][y].thePiece->wb == 0 && board.bor[x-1][y].thePiece->type == "pawn"){
            p->addMove(x-1, y-1);
        }
    }
}

void movesBish(piece * p, int x, int y){
    int y1 = y+1;
    int x1 = x+1;
    while(y1 < 8 && x1 < 8){
        if(board.bor[x1][y1].occupied){
            p->addMove(x1, y1);
        }else if(board.bor[x1][y1].thePiece->wb != p->wb){
            p->addMove(x1, y1);
            break;
        }else{//if piece is same color
            break;
        }
        y1++;
        x1++;
    }

    y1 = y-1;
    x1 = x-1;
    while(y1 >=0 && x1 >= 0){
        if(board.bor[x1][y1].occupied){
            p->addMove(x1, y1);
        }else if(board.bor[x1][y1].thePiece->wb != p->wb){
            p->addMove(x1, y1);
            break;
        }else{//if piece is same color
            break;
        }
        y1--;
        x1--;
    }

    y1 = y+1;
    x1 = x-1;
    while(y1 < 8 && x1 >= 0){
        if(board.bor[x1][y1].occupied){
            p->addMove(x1, y1);
        }else if(board.bor[x1][y1].thePiece->wb != p->wb){
            p->addMove(x1, y1);
            break;
        }else{//if piece is same color
            break;
        }
        y1++;
        x1--;
    }

    y1 = y-1;
    x1 = x+1;
    while(y1 >= 0 && x1 < 8){
        if(board.bor[x1][y1].occupied){
            p->addMove(x1, y1);
        }else if(board.bor[x1][y1].thePiece->wb != p->wb){
            p->addMove(x1, y1);
            break;
        }else{//if piece is same color
            break;
        }
        y1--;
        x1++;
    }
}

void movesKnit(piece * p, int x, int y){
    if(y+2 < 8){
        if(x+1 < 8 && (board.bor[x+1][y+2].occupied || board.bor[x+1][y+2].thePiece->wb != p->wb)){
            p->addMove(x+1, y+2);
        }
        if(x-1 >= 0 && (board.bor[x-1][y+2].occupied || board.bor[x-1][y+2].thePiece->wb != p->wb)){
            p->addMove(x-1, y+2);
        }
    }
    if(y-2 >=0){
        if(x+1 < 8 && (board.bor[x+1][y-2].occupied || board.bor[x+1][y-2].thePiece->wb != p->wb)){
            p->addMove(x+1, y-2);
        }
        if(x-1 >= 0 && (board.bor[x-1][y-2].occupied || board.bor[x-1][y-2].thePiece->wb != p->wb)){
            p->addMove(x-1, y-2);
        }
    }

    if(x+2 < 8){
        if(y+1 < 8 && (board.bor[x+2][y+1].occupied || board.bor[x+2][y+1].thePiece->wb != p->wb)){
            p->addMove(x+2, y+1);
        }
        if(y-1 >= 0 && (board.bor[x+2][y-1].occupied || board.bor[x+2][y-1].thePiece->wb != p->wb)){
            p->addMove(x+2, y-1);
        }
    }
    if(x-2 >=0){
        if(x+1 < 8 && (board.bor[x-2][y+1].occupied || board.bor[x-2][y+1].thePiece->wb != p->wb)){
            p->addMove(x-2, y+1);
        }
        if(x-1 >= 0 && (board.bor[x-2][y-1].occupied || board.bor[x-2][y-1].thePiece->wb != p->wb)){
            p->addMove(x-2, y-1);
        }
    }
}
void movesKing(piece * p, int x, int y){
    if(x+1 < 8){
        if(board.bor[x+1][y].occupied || board.bor[x+1][y].thePiece->wb != p->wb){
            p->addMove(x+1, y);
        }
        if(y+1 < 8 && (board.bor[x+1][y+1].occupied || board.bor[x+1][y+1].thePiece->wb != p->wb)){
            p->addMove(x+1, y+1);
        }
        if(y-1 >= 0 && (board.bor[x+1][y-1].occupied || board.bor[x+1][y-1].thePiece->wb != p->wb)){
            p->addMove(x+1, y-1);
        }
    }
    if(x-1 >= 0){
        if(board.bor[x-1][y].occupied || board.bor[x-1][y].thePiece->wb != p->wb){
            p->addMove(x-1, y);
        }
        if(y+1 < 8 && (board.bor[x-1][y+1].occupied || board.bor[x-1][y+1].thePiece->wb != p->wb)){
            p->addMove(x-1, y+1);
        }
        if(y-1 >= 0 && (board.bor[x-1][y-1].occupied || board.bor[x-1][y-1].thePiece->wb != p->wb)){
            p->addMove(x-1, y-1);
        }
    }
    if(y+1 < 8 && (board.bor[x][y+1].occupied || board.bor[x][y+1].thePiece->wb != p->wb)){
        p->addMove(x, y+1);
    }
    if(y-1 >=0 && (board.bor[x][y-1].occupied || board.bor[x][y-1].thePiece->wb != p->wb)){
        p->addMove(x, y-1);
    }




    if(!p->moved){//castling
        if(board.bor[0][y].thePiece->wb == p->wb && board.bor[0][y].thePiece->type == "rook" && !board.bor[0][y].thePiece->moved){
            p->addMove(x-2, y);
        }
        if(board.bor[7][y].thePiece->wb == p->wb && board.bor[7][y].thePiece->type == "rook" && !board.bor[7][y].thePiece->moved){
            p->addMove(x+2, y);
        }
    }
}




void setMoves(piece * p, int x, int y){//gives piece and coordinates for a location of a peice on the board, assuming x: 0-7 inclusive, y: 0-7 inclusive.
    //clearMoves(p);
    if(p->type == "b"){
        movesBish(p, x, y);
    }
    else if(p->type == "r"){
        movesRook(p, x, y);
    }
    else if(p->type == "bishop"){
        movesBish(p, x, y);
    }
    else if(p->type == "p"){
        movesPawn(p, x, y);
    }else if(p->type == "n"){
        movesKnit(p, x, y);
    }else if(p->type == "k"){
        movesKing(p, x, y);
    }
    else if(p->type == "q"){
        movesRook(p, x, y);
        movesBish(p, x, y);
    } else{
        std::cout<<"INVALID PIECE TYPE"<<std::endl;
    }
}

#endif
