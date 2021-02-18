#include<iostream>
using namespace std;
#define MaxVertexNum 20
typedef int WeightType;
typedef int DataType;
typedef int Vertex;

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
    DataType Data;
}AdjList[MaxVertexNum];


typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    AdjList G;
    GNode():Nv(0),Ne(0){}
};
typedef PtrToGNode LGraph;



typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
    AdjVNode():AdjV(0),Weight(0),Next(NULL){}
};

LGraph CreateGraph(int VertexNum){
    Vertex V, W;
    LGraph Graph;

    Graph = new GNode();
    Graph->Nv = VertexNum;

    for(V = 0; V < Graph->Nv; V++)
        Graph->G[V].FirstEdge = NULL;

    return Graph;
}

typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;
    WeightType Weight;
    ENode():V1(0),V2(0){}
};
typedef PtrToENode Edge;

void InsertEdge(LGraph Graph, Edge E){
    PtrToAdjVNode NewNode;
    
    NewNode = new AdjVNode();
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    NewNode = new AdjVNode();
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph(){
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    cin>>Nv;
    Graph = CreateGraph(Nv);
    cin>>Graph->Ne;
    if(Graph->Ne != 0){
        E = new ENode();
        for(i = 0; i < Graph->Ne; i++){
            cin>>E->V1>>E->V2>>E->Weight;
            InsertEdge(Graph, E);
        }
    }
    
    return Graph;
}