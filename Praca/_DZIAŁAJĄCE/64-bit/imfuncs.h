#include <cstdlib>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void insertionSort(int tablica[]);
int sharpen();
int blur();
int contrast_change (double change);
int brigthness_change(double change);
Mat ImageLoad ();
//void ImageSave (Mat *image);
int sepia ();
