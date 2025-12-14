#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    stack_ll* List = new stack_ll();
    stack_ll * List2 = new stack_ll() ;

 List -> push(10);
  List -> push(20);
   List -> push(30);
    List -> push(40);

    List -> Display();
    cout << endl;
    List2 = List ->nextGreaterElement() ;
    List2 -> Display();
    //( List -> nextGreaterElement() )->Display();
//     cout << List -> pop() << endl;
//  cout << List -> pop() << endl;
//    cout << List -> pop() << endl;
//   cout << List -> pop() << endl;
//   cout << List -> pop() << endl;
//     List -> Display();







}
