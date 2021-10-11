//
//  actor.cpp
//  simple-mold
//
//  Created by Moishe Lettvin on 10/10/21.
//

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#include "actor.hpp"
#include "board.hpp"

void actor::move() {

}

// must be called before move.
bool actor::deposit() {
    Board *board = Board::getInstance();
    // load the surround values
    int total;
    int channels[3];
    memset(surround_val, 0, sizeof(surround_val));
    for (int dx = std::max(0, x - 1); dx < std::min(board->w, x + 1); dx++) {
        for (int dy = std::max(0, y -1); dy < std::min(board->h, y + 1); dy++) {
            board->getAt(dx, dy, &surround_val[dx][dy]);
        }
    }
    
    return true;
}
