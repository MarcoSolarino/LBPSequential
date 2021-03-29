//
// Created by marcolarino on 27/03/21.
//

#include "LocalBinaryPattern.h"


Mat localBinaryPattern(Mat& inputImg) {

    Mat imgOut = Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC1);

    for (int i = 0; i< inputImg.rows; i++) {
        for (int j = 0; j < inputImg.cols; j++) {
            int *neighbors = getNeighbors(i, j, inputImg);
            int currentPixelGS = inputImg.at<uchar>(i, j);
            bool *differences = isGretEq(currentPixelGS, neighbors);

            int newVal = toDecimal(differences);
            imgOut.at<uchar>(i, j) = newVal;

            if (imgOut.at<uchar>(i, j) != newVal) {
                printf("Pixel at (%d, %d) was not set correctly", i, j);
            }
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


bool *isGretEq(int gs, int *n) {

    bool *differences = new bool [8];
    for (int i = 0; i < 8; i++) {
        if (n[i] >= gs)
            differences[i] = true;
        else
            differences[i] = false;
    }
    return differences;
}

int toDecimal(bool *diff) {
    int value = 0;
    int weight = 1;

    for (int i = 0; i < 8; i++) {
        if (diff[i] == true)
            value += weight;
        weight = weight << 1 ;
    }
    return value;
}