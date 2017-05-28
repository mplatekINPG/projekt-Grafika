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
					//nalezy teraz ustali� warto�ci macierzy dla tworzonego filtra
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
int blur(Mat src)
{
    Mat next;
    if( !src.data )
    {
        return -1;
    }
    //stworzenie tablicy 3x4 do "jezdzenia po obrazku"
    int tablica[9];
    next = src.clone();                     //przekopiowanie tablicy do drugiej
    for(int y = 0; y < src.rows; y++)
        for(int x = 0; x < src.cols; x++)
            next.at<uchar>(y,x) = 0.0;

        for(int y = 1; y < src.rows - 1; y++){
            for(int x = 1; x < src.cols - 1; x++){
                tablica[0] = src.at<uchar>(y - 1 ,x - 1);
                tablica[1] = src.at<uchar>(y, x - 1);
                tablica[2] = src.at<uchar>(y + 1, x - 1);
                tablica[3] = src.at<uchar>(y - 1, x);
                tablica[4] = src.at<uchar>(y, x);
                tablica[5] = src.at<uchar>(y + 1, x);
                tablica[6] = src.at<uchar>(y - 1, x + 1);
                tablica[7] = src.at<uchar>(y, x + 1);
                tablica[8] = src.at<uchar>(y + 1, x + 1);
                insertionSort(tablica);
                // przypisanie mediany do wyorodkowanego elementu tablicy
                next.at<uchar>(y,x) = tablica[4];
            }
        }
        //wyowietlenie obu obrazk�w
        namedwindow("final");
        imshow("final", next);
        namedwindow("initial");
        imshow("initial", src);
        return 0;
}
