#include<iostream>
#include<queue>
using namespace std;
//////////////////////////////////////////////深度优先搜索//////////////////////////////////////////////////////////
template<class T, class E>
void DFS(Graph<T,E> & G, const T& v){
	int i, loc, n = G.NumberOfVertices();
	bool * visited = new bool[n];
	for(i=0; i<n; i++) visited[i] = false;
	loc = G.getVertexPos(v);
	DFS(G, loc, visited);
	delete[] visited;
};

template<class T, class E>
void DFS(Graph <T,E> & G, int v, bool visited[]){
	cout<<G.getValue(v)<<' ';
	visited[v] = true;
	int w = G.getFirstNeighbor(v);
	while(w != -1){
		if(visited[w] == false) DFS(G,w,visited);
		w = G.getNextNeighbor(v,w);
	}
};
//////////////////////////////////////////////广度优先搜索//////////////////////////////////////////////////////////
template<class T, class E>
void BFS(Graph<T,E> & G, const T& v){                //////////注意这里的queue 的方法衔接
	int i, w, n = G.NumberOfVertices();
	bool *visited = new bool[n];
	for(i=0; i<n; i++) visited[i] = false;
	int loc = G.getVertexPos(v);
	cout<<G.getValue(loc)<<' ';
	visited[loc] = true;
	queue<int> q; q.push(loc);
	while(!q.empty()){
		loc = q.top();q.pop();
		w = G.getFirstNeighbor(loc);
		while(w != -1){
			if(visited[w] == false){
				cout<<G.getValue(w)<<' ';
				visited[w] = true;
				q.push(w);
			}
			w = G.getNextNeighbor(loc,w);
		}
	}
	delete[] visited;
};

/////////////////////////////////////////////最小生成树的类定义////////////////////////////////////////////////////////////
const float maxValue = FLT_MAX;
template<class T, class E>
struct MSTEdgeNode{
	T tail, head; E key;
	MSTEdgeNode():tail(-1),head(-1),key(0){}
	bool operator <= (MSTEdgeNode<T,E>& R){return key <= R.key;}
	bool operator > (MSTEdgeNode<T,E>& R){return key > R.key;}
};

template<class T, class E>
class MinSpanTree{
protected:
	MSTEdgeNode<T,E> *edgevalue;
	int maxSize,n;
public:
	MinSpanTree(int sz = DefaultSize - 1):MaxSize(sz),n(0){
		edgevalue = new MSTEdgeNode<T,E>[sz];
	}
	int Insert(MSTEdgeNode& item);
};
/////////////////////////////////////////////Kruskal算法////////////////////////////////////////////////////////////
/*
伪代码描述:
	T=空集;
		while(T包含的边少于n-1 && E不空){
		从E中选一条cost最小的边(v,w);
		从E中删去(v,w);
		如果(v,w)加到T中后不会产生回路，则将(v,w)加入T，否则放弃(v,w);
	}
	if(T中包含的边少于n-1条) cout<<"不是最小生成树"<<endl;
*/
template<class T, class E>
void Kruskal(Graph<T,E>&G,MinSpanTree<T,E>&MST){
	MSTEdgeNode<T,E> ed; int u, v, count;
	int n = G.NumberOfVertices();
	int m = G.NumberOfEdges();
	MinHeap<MSTEdgeNode<T,E>> H(m);          ////////////////用到了最小堆
	UFSets F(n);							////////////////用到了并查集
	for(u=0; u<n; u++){
		for(v=u+1; v<n; v++){
			if(G.getWeight(u,v) != maxValue){
				ed.tail = u; ed.head = v;
				ed.key = G.getWeight(u,v);
				H.Insert(ed);
			}
		}
	}
	count = 1;
	while(count < n){
		H.RemoveMin(ed);
		u = F.Find(ed.tail);
		v = F.Find(ed.head);
		if(u != v){
			F.Union(u,v);
			MST.Insert(ed);
			count++;
		}
	}
};

int main(){


	return 0;
}