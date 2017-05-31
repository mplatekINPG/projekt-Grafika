#include "CImg_demo.h"

#include "CImg.h"
#include "imfuncs.h"
using namespace cimg_library;

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#undef min
#undef max

void* item_blurring_gradient() {
    CImg<unsigned char> image("lena.bmp"), visu(500,400,1,3,0);
  const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
  image.blur(2.5);
  CImgDisplay main_disp(image,"Click a point"), draw_disp(visu,"Intensity profile");
  while (!main_disp.is_closed() && !draw_disp.is_closed()) {
    main_disp.wait();
    if (main_disp.button() && main_disp.mouse_y()>=0) {
      const int y = main_disp.mouse_y();
      visu.fill(0).draw_graph(image.get_crop(0,y,0,0,image.width()-1,y,0,0),red,1,1,0,255,0);
      visu.draw_graph(image.get_crop(0,y,0,1,image.width()-1,y,0,1),green,1,1,0,255,0);
      visu.draw_graph(image.get_crop(0,y,0,2,image.width()-1,y,0,2),blue,1,1,0,255,0).display(draw_disp);
      }
    }
}

void start_item(const unsigned int demo_number) {
  switch (demo_number) {
  case 1:  /*WCZYTYWANIE OBRAZU */ /*item_blurring_gradient(); */ break;
  case 2: /*FUNKCJA ROZMYWANIA*/ break;
  case 3: /*FUNKCJA WYOSTRZANIA*/ break;
  case 4: /*FUNKCJA ZMIANY KONTRASTU*/ break;
  case 5: /*SEPIA*/ break;
  case 6: /*ZAPISYWANIE*/ break;

  default: break;
  }
}

int main(int argc, char **argv) {

  unsigned int demo_number = cimg_option("-run",0,0);
  if (demo_number) start_item(demo_number);
  else {
    cimg::info();

    const unsigned char
      white[]  = { 255, 255, 255 }, black[] = { 0, 0, 0 }, red[] = { 120, 50, 80 },
      yellow[] = { 200, 155, 0 }, green[] = { 30, 200, 70 }, purple[] = { 175, 32, 186 },
      blue[] = { 55, 140, 185 }, grey[] = { 127, 127, 127 };
    float
      rx = 0, ry = 0, t = 0, gamma = 0, vgamma = 0, T = 0.9f,
      nrx = (float)(2*cimg::rand(-1,1)),
      nry = (float)(2*cimg::rand(-1,1));
    int y0 = 2*13;
    CImg<unsigned char> back(1,2,1,3,10), fore, text, img;
    back.fillC(0,1,0,10,10,235).resize(350,570,1,3,3).get_shared_channel(2).noise(10,1).draw_plasma();
    back.draw_rectangle(0,y0 - 7,back.width() - 1,y0 + 20,red);
    fore.assign(back.width(),50,1,1,0).draw_text(20,y0 - 3,"Projekt Grafika",grey,0,1,23, //zast¹pi³em "Menu Przyk³adowe"
                                                cimg_version/100,(cimg_version/10)%10,cimg_version%10);
    (fore+=fore.get_dilate(3).dilate(3)).resize(-100,-100,1,3);
    cimg_forXY(fore,x,y)
      if (fore(x,y)==127) fore(x,y,0) = fore(x,y,1) = fore(x,y,2) = 1;
      else if (fore(x,y)) {
        const float val = std::min(255.0f,7.0f*(y - 3));
        fore(x,y,0) = (unsigned char)(val/1.5f);
        fore(x,y,1) = (unsigned char)val;
        fore(x,y,2) = (unsigned char)(val/1.1f);
      }
    text.draw_text(1,1,
                   "Wczytaj obraz\n"
                   "Blurring gradient\n"
                   "Rozmycie\n"
                   "Wyostrzenie\n"
                   "Zmiana kontrastu\n"
                   "Sepia\n"
                   "Zapisz obraz\n"
    
          ,
                   white,0,1,18).resize(-100,-100,1,3);
    fore.resize(back,0).draw_image(20,y0 + 3*13,text|=text.get_dilate(3)>>4);

    CImgDisplay disp(back,"CImg Library Samples",0,false,true);
    disp.move((disp.screen_width() - disp.window_width())/2,(disp.screen_height() - disp.window_height())/2);
    img = back; back*=0.15f;
    for (y0+=3*13; !disp.is_closed() && !disp.is_keyQ() && !disp.is_keyESC(); demo_number = 0) {
      while (!demo_number && !disp.is_closed() && !disp.is_keyQ() && !disp.is_keyESC()) {
        img*=0.85f; img+=back;
        for (int i = 0; i<60; ++i) {
          const float
            mx = (float)(img.width()/2 + (img.width()/2 - 30)*((1 - gamma)*std::cos(3*t + rx*i*18.0f*cimg::PI/180) +
                                                         gamma*std::cos(3*t + nrx*i*18.0f*cimg::PI/180))),
            my = (float)(img.height()/2 + (img.height()/2 - 30)*((1 - gamma)*std::sin(4*t + ry*i*18.0f*cimg::PI/180) +
                                                         gamma*std::sin(4*t + nry*i*18.0f*cimg::PI/180))),
            mz = (float)(1.3f + 1.2f*((1 - gamma)*std::sin(2*t + (rx + ry)*i*20*cimg::PI/180) +
                                      gamma*std::sin(2*t + (nrx + nry)*i*20*cimg::PI/180)));
          const int j = i%5;
          img.draw_circle((int)mx,(int)my,(int)(10*mz),j!=0?(j!=1?(j!=2?(j!=3?green:red):yellow):purple):blue,0.2f).
            draw_circle((int)(mx + 4*mz),(int)(my - 4),(int)(3*mz),white,0.1f).
            draw_circle((int)mx,(int)my,(int)(10*mz),black,0.2f,~0U);
        }
        const unsigned char *ptrs = fore.data();
        cimg_for(img,ptrd,unsigned char) { const unsigned char val = *(ptrs++); if (val) *ptrd = val; }
        const int y = (disp.mouse_y() - y0)/18, _y = 18*y + y0 + 9;
        if (y>=0 && y<27) {
          for (int yy = _y - 9; yy<=_y + 8; ++yy)
            img.draw_rectangle(0,yy,0,1,img.width() - 1,yy,0,1,(unsigned char)(130 - 14*cimg::abs(yy - _y)));
          img.draw_triangle(2,_y -  6,2,_y + 6,8,_y,yellow).
            draw_triangle(img.width() - 2,_y - 6,img.width() - 2,_y + 6,img.width() - 8,_y,yellow);
        }
        gamma+=vgamma;
        if (gamma>1) {
          gamma = vgamma = 0;
          rx = nrx;
          ry = nry;
          nrx=(float)(2*cimg::rand(-1,1)); nry=(float)(2*cimg::rand(-1,1));
        }
        t+=0.006f; T+=0.005f; if (T>1) { T-=(float)(1 + cimg::rand(-1,1)); vgamma = 0.03f; }
        if (disp.button()) { demo_number = 1 + (disp.mouse_y() - y0)/18; disp.set_button(); }
        disp.resize(disp,false).display(img).wait(25);
      }
      start_item(demo_number);
    }
  }

  std::exit(0);

  return 0;
}

