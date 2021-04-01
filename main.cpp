#include <opencv2/opencv.hpp>
#include "LocalBinaryPattern.h"
#include <chrono>

using namespace cv;
using namespace std;

int main() {

    Mat inputImg = imread("../input/img.jpg", 0);
    imshow("Image before LBP", inputImg);
    chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Mat outputImg = localBinaryPattern(inputImg);
    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    long time = chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    cout << time << " milliseconds\n";
    imshow("Image after LBP", outputImg);
    waitKey(0);

    return 0;
}
