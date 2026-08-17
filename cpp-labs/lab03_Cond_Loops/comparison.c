#include <iostream>
using namespace std;

int main ()

{
   int  temperature = 1;
      if  ( temperature > 30)
   {   
            cout << "too hot\n;echo";
   }
   else if (temperature > 40)
   {
            cout << "crazy\n";
   }
   else if (temperature < 20)
   {
         cout << "mild\n";
   }
   else
   {
           cout << "ok\n";
   }
    return 0;
}
