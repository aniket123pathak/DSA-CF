#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};

class SLL
{
public:
    Node *head;
    SLL()
    {
        head = NULL;
    }
    void createLL(int data);
    void insertAtBeg();
    void insertAtEnd();
    void insertAtAny(int pos);
    void deleteAtBeg();
    void deleteAtEnd();
    void deleteAtAny(int pos);
    void display();
    int nodeCount();
};

void SLL ::createLL(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void SLL ::insertAtBeg()
{
    Node *newNode = new Node();
    cout << "Enter the data to Insert : ";
    cin >> newNode->data;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void SLL ::insertAtEnd()
{
    Node *newNode = new Node();
    cout << "Enter the data to Insert : ";
    cin >> newNode->data;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void SLL ::insertAtAny(int pos)
{
    Node *newNode = new Node();
    Node *temp = head;
    if (pos < 1 || pos > nodeCount() + 1)
    {
        cout << "Invalid Pos!!!";
    }
    else if (pos == 1)
    {
        insertAtBeg();
    }
    else if (pos == nodeCount() + 1)
    {
        insertAtEnd();
    }
    else
    {
        cout << "Enter the data to Insert  : ";
        cin >> newNode->data;
        while (pos - 1 > 1)
        {
            temp = temp->next;
            pos--;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void SLL ::deleteAtBeg()
{
    if (head == NULL)
    {
        cout << "Empty list";
    }
    else if (head->next == NULL)
    {
        delete (head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
    }
}

void SLL ::deleteAtEnd()
{
    if (head == NULL)
    {
        cout << "Empty list";
    }
    else if (head->next == NULL)
    {
        delete (head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
}

void SLL :: deleteAtAny(int pos){
    if(pos<1||pos>nodeCount()){
        cout << "Invalid Pos!!!";
    }
    else if(pos==1){
        deleteAtBeg();
    }
    else if(pos==nodeCount()){
        deleteAtEnd();
    }
    else{
        Node* temp1 = head;
        while(pos-1>1){
            temp1=temp1->next;
            pos--;
        }
        Node* temp2 = temp1->next;
        temp1->next=temp2->next;
        delete(temp2);
    }
}

void SLL ::display()
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty!!!!";
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n\n";
}

int SLL ::nodeCount()
{
    int count = 0;
    if (head == NULL)
    {
        return 0;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    SLL l1;
    cout << "Enter the Number of elements to Creat a Linked List : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : ";
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        l1.createLL(data);
    }
    l1.display();
    cout<<"\n\nINSERT AT BEGINNING\n";
    l1.insertAtBeg();
    l1.display();
    cout<<"\n\nINSERT AT END\n";
    l1.insertAtEnd();
    l1.display();
    cout<<"\n\nINSERT AT ANY POS\n";
    int pos;
    cout<<"Enter the Pos to insert: ";
    cin>>pos;
    l1.insertAtAny(pos);
    l1.display();
    cout<<"\n\nDELETE FROM BEGINNING\n";
    l1.deleteAtBeg();
    l1.display();
    cout<<"\n\nDELETE FROM END\n";
    l1.deleteAtEnd();
    l1.display();
    cout<<"\n\nDELETE FROM ANY POS\n";
    cout<<"Enter the Pos to insert: ";
    cin>>pos;
    l1.deleteAtAny(pos);
    l1.display();
    return 0;
}