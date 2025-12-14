#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;
class LinkedList
{
    public:



        LinkedList()
        {
            head = tail = NULL;
        }

        void add(int data)  // O(1)
        {
            // insert new node
            Node * node = new Node(data);

            // List if it was empty
            if(head == NULL)
            {
                head = tail = node;

            }
            else
            {

                // connect it
                node->prev = tail;
                tail->next = node;
                tail = node;

            }

        }


        // for testing
        void Display()  // O(n)
        {

            Node * current = head;
            // Loop
            while(current!= NULL)
            {
                // print data
                cout<<current->data<<"\t";

                //move next
                current = current->next;

            }
        }

        bool Search(int data)
        {
            // getNode(Data)
            if(getNode(data)!=NULL)
                return true;
            else return false;
        }


        bool Delete(int data)
        {
            // search
            Node * node = getNode(data);
            if(node!=NULL)
            {
                // delete
                //one element
                if(head == node && tail == node)
                {
                    head = tail = NULL;
                }

                // head
                else if(node == head)
                {
                    head = node->next;
                    head->prev = NULL;
                }

                // tail
                else if(node == tail)
                {
                     tail = node->prev;
                     tail->next = NULL;
                }

                // inbetween
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }

                delete node;

            }
            else return false;
        }
        ///method insert after //////////////////////////////
        bool  insertafter(int data,int afterdata )
        { if (Search(afterdata) )
        {
           Node *current =getNode(afterdata);
           Node *n = new Node(data) ;
           n->next =current->next ;
           n->prev=current ;
           current->next ->prev =n ;
           current -> next = n;
           return true ;
        }
          else return false ;
        }
        /// method insert before ////////////////////////////////
             bool  insertbefore(int data,int beforedata )
        { if (Search(beforedata) )
        {
           Node *current =getNode(beforedata);
           Node *n = new Node(data) ;
           n->next =current;
           n->prev=current->prev ;
           current->prev->next =n ;
           current -> prev = n;
           return true ;
        }
          else return false ;
        }
        /// count //////////////////////////
          int count()  // O(n)
        {
            int cont =0
             ;
            Node * current = head;
            // Loop
            while(current!= NULL)
            {
                // print data
           //     cout<<current->data<<"\t";

                //move next
                current = current->next;
                cont++ ;
      }
      return cont ;
        }
        /// get the value by the index ////////////////////
        int getvaluebyindex(int index )
        {
            int coun=1 ;
            Node *current =head ;
            while (current != NULL )
            {
                if(coun==index) cout << "the value of index "<< coun << " is : "<< current->data << endl;
                 current =current->next ;
                coun ++ ;
            }
        }
        /// 5. void reverse() – in place /////////////////
        template<typename t>
        t swap(t & a , t& b)
        {
            t temp = a ;
            a= b ;
            b =temp ;
        }

        void reverse()

        {  //Node *current = head ;
              swap (head , tail);
              Node *current = head ;
             while (current != NULL)
             {
                swap (current->next , current ->prev);
                current =current->next ;
             }

        }

        ///6. *LinkedList reverse() /////////////////
  LinkedList * Reverse2()
  {
      LinkedList *r =new LinkedList ();
      Node *current = tail ;
      while (current != NULL )
      {
          r->add(current->data);
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

#endif // LINKEDLIST_H
