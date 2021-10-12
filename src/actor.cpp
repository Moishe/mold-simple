//
//  actor.cpp
//  simple-mold
//
//  Created by Moishe Lettvin on 10/10/21.
//

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "ofMain.h"

#include "actor.hpp"
#include "board.hpp"
#include "config.hpp"

bool Actor::move() {
    float ahead = surround_val[d].lengthSquared();
    float left = surround_val[(d - 1) % 8].lengthSquared();
    float right = surround_val[(d + 1) % 8].lengthSquared();
    
    if ((left > right) && (left > ahead)) {
        d = (d - 1) % 8;
    } else if ((right > left) && (right > ahead)) {
        d = (d + 1) % 8;
    }
    
    x = x + idx_to_coords[d * 2];
    y = y + idx_to_coords[d * 2 + 1];
    
    Board *board = Board::getInstance();
    if (x <= 1 || x >= (board->w - 2) || y <= 1 || y >= (board->h - 2)) {
        return false;
    }
    
    return true;
}

// must be called before move.
bool Actor::deposit() {
    Board *board = Board::getInstance();
    // load the surround values
    int r, g, b;
    board->getAt(x, y, &r, &g, &b);
    current_val.set(r, g, b);
    
    ofVec3f totals(current_val);

    int dx, dy;
    for (int idx = 0; idx < 8; idx++) {
        dx = x + idx_to_coords[idx * 2];
        dy = y + idx_to_coords[idx * 2 + 1];
        board->getAt(dx, dy, &r, &g, &b);
        surround_val[idx].set(r, g, b);
        totals += surround_val[idx];
    }
    
    ofVec3f avgs = totals / 9;
    
    for (int idx = 0; idx < 8; idx++) {
        dx = x + idx_to_coords[idx * 2];
        dy = y + idx_to_coords[idx * 2 + 1];
        board->setAt(dx, dy, int(round(avgs.x)), int(round(avgs.y)), int(round(avgs.z)));
    }
    
    current_val += 1;
    board->setAt(x, y, int(round(current_val.x)), int(round(current_val.y)), int(round(current_val.z)))
    
    return true;
}

void Actor::random_initialize() {
    Board *board = Board::getInstance();

    x = rand() % (board->w - 2) + 1;
    y = rand() % (board->h - 2) + 1;
    
    d = rand() % 8;
    
    int r, g, b;
    board->getAt(x, y, &r, &g, &b);
    goal_color.set(r, g, b);
    
    next_free = NULL;
}
