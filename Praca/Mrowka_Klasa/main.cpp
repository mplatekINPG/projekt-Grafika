#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
class ProcImg
{
    private:
    Mat Image;
    public:
    ProcImg();
    ProcImg(const ProcImg &I);
    void ShowIMG();
    void BlurIMG();
    void ContrIMG();
    void SharpenIMG();
};
ProcImg::ProcIMG()
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
int main{}
{

}
