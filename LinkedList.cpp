#include <iostream>
using namespace std;
template <typename T>
class Node
{

public:
    T value;
    Node<T> *next;
    Node(T val)
    {
        value = val;
        next = nullptr;
    }
};
template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    bool isEmpty()
    {
        return head == nullptr;
    }
    void insertAtTail(T val)
    {
        Node<T> *temp = new Node<T>(val);
        if (isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void insertAtFront(T val)
    {
        Node<T> *temp = new Node<T>(val);
        if (isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            Node<T> *s = head;
            temp->next = s;
            head = temp;
        }
    }
    void insertAtMid(T val)
    {
        Node<T> *temp = new Node<T>(val);
        if (isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            Node<T> *fast = head -> next;
            Node<T> *slow = head;
            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            temp->next = slow->next;
            slow->next = temp;
        }
    }
    void insertAfter(T val, T key)
    {
        Node<T>* temp = new Node<T>(key);
        Node<T>* slow = head;
        while (slow != nullptr)
        {
            if (slow -> value == val)
            {
                break;
            }

            slow = slow -> next;
        }
        temp -> next = slow -> next;
        slow -> next = temp;
        if (tail -> next != nullptr)
        {
            tail = temp;
        }
    }
    void insertBefore(T val, T key)
    {
        Node<T>* temp = new Node<T>(key);
        Node<T>* slow = head;
        while (slow != nullptr)
        {
            if (slow -> next -> value == val)
            {
                break;
            }
            slow = slow -> next;
        }
        temp -> next = slow -> next;
        slow -> next = temp;
    }
    T getFront()
    {
        if (isEmpty())
        {
            return false;
        }
        return head -> value;

    }
    T getTail()
    {
        if (isEmpty())
        {
            return -1;
        }
        return tail -> value;
    }
    Node<T>* search(T val)
    {
        Node<T>* slow = head;
        while (slow != nullptr)
        {
            if (slow -> value == val)
            {
                return slow;
            }
            slow = slow -> next;
        }
        return NULL;
    }
    void removeFront()
    {
        if (isEmpty())
        {
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node<T>* temp = head;
            head = head -> next;
            delete temp;
        }
    }
    void removeEnd()
    {
        if (isEmpty())
        {
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node<T>* slow = head;
            while (slow -> next != tail)
            {
                slow = slow -> next;
            }
            delete tail;
            tail = slow;
            tail -> next = nullptr;
        }
    }
    void removeMiddle()
    {
        if (isEmpty())
        {
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node<T>* slow = head;
            Node<T>* fast = head -> next;
            Node<T>* prev = head;
            while (fast != nullptr && fast -> next != nullptr)
            {
                prev = slow;
                slow = slow -> next;
                fast = fast -> next -> next;
            }
            prev -> next = slow -> next;
            delete slow;


        }
    }
    void display()
    {
        for (Node<T> *s = head; s != nullptr; s = s->next)
        {
            cout << s->value << " ";
        }
    }
};

int main()
{
    LinkedList<int> obj;
    obj.insertAtFront(1);
    obj.insertAtTail(2);
    obj.insertAtTail(3);
    obj.insertAtTail(4);
    obj.display();
    cout << endl;
    obj.removeMiddle();
    obj.display();
    // obj.removeFront();
    // obj.display();
    // obj.removeEnd();
    // obj.display();

    // obj.insertAtMid(3);
    // obj.insertAfter(2, 3);
    // obj.insertBefore(4, 3);
    // cout << obj.getFront() << endl;
    // cout << obj.getTail() << endl;
    // obj.display();
    // Node* search = obj.search(2);
    // cout <<  search -> value;

}
