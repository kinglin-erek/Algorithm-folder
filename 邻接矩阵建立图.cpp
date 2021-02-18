#include<iostream>
using namespace std;
///////////////////////////通用模式///////////////////////////
#define MaxVertexNum 20

typedef int WeightType;
typedef int DataType;

typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
    GNode():Nv(0),Ne(0){}
};
typedef PtrToGNode MGraph;

typedef int Vertex;
MGraph CreateGraph(int VertexNum){
    Vertex V, W;
    MGraph Graph;

    Graph = new GNode();
    Graph->Nv = VertexNum;

    for(V = 0; V < Graph->Nv; V++)
        for(W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = 0;

    return Graph;
}

typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;
    WeightType Weight;
    ENode():V1(0),V2(0){}
};
typedef PtrToENode Edge;

void InsertEdge(MGraph Graph, Edge E){
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight; //无向图
}

MGraph BuildGraph(){
    MGraph Graph;
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

    for(V = 0; V < Graph->Nv ; V++)
        cin>>Graph->Data[V];
    
    return Graph;
}
///////////////////////////简单模式///////////////////////////
int G[MaxVertexNum][MaxVertexNum], Nv, Ne;
void Buildgraph(){
    int i, j, v1, v2, w;
    cin>>Nv;
    for(i=0; i<Nv; i++)
        for(j=0; j<Nv; j++)
            G[i][j]=0;
    cin>>Ne;
    for(i=0; i<Ne; i++){
        cin>>v1>>v2>>w;
        G[v1][v2] = w;
        G[v2][v1] = w;
    }
    
}

int main(){

    return 0;
}