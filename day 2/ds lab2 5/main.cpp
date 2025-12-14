#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    queue_shift* List = new queue_shift();
   queue_shift* List2 = new queue_shift();
 List -> push(10);
  List -> push(20);
   List -> push(30);
    List -> push(40);

    List -> Display();
    cout << endl;
    List2 = List->Reverse2();
    List2->Display();




//     cout << List -> pop() << endl;
//  cout << List -> pop() << endl;
//    cout << List -> pop() << endl;
//   cout << List -> pop() << endl;
//   cout << List -> pop() << endl;
//     List -> Display();







}
