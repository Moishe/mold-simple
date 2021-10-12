#include "ofApp.h"
#include "config.hpp"
#include "board.hpp"
#include "actor.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    Board *board = Board::getInstance();
    board->initialize();
    board->randomize();
    
    window_width = 1024;
    window_height = 768;
    
    actors = (Actor *)malloc(sizeof(Actor) * Config::max_actors);
    for (int i = 0; i < Config::max_actors; i++) {
        if (i < Config::initial_actors) {
            actors[i].random_initialize();
        } else {
            actors[i].next_free = &actors[i - 1];
        }
    }
    
    next_free_actor = &actors[Config::max_actors - 1];
    
    tex.allocate(board->w, board->h, GL_RGB);
}

//--------------------------------------------------------------
void ofApp::update(){
    Board *board = Board::getInstance();

    for (int i = 0; i < Config::max_actors; i++) {
        if (actors[i].next_free == NULL) {
            if (actors[i].deposit()) {
                if (!actors[i].move()) {
                    actors[i].next_free = next_free_actor;
                    next_free_actor = &actors[i];
                }
            }
        }
    }
    
    tex.loadData(board->getWriteBoard());

    board->flipBoard();
}

//--------------------------------------------------------------
void ofApp::draw(){
    Board *board = Board::getInstance();
    ofSetHexColor(0xffffff);

    float ratio = float(window_width) / float(board->w);

    tex.draw(0, 0, 512, 512); //board->w * ratio, board->h * ratio);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    window_width = w;
    window_height = h;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
