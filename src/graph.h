#ifndef GRAPH_H
#define GRAPH_H

typedef struct Edge Edge;
typedef struct Graph Graph;

struct Edge {
    int destination_vertex;
    double weight;
    Edge *next;
};

struct Graph {
    int num_vertices;
    Edge **heads;
};
/* Ownership Comments
-1. graph_create allocates the graph and the heads array.
-2. graph_add_edge allocates edges, one per call.
-3. graph_free frees the memory in order (edges, heads ,graph). Why? freeing the array or the struct first loses your only way to reach the edge lists
-4. The caller never calls free on indvidiual edges or on heads. After graph_free(g) the pointer g is dangling and must not be used.
*/
Graph* graph_create(int n); //returns a pointer to a new graph.

int graph_add_edge(Graph *g, int u, int v, double w); //adds a directed edge from u to v.

void graph_free(Graph *g); //releases everything

void graph_print(Graph *g); //prints each vertex and its outgoing edges


#endif