#include<iostream>
#include <string>
#include <graphics.h>

using namespace std;

class Garland
{
   int colour;
   int lenght;
public:
   Garland(int colour2, int len2)
   {
      colour=colour2;
      lenght=len2;
   }
   void draw(int x0, int y0);
};

int main()
{
   
   return 0;
}