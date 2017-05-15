#include  <; iostream >;;
using namespace std;
class przelicznik{
private:
int x,y;
public:
przelicznik(void);
void uruchom(void);
int wzor1(void);
int wzor2(void);
int wzor3(void);
int wzor4(void);
int wzor5(void);
int wzor6(void);
int wzor7(void);
int wzor1(int a, int b);
float wzor1(float a, float b);
};
int main(){
przelicznik przel;
przel.uruchom();
system("pause");
return 0;
}
przelicznik::przelicznik(void){
x=0;y=0;
};
int przelicznik:: wzor1(void){
cout<;<;"podaj x="; cin>;>; x;
cout<;<;"podaj y="; cin>;>; y;
return x*x+2*x*y+y*y;
};
int przelicznik:: wzor2(void){
cout<;<;"podaj x="; cin>;>; x;
cout<;<;"podaj y="; cin>;>; y;
return x*x-2*x*y+y*y;
};
int przelicznik:: wzor3(void){
cout<;<;"podaj x="; cin>;>; x;
cout<;<;"podaj y="; cin>;>; y;
return (x-y)*(x+y);
};
int przelicznik:: wzor4(void){
cout<;<;"podaj x="; cin>;>; x;
cout<;<;"podaj y="; cin>;>; y;
return x*x*x+3*x*x*y+3*x*y*y+y*y*y;
};
int przelicznik:: wzor5(void){
cout<;<;"podaj x="; cin>;>; x;
cout<;<;"podaj y="; cin>;>; y;
return x*x*x-3*x*x*y+3*x*y*y-y*y*y;
};
int przelicznik:: wzor6(void){
cout<;<;"podaj x="; cin>;>; x;
cout<;<;"podaj y="; cin>;>; y;
return (x-y)*(x*x+x*y+y*y);
};
int przelicznik:: wzor7(void){
cout<;<;"podaj x="; cin>;>; x;
cout<;<;"podaj y="; cin>;>; y;
return (x+y)*(x*x-x*y+y*y);
};
void przelicznik::uruchom(void){
cout<;<;"KALKULATOR"<;
cout<;<; "wybierz wzor skroconego mnozenia"<;<; endl;
cout<;<;" 1. (a+b)^2 "<;<; endl;
cout<;<;" 2. (a-b)^2 "<;<; endl;
cout<;<;" 3. a^2-b^2 "<;<; endl;
cout<;<;" 4. (a+b)^3"<;<; endl;
cout<;<;" 5. (a-b)^3"<;<; endl;
cout<;<;" 6. a^3-b^3"<;<; endl;
cout<;<;" 7. a^3+b^3"<;<; endl;
int m;
cin >;>; m;
switch(m){
case 1 : cout <;<; "wynik= "<;<; przelicznik::wzor1()<;<; endl;
break;
case 2 : cout <;<; "wynik="<;<; przelicznik::wzor2()<;<; endl;
break;
case 3 : cout <;<; "wynik= "<;<; przelicznik::wzor3()<;<; endl;
break;
case 4 : cout <;<; "wynik= "<;<; przelicznik::wzor4() <;<; endl;
break;
case 5 : cout <;<; "wynik= "<;<; przelicznik::wzor5() <;<; endl;
break;
case 6 : cout <;<; "wynik= "<;<; przelicznik::wzor6() <;<; endl;
break;
case 7 : cout <;<; "wynik= "<;<; przelicznik::wzor7() <;<; endl;
break;
}
};