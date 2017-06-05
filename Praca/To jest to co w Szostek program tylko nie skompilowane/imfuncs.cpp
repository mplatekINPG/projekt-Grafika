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
    Mat new_image = Mat::zeros( Image.size(), Image.type() );
    namedWindow("Wyostrzenie", WINDOW_AUTOSIZE );
    cv::addWeighted(image, 1.5, new_image, -0.5, 0, image);
    imshow("Wyostrzenie", new_image);
    waitKey(0);
    return 0;
}

int blur()
{
	Mat Image = ImageLoad();
    Mat new_image = Mat::zeros( Image.size(), Image.type() );
    namedWindow("Rozmycie", WINDOW_AUTOSIZE );
    blur( Image, new_image, Size( 5, 5 ), Point(-1,-1) );
    imshow("Rozmycie", new_image);
    waitKey(0);
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

sepia << .131,.534,.272    //wartoœci najczesciej uzywane w uzyskiwaniu sepii
        ,.168,.686,.349
        ,.189,.769,.393;
Mat out;
cv::transform(img,out,sepia);
imshow("i",out);
waitKey();
  return 0;
}

