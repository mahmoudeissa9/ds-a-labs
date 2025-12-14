#ifndef QUEUE_SHIFT_H
#define QUEUE_SHIFT_H


#include "Node.h"
using namespace std;
class queue_shift
{
    public:



        queue_shift ()
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
 { if (head != NULL )
 {     Node * curr = head ;
       int ret = head->data ;
     if (tail == head )
     {

         head = tail = NULL ;
     }
   else
   {
         head =  head ->next  ;
         tail ->prev  = NULL;
   }



     delete curr ;
      return ret ;
 }
 else
 { cout << " queue is empty " ;
     return false ;

   }

 }
   queue_shift * Reverse2()
  {
      queue_shift *r =new queue_shift ();
      Node *current = tail ;
      while (current != NULL )
      {
          r->push(current->data);
          current =current ->prev ;
      }
      return r ;

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

#endif // queue_shift _H
