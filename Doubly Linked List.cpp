#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;
};

//  الإضافة في البداية
void Insert_At_Beginning(Node *&head, int value)
{
    Node *New_Node = new Node();
    New_Node->value = value;
    New_Node->next = head;
    New_Node->prev = NULL;

    if (head != NULL)
    {
        head->prev = New_Node;
    }
    head = New_Node;
}

//  البحث عن نود معينة
Node *Find_Node(Node *head, int value)
{
    while (head != NULL)
    {
        if (head->value == value)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

//  الإضافة بعد نود محددة
void Insert_After(Node *current, int value)
{
    if (current == NULL)
        return; // حماية في حالة إن النود مش موجودة

    Node *New_Node = new Node();
    New_Node->value = value;
    New_Node->next = current->next;
    New_Node->prev = current;

    if (current->next != NULL)
    {
        current->next->prev = New_Node;
    }
    current->next = New_Node;
}

//  الإضافة في النهاية (تم التصحيح)
void Insert_At_End(Node *&head, int value)
{
    Node *New_Node = new Node();
    New_Node->value = value;
    New_Node->next = NULL;

    // لو القائمة فاضية
    if (head == NULL)
    {
        New_Node->prev = NULL;
        head = New_Node;
        return;
    }

    // نوصل لأخر نود
    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    // نربط النود الأخيرة بالجديدة من الناحيتين
    last->next = New_Node;
    New_Node->prev = last;
}

void Delete_Node(Node *&head, Node *Node_To_Delete)
{
    if (head == NULL || Node_To_Delete == NULL)
    {
        return;
    }

    if (head == Node_To_Delete)
    {
        head = Node_To_Delete->next;
    }

    if (Node_To_Delete->next != NULL)
    {
        Node_To_Delete->next->prev = Node_To_Delete->prev;
    }

    if (Node_To_Delete->prev != NULL)
    {
        Node_To_Delete->prev->next = Node_To_Delete->next;
    }
    delete Node_To_Delete;
}

void Delete_First_Node(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *temp;
    temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    delete temp;
}

void Delete_Last_Node(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    Node *temp = curr->next;
    curr->next = NULL;
    delete temp;
}

//  طباعة القائمة
void Print_List(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    Insert_At_Beginning(head, 5);
    Insert_At_Beginning(head, 4);
    Insert_At_Beginning(head, 3);
    Insert_At_Beginning(head, 2);
    Insert_At_Beginning(head, 1);

    cout << "Linked List Content: ";
    Print_List(head);

    Node *N1 = Find_Node(head, 3);
    if (N1 != NULL)
        cout << "\nNode found.\n";
    else
        cout << "\nNode not found.\n";

    Insert_After(N1, 207);
    cout << "Linked List After Insert       : ";
    Print_List(head);

    Insert_At_End(head, 500);
    cout << "Linked List After Insert At End: ";
    Print_List(head);

    Node *N_Delete = Find_Node(head, 3);
    Delete_Node(head, N_Delete);

    cout << "Linked List After Deleting     : ";
    Print_List(head);

    return 0;
}