//
//  config.hpp
//  simple-mold
//
//  Created by Moishe Lettvin on 10/10/21.
//

#ifndef config_hpp
#define config_hpp

#include <stdio.h>

class Config {
public:
    static const int board_w = 512;
    static const int board_h = 512;
    
    static const int max_actors = 512 * 512;
    static const int initial_actors = 256;
    
    constexpr static float blur_amount = 0.01;
};

#endif /* config_hpp */
