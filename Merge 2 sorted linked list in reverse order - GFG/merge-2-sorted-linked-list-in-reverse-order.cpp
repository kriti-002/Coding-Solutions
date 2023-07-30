//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/
Node* reverse(Node* head){
    Node* p=NULL, *q=head, *r=NULL;
    while(q){
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    return p;
}
Node* merge2sorted(Node* head1, Node* head2){
    if(!head1 and !head2) return NULL;
    if(!head1) return head2;
    if(!head2) return head1;
    
    Node* res=new Node(), *tmp=res, *p=head1, *q=head2;
    while(p and q){
        if(p->data > q->data){
            tmp->next=q;
            tmp=tmp->next;
            q=q->next;
        }else{
            tmp->next=p;
            tmp=tmp->next;
            p=p->next;
        }
    }
    if(p){
        tmp->next=p;
        p=p->next;
    }
    if(q){
        tmp->next=q;
        q=q->next;
    }
    return res->next;
}
struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here
    return reverse(merge2sorted(node1, node2));
    
}