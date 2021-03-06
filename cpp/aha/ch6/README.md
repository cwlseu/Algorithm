## Floyd-warshall
Floyd-Warshall算法,中文亦称弗洛伊德算法,是解决**任意两点**间的最短路径的一种算法,可以正确处理有向图或负权（**但不可存在负权回路**)的最短路径问题,
同时也被用于计算有向图的传递闭包。Floyd-Warshall算法的时间复杂度为$O(N^3)$，空间复杂度为$O(N^{2})$。

### Floyd-Warshall算法的原理是动态规划
设 $D_{i,j,k}$为从$i$到$j$的只以$(1..k)$集合中的节点为中间节点的最短路径的长度。
若最短路径经过点k,则 $D_{i,j,k}=D_{i,k,k-1}+D_{k,j,k-1}$；
若最短路径不经过点k,则 $D_{i,j,k}=D_{i,j,k-1}$。
因此，$D_{i,j,k}=min(D_{i,j,k-1},D_{i,k,k-1}+D_{k,j,k-1})$。
在实际算法中,为了节约空间,可以直接在原来空间上进行迭代,这样空间可降至二维。

### 伪代码

```python
"""
letdistbea |V|x|V| arrayofminimumdistanceinitializedtoinfinity
其中dist[i][j]表示由点i到点j的代价,当其为 ∞ 表示两点之间没有任何连接
"""
# initthegraph
forvinvertex:
    dist[v][v] = 0
foredge(u, v) inedge:
    dist[u][v] = w(u, v)

# startthemainalgorithm
forkrange(1,|V|):
    forirange(1, |V|):
        forjrange(1, |V|):
            ifdist[i][j] > dist[i][k] + dist[k][j]: 
                dist[i][j] = dist[i][k] + dist[k][j]
            endif
        endfor
    endfor
endfor
```

### 为什么不能解决带有"负权回路"的图,因为带有负权回路的图没有最短路径。因为1->2->3->1->2->3->1->2->3,每次绕一次就减少1, 永远都找不到最短路径。

## Dijkstra算法
戴克斯特拉算法是由荷兰计算机科学家艾兹赫尔·戴克斯特拉提出。迪科斯彻算法使用了**广度优先**搜索解决赋权有向图的单源最短路径问题,算法最终得到一个最短路径树。该算法常用于路由算法或者作为其他图算法的一个子模块。
举例来说,如果图中的顶点表示城市,而边上的权重表示城市间开车行经的距离,该算法可以用来找到两个城市之间的最短路径。该算法的输入包含了一个有权重的有向图G,以及G中的一个来源顶点S。我们以V表示G中所有顶点的集合。每一个图中的边,都是两个顶点所形成的有序元素对。(u, v) 表示从顶点u到v有路径相连。我们以E表示G中所有边的集合,而边的权重则由权重函数w: E → [0, ∞] 定义。因此,w(u, v) 就是从顶点u到顶点v的**非负权重**（weight）。边的权重可以想像成两个顶点之间的距离。任两点间路径的权重,就是该路径上所有边的权重总和。已知有V中有顶点s及t,Dijkstra算法可以找到s到t的最低权重路径(例如,最短路径)。这个算法也可以在一个图中, 找到从**一个顶点s到任何其他顶点**的最短路径。


### 伪代码

```python
def Dijkstra(Graph, source):
     dist[source] ← 0                 # Initialization
     create vertex set Q

     for each vertex v in Graph:           
         if v ≠ source
             dist[v] ← INFINITY       # Unknown distance from source to v
             prev[v] ← UNDEFINED      # Predecessor of v

         Q.add_with_priority(v, dist[v])


     while Q is not empty:            # The main loop
        u ← Q.extract_min()           # Remove and return best vertex
        for each neighbor v of u:     # only v that is still in Q
            alt ← dist[u] + length(u, v) 
            if alt < dist[v]
                 dist[v] ← alt
                 prev[v] ← u
                 Q.decrease_priority(v, alt)
     return dist[], prev[]
```

## Bellman Ford算法
对所有的E条**边**进行V-1次松弛操作。因为最短路径上最多有V-1条边. 第一次循环相当于经过一条边到达各个顶点的最短路径，经过k次循环相当于经过k条边到达各个顶点的最短路径。

```cpp
   for (int k = 1; k <= V - 1; k++)
   {
      for(int i = 1; i <= E; ++i)
      {
         if(dist[v[i]] > dist[u[i]] + w[i])
            dist[v[i]] = dist[u[i]] + w[i]; 
      }
   }
```

除此之外，Bellman ford算法还可以用来检查是否有**负权回路**. 如果在进行V-1次松弛操作之后，仍然存在

```cpp
  if(dist[v[i]] > dist[u[i]] + w[i])
            dist[v[i]] = dist[u[i]] + w[i]; 
```

的情况的话，也就是说V-1轮松弛之后，仍然可以松弛，那么必存在负权回路。

```cpp
   for (int k = 1; k <= V - 1; k++)
   {
      for(int i = 1; i <= E; ++i)
      {
         if(dist[v[i]] > dist[u[i]] + w[i])
            dist[v[i]] = dist[u[i]] + w[i]; 
      }
   }
   // 检查是否有负权回路
   bool flag = false;
   for(int i = 1; i <= E; ++i)
   {
      if(dist[v[i]] > dist[u[i]] + w[i])
        flag = true; 
   }
   if (flag) printf("这图有负权回路\n");
```

## 复杂度总结
|         | Floyd     | Dijkstra    | Bellman Ford | Bellman Ford Proiority |
|:-------:|:---------:|:-----------:|:----------:|:---------------------:|
| 空间复杂度 |  O(V^2) |  O(E) |    O(E)   | O(E) |
| 时间复杂度 |  O(V^3) | O((V+E)lgV)| O(VE)| 最坏O(VE)|
| 适应情景  |稠密图和顶点关系密切|稠密图和顶点关系密切|稀疏图和边关系密切|稀疏图和边关系密切|
| 负权    |不可以|不能解决|可以解决|可以解决负权|
