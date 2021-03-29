#ifndef LBPSEQUENTIAL_LOCALBYNARYPATTERN_H
#define LBPSEQUENTIAL_LOCALBYNARYPATTERN_H

#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

Mat localBinaryPattern(Mat& inputImg);

int *getNeighbors(int i, int j, Mat& img);

bool *isGreatEq(int gs, const int *n);

int toDecimal(const bool *diff, const int *weights);

#endif //LBPSEQUENTIAL_LOCALBYNARYPATTERN_H



