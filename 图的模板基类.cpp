#include<iostream>
using namespace std;

const int DefaultVertices = 30;

template<class T,class E>
class Graph{
public:
	const E maxWeight = 99999999;
	Graph(int sz = DefaultVertices);
	~Graph();
	bool GraphEmpty()const{
		if(numEdges == 0) return true;
		else return false;
	}
	bool GraphFull()const{
		if(numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1)/2) return true;
		else return false;
	}
	int NumberOfVertices(){return numVertices;}
	int NumberOfEdges(){return numEdges;}
	virtual T getValue?(int i);
	virtual E getWeight(int v1, int v2);
	virtual int getFirstNeighbor(int v);
	virtual int getNexNeighbor(int v, int w);
	virtual bool insetVertex(const T& vertex);
	virtual bool insertEdge(int v1, int v2, E cost);
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
	virtual int getVertexPos(T vertex);
};