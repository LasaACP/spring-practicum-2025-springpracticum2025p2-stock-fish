#ifndef CHESS_BOT_H
#define CHESS_BOT_H

#include <vector>

using namespace std;

enum Piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };
enum Color { NONE, WHITE, BLACK };

struct Square {
    Piece piece;
    Color color;
};

struct Move {
    int fromRow, fromCol;
    int toRow, toCol;
};

class ChessBot {
public:
    explicit ChessBot(Color aiColor);

    Move findBestMove(Square board[8][8],
                      const std::vector<Move>& legalMoves,
                      void (*makeMoveFunc)(Square[8][8], const Move&),
                      vector<Move> (*legalMovesFunc)(Square[8][8], Color));

private:
    Color aiColor;

    int pieceValue(Piece p);
    int evaluateBoard(Square board[8][8]);
    void copyBoard(Square dest[8][8], const Square src[8][8]);

    int minimax(Square board[8][8],
                int depth,
                bool isMaximizing,
                Color currentPlayer,
                void (*makeMoveFunc)(Square[8][8], const Move&),
                vector<Move> (*legalMovesFunc)(Square[8][8], Color));
};

#endif // CHESS_BOT_H
