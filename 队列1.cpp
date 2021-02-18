typedef int Position;
struct QNode{
		ElementType *Data;
		Position Front,Rear;
		int MaxSize;
};
typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize)
{
	Queue Q=(Queue)malloc(sizeof(struct QNode));
	Q->Data=(ElementType *)malloc(MaxSize * sizeof(ElementType));
	Q->Front=Q->Rear=0;
	Q->MaxSize=MaxSize;
	return Q;
}

bool IsFull(Queue Q)
{
	return((Q->Rear+1)%Q->MaxSize==Q->Front);
}

bool AddQ(Queue Q,ElementType X)
{
	if(isFull(Q)){
		printf("������");
		return false;
	}
	else {
        Q->Rear = (Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}

    bool IsEmpty( Queue Q )
    {
        return (Q->Front == Q->Rear);
    }
     
    ElementType DeleteQ( Queue Q )
    {
        if ( IsEmpty(Q) ) { 
            printf("���п�");
            return ERROR;
        }
        else  {
            Q->Front =(Q->Front+1)%Q->MaxSize;
            return  Q->Data[Q->Front];
        }
    }

