//
// Created by marcolarino on 03/05/21.
//

#include <opencv2/opencv.hpp>
#include <chrono>
#include "LocalBinaryPattern.h"

using namespace cv;
using namespace std;
using namespace std::chrono;


int* testWithIncreasingSize(int numTests, int N) {
    int *time =  (int*) malloc(sizeof(int) * numTests) ;
    String imgName = "img.jpg";
    Mat inputImg = imread("../input/" + imgName, 0);

    for (int i = 0; i < numTests; i++) {
        //creating at each iteration a larger image
        if(i != 0)
            copyMakeBorder(inputImg, inputImg, (inputImg.rows/2), (inputImg.rows/2), (inputImg.cols/2), (inputImg.cols/2), BORDER_CONSTANT, 0);

        // evaluating the mean time for each iteration
        int partialSum = 0;
        for (int j = 0; j < N; j++) {
            auto start = chrono::high_resolution_clock::now();
            localBinaryPattern(inputImg);
            auto end = chrono::high_resolution_clock::now();
            auto ms_int = duration_cast<chrono::milliseconds>(end - start);

            partialSum += ms_int.count();
        }

        time[i] = partialSum / N;
        cout << "iteration with a " << inputImg.cols << " X " << inputImg.rows << " ended in " << time[i] << " milliseconds \n";
    }

    return time;
}