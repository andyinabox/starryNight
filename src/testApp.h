#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"

#include "ofxGui.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// image grabbing
		int camWidth;
		int camHeight;
		ofVideoGrabber cam;

		// image manipulation
		ofxCvColorImage cvColorImage;
		ofxCvGrayscaleImage	cvGreyImage;
		std::vector< cv::Point2f > corners;

		// gui
		ofxPanel gui;
		ofxIntSlider maxCorners;
		ofxFloatSlider minDistance;
		ofxFloatSlider maxStarSize;
		ofxFloatSlider minStarSize;

		
};
