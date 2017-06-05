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
ProcIMG()
{

}
int main{}
{

}
