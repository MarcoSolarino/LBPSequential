//
// Created by marcolarino on 27/03/21.
//

#include "LocalBinaryPattern.h"

vector<int> weights{1, 2, 4, 8, 16, 32, 64, 128};

Mat localBinaryPattern(Mat& inputImg) {
    Mat imgOut = Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC1);

    for (int i = 0; i< inputImg.rows; i++) {
        for (int j = 0; j < inputImg.cols; j++) {
            vector<int> neighbors = getNeighbors(i, j, inputImg);
            int currentPixelGS = inputImg.at<uchar>(i, j);
            vector<int> differences = computeDifferences(currentPixelGS, neighbors);

            int newVal = doDecimal(differences);
            imgOut.at<uchar>(i, j) = newVal;

            if (imgOut.at<uchar>(i, j) != newVal) {
                printf("Pixel at (%d, %d) was not set correctly", i, j);
            }

        }
    }

    return imgOut;
}


vector<int> getNeighbors(int i, int j, Mat& img) {
    vector<int> neighbors(8, 0);

    if (i == 0) {

        if (j == 0) {

            neighbors.at(3) = img.at<uchar>(i, j + 1);

            neighbors.at(4) = img.at<uchar>(i + 1, j + 1);

            neighbors.at(5) = img.at<uchar>(i + 1, j);

        }

        else if (j < img.cols - 1) {
            neighbors.at(3) = img.at<uchar>(i, j + 1);

            neighbors.at(4) = img.at<uchar>(i + 1, j + 1);

            neighbors.at(5) = img.at<uchar>(i + 1, j);

            neighbors.at(6) = img.at<uchar>(i + 1, j - 1);

            neighbors.at(7) = img.at<uchar>(i, j - 1);
        }

        else if (j == img.cols - 1) {
            neighbors.at(5) = img.at<uchar>(i + 1, j);

            neighbors.at(6) = img.at<uchar>(i + 1, j - 1);

            neighbors.at(7) = img.at<uchar>(i, j - 1);
        }

    }

    else if (i > 0 && i < img.rows - 1) {

        if (j == 0) {
            neighbors.at(1) = img.at<uchar>(i - 1, j);

            neighbors.at(2) = img.at<uchar>(i - 1, j + 1);

            neighbors.at(3) = img.at<uchar>(i, j + 1);

            neighbors.at(4) = img.at<uchar>(i + 1, j + 1);

            neighbors.at(5) = img.at<uchar>(i + 1, j);
        }

        else if (j < img.cols - 1) {

            neighbors.at(0) = img.at<uchar>(i - 1, j - 1);

            neighbors.at(1) = img.at<uchar>(i - 1, j);

            neighbors.at(2) = img.at<uchar>(i - 1, j + 1);

            neighbors.at(3) = img.at<uchar>(i, j + 1);

            neighbors.at(4) = img.at<uchar>(i + 1, j + 1);

            neighbors.at(5) = img.at<uchar>(i + 1, j);

            neighbors.at(6) = img.at<uchar>(i + 1, j - 1);

            neighbors.at(7) = img.at<uchar>(i, j - 1);
        }

        else if (j == img.cols - 1) {
            neighbors.at(0) = img.at<uchar>(i - 1, j - 1);

            neighbors.at(1) = img.at<uchar>(i - 1, j);

            neighbors.at(5) = img.at<uchar>(i + 1, j);

            neighbors.at(6) = img.at<uchar>(i + 1, j - 1);

            neighbors.at(7) = img.at<uchar>(i, j - 1);
        }
    }

    else {
        if (j == 0) {
            neighbors.at(1) = img.at<uchar>(i - 1, j);

            neighbors.at(2) = img.at<uchar>(i - 1, j + 1);

            neighbors.at(3) = img.at<uchar>(i, j + 1);
        }

        else if (j < img.cols - 1) {
            neighbors.at(0) = img.at<uchar>(i - 1, j - 1);

            neighbors.at(1) = img.at<uchar>(i - 1, j);

            neighbors.at(2) = img.at<uchar>(i - 1, j + 1);

            neighbors.at(3) = img.at<uchar>(i, j + 1);

            neighbors.at(7) = img.at<uchar>(i, j - 1);
        }

        else if (j == img.cols - 1) {
            neighbors.at(0) = img.at<uchar>(i - 1, j - 1);

            neighbors.at(1) = img.at<uchar>(i - 1, j);

            neighbors.at(7) = img.at<uchar>(i, j - 1);
        }
    }

    return neighbors;
}


vector<int> computeDifferences(int gs, vector<int> n) {
    vector<int> differences(8, 0);
    for (int i = 0; i < n.size(); i++) {
        if (n.at(i) >= gs)
            differences.at(i) = 1;
    }

    return differences;
}

int doDecimal(vector<int> diff) {
    int value = 0;
    for (int i = 0; i < diff.size(); i++) {
        if (diff.at(i) == 1)
            value += weights.at(i);
    }

    return value;
}