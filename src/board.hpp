//
//  board.hpp
//  simple-mold
//
//  Created by Moishe Lettvin on 10/10/21.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>

class Board {
public:
    static Board *getInstance() {
        static Board instance;
        return &instance;
    }
    
    void initialize();
    
    int *food;
    int *board[2];
    int w,h;
    
    int cur_board;
    
    void flipBoard();
    
    void getAt(int x, int y, int *channels[3]);
    
private:
    Board() {};
};

#endif /* board_hpp */
