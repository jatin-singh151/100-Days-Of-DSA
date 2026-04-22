
typedef struct{
    int node;
    int cost;
}State;

void swap(State *a, State *b){
    State temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct{
    State data[10000];
    int size;
}MinHeap;

bool empty(MinHeap *h){
    return h->size == 0;
}

void heapify(MinHeap*h, int i, int n){
    int lc = 2*i+1;
    int rc = 2*i+2;
    int min = i;
    if (lc < n && h->data[lc].cost < h->data[min].cost)
        min = lc;
    if (rc < n && h->data[rc].cost < h->data[min].cost)
        min = rc;
    if (min != i) {
        swap(&h->data[i], &h->data[min]);
        heapify(h, min, n);
    }
}

void push(MinHeap *h, State s){
    int i = h->size++;
    h->data[i] = s;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->data[parent].cost <= h->data[i].cost)
            break;
        swap(&h->data[parent], &h->data[i]);
        i = parent;
    }
}

State pop(MinHeap *h){
    State minVal = h->data[0];
    h->data[0] = h->data[--h->size];
    heapify(h, 0, h->size);
    return minVal;
}

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int reachable[n];
    for(int i=0;i<n;i++) reachable[i] = 0;

    int adj[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j] = 0;

    for(int i=0;i<edgesSize;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u][v] = w;
        adj[v][u] = w;
    }

    for(int i=0;i<n;i++){
        MinHeap h = {0};
        int distances[n];
        for(int j=0;j<n;j++) distances[j] = INT_MAX;

        distances[i] = 0;
        push(&h, (State){i, 0});

        while(!empty(&h)){
            State curr = pop(&h);
            if(curr.cost > distances[curr.node]) continue;

            int u = curr.node;
            for(int j=0;j<n;j++){
                if(adj[u][j] && j != u){
                    int newCost = curr.cost + adj[u][j];
                    if(newCost < distances[j]){
                        distances[j] = newCost;
                        push(&h, (State){j, newCost});
                    }
                }
            }
        }

        for(int j=0;j<n;j++){
            if(distances[j] <= distanceThreshold)
                reachable[j]++;
        }
    }

    int count = INT_MAX;
    int index = 0;
    for(int i=0;i<n;i++){
        if(reachable[i] <= count){
            index = i;
            count = reachable[i];
        }
    }
    return index;
}
