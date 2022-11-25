//variant 14
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CDCollection
{
   private:
      int n_Person;
      int n_CD;
      int k = 0; //счетчик для проверки занятых дисков
      vector<vector<string>> CD_info;
   public:
      CDCollection(int nPerson, int nCD){
         n_Person = nPerson;
         n_CD = nCD;
         CD_info.resize(n_Person);
      }
      ~CDCollection(){}
      void add(const string& CDname, int idPerson){
         if(k < n_CD){
            CD_info[idPerson].push_back(CDname);
            cout << "Я добавил диск " << CDname << "\n";
            k++;
         }
         else cout << "Вы все диски уже выдали" << "\n";
      }
      void tranfer(const string& CDname, int idPerson){//используем where для поиска и отдаем диск
         int pos = where(CDname);
         auto iter = CD_info[pos].cbegin();
         for(int i=0; i<=amount(pos);i++){
            if(CDname == CD_info[pos][i]){
               CD_info[idPerson].push_back(CD_info[pos][i]);
               CD_info[pos].erase(iter+i);
               return;
            }
         }
      }
      int where(const string& CDname){
         for(int i = 0; i<n_Person; i++){
            for(int j = 0; j < amount(i); j++){
               if(CDname == CD_info[i][j]){
                  return i;
               }
            }
         }
         cout << "Такого диска нет ни у кого" << "\n";
      }
      int amount(int idPerson){
         return CD_info[idPerson].size();
      }
      const string& nameCD(int idPerson, int i){
         return CD_info[idPerson][i];
      }
      void print(){
         int p = 3;
         if(n_Person < 3){
            p = n_Person;
         }
         for(int i = 0; i < n_Person;i++){
            cout << i << ": ";
            for(int j = 0; j < amount(i);j++){
               cout << CD_info[i][j] << " ";
            }
            cout << "\n";
         }
      }
};


int main()
{
   CDCollection test = CDCollection(3, 4);
   test.add("Ханна Монтана", 1);
   test.add("Animals", 0);
   cout << test.amount(0) << "\n";
   cout << test.nameCD(0, 0) << "\n";
   cout << test.where("Ханна Монтана") << "\n";
   test.tranfer("Animals", 1);
   test.print();
}