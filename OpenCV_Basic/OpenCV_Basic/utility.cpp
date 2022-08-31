#include "utility.h"

using namespace std;
using namespace cv;

void load_and_show_image() {
	/*
	* Ref: https://docs.opencv.org/4.5.5/d7/dfc/group__highgui.html#ga453d42fe4cb60e5723281a89973ee563
	* #include <opencv2/imgcodecs.hpp>
	* #include <opencv2/highgui.hpp> 
	*/

	// read image from the file 
	string path = "./data/dog.jpg";
	//Mat img = imread(path, IMREAD_GRAYSCALE);
	Mat img = imread(path);
	// show image on new window
	imshow("Demo", img);
	// must end with waitKey
	waitKey(0);
}


void capture_video() {
	/*
	* Ref: https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html
	* #include <opencv2/videoio.hpp>
	*/

	VideoCapture cap(0);	// open default camera
	Mat frame;
	while (true) {
		cap.read(frame);
		if (frame.empty()) break;
		imshow("Live", frame);
		if (waitKey(5) >= 0) break;
	}

}

