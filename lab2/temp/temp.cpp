


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
   Length &operator+=(const Length &);//увеличить длину на соответствующую длину
   Length &operator-=(const Length &);//уменьшить длину на соответствующую длину
   Length &operator*=(int);//увеличить длину в z раз
   Length &operator/=(int);//уменьшить длину в z раз
   friend bool operator==(const Length &, const Length &);//перегрузка операции ==
   friend bool operator!=(const Length &, const Length &);//перегрузка операции !=
   friend bool operator<(const Length &, const Length &);//перегрузка операции <
   friend bool operator>(const Length &, const Length &);//перегрузка операции >
   friend bool operator<=(const Length &, const Length &);//перегрузка операции <=
   friend bool operator>=(const Length &, const Length &);//перегрузка операции >=
   friend bool operator!(const Length &);//равна ли длина нулю
   friend istream& operator>>(istream&, Length&);//перегрузка операции  >>
   friend ostream& operator<<(ostream&, const Length&);// перегрузка операции  <<
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
   return o<<L.inch/(1760*36)<<"m "<<(L.inch/(3*12))%1760<<"y "<<(L.inch/12)%3<<"f "<<_abracadabra_cast(L);