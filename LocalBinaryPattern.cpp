//
// Created by marcolarino on 27/03/21.
//

#include "LocalBinaryPattern.h"


Mat localBinaryPattern(Mat& inputImg) {
    Mat imgOut = inputImg;

    for (int i = 0; i< inputImg.rows; i++) {
        for (int j = 0; j < inputImg.cols; j++) {
            vector<int> neighbors = getNeighbors(i, j, inputImg);
        }
    }

    return imgOut;
}

vector<int> getNeighbors(int i, int j, Mat& img) {
    vector<int> neighbors(8, 0);

    if (i == 0) {

        if (j == 0) {

            Scalar intensity = img.at<uchar>(i, j + 1);
            neighbors.at(3) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j + 1);
            neighbors.at(4) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j);
            neighbors.at(5) = intensity.val[0];

        }

        else if (j < img.cols - 1) {
            Scalar intensity = img.at<uchar>(i, j + 1);
            neighbors.at(3) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j + 1);
            neighbors.at(4) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j);
            neighbors.at(5) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j - 1);
            neighbors.at(6) = intensity.val[0];

            intensity = img.at<uchar>(i, j - 1);
            neighbors.at(7) = intensity.val[0];
        }

        else if (j == img.cols - 1) {
            Scalar intensity = img.at<uchar>(i + 1, j);
            neighbors.at(5) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j - 1);
            neighbors.at(6) = intensity.val[0];

            intensity = img.at<uchar>(i, j - 1);
            neighbors.at(7) = intensity.val[0];
        }

    }

    else if (i > 0 && i < img.rows - 1) {

        if (j == 0) {
            Scalar intensity = img.at<uchar>(i - 1, j);
            neighbors.at(1) = intensity.val[0];

            intensity = img.at<uchar>(i - 1, j + 1);
            neighbors.at(2) = intensity.val[0];

            intensity = img.at<uchar>(i, j + 1);
            neighbors.at(3) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j + 1);
            neighbors.at(4) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j);
            neighbors.at(5) = intensity.val[0];
        }

        else if (j < img.cols - 1) {

            Scalar intensity = img.at<uchar>(i - 1, j - 1);
            neighbors.at(0) = intensity.val[0];

            intensity = img.at<uchar>(i - 1, j);
            neighbors.at(1) = intensity.val[0];

            intensity = img.at<uchar>(i - 1, j + 1);
            neighbors.at(2) = intensity.val[0];

            intensity = img.at<uchar>(i, j + 1);
            neighbors.at(3) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j + 1);
            neighbors.at(4) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j);
            neighbors.at(5) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j - 1);
            neighbors.at(6) = intensity.val[0];

            intensity = img.at<uchar>(i, j - 1);
            neighbors.at(7) = intensity.val[0];
        }

        else if (j == img.cols - 1) {
            Scalar intensity = img.at<uchar>(i - 1, j - 1);
            neighbors.at(0) = intensity.val[0];

            intensity = img.at<uchar>(i - 1, j);
            neighbors.at(1) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j);
            neighbors.at(5) = intensity.val[0];

            intensity = img.at<uchar>(i + 1, j - 1);
            neighbors.at(6) = intensity.val[0];

            intensity = img.at<uchar>(i, j - 1);
            neighbors.at(7) = intensity.val[0];
        }
    }

    else {
        if (j == 0) {
            Scalar intensity = img.at<uchar>(i - 1, j);
            neighbors.at(1) = intensity.val[0];

            intensity = img.at<uchar>(i - 1, j + 1);
            neighbors.at(2) = intensity.val[0];

            intensity = img.at<uchar>(i, j + 1);
            neighbors.at(3) = intensity.val[0];
        }

        else if (j < img.cols - 1) {
            Scalar intensity = img.at<uchar>(i - 1, j - 1);
            neighbors.at(0) = intensity.val[0];

            intensity = img.at<uchar>(i - 1, j);
            neighbors.at(1) = intensity.val[0];

            intensity = img.at<uchar>(i - 1, j + 1);
            neighbors.at(2) = intensity.val[0];

            intensity = img.at<uchar>(i, j + 1);
            neighbors.at(3) = intensity.val[0];

            intensity = img.at<uchar>(i, j - 1);
            neighbors.at(7) = intensity.val[0];
        }

        else if (j == img.cols - 1) {
            Scalar intensity = img.at<uchar>(i - 1, j - 1);
            neighbors.at(0) = intensity.val[0];

            intensity = img.at<uchar>(i - 1, j);
            neighbors.at(1) = intensity.val[0];

            intensity = img.at<uchar>(i, j - 1);
            neighbors.at(7) = intensity.val[0];
        }
    }

    return neighbors;
}
