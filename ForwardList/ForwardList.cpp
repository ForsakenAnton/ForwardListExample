#include <iostream>
using namespace std;

template <typename T>
class Node 
{
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) 
    { 
    }
};


template <typename T>
class ForwardList 
{
private:
    Node<T>* head;

public:
    ForwardList() : head(nullptr) 
    { 
    }

    ~ForwardList() 
    {
        while (head != nullptr) 
        {
            removeFromHead();
        }
    }

    void addToHead(T value)
    {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr)
        {
            head = newNode;
        }
        else 
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void addToTail(T value) 
    {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) 
        {
            head = newNode;
        }
        else
        {
            Node<T>* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void removeFromHead()
    {
        if (head == nullptr) 
        {
            cerr << "List is empty. Cannot remove from head." << endl;
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void removeFromTail()
    {
        if (head == nullptr) 
        {
            cerr << "List is empty. Cannot remove from tail." << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* current = head;
        while (current->next->next != nullptr) 
        {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    void display() 
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";

            current = current->next;
        }
        cout << endl;
    }

    void insertAt(T value, int position)
    {
        if (head == nullptr || position == 0) 
        {
            addToHead(value);
        }
        else 
        {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* current = head;
            int currentPosition = 0;

            while (currentPosition < position - 1 && current->next != nullptr)
            {
                current = current->next;
                currentPosition++;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }
};

int main() {
    ForwardList<string> myList;

    myList.addToHead("one");
    myList.addToHead("two");
    myList.addToHead("three");
    myList.addToTail("four");
    myList.display();

    myList.removeFromHead();
    myList.display();

    myList.removeFromTail();
    myList.display();

    myList.insertAt("five", 0);
    myList.insertAt("six", 1);
    myList.insertAt("seven", 1);
    myList.insertAt("eight", 2);
    myList.display();

    return 0;
}
