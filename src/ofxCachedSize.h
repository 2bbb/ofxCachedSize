//
//  ofxCachedSize.h
//

#ifndef ofxCachedSize_h
#define ofxCachedSize_h

#include "ofMain.h"

struct ofxCachedSize {
    static ofxCachedSize &shared() {
        static ofxCachedSize _;
        return _;
    }
    
    void windowResized(ofResizeEventArgs &arg) {
        screenSize.set(ofGetScreenWidth(), ofGetScreenHeight());
        windowSize = ofGetWindowSize();
        width = arg.width;
        height = arg.height;
    }
    
    ofPoint windowSize;
    ofPoint screenSize;
    int width;
    int height;
private:
    ofxCachedSize() {
        ofResizeEventArgs arg(ofGetWidth(), ofGetHeight());
        windowResized(arg);
        ofAddListener(ofEvents().windowResized, this, &ofxCachedSize::windowResized);
    }
};

static inline int ofxGetScreenWidth() {
    return ofxCachedSize::shared().screenSize.x;
}

static inline int ofxGetScreenHeight() {
    return ofxCachedSize::shared().screenSize.y;
}

static inline ofPoint ofxGetScreenSize() {
    return ofxCachedSize::shared().screenSize;
}

static inline int ofxGetWidth() {
    return ofxCachedSize::shared().width;
}

static inline int ofxGetHeight() {
    return ofxCachedSize::shared().height;
}

static inline ofPoint ofxGetWindowSize() {
    return ofxCachedSize::shared().windowSize;
}

static inline int ofxGetWindowWidth() {
    return ofxCachedSize::shared().windowSize.x;
}

static inline int ofxGetWindowHeight() {
    return ofxCachedSize::shared().windowSize.y;
}

static inline ofRectangle ofxGetWindowRect() {
    return ofRectangle(0, 0, ofxGetWindowWidth(), ofxGetWindowHeight());
}

#endif /* ofxCachedSize_h */
