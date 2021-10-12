//
//  board.cpp
//  simple-mold
//
//  Created by Moishe Lettvin on 10/10/21.
//

#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#include "ofMain.h"

#include "board.hpp"
#include "config.hpp"

void Board::initialize() {
    food.allocate(Config::board_w, Config::board_h, OF_PIXELS_RGB);
    
    for (int i = 0; i < 2; i++) {
        board[i].allocate(Config::board_w, Config::board_h, OF_PIXELS_RGB);
    }
    
    w = Config::board_w;
    h = Config::board_h;
}

void Board::randomize() {
    for (int i = 0; i < w * h * sizeof(int) * 3; i++) {
        board[0][i] = board[1][i] = int(round(ofRandom(32)));
    }
}

void Board::flipBoard() {
    read_board = (read_board + 1) % 2;
}

void Board::getAt(int x, int y, int *r, int *g, int *b) {
    int idx = (x + y * w) * 3;
    *r = board[read_board][idx];
    *g = board[read_board][idx + 1];
    *b = board[read_board][idx + 2];
}

void Board::getAt(int x, int y, int *rgb) {
    int idx = x + y * w;
    memmove(rgb, &board[read_board][idx], sizeof(int) * 3);
}

void Board::setAt(int x, int y, int r, int g, int b) {
    int idx = (x + y * w) * 3;
    int write_board = (read_board + 1) % 2;
    board[write_board][idx] = r;
    board[write_board][idx + 1] = g;
    board[write_board][idx + 2] = b;
}

void Board::setAt(int x, int y, int *rgb) {
    int idx = x + y * w;
    memmove(&board[read_board][idx], rgb, sizeof(int) * 3);
}
