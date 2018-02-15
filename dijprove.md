Dijkstra(G,s)
- init dist, prev arrays
- init empty heap H

Define A as the set of vertice popped off heap so far, will show dist[] is correct on A by induction on |A|


Bellman-Ford
Algorithm built on the observation that ***sub-paths of shortest paths must also be shortest paths***
f(u,k) = length of shortest path from s to u using <= k edges
then f(u, n-1) is shortest paths
space complexity -> k

start from k=0
f(u,k) = {
  INF if u!=s, k=0
  0 if u==s, k=0
  min {
    f(v, k-1) (k>0) + w(v, u) (v, u)->E
  }
}
assume s->v->u
s->u has k edges, s->v has k-1 edges

Slow Algorithm: O((n-1)^(n-1))

MEMORIZATION
Idea: since f has very few distinct arguments (n^2), keep a global lookup table T of size n^2 T [1..n] [0..n-1]
recursion + lookup table
def f(u, k)

Runtime
Sum of all distince node w in the recursion tree
work(w) -> # nodes in tree * max work in any nodes
n^2 * O(n) --> Better than (n-1)^(n-1)

Sum(k=0->n-1)total work done at level k of recursion <= n(max work done in any level) = n*O(sum u-->v indeg(u)+1) ->O(n(m+m))
O(n(m+n))

Dynamic programming -> for version
memorization -> recursive version

Why recursion better?
memorize space O(n^2)
Value of k only depends on k-1
Iterative approach: for k=0 to n-1 for u <- V
f(k) value only depends on f(k-1) Value
Fill T[1..n] [k] use T[1..n] [k-1], then switch

Simple version of Bellman Ford
(G, s)
G->graph, s->source
T[1..n] --> NEGINF
T[1] <-- 0
for k=1 to n-1
  for (u, v) in E
    T[v] <- min(T[v], T[u]+w(u, v))
  return - [ ]

Analysis
Prove by induction on k after k times through the main loop for all vertice u
Vu belongs to V, T[u] <= f(u, k)

Detecting negative cycles
claim: the negative cycles rechable from s
If f(u, n) < f(u, n-1), negative cycle detected
Pf: If exist u such that f(u,n) < f(u, n-1), there is neg cycles
other direction: exist neg cycles -> f(u, n) < d(u, n-1)
equal f(u, n) >= f(u, n-1) all cycle c, w(c) >= 0
Take arbitary cycles, v1->v2->vr->v1, show w(c) >= 0

Assumption f(vi+1, n-1) = f(vi+1, n) <= f(vi, n-1) + w(vi, vi+1)
--> sum(1..r) f(vi+1, n-1)-f(vi, n-1) <= sum(1..r) w(vi, vi+1)
sum(1..r) f(vi+1, n-1)-f(vi, n-1) = f(vi+2, n-1)-f(vi+1, n-1)+f(vi+1, n-1)-f(vi, n-1).... = 0

Other shortest paths problem
1. SSSP on DAG
2. All pairs shortest paths (No source)

DAG: f(s) = len of shortest path s->u
f(u)={
  0, u==s
  INF, u!=s, indeg(u)==0
  min{
    (v, u) of f(v)+w(v, u)
  }
}
O(m+n) times
O(n) extra times
topologically sorted DAG

For bottom up DP, use topologically sort order

APSP: Floyd Warshall algorithm
f(u, v, k) = len of shortest u -> v path in which all intermediate vertices are in the set (1..k)
f(u, v, n) -> len of shortest path from u->v
Recurrence:
Assume u, v is edge
f(u, v, k) = {
  w(u, v) k=0
  min {
    f(u, v, k-1)
    f(u, k, k-1)+f(k, v, k-1)
  }
}

Memorization
space mem table O(n^3)
bottom up DP: all k depend k-1 -> O(n^2)

Time
O(n^3)

for k=1 to n
  for u=1 to n
    for v=1 to n
      T[u] [v] = min(T[u] [v], T[u] [k]+T[k] [v])
