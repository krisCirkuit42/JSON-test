#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    void setup() override;
    void draw() override;

    ofJson phrases;   // storage for the loaded JSON
};

