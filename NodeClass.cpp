#include <iostream>
#include <stack>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *input()
{

    //complexity of this function is order of n
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            // tail = tail->next;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

Node *takeInput()
{

    //Complexity of this function is order of n square
    int data;
    cin >> data;
    Node *head = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin >> data;
    }
    return head;
}

// Print the linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//Print the ith NOde of the linkded list

void print(Node *head, int i)
{
    Node *temp = head;
    int count = 0;
    if (i == 0)
    {
        cout << temp->data << endl;
    }
    else
    {
        while (temp != NULL && count < i)
        {
            temp = temp->next;
            count++;
        }
        cout << temp->data << endl;
    }
}

// Find the lenght and return it

int length(Node *head)
{
    Node *temp = head;
    int count = 0;
    if (temp == NULL)
    {
        return 0;
    }
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// Delete the ith Node from the lisnked list

Node *deleteNode(Node *head, int i)
{
    Node *temp = head;
    int count = 0;
    if (i == 0)
    {
        temp = temp->next;
        head = temp;
        return head;
    }

    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *a = temp->next;
    Node *b = a->next;
    temp->next = b;
    delete a;
    return head;
}

// Find the lenght recursive

int recursiveLength(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        return 0;
    }
    int ans = recursiveLength(temp->next);
    return ans + 1;
}

// Insert the NOde recursive to the linked list
Node *insertNodeRecursive(Node *head, int data, int i)
{
    if (head == NULL)
    {
        if (i == 0)
        {
            Node *newNode = new Node(data);
            return newNode;
        }
        else
        {
            return head;
        }
    }
    Node *newNode = new Node(data);
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    head->next = insertNodeRecursive(head->next, data, i - 1);
    return head;
}

// Delete the NOde from the linked list recursive

Node *deleteNodeRecursive(Node *head, int i)
{
    if (head == NULL)
    {
        return head;
    }
    if (i == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *ans = deleteNodeRecursive(head->next, i - 1);
    head->next = ans;
    return head;
}

// Find the NOde and return the index of the Node
int findNode(Node *head, int data)
{
    Node *temp = head;
    int index = -1;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            flag = 1;
            return index + 1;
        }
        else
        {
            index++;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        return -1;
    }
}

// Append the number of the Node last node to the first in the Linked list

Node *appendLastToFirst(Node *head, int n)
{
    if (n == 0 || head == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    Node *initialHead = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    fast->next = initialHead;
    head = temp;
    return head;
}

// Remove the duplictaes Node from the linked List

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            temp = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
        head = temp;
        return head;
    }
}

// Print Reverse Linked list

void printReverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    printReverse(head->next);
    cout << head->data << " ";
}

// Palindrome List

bool isPlindrome(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *temp = head;
    stack<int> s;
    while (temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        int i = s.top();
        s.pop();
        if (temp->data != i)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

// Find the mid NOde of the linked lIst

Node *midNode(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge the two Sorted Linked list
Node *sortedLinkedList(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;
    if (head1->data <= head2->data)
    {
        head = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
    }
    if (head1 == NULL)
    {
        tail->next = head2;
    }
    if (head2 == NULL)
    {
        tail->next = head1;
    }
    return head;
}

// Merge Sort
Node *mergeSort(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *initial = head;

    Node *temp = midNode(head);
    Node *a = mergeSort(initial);
    Node *b = mergeSort(temp->next);
    Node *finalHead = sortedLinkedList(a, b);
    return finalHead;
}

// Reverse the Linked list AND the complexity of the function is order of n sqaure
Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallAns = reverse(head->next);
    Node *temp = smallAns;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallAns;
}

class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverseList(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverseListBetter(Node *head)
{
    return reverseList(head).head;
}

Node *reverse_LinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallAns = reverse_LinkedList(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}

// Reverse the linked list Itetrative
Node *reverseIterative(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *prevoius = NULL;
    Node *current = head;
    Node *next = head->next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prevoius;
        prevoius = current;
        current = next;
    }
    return prevoius;
}

int findNode2(Node *head, int data)
{
    if (head == NULL)
    {
        return -1;
    }

    if (head->data == data)
    {
        return 0;
    }
    int ans = findNode(head->next, data);
    if (ans != -1)
    {
        ans++;
    }
    else
    {
        return -1;
    }

    return ans;
}
void rearrangeEvenOdd( Node* head)
{
     Node *odd = NULL, *oddTail = NULL;
     Node *even = NULL, *evenTail = NULL;
 
     Node* curr = head;
 
    while (curr != NULL)
    {
        if (curr->data & 1)        // current node is odd
        {
            // handle head for the first odd node
            if (odd == NULL) {
                odd = oddTail = curr;
            }
            else {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
        }
        else    // current node is even
        {
            // handle head for the first even node
            if (even == NULL) {
                even = evenTail = curr;
            }
            else {
                evenTail->next = curr;
                evenTail = curr;
            }
        }
        curr = curr->next;
    }
 
    // if the list contains at least one even node
    if (even)
    {
        head = even;
        evenTail->next = odd;
    }
    // special case – list contains all odd nodes
    else {
        head = odd;
    }
 
    // NULL to terminate the list; otherwise, it will go into an infinite loop
    if (oddTail) {
        oddTail->next = NULL;
    }
}

Node *arrangeLinkedList(Node *head){
    if(head == NULL){
        return head;
    }

    Node *evenHead = NULL;
    Node *evenTail = NULL;
    Node *oddHead = NULL;
    Node *oddTail = NULL;

    Node *temp = head;
    while(temp != NULL){
        if(temp -> data % 2 == 0){
            if(evenHead == NULL){
                evenHead = temp;
                evenTail = temp;
            }
            else{
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }
        else{
            if(oddHead == NULL){
                oddHead = temp;
                oddTail = temp;
            }
            else{
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }
        temp = temp->next;
    }
    if(oddTail == NULL){
        return evenHead;
    }
    if(evenHead == NULL){
        return oddHead;
    }
    oddTail->next = evenHead;
    return oddHead;
}


int main()
{

    // Node *head = input();

    Node *head = input();
    print(head);
    cout << endl;
    head = arrangeLinkedList(head);
    print(head);
    // rearrangeEvenOdd(head);
    // print(head);

    // cout << isPlindrome(head);
    // bool palindrome = isPlindrome(head);
    // if(palindrome == true){
    //     cout << "True";
    // }
    // else{
    //     cout << "False";
    // }
    // printReverse(head);
    // head = appendLastToFirst(head, 3);
    // head = reverseIterative(head);
    // print(head);
    // Node *head2 = input();
    // Node *head = sortedLinkedList(head1, head2);
    // print(head);
    // print(head);
    // cout << endl;
    // Node* mid = midNode(head);
    // cout << mid->data;
    // int n;
    // cin >> n;
    // head = appendLastToFirst(head, n);
    // print(head);
    // cout << endl;
    // head = removeDuplicates(head);
    // print(head);
    // int node = findNode(head, 6);
    // cout << node << endl;
    // print(head);
    // cout << endl;
    // head = insertNodeRecursive(head, 23, 0);
    // print(head);

    //  int length = recursiveLength(head);
    //cout << length << endl;
    // head = deleteNode(head, 7);
    // print(head);

    /*
    Node *head = input();
    //  print(head);
    int count = length(head);
    //cout <<"\n" << count << endl;

    //cout << endl
    //   << endl;
    print(head, 3);
/*
    /*
    Node *n1 = new Node(10);
    Node *head = n1;
    Node *n2 = new Node(20);
    n1->next = n2;
    Node *n3 = new Node(30);
    n2->next = n3;
    Node *n4 = new Node(40);
    n3->next = n4;
    Node *n5 = new Node(50);
    n4->next = n5;
    print(head);
*/
    /*
    Node n1(10);
    Node *head = &n1;
    Node n2(20);
    n1.next = &n2;
    cout << n1.data << " " << n2.data << endl;
    cout << head->data << endl;
*/
}