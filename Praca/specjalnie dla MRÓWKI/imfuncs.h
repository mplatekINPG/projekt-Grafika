#include <cstdlib>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void insertionSort(int tablica[]);
int sharpen(char* filenaem);
int blur(char* filenaem);
int contrast_change (double change,char* filenaem);
int brigthness_change(double change,char* filenaem);
Mat ImageLoad (char* filenaem);
//void ImageSave (Mat *image);
int sepia (char* filenaem);
