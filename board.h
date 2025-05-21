#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

using namespace std;

class piece;
class Board;

class tile{
    public:
        const char* imag;
        bool wb;
        bool occupied;
        piece* thePiece;
    
        tile();
        void setTile(const char*, bool, bool);
        void tilePiece(bool, char);
};


class Board{
    public:
        tile bor[8][8];
        Board();
        tile getTile(int, int);
        void printBoard();
        void moveTile(int, int, piece*);
};

class piece{
    public:
        Board* board;

        piece(Board * b);
        bool wb;
        int x;
        int y;
        int point;
        bool moved;
        string type;
        
        const char* imag;
        vector<string> posMv;
        void setPiece(bool, int, int, string);
        void addMove(int, int);
        void move(int, int);
        void setPiece(bool, string);
        void setMoves(piece *, int, int);
        void movesBish(piece *, int, int);
        void movesRook(piece *, int, int);
        void movesPawn(piece *, int, int);
        void movesKnit(piece *, int, int);
        void movesKing(piece *, int, int);
};

#endif
