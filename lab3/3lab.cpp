#include <iostream>
#include <graphics.h>

class Figure{
private:
   int c; //����
   bool visible; // ���������
protected:
   int x, y; //������� �����
   virtual void draw() = 0; // ����������
public:
   Figure(int c, int x, int y):c(c), visible(0), x(x), y(y) {}
   virtual ~Figure() {}
   void move(int x, int y); //�������� ������ � (x, y)
   void setcolor(int c); //���������� ���� ������, ������� ��������, � ��������� �������� ����
   int getcolor() const { return c; } //�������� ����
   void hide(); //��������
   void show(); //��������
   bool isvisible() const { return visible; } //������?
   virtual void area(int &x1, int &y1, int &x2, int &y2) const = 0; //������� �������, ���������� ������
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
   void setsizes(int r_1, int r_2);//��������� ����������� � �������� ������� �������
   void area(int &x1, int &y1, int &x2, int &y2) const;//�������, ��� ���������� ������
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
   int fc;// ���� ��������
   void draw();// ����������
public:
   FillBoublik(int c, int x, int y, int r1, int r2,int fc):Boublik(c,x,y,r1,r2),fc(fc){}
   void setfillcolor(int);//�������� ���� ��������
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