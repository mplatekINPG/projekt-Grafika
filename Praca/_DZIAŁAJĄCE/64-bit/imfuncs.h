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
Mat ImageLoad ();
//void ImageSave (Mat *image);
int sepia (Mat img);
