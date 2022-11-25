


using namespace std;

class Cat
{
   private:
      string name;
      int age;
      string colour;
      string owner;
   public:
      Cat(int age, string colour):age(age), colour(colour) {}
      void set_age(int num);
      void set_colour(string colour2);
      void set_owner(string owner2);
      void set_name(string name2);
      int get_age();
      string get_name();
      string get_owner();   
};

int main()
{
   Cat a(12, "Черный");
   cout << _abracadabra_cast(a);