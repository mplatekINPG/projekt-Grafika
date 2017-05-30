#include <cstdlib>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void insertionSort(int tablica[]);
int sharpen(Mat image);
int blur(Mat image);
int contrast_change (Mat image);
void ImageLoad (Mat *image);
void ImageSave (Mat *image);
