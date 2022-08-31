#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>    // this project used  
#include <opencv2/cudaimgproc.hpp>  // this project used
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudafilters.hpp>
#include <opencv2/cudabgsegm.hpp>
#include <opencv2/cudacodec.hpp>
#include <opencv2/cudaobjdetect.hpp>
#include <opencv2/cudaoptflow.hpp>
#include <opencv2/cudastereo.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv2/cudafeatures2d.hpp>

using namespace std;
using namespace cv;

VideoCapture cap(0);

int main(int argc, char** argv)
{
    // Print GPU info
    cuda::printCudaDeviceInfo(0);

    // Setup variables and matrices
    Mat img;
    cuda::GpuMat imgGpu;
    vector<cuda::GpuMat> gpuMats;
    cuda::GpuMat mat;


    while (cap.isOpened()) {

        auto start = getTickCount();

        cap.read(img);

        imgGpu.upload(img);

        // Core operations
        cuda::cvtColor(imgGpu, imgGpu, COLOR_BGR2GRAY);
        //cvtColor(img, img, COLOR_BGR2GRAY); // withour GPU
        //cuda::transpose(imgGpu, imgGpu);

        // Core operations without GPU
        cuda::split(imgGpu, gpuMats);
        // cout << gpuMats.size() << endl;

        // Do the operations 
        //cuda::merge(gpuMats, imgGpu);

        // Elements wise operations
        cuda::threshold(imgGpu, imgGpu, 100, 255, THRESH_BINARY);
        //threshold(img, img, 100, 255, THRESH_BINARY);   // without GPU

        // Matrix operations
        cuda::normalize(imgGpu, imgGpu, 0, 1, NORM_MINMAX, CV_32F);
        //normalize(img, img, 0, 1, NORM_MINMAX, CV_32F); // without GPU

        imgGpu.download(img);

        auto end = getTickCount();
        auto totalTime = (end - start) / getTickFrequency();
        auto fps = 1 / totalTime;

        putText(img, "FPS: " + to_string(int(fps)), Point(50, 50), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 2, false);
        imshow("Image", img);


        if (waitKey(1) == 'q') {
            break;
        }

    }

    cap.release();
    destroyAllWindows();

    return 0;
}