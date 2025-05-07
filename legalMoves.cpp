#include "..."



void ...::setMoves(piece * p, int x, int y){//gives piece and coordinates for a location of a peice on the board, assuming x: 0-7 inclusive, y: 0-7 inclusive.
    clearMoves(p);
    switch(p->type){
        case "bishop":
            movesBish(p, x, y);
            break;
        case "rook":
            movesRook(p, x, y);
            break;
        case "pawn":
            movesPawn(p, x, y);
            break;
        case "knight":
            movesKnit(p, x, y);
            break;
        case "king":
            movesKing(p, x, y);
            break;
        case "queen":
            movesBish(p, x, y);
            movesRook(p, x, y);
            break;
        default:
            std::cout<<"INVALID PIECE TYPE"<<std::endl;
    }
}

void ...::movesRook(piece * p, int x, int y){
    int x1 = x + 1;
    while(x1 < 8){
        if(board[x1][y].isEmpty){
            p->addMove(x1, y);
        }else if(board[x1][y].cur_piece->color != p->color){
            p->addMove(x1, y);
            break;
        }else{//if piece is same color
            break;
        }
        x1++;
    }
    x1 = x-1;
    while(x1 >= 0){
        if(board[x1][y].isEmpty){
            p->addMove(x1, y);
        }else if(board[x1][y].cur_piece->color != p->color){
            p->addMove(x1, y);
            break;
        }else{//if piece is same color
            break;
        }
        x1--;
    }

    int y1 = y+1;
    while(y1 < 8){
        if(board[x][y1].isEmpty){
            p->addMove(x, y1);
        }else if(board[x][y1].cur_piece->color != p->color){
            p->addMove(x, y1);
            break;
        }else{//if piece is same color
            break;
        }
        y1++;
    }

    y1 = y-1;
    while(y1 >= 0){
        if(board[x][y1].isEmpty){
            p->addMove(x, y1);
        }else if(board[x][y1].cur_piece->color != p->color){
            p->addMove(x, y1);
            break;
        }else{//if piece is same color
            break;
        }
        y1--;
    }

    
}

void ...::movesPawn(piece * p, int x, int y){
    if(p->color = "white"){
        if(y == 7){//should've promoted
            return;
        }
        if(board[x][y+1].isEmpty){
            p->addMove(x, y+1);
            if(y == 1 && board[x][y+2].isEmpty){
                p->addMove(x, y+2);
            }
        }
        if(!board[x+1][y+1].isEmpty && board[x+1][y+1].cur_piece->color != p->color){
            p->addMove(x+1, y+1);
        }
        if(!board[x-1][y+1].isEmpty && board[x-1][y+1].cur_piece->color != p->color){
            p->addMove(x-1, y+1);
        }

        //en passant
        if(y==4 && !board[x+1][y].isEmpty && board[x+1][y].cur_peice->color == "black" && board[x+1][y].cur_piece->type == "pawn"){
            p->addMove(x+1, y+1);
        }
        if(y==4 && !board[x-1][y].isEmpty && board[x-1][y].cur_peice->color == "black" && board[x-1][y].cur_piece->type == "pawn"){
            p->addMove(x-1, y+1);
        }
    }else{//if pawn is black
        if(y == 0){//should've promoted
            return;
        }
        if(board[x][y-1].isEmpty){
            p->addMove(x, y-1);
            if(y == 6 && board[x][y-2].isEmpty){
                p->addMove(x, y-2);
            }
        }
        if(!board[x+1][y-1].isEmpty && board[x+1][y-1].cur_piece->color != p->color){
            p->addMove(x+1, y-1);
        }
        if(!board[x-1][y-1].isEmpty && board[x-1][y-1].cur_piece->color != p->color){
            p->addMove(x-1, y-1);
        }

        //en passant
        if(y==3 && !board[x+1][y].isEmpty && board[x+1][y].cur_peice->color == "black" && board[x+1][y].cur_piece->type == "pawn"){
            p->addMove(x+1, y-1);
        }
        if(y==3 && !board[x-1][y].isEmpty && board[x-1][y].cur_peice->color == "black" && board[x-1][y].cur_piece->type == "pawn"){
            p->addMove(x-1, y-1);
        }
    }
}