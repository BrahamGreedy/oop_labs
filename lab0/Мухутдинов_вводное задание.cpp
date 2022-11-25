// variant 14
#include <iostream>
#include <time.h>

using namespace std;

int main()
{ 
   int size, A, B;
   
   cout << "Input array size: ";
   cin >> size;
   cout << "Input array numbers range: ";
   cin >> A >> B;
   int *m = new int[size+1];
   srand(time(0));
   for(int i = 0; i < size; i++)
   {
      m[i] = (rand()%(B-A+1)+A);
      cout << "m[" << i << "]=" << m[i] << " ";
   }
   cout << "\n";
   
   int beg = 0, end = size, temp = 0, len = 0 ;
   bool flag = false;   
   for(int i = 0; i<size; i++)
   {
      if(m[i]>=0  && flag == false)
      {
         beg = i;
         flag = true;
      }
      else if(m[i]<0 && flag == true
         || m[i]>=0 && i == size-1)
      {
         end = (m[i]>=0 && i == size-1 ? ++i : i);
         flag = false;
         len = end - beg;
         if(len == 1) continue;
         for(int j = 0; j <= len/2; j++)
         {
            if(j == len/2) break;
            temp = m[beg+j];
            m[beg+j] = m[end-1 - j];
            m[end-1 - j] = temp;
         }
      }
   }

   for(int k = 0; k < size; k++)
   {
      cout << "m[" << k << "]=" << m[k] << " ";
   }
   cout << "\n";
   delete[] m;
   return 0;
}