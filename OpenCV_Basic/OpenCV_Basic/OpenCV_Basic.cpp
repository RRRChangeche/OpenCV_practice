// REMEMBER TO ADD THE OPENCV BIN FOLDER TO THE PATH IN ENVIRONMENTAL VARIABLES
// C:\your_path\opencv\build\install\x64\vc16\bin

#include <iostream>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/cuda.hpp>
#include "utility.h"

using namespace std;
using namespace cv;
using namespace dnn;
using namespace cuda;

/*
* Debug mode log setting 
* https://blog.csdn.net/benobug/article/details/117653268
*/
#define CLOSE_LOG
#ifdef CLOSE_LOG
#include <opencv2/core/utils/logger.hpp>
utils::logging::LogLevel prelevel = utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);
#endif // CLOSE_LOG


int main(int, char**) {
    // print CUDA device information
    //printCudaDeviceInfo(0);


     /*
     * Load and show image from the file 
     */
    //load_and_show_image();


    /*
    * Vediocapture
    */
    //capture_video();


    /*
    * resize the image 
    */
    //resize_image();


    /*
    * Crop image 
    */
    //crop_image();

    /*
    * Translate and rotation image
    */
    //translate_image();
    rotate_image();
}