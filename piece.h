#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>

using namespace std;


class piece{
    public:
        piece();
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
};

#endif
