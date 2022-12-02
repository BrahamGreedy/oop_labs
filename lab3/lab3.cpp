#include <iostream>
#include <graphics.h>

class Figure{
   int c; //���� �����
   bool visible; //���������
protected:
   int x, y; // ������� �����
   virtual void draw()=0; //����������
public:
   Figure(int col, int x, int y):c(col), visible(0), x(x), y(y) {}
   ~Figure() {}
   void move(int x2, int y2); //�������� ������ � (x2,y2)
   void setcolor(int col); // ���������� ���� ������, ������� ��������, � ��������� �������� ����
   int getcolor() const {return c;} //�������� ����
   void hide(); //��������
   void show(); //��������
   bool isvisible() const {return visible;} //������?
   virtual void area(int &x1, int &y1, int &x2, int &y2) const = 0; //������� �������, ���������� ������
};

class Boublik: public Figure{
protected:
   int r1, r2;
   void draw();
public:
   Boublik(int col, int x_, int y_, int r_1, int r_2): Figure(col, x_, y_), r1(r_1), r2(r_2) {}
   ~Boublik() {hide();}
   void setsizes(int r_1, int r_2); //��������� ����������� � �������� ������� �������
   void area(int &x1, int &y1, int &x2, int &y2) const; //�������, ��� ���������� ������
};

class FillBoublik: public Boublik{
protected:
   int fc; //���� ��������
   void draw(); //����������
public:
   FillBoublik(int col, int x_, int y_, int r_1, int r_2, int fillcol): Boublik(col, x_, y_, r_1, r_2), fc(fillcol){}
   void setfillcolor(int fillcol); //�������� ���� ��������
};

void Figure::setcolor(int col){
   c = col;
   if(visible) draw();
}

void Figure::move(int x2, int y2){
   bool vis = visible;
   if(vis) hide();
   x = x2;
   y = y2;
   if(vis) show();
}

void Figure::hide(){
   if(!visible) return;
   int x1, y1, x2, y2;
   area(x1, y1, x2, y2);
   setfillstyle(SOLID_FILL, BLACK);
   bar(x1, y1, x2, y2);
   visible = 0;
}

void Figure::show(){
   if(visible) return;
   visible = 1;
   draw();
}

void Boublik::setsizes(int r_1, int r_2){
   bool vis = isvisible();
   if(vis) hide();
   r1 = r_1;
   r2 = r_2;
   if(vis) show();
}

void Boublik::area(int &x1, int &y1, int &x2, int &y2) const{
   x1 = x - r2;
   y1 = y - r2;
   x2 = x + r2;
   y2 = y + r2;
}

void Boublik::draw(){
   setcolor(getcolor());
   circle(x, y, r2);
   circle(x, y, r1);
}

void FillBoublik::setfillcolor(int fillcol){
   fc = fillcol;
   if(isvisible()) draw();
}

void FillBoublik::draw(){
   setfillstyle(SOLID_FILL, fc);
   fillellipse(x, y, r2, r2);
   setfillstyle(SOLID_FILL, BLACK);
   fillellipse(x, y, r1, r1);
}

int main(){
   initwindow(1000, 800);
   Figure *figure1 = new Boublik(WHITE, 200, 200, 30, 100);
   Figure *figure2 = new FillBoublik(BLUE, 500, 500, 50, 150, LIGHTGREEN);
   figure1->show();
   figure2->show();
   getch();
   figure1->hide();
   figure2->hide();
   getch();
   figure1->move(600, 500);
   figure2->move(200, 250);
   figure1->show();
   figure2->show();
   getch();
   figure1->setcolor(LIGHTBLUE);
   figure2->setcolor(WHITE);
   // ��������� ��������� ��������, ��� ������ ��������
   if(Boublik *r = dynamic_cast<Boublik*>(figure1)) r->setsizes(70, 200);
   if(Boublik *r = dynamic_cast<Boublik*>(figure2)) r->setsizes(90, 120);
   getch();
   // ��������� ����������, ������ ������ �� ������ ����������
   if(FillBoublik *r = dynamic_cast<FillBoublik*>(figure1)) r->setfillcolor(RED);
   if(FillBoublik *r = dynamic_cast<FillBoublik*>(figure2)) r->setfillcolor(LIGHTRED);
   figure1->show();
   figure2->show();
   getch();
   //��������� ������������ � ������ ��� ��������
   delete figure1;
   delete figure2;
   getch();
   return 0;
}