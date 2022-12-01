#include <iostream>
#include <graphics.h>

class Figure{
private:
   int c; //цвет
   bool visible; // видимость
protected:
   int x, y; //базовая точка
   virtual void draw() = 0; // нарисовать
public:
   Figure(int c, int x, int y):c(c), visible(0), x(x), y(y) {}
   virtual ~Figure() {}
   void move(int x, int y); //сместить фигуру в (x, y)
   void setcolor(int c); //установить цвет фигуры, видимая рисуется, у невидимой меняется цвет
   int getcolor() const { return c; } //получить цвет
   void hide(); //спрятать
   void show(); //показать
   bool isvisible() const { return visible; } //видима?
   virtual void area(int &x1, int &y1, int &x2, int &y2) const = 0; //размеры области, содержащей фигуру
};

void Figure::setcolor(int c) {
   this->c=c;
   if (visible) draw();
}
void Figure::move(int x, int y) {
   bool f=visible;
   if (f) hide();
   this->x=x;
   this->y=y;
   if(f) show();
}
void Figure::hide() {
   if(!visible) return;
   int x1, y1, x2, y2;
   area(x1, y1, x2, y2);
   setfillstyle(SOLID_FILL, BLACK);
   bar(x1, y1, x2, y2);
   visible=0;
}
void Figure::show() {
   if(visible) return;
   visible=1;
   draw();
}

class Boublik: public Figure{
protected:
   int r1, r2;
   void draw();
public:
   Boublik(int c, int x, int y, int r1, int r2): Figure(c, x, y), r1(r1), r2(r2) {}
   ~Boublik() {hide();}
   void setsizes(int r_1, int r_2);//изменение внутреннего и внешнего радиуса бублика
   void area(int &x1, int &y1, int &x2, int &y2) const;//область, где нарисована фигура
};

void Boublik::setsizes(int r_1, int r_2){
   bool f = isvisible();
   if(f) hide();
   r1 = r_1;
   r2 = r_2;
   if(f) show();
}

void Boublik::area(int &x1, int &y1, int &x2, int &y2)const {
   x1 = x - r2;
   y1 = y - r2;
   x2 = x + r2;
   y2 = y + r2;
}

class FillBoublik: public Boublik{
protected:
   int fc;// цвет закраски
   void draw();// нарисовать
public:
   FillBoublik(int c, int x, int y, int r1, int r2,int fc):Boublik(c,x,y,r1,r2),fc(fc){}
   void setfillcolor(int);//изменить цвет закраски
};

void FillBoublik::draw(){
   setfillstyle(SOLID_FILL, fc);
   fillellipse(x, y, r2, r2);
   setfillstyle(SOLID_FILL, BLACK);
   fillellipse(x, y, r1, r1);
}

void FillBoublik::setfillcolor(int c){
   fc=c;
   if(isvisible()) draw();
}

int main(){
   
}