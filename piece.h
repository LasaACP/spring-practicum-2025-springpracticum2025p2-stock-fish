#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>

using namespace std;


class piece{
    private:
        bool wb;
        int x;
        int y;
        int point;
        bool moved;
        string type;
        const char* imag;
    public:
        piece();
        vector<string> posMv;
        void setPiece(bool, int, int, string);
        void addMove(int, int);
        void move(int, int);
};

#endif