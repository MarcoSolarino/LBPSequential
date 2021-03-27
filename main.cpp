#include <opencv2/opencv.hpp>
#include <iostream>
#include "LocalBinaryPattern.h"

using namespace cv;
using namespace std;

int main() {

    // read the input image and launch LBP
    Mat inputImg = imread("../input/img.jpg", 0);
    Mat outputImg = localBinaryPattern(inputImg);

    return 0;
}
