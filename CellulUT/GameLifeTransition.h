#ifndef CELLULUT_GAMELIFE_TRANSITION_H
#define CELLULUT_GAMELIFE_TRANSITION_H
#include <iostream>
#include "Transition.h"

class TransitionGameLife : public Transition {

ETAT_NP::Etat& creerTransition(ETAT_NP::Etat* etats, ETAT_NP::Etat& etat, CELLULE_NP::Cellule* voisines, unsigned int nbVoisines) override;
/*
int countNeighbours(int i, int j) {

int living = 0;

// when the starting cell is the one on the upper left (start of the board)
for (i = 0: :i++){
    for (j=0: :j++){


if (i == 0 && j == 0) {

    // cell below
    if (board[i - 1][j] != DEAD) {
        living++;
    }
    // cell right below
    if (board[i + 1][j + 1] != DEAD) {
        living++;
    }
    // cell right
    if (board[i][j + 1] != DEAD) {
        living++;
    }
    // cell above (other side of the board)
    if (board[HEIGHT - 1][j] != DEAD) {
        living++;
    }
    // cell above right (other side of the board)
    if (board[HEIGHT - 1][j + 1] != DEAD) {
        living++;
    }

}

// first edge case (height = 0, width != 0):
else if (i == 0 && j != 0) {
    // cell below
    if (board[i - 1][j] != DEAD) {
        living++;
    }
    // cell right below
    if (board[i + 1][j + 1] != DEAD) {
        living++;
    }
    // cell right
    if (board[i][j + 1] != DEAD) {
        living++;
    }
    // cell left below
    if (board[i + 1][j - 1] != DEAD) {
        living++;
    }
    // cell left
    if (board[i][j - 1] != DEAD) {
        living++;
    }
    // cell left above (other side of the board)
    if (board[HEIGHT - 1][j - 1] != DEAD) {
        living++;
    }
    // cell above (other side of the board)
    if (board[HEIGHT - 1][j] != DEAD) {
        living++;
    }
    // cell above right (other side of the board)
    if (board[HEIGHT - 1][j + 1] != DEAD) {
        living++;
    }
}

return living;

};*/
};

#endif
