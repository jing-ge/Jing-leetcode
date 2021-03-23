# 回溯算法
----
## 1.回溯算法简介
回溯是一种算法框架，这是一种暴力求解的算法，有些问题，可以暴力求解就已经很不错了，但是优雅的暴力求解，这就是一门技术啦。回溯算法可以用来解决，排列，组合，子集，切割，棋盘这几大类的问题。我们先从回溯算法的理论框架来讲起，然后慢慢讲解这几大类的问题来如何解决。然后介绍一些剪枝的操作，剪枝不同问题有不同的剪枝方式，要根据问题来具体对待。

## 2.回溯算法理论框架
任何回溯算法解决的问题都可以看作是一个决策树遍历的过程，所以当一个问题可以抽象成为一个决策树遍历的过程的时候，回溯算法就可以排上用场，从代码实现的角度来看，就是for循环里面来递归调用自己。这样乍一看来很想是DFS这样的算法，但是回溯算法之所以叫做回溯，因为它不仅像DFS这样只是遍历，他还要走回头路，很像走迷宫的时候，遇到障碍，以后就掉头回去，重新来走。对于一个决策树的遍历，只需要明白下面三个问题：
1. 当前路径：也就是之前已经做的选择
2. 可以做的选择：当前可以进行的选择
3. 结束条件：选择到什么时候停止继续选择了
用于代码描述，可以表示为下面的样子：
```c++
void backtrack(路径,选择列表){
    for (选择:选择列表){
        do 选择
        backtrack(路径,选择列表)
        do 撤销选择
    }
}
```
框架大致就是这个样子，会有人提问说，这个函数返回在哪里，在整个过程中，我们维护的只是这个路径，在恰当的时候，把这个路径存入最终结果就可以啦。
## 3.组合问题
我们先从最简单的组合问题入手，对应leetcode 77，先看题目介绍：
```
77. 组合
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],[3,4],[2,3],[1,2],[1,3],[1,4]
]
通过次数142,127提交次数185,472
```
很简单，这是一个组合问题，小朋友都会做，两两匹配嘛，我来操作一波：
```c++
vector<vector<int>> combine(int n){
    vector<vector<int>> res;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            res.push_back({i,j});
        }
    }
    return res;
}
```
这是解决了长度为2的组合，那长度为3怎么办？简单再套一次循环嘛，三层for循环，搞定，那长度为k呢？这下就没办法用for循环来了吧，这时候回溯算法就排上了用场。我们先来抽象一下这个问题，看看可否描述成为一个树的遍历，想象我们有k个篮子，要从这n个数里面选择k个出来，我们肯定是一个一个装，装篮子的过程和下面图所示的是否一样？
![graph](./images/BackTrack/1.jpg#pic_center "graph")
图中上方数字表示做的选择，括号内的数字，表示剩余没选择数字（可做的选择），看看最后一排的叶子节点是不是就是我们最终的答案？为什么树张的是这个样子呢？，如果我们第一步选择了2，此时的选择列表是[1,3,4]的话，那么就会产生[2,1]的结果，这和[1,2]的结果是一致的，我们这是个排列问题，要做到不重不漏，这个效果该如何实现呢，很简单，我们再每次回溯的时候加入一个起始位置的index就可以啦，（注意这里的index与排列的index有所区别哟，叶子节点使用过以后的，同级的叶子节点无法再次使用啦），代码实现的效果如下：
```c++
vector<vector<int>> res;
vector<int> path;
vector<vector<int>> combine(int n,int k){
    backtrack(n,k,1);
    return res;
}
void backtrack(int n,int k,int idx){
    //因为我们只要最后的叶子节点，在此结束递归
    if(path.size()==k){
        res.push(path);
        return ;
    }
    // for(选择：选择列表) 我们要从idx开始的位置做选择，之前的已经使用过了不可再次使用
    for(int i=idx;i<=n;i++){
        //做选择
        path.push_back(i);
        backtrack(n,k,i+1);//注意这里做的是i+1，同级的叶子节点不可以再次选择
        //撤销选择
        path.pop_back();
    }
}
```
代码注释很详细啦，我来根据回溯的过程来看看path的变化如下
```
->[]第一层的递归（选择1）
->[1]->[1,2]->[1]->[1,3]->[1]->[1,4]->[1]->[]
->[]第一层的递归（选择2）
->[2]->[2,3]->[2]->[2,4]->[2]
->[]第一层的递归（选择3）
->[3]->[3,4]->[3]
->[]第一层的递归（选择2）
->[4]
```
这样整个回溯基本就已经走完啦，想想还有没有什么可以优化的部分？是想一下，如果我们最终要装k个篮子，目前还有t个空蓝子，但是剩余可选择的菜都不够填满t个空蓝子了，证明这个方案是完全不可行的，他后面的递归也就没用啦。我们就可以剪枝掉他。代码如何实现呢？
```c++
vector<vector<int>> res;
vector<int> path;
vector<vector<int>> combine(int n,int k){
    backtrack(n,k,1);
    return res;
}
void backtrack(int n,int k,int idx){
    if(path.size()==k){
        res.push(path);
        return ;
    }
    for(int i=idx;i<=n;i++){
        path.push_back(i);
        //剪枝
        //当前有path.size个，菜还有n-i+1个，若是加起来都不够k个，剪枝掉就可以
        if(path.size()+n-i+1<k)break;
        backtrack(n,k,i+1);
        path.pop_back();
    }
}
```
换个写法，写道for循环里面剪枝也可以
```c++
vector<vector<int>> res;
vector<int> path;
vector<vector<int>> combine(int n,int k){
    backtrack(n,k,0);
    return res;
}
void backtrack(int n,int k,int idx){
    if(path.size()==k){
        res.push(path);
        return ;
    }
    //剪枝
        //把上面等式变化一下 
        //path.size()+n-k+1<i 的话 break，也就是说i<=path.size()+n-k+1
    for(int i=idx;i<=path.size()+n-k+1;i++){
        path.push_back(i);
        
        if(path.size()+n-i+1<k)break;
        backtrack(n,k,i+1);
        path.pop_back();
    }
}
```
对于组合操作的剪枝就这样啦~~~
## 4.子集问题
下面来看另一个的“组合”问题，我们之前求长度为2的组合，换个说法是不是求一个长度为2的子集，那要是求所有的子集呢？
有人会说，我组合都会求了，子集不就是把组合长度从1遍历到n，然后累计就可以了嘛？这是一个好方法，学以致用，但是里面有很多的重复计算，我把上面那张图补全来看。（这里面涉及一个很重要的点，叶子节点和所有节点）,这是求长度为4的组合的决策树图。
![graph](./images/BackTrack/2.jpg#pic_center "graph")
如果我们只需要求长度为4的组合数，那就只有最后一行节点，有没有发现一个规律（开头节点不算），第一行是长度为1，第二行是长度为2，。。。，最后一行是长度为n的组合数，这些所有的节点不就是该子集的集合嘛？
我们只是在收集答案的时候，位置不同而已，我们重新来审查一下回溯算法这个框架。
```c++
void backtrack(路径,选择列表){
    //位置①
    for (选择:选择列表){
        //位置②
        do 选择
        //位置③
        backtrack(路径,选择列表)
        //位置④
        do 撤销选择
        //位置⑤
    }
    //位置⑥
}
```
能进行选择的位置无非就这上面几个位置，首先明确的一点位置①和位置⑥的结果是完全一样的，位置②和位置⑤的结果是一样的，要不然不还原怎么叫回溯嘛，我们来一一看这几个位置
### 4.1位置①和位置⑥
要明白，这个位置是进入节点之后就把path放入答案集合，刚开始是空集，然后有多少个节点就有多少个path，这不就是我们想要的答案嘛来看看最终实现
```c++
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        // res.push_back({});
        backtrace(nums,0);
        return res;
    }
    void backtrace(vector<int> &nums,int idx){
        res.push_back(tmp);
        for(int i=idx;i<nums.size();i++){
            tmp.push_back(nums[i]);
            backtrace(nums,i+1);
            tmp.pop_back();
        }
    }
```
### 4.2位置②和位置⑤
这个位置进行结果储存的话，无任何意义
### 4.3位置③
位置③位于选择之后，进入节点之前，也就是节点的下方边，这样可以达到结果，但是会漏掉空集，补一个就可以
```c++
   vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back({});
        backtrace(nums,0);
        return res;
    }
    void backtrace(vector<int> &nums,int idx){
        for(int i=idx;i<nums.size();i++){
            tmp.push_back(nums[i]);
            backtrace(nums,i+1);
            res.push_back(tmp);
            tmp.pop_back();
        }
    }
```
### 4.4位置④
这个位置是上方边，完成效果，每一个节点头上都有边，不需要补
```c++
vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrace(nums,0);
        return res;
    }
    void backtrace(vector<int> &nums,int idx){
        for(int i=idx;i<nums.size();i++){
            tmp.push_back(nums[i]);
            backtrace(nums,i+1);
            res.push_back(tmp);
            tmp.pop_back();
        }
    }
```
![graph](./images/BackTrack/3.jpg#pic_center "graph")
### 4.5 总结
位置1和位置6效果相同看节点；位置3和位置4有细小差别，额外代码补就可以；位置2和位置5效果相同暂时没发现规律。莫要纠结这个点，统一都写在递归结束开头就可以。~~~~

## 5.排列问题
对于排列问题也可以使用回溯算法来处理解决，如下面这个最基本的全排列问题，对于leetcode 46
```
1.  全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
通过次数280,029提交次数360,141
```
对于排列问题就是一个无放回的拿球问题，排列问题和拿的顺序是有关系的，所以我们需要一个数组来记录是否被取走的状态，如果是1，就代表已经被取走了，如果是0，还可以取，通过状态记录，有效的实现了动态剪枝的效果，废话不多说我们来看看代码
```c++
vector<int> res;
vector<int> status;
vector<vector<int>> permute(vector<int>& nums) {
        backtrack2(nums,0);
        return res;
}
void backtrack(vector<int>& nums){
    if (tmp.size() == nums.size()) {
        res.push_back(tmp);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if(status[i]==0){
            tmp.push_back(nums[i]);
            status[i] = 1;
            backtrack(nums);
            status[i] = 0;
            tmp.pop_back();
        }
    }
}
```

还有另外一种解法，每次剪枝也比较麻烦，有没有不用记录状态就可以解决的办法呢，答案是可以的，我们可以将题目给定的 n 个数的数组nums划分成左右两个部分，左边的表示已经填过的数，右边表示待填的数，我们在回溯的时候只要动态维护这个数组即可。代码如下：
```c++
vector<int> res;
vector<vector<int>> permute(vector<int>& nums) {
    backtrack(nums,0);
    return res;
}
void backtrack2(vector<int>& nums,int idx){
    if(idx==nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[i],nums[idx]);
        backtrack2(nums,idx+1);
        swap(nums[i],nums[idx]);
    }
}
```

## 6.搜索问题
搜索问题这个就涉及的应用比较广泛了，从解数独到N皇后，都有他的用武之地。只要理解了回溯的思想，正确的画出来决策树，