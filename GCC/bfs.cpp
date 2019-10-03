#include <iostream>
#include <limits.h>
using namespace std;
struct adjlistnode
{
	int data;
	struct adjlistnode *next;
};
struct adjlist
{
	struct adjlistnode *head;
};
struct graph
{
	int vertices;
	struct adjlist* array;
	int* visited;
};
struct adjlistnode* c_node(int v)
{
	struct adjlistnode* node=new struct adjlistnode;
	node->data=v;
	node->next=NULL;
	return node;
}
struct graph* creategraph(int numv)
{
	struct graph* g= new graph;
	g->vertices=numv;
	g->array=new struct adjlist[(numv)*sizeof(adjlist)];
	g->visited=new int[numv*sizeof(int)];
	for(int i=0;i<numv;i++)
	{
		g->array[i].head=NULL;
	}
	return g;
}
void addedge(struct graph* g,int v1,int v2)
{
	 struct adjlistnode* temp=c_node(v1);
	 temp->next=g->array[v2].head;
	 g->array[v2].head=temp;
	 temp=c_node(v2);
	 temp->next=g->array[v1].head;
	 g->array[v1].head=temp;
}
void printgraph(struct graph* g,int v)
{
	int i;
	for(i=0;i<v;i++)
	{
		struct adjlistnode *q=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
		q=g->array[i].head;
		cout<<"for node"<<i<<endl;
		while(q)
		{
			cout<<q->data;
			q=q->next;
		}
		cout<<endl;
	}
}
class queue
{
public:
	int front,rear,size;
	unsigned capacity;
	int *array;	
};
queue* createqueue(unsigned capacity)
{
	queue* q=new queue();
	q->capacity=capacity;
	q->front=q->size=0;
	q->rear=capacity-1;
	q->array=new int[(q->capacity)*sizeof(int)];
	return q;
}
int isfull(queue* q)
{
	return (q->size==q->capacity);
}
int isempty(queue* q)
{
	return(q->size==0);
}
void printQueue(struct queue *q) {
        int i = q->front;
        if(isempty(q)) {
            cout<<"Queue is empty"<<endl;
        } else {
            cout<<"Queue contains"<<endl;
            for(i = q->front; i < q->rear + 1; i++) {
                    cout<<q->array[i];
            }
        }    
    }
void enqueue(queue* q,int item)
{
	if(isfull(q))
		return;
	else
	{
		q->rear=(q->rear+1)%q->capacity; // here % is there so that it does not cross the capacity
		q->array[q->rear]=item;
		q->size++;
	}
}
int dequeue(queue *q)
{
	int item=q->array[q->front];
	q->front=(q->front+1)%q->capacity;
	q->size--;
	return item;
}
int front(queue *q)
{
	if(isempty(q))
		return INT_MIN;
	else
	{
		int item=q->array[q->front];
		return item;
	}
}
int rear(queue *q)
{
	if(isempty(q))
		return INT_MIN;
	return q->array[q->rear];
}
void bfs(struct graph* g,int startvertex,int numv)
{
	queue* q=createqueue(numv);
	g->visited[startvertex]=1;
	enqueue(q,startvertex);
	while(!isempty(q))
	{
		printQueue(q);
		int currenvertex=dequeue(q);
		cout<<"visited"<<currenvertex<<endl;
		struct adjlistnode* temp=g->array[currenvertex].head;
		while(temp)
		{
			if(g->visited[temp->data]==0)
			{
				g->visited[temp->data]=1;
				enqueue(q,temp->data);
			}
			temp=temp->next;
		}
	}
}
int main()
{

        struct graph* graph = creategraph(6);
        addedge(graph, 0, 1);
        addedge(graph, 0, 2);
        addedge(graph, 1, 2);
        addedge(graph, 1, 4);
        addedge(graph, 1, 3);
        addedge(graph, 2, 4);
        addedge(graph, 3, 4);
     
        bfs(graph,0,5);
     
        return 0;
}