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
    void randomize();
    
    ofPixels food;
    ofPixels board[2];
    int w,h;
    
    int read_board;
    
    void flipBoard();
    ofPixels &getWriteBoard() {
        return board[(read_board + 1) % 2];
    }
    
    void getAt(int x, int y, int *r, int *g, int *b);
    void getAt(int x, int y, int *rgb);
    void setAt(int x, int y, int *rgb);
    void setAt(int x, int y, int r, int g, int b);

private:
    Board() {};
};

#endif /* board_hpp */
