#include <iostream>
#include <string>

using namespace std;

class Length{
private:
   int inch;//переменная для хранения длины, все хранится в дюймах
public:
   //конструктор
   Length(int, int, int, int);
   //геттеры
   int getMile();
   int getYard();
   int getFoot();
   int getInch();
   //перегрузка операторов
   friend Length operator+(const Length &, const Length &);
   friend Length operator-(const Length &, const Length &);
   friend Length operator*(int, const Length &);
   friend Length operator/(const Length &, int);
   Length &operator+=(const Length &);
   Length &operator-=(const Length &);
   Length &operator*=(int);
   Length &operator/=(int);
   friend bool operator==(Length, Length);
   friend bool operator!=(Length, Length);
   friend bool operator<(Length, Length);
   friend bool operator>(Length, Length);
   friend bool operator<=(Length, Length);
   friend bool operator>=(Length, Length);
   friend bool operator!(Length);
   friend istream& operator>>(istream&, Length&);
   friend ostream& operator<<(ostream&, Length);
};

Length::Length(int m, int y, int f, int i){inch = m*1760*36+y*36+f*12+i;}

int Length::getMile(){return inch/(1760*36);}

int Length::getYard(){return (inch/(3*12))%1760;}

int Length::getFoot(){return (inch/12)%3;}

int Length::getInch(){return inch%12;}

Length operator+(const Length &L1, const Length &L2){return Length(L1.inch + L2.inch);}

Length operator-(const Length &L1, const Length &L2){return (L1.inch - L2.inch>=0)?Length(L1.inch - L2.inch): Length(0);}

Length operator*(int z, const Length &L1){return Length(L1.inch * z);}

Length operator/(const Length &L1, int z){return Length(L1.inch / z);}

bool operator==(Length L1, Length L2){
   if(L1.inch == L2.inch) return true;
   return false;
}

bool operator!=(Length L1, Length L2){
   if(L1.inch != L2.inch) return true;
   return false;
}

bool operator<(Length L1, Length L2){
   if(L1.inch < L2.inch) return true;
   return false;
}

bool operator>(Length L1, Length L2){
   if(L1.inch > L2.inch) return true;
   return false;
}

bool operator<=(Length L1, Length L2){
   if(L1.inch <= L2.inch) return true;
   return false;
}

bool operator>=(Length L1, Length L2){
   if(L1.inch >= L2.inch) return true;
   return false;
}

bool operator!(Length L){
   if(L.inch == 0) return true;
   return false;
}

Length &Length::operator+=(const Length &L2){
   this->inch += L2.inch;
   return *this;
}

Length &Length::operator-=(const Length &L2){
   this->inch -= L2.inch;
   return *this;
}

Length &Length::operator*=(int z){
   this->inch *= z;
   return *this;
}

Length &Length::operator/=(int z){
   this->inch /= z;
   return *this;
}

istream& operator>>(istream &i, Length &L){
   int m, y, f, inch;
   i >> m;
   i.ignore(1);
   i >> y;
   i.ignore(1);
   i >> f;
   i.ignore(1);
   i >> inch;
   i.ignore(1);
   L.inch = m*1760*36+y*36+f*12+inch;
   return i;
}

ostream& operator<<(ostream &o, Length L){
   return o<<L.getMile()<<"m "<<L.getYard()<<"y "<<L.getFoot()<<"f "<<L.getInch()<<"i";
}

int main(){
   Length a(0,0,0,0);
   Length b(0,0,0,0);
   Length c(0,0,0,0);
   cout << "a: ";
   cin >> a;
   cout << "b: ";
   cin >> b;
   if(!c)
      cout << "c равно 0" << endl;
   else
      cout << "c не равно 0" << endl;
   cout << "a: " << a << endl;
   cout << "b: " << b << endl;
   c = a + b;
   cout << "c: " << c << endl;
   if(a >= b)
      c = a - b;
   else
      c = b - a;
   cout << "c: " << c << endl;
   c = 10*a;
   cout << "c: " << c << endl;
   a /= 10;
   cout << "a: " << a << endl;
   a += b;
   cout << "a: " << a << endl;
}