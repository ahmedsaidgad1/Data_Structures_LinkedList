#include <iostream>
using namespace std;

class Node
{
public:
    int value;  // القيمة أو الداتا اللي هتنشار في النود
    Node *next; // المؤشر اللي بيشاور على النود اللي بعديها في القائمة
};

// دالة لإضافة نود جديدة في الاول
void Insert_At_Beginning(Node *&head, int value)
{
    Node *New_Node = new Node(); // بنحجز مكان جديد في الذاكرة للنود
    New_Node->value = value;     // بنحط القيمة جواه
    New_Node->next = head;       // بنخلي النود الجديدة تشاور على اللي كان الأول
    head = New_Node;             // بنخلي الـ head يشاور على النود الجديدة لأنها بقت الأولى
}

// دالة لإضافة نود جديدةفي الاخر 
void Insert_At_End(Node *&head, int value)
{
    Node *New_Node = new Node(); // بنعمل نود جديدة في الذاكرة
    New_Node->value = value;     // بنحط القيمة جواها
    New_Node->next = NULL;       // طالما هي الأخيرة، يبقى الـ next بتاعها فاضي (NULL)

    // لو القائمة فاضية أصلاً، يبقى النود دي هتبقى هي الأولى والأخيرة
    if (head == NULL)
    {
        head = New_Node;
        return;
    }

    // بنمشي من أول الـ head لحد ما نوصل لآخر نود
    Node *Last_Node = head;
    while (Last_Node->next != NULL)
    {
        Last_Node = Last_Node->next; // بنتحرك للنود اللي بعدها
    }

    // بنربط أخر نود قديمة بالنود الجديدة
    Last_Node->next = New_Node;
}

void Insert_After(Node *Prev_Node, int value)
{
    // بنتأكد الأول إن النود اللي هنضيف بعدها مش بـ NULL
    if (Prev_Node == NULL)
    {
        cout << "\nPrevious node cannot be NULL!" << endl;
        return;
    }

    Node *New_Node = new Node();      // بنعمل نود جديدة
    New_Node->value = value;          // بنحط القيمة جواها
    New_Node->next = Prev_Node->next; // بنخلي النود الجديدة تشاور على اللي كان بعد Prev_Node
    Prev_Node->next = New_Node;       // بنخلي Prev_Node تشاور على النود الجديدة
}

Node *find(Node *head, int value)
{
    while (head != NULL) // بنلف على القائمة نود نود
    {
        if (head->value == value) // لو لقينا القيمة اللي بنبحث عنها
        {
            return head; // بنرجع العنوان بتاع النود دي
        }
        head = head->next; // بنتحرك للنود اللي بعدها
    }
    return NULL; // لو القائمة خلصت وملقيناش القيمة بنرجع NULL
}


// دالة لحذف أول نود في القائمة
void Delete_first(Node *&head)
{
    if (head == NULL) // لو القائمة فاضية أصلاً بنطلع
    {
        return;
    }

    Node *temp = head; // بنشيل النود الأولى مؤقتاً في متغير عشان نعرف نمسحها من الذاكرة
    head = head->next; // بنخلي الـ head يشاور على النود التانية
    delete temp;       // بنمسح النود الأولى القديمة من الذاكرة تماماً
}

// دالة لحذف آخر نود في القائمة
void Delete_last(Node *&head)
{
    if (head == NULL) // لو القائمة فاضية بنطلع
    {
        return;
    }

    // لو القائمة فيها نود واحدة بس
    if (head->next == NULL)
    {
        delete head; // بنمسح النود الوحيدة
        head = NULL; // ونرجع الـ head ينور فاضي (NULL)
        return;
    }

    // لو القائمة فيها أكتر من نود، بنمشي لحد النود قبل الأخيرة
    Node *prev = head;
    while (prev->next->next != NULL)
    {
        prev = prev->next;
    }

    delete prev->next; // بنمسح النود الأخيرة من الذاكرة
    prev->next = NULL; // بنخلي النود قبل الأخيرة تتقفل بـ NULL لأنها بقت هي الأخيرة
}

// دالة لحذف نود بمعرفة قيمتها
void Delete_Node(Node *&head, int value)
{
    if (head == NULL) // لو القائمة فاضية بنطلع
    {
        return;
    }

    // ⚠️ تنبيه: هنا في شرط الـ if مكتوبة = بدل == (وده هيخليها تخصيص مش مقارنة)
    // الصح تكون: if (head->value == value)
    if (head->value = value) 
    {
        Delete_first(head); // لو النود الأولى هي المطلوب حذفها بننادي دالة Delete_first
        return;
    }

    Node *curr = head; // النود اللي واقفين عليها
    Node *prev = NULL; // النود اللي قبل اللي واقفين عليها

    // بنمشي نلف في القائمة لحد ما نلاقي القيمة أو نوصل لآخر القائمة
    while (curr != NULL && curr->value != value)
    {
        prev = curr;
        curr = curr->next;
    }

    //   هنا المفروض نتأكد إن curr مش بـ NULL الأول عشان الكود ما يضربش 
    // لو القيمة مش موجودة: if (curr == NULL) return;

    prev->next = curr->next; // بنربط النود اللي قبل المحذوفة بالنود اللي بعد المحذوفة
    delete curr;             // بنمسح النود المطلوبة من الذاكرة
}

// دالة لطباعة كل عناصر القائمة بالترتيب
void Print_List(Node *head)
{
    while (head != NULL) // طول ما القائمة فيها عناصر
    {
        cout << head->value << " "; // بنطبع قيمة النود الحالية
        head = head->next;          // بنتحرك للنود اللي بعديها
    }
    cout << endl; // بننزل سطر جديد في الآخر
}

int main()
{
    Node *head = NULL;

    Insert_At_Beginning(head, 1);
    Insert_At_Beginning(head, 2);
    Insert_At_Beginning(head, 3);

    Insert_At_End(head, 0);

    cout << "List Content: ";
    Print_List(head);

    Node *foundNode = find(head, 2);

    if (foundNode != NULL)
    {
        cout << "Node 2 is found, inserting 99 after it..." << endl;
        Insert_After(foundNode, 99); 
    }
    else
    {
        cout << "Node is not found." << endl;
    }


    cout << "Updated List: ";
    Print_List(head);

    return 0;//خلاويص خلصنا اخيرا 
}