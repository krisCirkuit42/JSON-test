#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);

    // load JSON file from bin/data
    std::string path = ofToDataPath("/Users/kris1hillquist/creativeCoding/of_v0.12.0_osx_release/apps/myApps/JSON load test/bin/data/alwayson_phrases.json", true);

    if(ofFile::doesFileExist(path)){
        ofLogNotice() << "Loading JSON from " << path;
        ofFile file(path);
        file >> phrases;  // ofJson automatically parses

        ofLogNotice() << "Loaded " << phrases.size() << " records";

        // preview first 5 records
        int preview = std::min((int)phrases.size(), 5);
        for(int i = 0; i < preview; i++){
            auto &rec = phrases[i];
            ofLogNotice() << "[" << i << "] "
                          << rec["timestamp"].get<std::string>() << " | "
                          << rec["family"].get<std::string>() << " | "
                          << rec["keyword"].get<std::string>();
        }
    } else {
        ofLogError() << "JSON file not found: " << path;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(220);
    ofDrawBitmapString("Check console for JSON load log", 20, 20);
}

