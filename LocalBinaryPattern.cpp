#include "LocalBinaryPattern.h"


Mat localBinaryPattern(Mat& inputImg) {
    const int *weights = new int[8]{1, 2, 4, 8, 16, 32, 64, 128};
    Mat imgOut = Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC1);

    for (int i = 0; i< inputImg.rows; i++) {
        for (int j = 0; j < inputImg.cols; j++) {
            int *neighbors = getNeighbors(i, j, inputImg);
            int currentPixelGS = inputImg.at<uchar>(i, j);
            bool *differences = isGreatEq(currentPixelGS, neighbors);

            int newVal = toDecimal(differences, weights);
            imgOut.at<uchar>(i, j) = newVal;

            if (imgOut.at<uchar>(i, j) != newVal) {
                printf("Pixel at (%d, %d) was not set correctly", i, j);
            }

            delete[] neighbors;
            delete[] differences;
        }
    }
    return imgOut;
}


int *getNeighbors(int i, int j, Mat& img) {
    int *neighbors = new int[8];

    if (i == 0) {

        if (j == 0) {
            neighbors[3] = img.at<uchar>(i, j + 1);
            neighbors[4] = img.at<uchar>(i + 1, j + 1);
            neighbors[5] = img.at<uchar>(i + 1, j);
        }

        else if (j < img.cols - 1) {
            neighbors[3] = img.at<uchar>(i, j + 1);
            neighbors[4] = img.at<uchar>(i + 1, j + 1);
            neighbors[5] = img.at<uchar>(i + 1, j);
            neighbors[6] = img.at<uchar>(i + 1, j - 1);
            neighbors[7] = img.at<uchar>(i, j - 1);
        }

        else if (j == img.cols - 1) {
            neighbors[5] = img.at<uchar>(i + 1, j);
            neighbors[6] = img.at<uchar>(i + 1, j - 1);
            neighbors[7] = img.at<uchar>(i, j - 1);
        }

    }

    else if (i > 0 && i < img.rows - 1) {

        if (j == 0) {
            neighbors[1] = img.at<uchar>(i - 1, j);
            neighbors[2] = img.at<uchar>(i - 1, j + 1);
            neighbors[3] = img.at<uchar>(i, j + 1);
            neighbors[4] = img.at<uchar>(i + 1, j + 1);
            neighbors[5] = img.at<uchar>(i + 1, j);
        }

        else if (j < img.cols - 1) {
            neighbors[0] = img.at<uchar>(i - 1, j - 1);
            neighbors[1] = img.at<uchar>(i - 1, j);
            neighbors[2] = img.at<uchar>(i - 1, j + 1);
            neighbors[3] = img.at<uchar>(i, j + 1);
            neighbors[4] = img.at<uchar>(i + 1, j + 1);
            neighbors[5] = img.at<uchar>(i + 1, j);
            neighbors[6] = img.at<uchar>(i + 1, j - 1);
            neighbors[7] = img.at<uchar>(i, j - 1);
        }

        else if (j == img.cols - 1) {
            neighbors[0] = img.at<uchar>(i - 1, j - 1);
            neighbors[1] = img.at<uchar>(i - 1, j);
            neighbors[5] = img.at<uchar>(i + 1, j);
            neighbors[6] = img.at<uchar>(i + 1, j - 1);
            neighbors[7] = img.at<uchar>(i, j - 1);
        }
    }

    else {
        if (j == 0) {
            neighbors[1] = img.at<uchar>(i - 1, j);
            neighbors[2] = img.at<uchar>(i - 1, j + 1);
            neighbors[3] = img.at<uchar>(i, j + 1);
        }

        else if (j < img.cols - 1) {
            neighbors[0] = img.at<uchar>(i - 1, j - 1);
            neighbors[1] = img.at<uchar>(i - 1, j);
            neighbors[2] = img.at<uchar>(i - 1, j + 1);
            neighbors[3] = img.at<uchar>(i, j + 1);
            neighbors[7] = img.at<uchar>(i, j - 1);
        }

        else if (j == img.cols - 1) {
            neighbors[0] = img.at<uchar>(i - 1, j - 1);
            neighbors[1] = img.at<uchar>(i - 1, j);
            neighbors[7] = img.at<uchar>(i, j - 1);
        }
    }

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