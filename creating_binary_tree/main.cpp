#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
};

struct Queue
{
    int front;
    int rear;
    int size;
    Node **Q;
};

void Enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front)
        cout<<"Queue is full"<<endl;
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct Node * Dequeue(struct Queue *q)
{
    Node *x=NULL;
    if(q->rear==q->front)
        cout<<"Queue is Empty"<<endl;
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

bool isEmpty(struct Queue q)
{
    if(q.front==q.rear)
        return true;
    else
        return false;
}

void create(struct Queue *q,int size)
{
    q->size=size;
    q->Q=(struct Node **)malloc(sizeof(struct Node *)*q->size);
    q->front=q->rear=0;
}

struct Node *root=NULL;

void Treecreate()
{
    int x;
    struct Node *p,*t;
    struct Queue q;
    cout<<"Enter the value of the root "<<endl;
    root=(Node*)malloc(sizeof(Node));
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=NULL;
    Enqueue(&q,root);
    while(!isEmpty(q))
    {
        p=Dequeue(&q);
        cout<<"Enter the left child of "<<p->data<<" :"<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=(Node*)malloc(sizeof(Node));
            t->data=x;
            p->lchild=t;
            Enqueue(&q,t);
        }
        cout<<"Enter the right child of "<<p->data<<" :"<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=(Node*)malloc(sizeof(Node));
            t->data=x;
            p->rchild=t;
            Enqueue(&q,t);
        }
    }
}

void preorder(struct Node *n)
{
    if(n)
    {
        cout<<n->data<<" "<<endl;
        preorder(n->lchild);
        preorder(n->rchild);
    }
}

void postorder(struct Node *n)
{
    if(n)
    {
        preorder(n->lchild);
        preorder(n->rchild);
        cout<<n->data<<" "<<endl;
    }
}

void inorder(struct Node *n)
{
    if(n)
    {
        preorder(n->lchild);
        cout<<n->data<<" "<<endl;
        preorder(n->rchild);
    }
}

void levelorder(struct Node *n)
{
    struct Queue q;
    create(&q,20);
    cout<<n->data<<" ";
    Enqueue(&q,n);
    while(!isEmpty(q))
    {
        n=Dequeue(&q);
        if(n->lchild)
        {
            cout<<n->lchild->data<<" ";
            Enqueue(&q,n->lchild);
        }
        if(n->rchild)
        {
            cout<<n->rchild->data<<" ";
            Enqueue(&q,n->rchild);
        }
    }
}

int main()
{
    Treecreate();
    cout<<"The preorder traversal of the entered tree is given by : "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"The inorder traversal of the entered tree is given by : "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"The postorder traversal of the entered tree is given by : "<<endl;
    postorder(root);
    cout<<endl;
    cout<<"The levelorder traversal of the entered tree is given by : "<<endl;
    levelorder(root);
    cout<<endl;
    return 0;
}
