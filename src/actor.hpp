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

class actor {
public:
    int x;
    int y;
    
    int surround_val[3][3][3];
    
    void move();
    bool deposit();
    
    int lx;
    int ly;
    int goal_color[3];
};

#endif /* actor_hpp */
