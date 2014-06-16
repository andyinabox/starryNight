#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(15);

	camWidth = 640;
	camHeight = 480;

	cam.setVerbose(true);
	cam.initGrabber(camWidth, camHeight);

	cvColorImage.allocate(camWidth, camHeight);
	cvGreyImage.allocate(camWidth, camHeight);

	cout << "camWidth: " << camWidth << ", camHeight: " << camHeight << endl;
}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(0,0,0);

	cam.update();
    bool newFrame = cam.isFrameNew();

    if(newFrame) {
    	// create cv image from cam
    	cvColorImage.setFromPixels(cam.getPixels(), camWidth, camHeight);
    	cvGreyImage = cvColorImage;

    	// create intermediary cv image
    	// IplImage *tmp = cvCreateImage(cvGetSize(cvImage.getCvImage()), IPL_DEPTH_8U, 1);
    	
    	// I guess the goodFeaturesToTrack method wants type Mat, not IplImage
    	cv::Mat img = cv::Mat(cvGreyImage.getCvImage(), true);

    	// these should all go in a HUD

		// maxCorners – The maximum number of corners to return. If there are more corners
		// than that will be found, the strongest of them will be returned
    	int maxCorners = 50;

    	// qualityLevel – Characterizes the minimal accepted quality of image corners;
		// the value of the parameter is multiplied by the by the best corner quality
		// measure (which is the min eigenvalue, see cornerMinEigenVal() ,
		// or the Harris function response, see cornerHarris() ).
		// The corners, which quality measure is less than the product, will be rejected.
		// For example, if the best corner has the quality measure = 1500,
		// and the qualityLevel=0.01 , then all the corners which quality measure is
		// less than 15 will be rejected.
  		double qualityLevel = 0.01;

  		// minDistance – The minimum possible Euclidean distance between the returned corners
		double minDistance = 10.0;

		// blockSize – Size of the averaging block for computing derivative covariation
		// matrix over each pixel neighborhood, see cornerEigenValsAndVecs()
		int blockSize = 3;

		// useHarrisDetector – Indicates, whether to use operator or cornerMinEigenVal()
		bool useHarrisDetector = true;

		// k – Free parameter of Harris detector
		double k = 0.04;

		// the coreners array is an array of cv::Point2f objects
    	cv::goodFeaturesToTrack(img, corners, maxCorners, qualityLevel, minDistance, cv::Mat(), blockSize, useHarrisDetector, k);

    	cout << "Number of corners detected: " << corners.size() << endl;

    }

}

//--------------------------------------------------------------
void testApp::draw(){
	ofClear(0,0,0);

	// draw the input
	cam.draw(0,0);

	// draw the points
	ofPushMatrix();

		ofTranslate(camWidth, 0);

		for( int i = 0; i < corners.size(); i++ ) {
			ofCircle(corners[i].x, corners[i].y, 1);
		}

	ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
