#include <iostream>
#include "queue_shift.h"
using namespace std;

int main()
{
    queue_shift* List = new queue_shift();

 List -> push(10);
  List -> push(20);
   List -> push(30);
    List -> push(40);

    List -> Display();
    cout << endl;
     cout << List -> pop() << endl;
  cout << List -> pop() << endl;
    cout << List -> pop() << endl;
   cout << List -> pop() << endl;
   cout << List -> pop() << endl;
     List -> Display();







}
