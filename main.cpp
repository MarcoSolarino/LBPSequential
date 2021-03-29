#include <opencv2/opencv.hpp>
#include "LocalBinaryPattern.h"

using namespace cv;
using namespace std;

int main() {

    Mat inputImg = imread("../input/img.jpg", 0);
    Mat outputImg = localBinaryPattern(inputImg);

    imshow("Image before LBP", inputImg);
    imshow("Image after LBP", outputImg);
    waitKey(0);

    return 0;
}
