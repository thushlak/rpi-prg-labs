#include <iostream>
using namespace std;
int main ()
{
  int option = 2;
  switch(option)

  {
    case 1:
    cout << "start";
    

    case 2:
    cout << "stop";
    

    case 3:
    cout << "move";
    break;

    case 4:
    cout << "remove";
    break;

    default:
    cout << "unknown";

  }

  return 0;
}