#ifndef QUEUE_SHIFT _H
#define QUEUE_SHIFT _H

#include "Node.h"
using namespace std;

class queue_shift
{
    public:



        queue_shift()
        {
            head = tail = NULL;
        }


//
//
//        // for testing
        void Display()  // O(n)
        {

            Node * current = head;
            // Loop
            while(current!= NULL)
            {
                // print data
                cout<<current->data<<" \t";

                //move next
                current = current->next;

            }
        }

  void push (int data )
  {
      Node * nd =new Node(data);
      if (head == NULL )
      {
          head = tail = nd ;
      }
    else
      {
          nd ->prev = tail;
          tail ->next = nd ;
         // nd ->next = NULL ;
          tail = nd ;
      }
  }
   int pop ()
 { if (tail != NULL )
 {     Node * curr = tail ;
       int ret = tail->data ;
     if (tail == head )
     {

         head = tail = NULL ;
     }
   else
   {
         tail =  tail ->prev  ;
  tail ->next = NULL;
   }



     delete curr ;
      return ret ;
 }
 else
 { cout << " stack is empty " ;
     return false ;

   }

 }


    private:
        Node * head;
        Node * tail;

    Node* getNode(int data)
    {
        Node * current = head;
        while(current != NULL)
        {
            // found
            if(data == current->data)
                return current;
            //move next
            current = current->next;
        }
        return NULL;
    }
};

#endif // queue_shift_H
