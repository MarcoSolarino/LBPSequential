//
// Created by marcolarino on 27/03/21.
//

#include "LocalBinaryPattern.h"


Mat localBinaryPattern(Mat& inputImg) {
    Mat imgOut = Mat::zeros(inputImg.rows, inputImg.cols, CV_64FC1);

    for (int i = 0; i< inputImg.rows; i++) {
        for (int j = 0; j < inputImg.cols; j++) {
            vector<int> neighbors = getNeighbors(i, j, inputImg);
            Scalar intensity = inputImg.at<uchar>(i, j);
            int currentPixelGS = intensity.val[0];
            vector<int> differences = computeDifferences(currentPixelGS, neighbors);

            imgOut.at<uchar>(i, j) = doDecimal(differences);
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
        value += diff.at(i) * pow(2, i);
    }

    return value;
}