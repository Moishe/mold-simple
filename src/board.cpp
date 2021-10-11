//
//  board.cpp
//  simple-mold
//
//  Created by Moishe Lettvin on 10/10/21.
//

#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#include "board.hpp"
#include "config.hpp"

void Board::initialize() {
    food = NULL;
    
    for (int i = 0; i < 2; i++) {
        board[i] = (int *)malloc(Config::board_x * Config::board_y * sizeof(int) * 3);
        memset(board[i], 0, Config::board_x * Config::board_x * sizeof(int) * 3);
    }
    
    w = Config::board_x;
    h = Config::board_y;
}

void Board::flipBoard() {
    cur_board = (cur_board + 1) % 2;
}

void Board::getAt(int x, int y, int *channels[3]) {
    int idx = x + y * w;
    memmove(channels, &board[cur_board][idx], 3 * sizeof(int));
}
