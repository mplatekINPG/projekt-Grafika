#include <cstdlib>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

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
int sharpen(Mat image){
	Mat kernel(3,3,CV_32F,cv::Scalar(0));	//rozmiar macierzy teorzacej baze filtra
					//nalezy teraz ustaliæ wartoœci macierzy dla tworzonego filtra
	kernel.at(1,1)= 5.0;
	kernel.at(0,1)= -1.0;
	kernel.at(2,1)= -1.0;
	kernel.at(1,0)= -1.0;
	kernel.at(1,2)= -1.0;

			//filtrowanie obrazu
	cv::filter2D(image,image,image.depth(),kernel);

	namedWindow( "Sharpen5", WINDOW_AUTOSIZE );
  imshow( "Sharpen5", image );
  waitKey(0);
  return 0;
}
int blur(Mat image)
{
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
        //wyowietlenie obu obrazków
        namedwindow("final");
        imshow("final", next);
        namedwindow("initial");
        imshow("initial", image);
        return 0;
}

int contrast_change (Mat image)
{
{
	Mat new_image = Mat::zeros( image.size(), imge.type() ); 				//tworzenie nowego obrazu, wype³nionego zerami, o takim samym rozmiarze i typie jak wczytywany
	double change;
	cout<<"Prosze podac wartosc zmiany kontastu.\n"<<
	<<"Wartosci wieksze od 1 powoduja zwiekszenie, a miedzy 0 a 1 zmniejszenie kontrastu\n";		//informacja o zmianie kontrastu
	cin>>change;										//wczytanie czynnika zmiany

	for (int x = 0; x < image.rows; x++)
		for (int y = 0; y < image.cols; y++)						//image.rows i image.cols sa obiektami biblioteki cv, kore przechowuja rozmiar obrazu
		{
			new_image[x][y] = image[x][y] * change;
			new_image[x][y] = static_cast<int>(new_image[x][y]);			//zaokr¹glenie wartoœci do int

			if (new_image[x][y] > 255)
				new_image[x][y] = 255;

			if (new_image[x][y] < 0)
				new_image[x][y] = 0;
		}
    imshow("final", new_image);
	return 0;
}

