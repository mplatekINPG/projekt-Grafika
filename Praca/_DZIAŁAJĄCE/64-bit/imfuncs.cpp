#include <cstdlib>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Mat ImageLoad ()
{
	Mat image;
	image = imread("lena.bmp", CV_LOAD_IMAGE_COLOR);
	if ( !image.data ) 
	{cout<<"BLAD WCZYTYWANIA";}
	namedWindow("Color Image", WINDOW_AUTOSIZE);
    imshow("Color Image", image);
    return image;
}

//void ImageSave (Mat * image);
/*{
	cout<<"Podaj nazwe nowego pliku\n";
	char *name = new char[50];
	cin>>name;
	cvSaveImage(name, *image);
	delete [] name;
	return;
}*/

void insertionSort(int tablica[])
{
    int temp, i , j;
    for(i = 0; i < 9; i++){
        temp = tablica[i];
        for(j = i-1; j >= 0 && temp < tablica[j]; j--){
            tablica[j+1] = tablica[j];
        }
        tablica[j+1] = temp;
    }
}
int sharpen()
{
	Mat image = ImageLoad();
	Mat kernel(3,3,CV_32F,cv::Scalar(0));	//rozmiar macierzy teorzacej baze filtra
					//nalezy teraz ustali� warto�ci macierzy dla tworzonego filtra
	kernel.at<double>(1,1)= 5.0;
	kernel.at<double>(0,1)= -1.0;
	kernel.at<double>(2,1)= -1.0;
	kernel.at<double>(1,0)= -1.0;
	kernel.at<double>(1,2)= -1.0;

			//filtrowanie obrazu
	cv::filter2D(image,image,image.depth(),kernel);

	namedWindow( "Sharpen5", WINDOW_AUTOSIZE );
  imshow( "Sharpen5", image );
  waitKey(0);
  return 0;
}

int blur()
{
	Mat image = ImageLoad();
    Mat next;
    if( !image.data )
    {
        return -1;
    }
    //stworzenie tablicy 3x4 do "jezdzenia po obrazku"
    int tablica[9];
    next = image.clone();                     //przekopiowanie tablicy do drugiej
    for(int y = 0; y < image.rows; y++)
        for(int x = 0; x < image.cols; x++)
            next.at<uchar>(y,x) = 0.0;

        for(int y = 1; y < image.rows - 1; y++){
            for(int x = 1; x < image.cols - 1; x++){
                tablica[0] = image.at<uchar>(y - 1 ,x - 1);
                tablica[1] = image.at<uchar>(y, x - 1);
                tablica[2] = image.at<uchar>(y + 1, x - 1);
                tablica[3] = image.at<uchar>(y - 1, x);
                tablica[4] = image.at<uchar>(y, x);
                tablica[5] = image.at<uchar>(y + 1, x);
                tablica[6] = image.at<uchar>(y - 1, x + 1);
                tablica[7] = image.at<uchar>(y, x + 1);
                tablica[8] = image.at<uchar>(y + 1, x + 1);
                insertionSort(tablica);
                // przypisanie mediany do wyorodkowanego elementu tablicy
                next.at<uchar>(y,x) = tablica[4];
            }
        }
        //wyowietlenie obu obrazk�w
        namedWindow("final");
        imshow("final", next);
        namedWindow("initial");
        imshow("initial", image);
        return 0;
}

int contrast_change (double change)
{
	Mat image = ImageLoad();
	Mat new_image = Mat::zeros( image.size(), image.type() ); 
	image.convertTo(new_image, -1, change, 0);
    imshow("final", new_image);
	return 0;
}
int brigthness_change(double change)
{
	Mat image = ImageLoad();
	Mat new_image = Mat::zeros( image.size(), image.type() ); 
	image.convertTo(new_image, -1, 1, change);
    imshow("final", new_image);
	return 0;	
}

int sepia ()
{
Mat img = ImageLoad();
Mat_<float> sepia(3,3); 

sepia << .131,.534,.272    //warto�ci najczesciej uzywane w uzyskiwaniu sepii
        ,.168,.686,.349
        ,.189,.769,.393;
Mat out;
cv::transform(img,out,sepia);
imshow("i",out);
waitKey();
  return 0;
}

