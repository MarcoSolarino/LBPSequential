//
// Created by marcolarino on 27/03/21.
//

#ifndef LBPSEQUENTIAL_LOCALBYNARYPATTERN_H
#define LBPSEQUENTIAL_LOCALBYNARYPATTERN_H

#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

Mat localBinaryPattern(Mat& inputImg);

int *getNeighbors(int i, int j, Mat& img);

bool *isGretEq(int gs, int *n);

int toDecimal(bool *diff);

#endif //LBPSEQUENTIAL_LOCALBYNARYPATTERN_H



