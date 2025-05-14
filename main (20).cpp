/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath> 
#include <string>
#include "slist.h"
#include <cstdlib>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;


// void setBoard(){
//     tile board[8][8];
//     const  char* w = "⬜ ";
//     const  char* b = "⬛ ";
//     for(int i = 0; i < 8; i++){
//         for(int j = 0; j < 8; j++){
//           if((i+j)%2 == 1){
//               board[j][i].imag = w;
//               board[j][i].wb = true;
//           }
//           else{
//               board[j][i].imag = b;
//               board[j][i].wb = false;
//           } 
         
//         }
//     }
//     board[0][0].occupied = true;
//     board[0][0]->thePiece = 
//     for(int i = 0; i<8; i++){
//         for(int j = 0; j < 8;j++){

//             cout << board[j][i].imag;

//         }
        
//         cout << endl;
//     }
//         // system(CLEAR);
// }



int main()
{
    board* theBoard = new board;
    

    theBoard->printBoard();
    

    return 0;
}