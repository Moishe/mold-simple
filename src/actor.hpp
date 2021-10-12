//
//  actor.hpp
//  simple-mold
//
//  Created by Moishe Lettvin on 10/10/21.
//

#ifndef actor_hpp
#define actor_hpp

#include <stdio.h>
#include "board.hpp"

class Actor {
public:
    Actor() {
        x = 1;
        y = 1;
        d = 0;

        next_free = NULL;
    }
    
    void random_initialize();

    bool move();
    bool deposit();

    // calculated at spawn time
    ofVec3f goal_color;
    
    // calculated at deposit time
    ofVec3f surround_val[8];
    ofVec3f current_val;

    int x;
    int y;
    int d;
    
    constexpr static const int idx_to_coords[] = {
        -1, -1, // NW
         0, -1, // N
         1, -1, // NE
         1,  0, // E
         1,  1, // SE
         0,  1, // S
        -1,  1, // SW
        -1,  0, // W
    };
    
    Actor *next_free;
};

#endif /* actor_hpp */
