#include "utility.h"
#include <iostream>

using namespace std;
using namespace cv;
using namespace cv::dnn;

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

void capture_video_from_webCam() {
	/*
	* Ref: https://docs.opencv.org/4.x/d8/dfe/classcv_1_1VideoCapture.html
	* #include <opencv2/videoio.hpp>
	*/

	VideoCapture cap(0);	// open default camera
	Mat frame;

	// check if we succeeded
	if (!cap.isOpened()) {
		cerr << "ERROR! Unable to open camera\n";
	}

	while (true) {
		cap.read(frame);
		if (frame.empty()) break;
		imshow("Live", frame);
		if (waitKey(5) >= 0) break;
	}
}

void resize_image()
{
	/*
	* Ref: https://docs.opencv.org/4.5.5/da/d54/group__imgproc__transform.html#ga47a974309e9102f5f08231edc7e7529d
	* https://learnopencv.com/image-resizing-with-opencv/
	* #include <opencv2/imgproc.hpp>
	* Resizing With a Scaling Factor
	*/

	string path = "./data/dog.jpg";
	Mat img = imread(path);
	Mat img_resize;
	resize(img, img_resize, Size(), 0.5, 0.5);
	imshow("Origin", img);
	imshow("Resized", img_resize);
	waitKey(0);
}

void crop_image()
{
	/*
	* Ref: https://learnopencv.com/cropping-an-image-using-opencv/
	* Range(start, end)
	* Mat(row_range, col_range)
	*/
	string path = "./data/dog.jpg";
	Mat img = imread(path);
	int W = img.size().width, H = img.size().height;
	int pad = 50;

	// crop image by using range
	Mat cropped_img = img(Range(pad, H-pad), Range(pad, W-pad));

	// show image
	imshow("Origin", img);
	imshow("Cropped", cropped_img);
	waitKey(0);
}

void translate_image()
{
	/*
	* Ref: https://learnopencv.com/image-rotation-and-translation-using-opencv/
	* warpAffine(img, translated_img, translation_matrix, img.size())
	*/
	string path = "./data/dog.jpg";
	Mat img = imread(path);
	Mat translated_img;

	// translate 
	float tx = 100.0;
	float ty = 100.0;

	// create the translation matrix using tx and ty
	float warp_values[] = { 1.0, 0.0, tx, 0.0, 1.0, ty };
	cv::Mat translation_matrix = Mat(2, 3, CV_32F, warp_values);

	// apply affine transformation
	cv::warpAffine(img, translated_img, translation_matrix, img.size());

	imshow("Translation", translated_img);
	waitKey(0);
}

void rotate_image()
{
	/*
	* Ref: https://learnopencv.com/image-rotation-and-translation-using-opencv/
	* getRotationMatrix2D(center, angle, scale)
	* warpAffine(img, rotated_img, rotation_matrix, img.size())
	*/
	string path = "./data/dog.jpg";
	Mat img = imread(path);
	Mat rotated_img;

	// create the rotation matrix using getRotationMatrix2D
	cv::Point2f center((img.cols - 1) / 2.0, (img.rows - 1) / 2.0);
	int angle = 45;
	float scale = 1.0;
	cv::Mat rotation_matrix = cv::getRotationMatrix2D(center, angle, scale);

	// apply affine transformation
	cv::warpAffine(img, rotated_img, rotation_matrix, img.size());

	imshow("Rotation", rotated_img);
	waitKey(0);
}
