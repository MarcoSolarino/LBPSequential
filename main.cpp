#include <opencv2/opencv.hpp>
#include <iostream>
#include "LocalBinaryPattern.h"

using namespace cv;
using namespace std;

int main() {

    // read the input image and launch LBP
    Mat inputImg = imread("../input/img.jpg", 0);
    Mat outputImg = localBinaryPattern(inputImg);

    namedWindow("Image", WINDOW_AUTOSIZE );
    imshow("Image before LBP", inputImg);
    imshow("Image after LBP", outputImg);
    waitKey(0);

    return 0;
}
