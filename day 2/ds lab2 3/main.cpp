#include <iostream>
using namespace std;

class fifo
{
    int* q, head, tail;
    int sizee;
    int coun;

public:
    fifo()
    {
        sizee = 5;              // MUST be initialized!
        q = new int[sizee];
        head = 0;
        tail = 0;
        coun = 0;
        cout << "i am a default cons" << endl;
    }

    fifo(int siz)
    {
        cout << "i am a parameterized cons" << endl;
        sizee = siz;
        q = new int[sizee];
        head = 0;
        tail = 0;
        coun = 0;
    }

    ~fifo()
    {
        cout << "i am a destructor" << endl;
        delete[] q;
    }

    bool isfull()
    {
        return (coun == sizee);
    }

    bool isempty()
    {
        return (coun == 0);
    }

    void enqueue(int value)
    {
        if (isfull())
        {
            cout << "queue is full" << endl;
            return;
        }

        q[tail] = value;
        tail = (tail + 1) % sizee;
        coun++;
    }

    int dequeue()
    {
        if (isempty())
        {
            cout << endl << "the queue is empty" << endl;
            return -1;
        }

        int val = q[head];
        head = (head + 1) % sizee;
        coun--;
        return val;
    }

    void print()
    {
        cout << "the queue is: ";
        for (int i = 0; i < coun; i++)
        {
            int index = (head + i) % sizee;
            cout << q[index] << " ";
        }
        cout << endl;
    }
};

int main()
{
    fifo s(5);
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.enqueue(4);
    s.enqueue(5);
    s.enqueue(6); // full

    s.print();

    cout << s.dequeue() << " ";
    cout << s.dequeue() << " ";
    cout << s.dequeue() << " ";
    cout << s.dequeue() << " ";
    cout << s.dequeue() << " ";
    cout << s.dequeue() << " "; // empty

    cout << endl;
    s.print();

    return 0;
}
