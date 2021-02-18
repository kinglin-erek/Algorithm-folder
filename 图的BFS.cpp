void BFS(Vertex V){
    visited[V] = true;
    Enqueue(V,Q);
    while(!isempty(Q)){
        V = Dequeue(Q);
        for(V的每个邻接点W)
            if(!visited[W]){
                visited[W] = true;
                Enqueue(W,Q);
            }
    }
}