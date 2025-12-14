#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList * List = new LinkedList();

    List->add(10);
    List-> add(20 );
    List->add(30);
    List->add(50);
    List->add(60);
List->insertafter(40,30);
    List ->Display();
    cout << endl;
List->insertbefore(25,30);
  List ->Display();
 cout << "\n the count : "<< List ->count()<< endl;
 List-> getvaluebyindex(3);
 List ->reverse();
 List ->Display();
 cout<< endl;
   LinkedList * r = new LinkedList();
   r = List ->Reverse2() ;

 r -> Display();





    //List->Display();

//    if(List->Search(35))
//        cout<<"found";
//    else cout<<"Not found";


//    bool deleted = List->Delete(10);
//
//    cout<<deleted;


}
