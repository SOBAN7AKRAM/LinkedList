#include <iostream>
using namespace std;
class Node
{

public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};
class LinkedList
{
private:
    Node *head;
    Node *tail;

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
    void insertAtTail(int val)
    {
        Node *temp = new Node(val);
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
    void insertAtFront(int val)
    {
        Node *temp = new Node(val);
        if (isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            Node *s = head;
            temp->next = s;
            head = temp;
        }
    }
    void insertAtMid(int val)
    {
        Node *temp = new Node(val);
        if (isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            Node *fast = head -> next;
            Node *slow = head;
            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            temp->next = slow->next;
            slow->next = temp;
        }
    }
    void insertAfter(int val, int key)
    {
        Node* temp = new Node(key);
        Node* slow = head;
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
    void insertBefore(int val, int key)
    {
        Node* temp = new Node(key);
        Node* slow = head;
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
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return head -> value;

    }
    int getTail()
    {
        if (isEmpty())
        {
            return -1;
        }
        return tail -> value;
    }
    Node* search(int val)
    {
        Node* slow = head;
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
            Node* temp = head;
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
            Node* slow = head;
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
            Node* slow = head;
            Node* fast = head -> next;
            Node* prev = head;
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
        for (Node *s = head; s != nullptr; s = s->next)
        {
            cout << s->value << " ";
        }
    }
};

int main()
{
    LinkedList obj;
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
