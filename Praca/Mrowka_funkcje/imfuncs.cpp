#include <cstdlib>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int sharpen(Mat img){
	Mat kernel(3,3,CV_32F,cv::Scalar(0));	//rozmiar macierzy teorzacej baze filtra
					//nalezy teraz ustaliæ wartoœci macierzy dla tworzonego filtra
	kernel.at(1,1)= 5.0;
	kernel.at(0,1)= -1.0;
	kernel.at(2,1)= -1.0;
	kernel.at(1,0)= -1.0;
	kernel.at(1,2)= -1.0;

			//filtrowanie obrazu
	cv::filter2D(img,img,img.depth(),kernel);

	namedWindow( "Sharpen5", WINDOW_AUTOSIZE );
  imshow( "Sharpen5", img );
  waitKey(0);
  return 0;
}

