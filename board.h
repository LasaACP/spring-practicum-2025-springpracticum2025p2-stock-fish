class piece{
    public:
        bool wb;
        int point;
        int moved;
        char type;
        const char* imag;
        piece();
        void setPiece(bool, char);
};


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


class board{
    public:
        tile bor[8][8];
        board();
        tile getTile(int, int);
        void printBoard();
        void moveTile(int, int, piece*);
};


