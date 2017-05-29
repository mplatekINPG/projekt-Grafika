#include <cstdlib>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(){
 Mat img = imread("./xxx", 1 );	//./xxx - nazwa wczytywanego obrazu
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
____________________________________________________________________________________________________________________________
CVAPI(void) cvFilter2D( const CvArr* src, CvArr* dst, const CvMat* kernel,
                        CvPoint anchor CV_DEFAULT(cvPoint(-1,-1)));
                        
//nast�pny filtr potem nast�pi jego po��cznie z plikiem doclowym

Mat img = imread("lena.jpg");
Mat_<float> sepia(3,3); 

sepia << //nale�y znale�� najlepsze warto�ci do macierzy odpowiedialne za filtr;
Mat out;
cv::transform(img,out,sepia);
imshow("i",out);
waitKey();

