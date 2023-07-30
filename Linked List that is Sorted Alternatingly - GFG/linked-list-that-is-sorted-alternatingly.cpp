//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
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
Node* merge(Node* h1, Node* h2){
    if(!h1 and !h2) return NULL;
    if(!h1) return h2;
    if(!h2) return h1;
    
    Node* res= new Node(-1), *tmp=res, *p=h1, *q=h2;
    while(p and q){
        if(p->data > q->data){
            tmp->next=q;
            q=q->next;
        }else{
            tmp->next=p;
            p=p->next;
        }
        tmp=tmp->next;
    }
    if(p) tmp->next=p;
    if(q) tmp->next=q;
    return res->next;
}
void sort(Node **head)
{
     // Code here
     Node* h1= (*head), * h= (*head)->next, *h2=h;
     while(h and h->next){
         h1->next=h1->next->next;
         h->next=h->next->next;
         
         h1=h1->next;
         h=h->next;
     }
     h1->next=NULL;
     *head= merge(*head, reverse(h2));
}