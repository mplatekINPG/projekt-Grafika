#include <opencv2/core/core.hpp>
 #include <opencv2/highgui/highgui.hpp>
 #include <iostream>
 using namespace cv;
 using namespace std;

     int main()
    {
        Mat image1, image2;
        image1 = imread("lena.bmp", CV_LOAD_IMAGE_COLOR);
        namedWindow("Color Image", WINDOW_AUTOSIZE);

    }
