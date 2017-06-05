#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;
int display_caption( const char* caption )
{
  dst = Mat::zeros( src.size(), src.type() );
  putText( dst, caption,
           Point( src.cols/4, src.rows/2),
           FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );
  imshow( window_name, dst );
  int c = waitKey( DELAY_CAPTION );
  if( c >= 0 ) { return -1; }
  return 0;
}
int display_dst( int delay )
{
  imshow( window_name, dst );
  int c = waitKey ( delay );
  if( c >= 0 ) { return -1; }
  return 0;
}

class ProcImg
{
    private:
    Mat Image;
    public:
    ProcImg();
    ProcImg(const ProcImg &I);
    void ShowIMG();
    int BlurIMG();
    int ContrIMG(double change);
    int SharpenIMG();
};

ProcImg::ProcImg()
{
    Mat limg;
    limg = imread("lena.bmp",CV_LOAD_IMAGE_COLOR);
    if(!limg.data)
    {
        cout <<"Niepowodzeni przy wczytywaniu obraska" << endl;
        return;
    }
    Image=limg;
    namedWindow("Wczytany Obrazek",WINDOW_AUTOSIZE);
    imshow("Wczytany Obrazek",Image);
    waitKey(0);
    destroyAllWindows();
}

ProcImg::ProcImg(const ProcImg &I)
{
    Image=I.Image;
}

void ProcImg::ShowIMG()
{
    namedWindow("Wczytany Obrazek",WINDOW_AUTOSIZE);
    imshow("Wczytany Obrazek",Image);
}

int ProcImg::BlurIMG()
{
    Mat postimg;
    namedWindow("Rozmycie", WINDOW_AUTOSIZE );
    if(display_caption("Oryginalny obrazek") !=0)
        return 0;
    postimg=Image.clone();
    if( display_dst( DELAY_CAPTION ) != 0 )
        return 0;
    if( display_caption( "Rozmycie" ) != 0 )
        return 0;
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        blur( Image, postimg, Size( i, i ), Point(-1,-1) );
        if( display_dst( DELAY_BLUR ) != 0 )
        return 0;
    }
    imshow("Rozmycie", postimg);
}
int ProcImg::ContrIMG(double change)
{
    Mat image = Image;
	Mat new_image = Mat::zeros( image.size(), image.type() );
	image.convertTo(new_image, -1, change, 0);
    imshow("Kontrast", new_image);
	return 0;
}
int ProcImg::SharpenIMG()
{
    Mat postimg;
    namedWindow("Wyostrzenie", WINDOW_AUTOSIZE );
    if(display_caption("Oryginalny obrazek") !=0)
        return 0;
    postimg=Image.clone();
    if( display_dst( DELAY_CAPTION ) != 0 )
        return 0;
    if( display_caption( "Wyostrzenie" ) != 0 )
        return 0;
    GaussianBlur(Image, postimg, Size(0, 0), 3);
    imshow("Wyostrzenie", postimg);
    return 0;
}
int main{}
{
    ProcImg obraz;
    int sterowanie 5;
    double change =2;
    while(sterowanie!=0)
    {
        cout << "Filtry:"<<endl<<"1 rozmycie"<<endl<<"2 kontrast"<<endl<<"3 wyostrz"<<endl<<"4 pokaz obrazka"<<endl<<"0 koniec"<<endl;
        switch(sterowanie)
        case 1:
        {
            obraz.BlurIMG();
        }
        case 2:
        {
            obraz.ContrIMG(double change);
        }
        case 3:
        {
            obraz.SharpenIMG();
        }
        case 4:
        {
            obraz.ShowIMG();
        }
        default:
        {
            cout<<"Prosze o numer z przedzialu"<<endl;
        }
        cin>>sterowanie;
    }
    return 0;
}
