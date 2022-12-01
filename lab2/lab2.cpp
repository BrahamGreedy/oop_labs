#include <iostream>
#include <string>

using namespace std;

class Length{
private:
   int inch;//���������� ��� �������� �����, ��� �������� � ������
public:
   //�����������
   Length(int, int, int, int);
   //�������
   int getMile();
   int getYard();
   int getFoot();
   int getInch();
   Length &operator+=(const Length &);//��������� ����� �� ��������������� �����
   Length &operator-=(const Length &);//��������� ����� �� ��������������� �����
   Length &operator*=(int);//��������� ����� � z ���
   Length &operator/=(int);//��������� ����� � z ���
   friend bool operator==(const Length &, const Length &);//���������� �������� ==
   friend bool operator!=(const Length &, const Length &);//���������� �������� !=
   friend bool operator<(const Length &, const Length &);//���������� �������� <
   friend bool operator>(const Length &, const Length &);//���������� �������� >
   friend bool operator<=(const Length &, const Length &);//���������� �������� <=
   friend bool operator>=(const Length &, const Length &);//���������� �������� >=
   friend bool operator!(const Length &);//����� �� ����� ����
   friend istream& operator>>(istream&, Length&);//���������� ��������  >>
   friend ostream& operator<<(ostream&, const Length&);// ���������� ��������  <<
};

Length::Length(int m, int y, int f, int i){inch = m*1760*36+y*36+f*12+i;}

int Length::getMile(){return inch/(1760*36);}

int Length::getYard(){return (inch/(3*12))%1760;}

int Length::getFoot(){return (inch/12)%3;}

int Length::getInch(){return inch%12;}

bool operator==(const Length &L1, const Length &L2){
   if(L1.inch == L2.inch) return true;
   return false;
}

bool operator!=(const Length &L1, const Length &L2){
   if(L1.inch != L2.inch) return true;
   return false;
}

bool operator<(const Length &L1, const Length &L2){
   if(L1.inch < L2.inch) return true;
   return false;
}

bool operator>(const Length &L1, const Length &L2){
   if(L1.inch > L2.inch) return true;
   return false;
}

bool operator<=(const Length &L1, const Length &L2){
   if(L1.inch <= L2.inch) return true;
   return false;
}

bool operator>=(const Length &L1, const Length &L2){
   if(L1.inch >= L2.inch) return true;
   return false;
}

bool operator!(const Length &L){
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

inline Length operator + (Length &L1, Length &L2){// x + y
   int inch = L1.getInch() + L2.getInch();
   Length L3(inch/(1760*36), (inch/(3*12))%1760, (inch/12)%3, inch%12);
   return L3;
}

inline Length operator - (Length &L1, Length &L2){// x - y
   int inch = L1.getInch() - L2.getInch();
   Length L3(inch/(1760*36), (inch/(3*12))%1760, (inch/12)%3, inch%12);
   return L3;
}

inline Length operator * (int z, Length &L2){// z*x
   int inch = z * L2.getInch();
   Length L3(inch/(1760*36), (inch/(3*12))%1760, (inch/12)%3, inch%12);
   return L3;
}

inline Length operator / (Length &L1, int z){// x/z
   int inch = L1.getInch() / z;
   Length L3(inch/(1760*36), (inch/(3*12))%1760, (inch/12)%3, inch%12);
   return L3;
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

ostream& operator<<(ostream &o, const Length &L){
   return o<<L.getMile()<<"m "<<L.getYard()<<"y "<<L.getFoot()<<"f "<<L.getInch()<<"i";
}

int main(){
   Length a(0,0,0,0);
   Length b(0,0,0,0);
   Length c(0,0,0,0);
   cout << "����" << endl;
   cout << "a = ";
   cin >> a;
   cout << "b = ";
   cin >> b;
   cout << "�������� �������� !x\n";
   cout << " !" << a << " = " << !a << endl;
   cout << "�������� �������� x == y\n";
   cout << a << " == " << b << " = " << (a == b) << endl;
   cout << "�������� �������� x != y\n";
   cout << a << " != " << b << " = " << (a != b) << endl;
   cout << "�������� �������� x < y\n";
   cout << a << " < " << b << " = " << (a < b) << endl;
   cout << "�������� �������� x > y\n";
   cout << a << " > " << b << " = " << (a > b) << endl;
   cout << "�������� �������� x <= y\n";
   cout << a << " <= " << b << " = " << (a <= b) << endl;
   cout << "�������� �������� x >= y\n";
   cout << a << " >= " << b << " = " << (a >= b) << endl;
   cout << "�������� �������� x - y\n";
   cout << a << " - " << b << " = ";
   c = a - b;
   cout << c << endl;
   cout << "�������� �������� x + y\n";
   cout << a << " + " << b << " = ";
   c = a + b;
   cout << c << endl;
   cout << "�������� �������� x += y\n";
   cout << a << " += " << b << " = ";
   a += b;
   cout << a << endl;
   cout << "�������� �������� x -= y\n";
   cout << a << " -= " << b << " = ";
   a -= b;
   cout << a << endl;
   cout << "�������� �������� z * y\n";
   cout << "5" << " * " << b << " = ";
   c = 5 * b;
   cout << c << endl;
   cout << "�������� �������� x / z\n";
   cout << a << " / " << "5" << " = ";
   c = a / 5;
   cout << c << endl;
   cout << "�������� �������� y *= z\n";
   cout << b << " *= " << "9" << " = ";
   b *= 9;
   cout << b << endl;
   cout << "�������� �������� y *= z\n";
   cout << b << " /= " << "6" << " = ";
   b /= 6;
   cout << b << endl;
   cout << "�����" << endl;
   cout << "a = " << a << "\nb = " << b << "\nc = " << c;
}