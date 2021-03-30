#include "LocalBinaryPattern.h"


Mat localBinaryPattern(Mat& inputImg) {
    const int *weights = new int[8]{1, 2, 4, 8, 16, 32, 64, 128};
    Mat imgOut = Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC1);

    copyMakeBorder(inputImg, inputImg, 1,1,1,1, BORDER_CONSTANT, 0);
    for (int i = 1; i< inputImg.rows - 1; i++) {
        for (int j = 1; j < inputImg.cols - 1; j++) {
            int *neighbors = getNeighbors(i, j, inputImg);
            int currentPixelGS = inputImg.at<uchar>(i, j);
            bool *differences = isGreatEq(currentPixelGS, neighbors);

            int newVal = toDecimal(differences, weights);
            imgOut.at<uchar>(i - 1, j - 1) = newVal;

            delete[] differences;
            delete[] neighbors;
        }
    }

    delete[] weights;
    return imgOut;
}


int *getNeighbors(int i, int j, Mat& img) {
    int *neighbors = new int[8];

    neighbors[0] = img.at<uchar>(i - 1, j - 1);
    neighbors[1] = img.at<uchar>(i - 1, j);
    neighbors[2] = img.at<uchar>(i - 1, j + 1);
    neighbors[3] = img.at<uchar>(i, j + 1);
    neighbors[4] = img.at<uchar>(i + 1, j + 1);
    neighbors[5] = img.at<uchar>(i + 1, j);
    neighbors[6] = img.at<uchar>(i + 1, j - 1);
    neighbors[7] = img.at<uchar>(i, j - 1);

    return neighbors;
}


bool *isGreatEq(int gs, const int *n) {
    bool *differences = new bool [8];
    for (int i = 0; i < 8; i++) {
        if (n[i] >= gs)
            differences[i] = true;
        else
            differences[i] = false;
    }
    return differences;
}


int toDecimal(const bool *diff, const int *weights) {
    int value = 0;

    for (int i = 0; i < 8; i++) {
        if (diff[i])
            value += weights[i];
    }
    return value;
}