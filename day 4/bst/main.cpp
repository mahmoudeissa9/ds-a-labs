#include <iostream>

using namespace std;

class Employee
{
public :
    int ID ;
    string Name ;
    int Age ;

    Employee(int id = 0 , string name = "" , int age = 0)
    {
        ID = id ;
        Name = name ;
        Age = age ;
    }
};

class Node
{
public :
    Employee data ;
    Node *left , *right ;

    Node (Employee emp)
    {
        data = emp ;
        left = right = NULL ;
    }
};

class bst
{
public :
    Node *root;

    bst ()
    {
        root = NULL ;
    }

    ///  insert /////////////////////////////////////////////////
    Node * insertnode(Node *r  , Employee emp)
    {
        if (r == NULL)
        {
            Node *newnode = new Node(emp);
            r = newnode ;
        }
        else if (emp.ID < r->data.ID)
        {
            r->left = insertnode(r->left , emp);
        }
        else
        {
            r->right = insertnode(r->right , emp);
        }
        return r ;
    }

    void insertnode(Employee emp)
    {
        root = insertnode(root , emp);
    }


    /// inorder //////////////////////////////////////////////
    void inorder(Node *r )
    {
        if (r == NULL) return ;
        inorder(r->left);
        cout << r->data.ID << "  " << r->data.Name << "  " << r->data.Age << endl;
        inorder(r->right);
    }

    /// search ///////////////////////////////////////////////
    Node * searchnode(Node *r , int key )
    {
        if (r == NULL) return NULL ;

        if (key < r->data.ID)
            return searchnode(r->left , key);

        else if (key > r->data.ID)
            return searchnode(r->right , key);

        else
            return r ;
    }

    bool searchnode(int key)
    {
        Node *result = searchnode(root , key);
        if (result == NULL) return false ;
        return true ;
    }



    Node * findmin(Node *r)
    {
        if (r == NULL) return NULL ;
        if (r->left == NULL) return r ;
        return findmin(r->left);
    }


    Node * findmax(Node *r)
    {
        if (r == NULL) return NULL ;
        if (r->right == NULL) return r ;
        return findmax(r->right);
    }


    /// delete /////////////////////////////////////////////////
    Node * deletenode(Node *r , int key)
    {
        if (r == NULL) return NULL ;

        if (key < r->data.ID)
            r->left = deletenode(r->left , key);

        else if (key > r->data.ID)
            r->right = deletenode(r->right , key);

        else
        {
            // case 1 : no children
            if (r->left == NULL && r->right == NULL)
            {
                delete r ;
                return NULL ;
            }

            // case 2 : one child
            else if (r->left == NULL)
            {
                Node *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                Node *temp = r->left;
                delete r;
                return temp;
            }

            // case 3 : two children
            else
            {
                Node *temp = findmin(r->right);
                r->data = temp->data ;
                r->right = deletenode(r->right , temp->data.ID);
            }
        }

        return r ;
    }

    void deletenode(int key)
    {
        root = deletenode(root , key);
    }

};


int main()
{
    bst tree ;

    tree.insertnode(Employee(40 , "Ahmed" , 25));
    tree.insertnode(Employee(20 , "Sara"  , 30));
    tree.insertnode(Employee(50 , "Omar"  , 28));
    tree.insertnode(Employee(90 , "Laila" , 22));
    tree.insertnode(Employee(10 , "Mostafa" , 35));

    cout << "\nInorder Traversal: " << endl;
    tree.inorder(tree.root);

    cout << "\nMinimum Employee: "
         << tree.findmin(tree.root)->data.ID<< endl;


    cout << "Maximum Employee: "
         << tree.findmax(tree.root)->data.ID<< endl;

    cout << "\nSearch for ID 40: " << tree.searchnode(40) << endl;

    tree.deletenode(20);

    cout << "\nAfter deleting ID 20: " << endl;
    tree.inorder(tree.root);

    return 0;
}
