# UnionFind (并查集)
----
## 1.简介
并查集是用来解决图中连通性的问题，在一个graph中，判断两个节点是否连通，这种算法可以得到很快速的解答。看着名词很高大上，并查集，拆开读就是合并查找的集合，他的操作也就这两样，由此引发了很多有趣的问题，我们一步步来介绍这个算法。

一提起图上的遍历，大家肯定会想到DFS或者BFS再加上记忆也可以完全做到这个效果，但是这里的连通性和DFS或者BFS在图中的遍历也稍微有些许区别，首先我们这里说的连通性是相对与无向图的，dfs、bfs可以用于有方向的图结构，并查集使用的图是无向的，其次这个图具有对称性和传递性，对称性很好理解，对于连通性a与b连通，b与c连通，那么a一定与c连通。抽象出来就像下面这个伪代码。
```C++
  class UnionFind{
      /*构造函数*/
      UnionFind(int n);
      /*将节点i与节点j相链接*/
      bool merge(int i,int j);
      /*判断节点i与节点j是否相链接*/
      bool connected(int i,int j);
      /*返回节点i与节点j*/
      int count();
  };
```
初始化的时候所有节点都是孤立的，随后我们一步步调用`merge(i,j)`函数来链接两个节点（给图加边），最后当所有的边加入到并查集当中的时候，我们就可以使用`connected(i,j)`判断两个节点是否相链接了。

举个例子假如我们有如下图:

![graph](./images/UnionFind/1.jpg#pic_center "graph")
途中共有6个节点
```c++
    UnionFind uf(6);
    uf.merge(1,2);
    uf.merge(2,3);
    uf.merge(2,4);
    uf.merge(2,5);
    uf.merge(5,6);
```
因为这是一个连通图，所以任意两个节点之间都是连通的。问题我们了解清楚了，该如何实现这个数据结构呢？该如何在时间效率和空间效率中平衡这个算法呢？并查集这个算法有什么应用呢？

## 2.基本建模思路
既然连通的算一伙，那么总得有个标识吧，就用这个标识来代表这一伙，比如一群人张三，王五，李四，王八见面了，互相认识了一下，王五就乐呵呵的和王八在一起了，为啥呢？他们都信王啊！！！没准祖上都是一个人，哟呵这就提醒我们了，家族有族谱，代表家族的就是族长，族谱就是一个树的结构！！！但是每个人都能记得住族长的名字嘛？不可能的，过个几十年，族长都换多少人了，但是肯定记得他爸的名字，他爸肯定记得爸爸的爸爸，就这样一只顺腾摸瓜上去，一定可以找得到最初的那个人！！！最初刚开始，大家都是自己当自己的爸，然后节点与节点的链接就是认爸的过程~~~
我们开始找爸爸~~~
```c++
class UnionFind{
public:
    /*记录连通分量的数量*/
    int n;
    /*记录自己的爸爸*/
    vector<int> parent;
    /*构造函数初始化*/
    UnionFind(int _n){
        n = _n;
        //刚开始每个人都是自己的爸，每个人都是一组，所以有n个连通分量
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        //自己当自己爸，族里只有自己一个人，所以也是自己当族长
    }
};
```
下面就是认爸的过程,两个人见面，肯定不能青红皂白的就叫对方爸爸！得先看看这两人到底是不是一个家族的，要是一个家族的，都是一家人的话，就不用认了，如果不是，那不好意思，得分个谁是爸爸谁是儿子~~~
```c++
class UnionFind{
public:
    /*之前的函数*/
    ···
    /*之前的函数*/
    /*找祖宗:找祖宗的原则就是，问自己是不是族长，是族长的话，就是你自己的名字，要你不是族长的话，问你
    爸爸是不是族长，顺腾摸瓜，总能找到族长的，这里给出两个版本，递归版和迭代版，大家想用那个看喜好*/
    //递归版本
    int root(int i){
        return parent[i]==i?i:root(parent[i]);
    }
    //迭代版本
    int root(int i){
        while(i!=parents[i]){
            i = parents[i];
        }
        return i;
    }
    //叫爸爸
    bool merge(int i,int j){
        //找祖宗
        int i = root(i);
        int j = root(j);
        if(i==j)return false;//一家人客客气气
        //叫爸爸
        parent[i] = j;
        n--;//连通分量减1
        return true;
    }
};
```
这样我们的族谱构建好了以后，以后找爸爸看是不是一家人就方便多了
```c++
class UnionFind{
public:
    /*之前的函数*/
    ···
    /*之前的函数*/
    //返回当前集合有多少连通分量
    int count(){
        return n;
    }
    //判断两个人是不是一家子
    int connected(int i, int j){
        //找祖宗
        i = root(i);
        j = root(j);
        //不是一家人不进一家门
        return i==j;
    }
};
```
至此我们就完成了这个简单高效的算法。so amazing~~~~我们来分析分析，整个算法`connected`和`merge`函数的复杂度都是找祖宗的过程`root`造成的，这个`root`函数的复杂度怎么分析呢，因为我们是顺腾摸瓜，因此这个函数的复杂度就是和树的深度是一样的，但注意复杂度可不是`O(logN)`,为啥呢，我们在写叫爸爸的时候总是让`i`去叫`j`爸爸，这样会造成什么后果呢？——>在下十八代单传!!!也就是说我们构建出来的可能不是一个平衡的二叉树
    