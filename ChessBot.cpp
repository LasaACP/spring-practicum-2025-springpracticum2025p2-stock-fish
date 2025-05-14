#include "ChessBot.h"
#include <algorithm>

using namespace std;

ChessBot::ChessBot(Color aiColor) : aiColor(aiColor) {}

int ChessBot::pieceValue(Piece p) {
	switch(p) {
	case PAWN:
		return 10;
	case KNIGHT:
		return 30;
	case BISHOP:
		return 30;
	case ROOK:
		return 50;
	case QUEEN:
		return 90;
	case KING:
		return 900;
	default:
		return 0;
	}
}

int ChessBot::evaluateBoard(Square board[8][8]) {
	int score = 0;
	for(int r = 0; r < 8; ++r) {
		for(int c = 0; c < 8; ++c) {
			Square s = board[r][c];
			int val = pieceValue(s.piece);
			if(s.color == aiColor) {
				score += val;
			}
			else if(s.color != NONE) {
				score -= val;
			}
		}
	}
	return score;
}

void ChessBot::copyBoard(Square dest[8][8], const Square src[8][8]) {
	for(int row = 0; row < 8; ++row) {
		for(int col = 0; col < 8; ++col) {
			dest[row][col] = src[row][col];
		}
	}
}

Move ChessBot::findBestMove(Square board[8][8],
                            const vector<Move>& legalMoves,
                            void (*makeMoveFunc)(Square[8][8], const Move&),
                            vector<Move> (*legalMovesFunc)(Square[8][8], Color)) {
	if(legalMoves.empty()) {
		return { -1, -1, -1, -1 };
	}

	int bestEval = -99999;
	Move bestMove = legalMoves[0];

	for(const Move& move : legalMoves) {
	    Square tempBoard[8][8];
		copyBoard(tempBoard, board);

		makeMoveFunc(tempBoard, move);

		int eval = minimax(tempBoard, 1, false,
		                   (aiColor == WHITE ? BLACK : WHITE),
		                   makeMoveFunc, legalMovesFunc);

		if(eval > bestEval) {
			bestEval = eval;
			bestMove = move;
		}
	}

	return bestMove;
}

int ChessBot::minimax(Square board[8][8],
                      int depth,
                      bool isMaximizing,
                      Color currentPlayer,
                      void (*makeMoveFunc)(Square[8][8], const Move&),
                      vector<Move> (*legalMovesFunc)(Square[8][8], Color)) {
	if(depth == 0) {
		return evaluateBoard(board);
	}

	vector<Move> moves = legalMovesFunc(board, currentPlayer);
	
	if(moves.empty()) {
		return evaluateBoard(board);
	}

	int bestEval = isMaximizing ? -99999 : 99999;

	for(const Move& move : moves) {
		Square tempBoard[8][8];
		copyBoard(tempBoard, board);

		makeMoveFunc(tempBoard, move);

		int eval = minimax(tempBoard, depth - 1, !isMaximizing,
		                   (currentPlayer == WHITE ? BLACK : WHITE),
		                   makeMoveFunc, legalMovesFunc);

		if(isMaximizing) {
			bestEval = max(bestEval, eval);
		}
		else {
			bestEval = min(bestEval, eval);
		}
	}

	return bestEval;
}
