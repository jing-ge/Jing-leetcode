# 算法面经整理
## 一·机器学习基础
### 1.1 XGBoost
XGBoost树模型是通过CART实现集成学习，通过Gradient Boosting进行模型训练。XGBoost由多棵CART组成，每一颗决策树学习的是目标值与之前所有树的预测值之和的残差，多颗决策树共同决策，最后将所有树的结果累加起来作为最终的预测结果。（只能串行的进行训练）
#### 1.1.1 CART
* CART(Classification And Regression Tree) 是指分类回归树，ID3算法采用信息增益来度量划分数据集前后不确定性减少的程度，C4.5采用的是信息增益比，CART采用一种新的策略：分类树采用基尼指数最小化进行特征选择，回归树采用平方误差最小化。

* 基尼指数：
$$
    Gini(D)=1-\sum_{k=1}^{K}p_k^2
$$
其中D为样本集，K表示类别个数，$p_k$表示类别为$k$的样本占所有样本的比值。

* 平方误差：
$$
    L=\sum_{x_i\in R^n}(y_i-f(x_i))^2
$$
回归树在进行特征选择之时，对于所有的特征以及切分点，分别计算分裂后的子节点的平方误差和，选择平方误差之和最小的作为最优特征和最优切分点。

* CART采用后剪枝算法。
#### 1.1.2 Boosting算法思想和实现

* AdaBoost：为每个弱学习器赋予不同的权值，将所有的弱学习器的权重和作为预测结果。
* Gradient Boosting：与AdaBoost不同的是，它将损失函数梯度下降的方向作为优化的目标
* Gradient Tree Boosting：是以决策树为子模型的，Gradient Boosting。可以有效的挖掘特征和特征组合；模型具有良好的泛化能力；能够达到较高的预测准确率。
* XGBoost训练时树生成的算法和CART算法是一致的，通过计算节点分裂后和分裂前是否产生增益来确定是否分裂，并且通过参数控制树的深度。当一棵树生成完毕之后，再对其进行剪枝，防止过拟合，第m轮生成的树会学习真实值和目标m-1轮模型预测值的残差，使得模型预测结果逐步逼近真实值。
#### 1.1.3 XGBoost
* XGBoost模型定义: $\hat{y}_i=F_k(x_i)+f_K(x_i)$,$f_K(x_i)$表示第K颗决策树。
* XGBoost目标函数：$$Obj=\sum_{i=1}^nL(y_i,\hat{y}_i)+\sum_{k=1}^K\Omega(f_k)$$
  * 目标函数$Obj$由两部分组成:
  * 第一项为损失函数，该函数必须是可微分的凸函数,因为后续要进行二阶求导，泰勒展开；
  * 第二项为正则化项，$\Omega(f)=\gamma T+\frac{1}{2}\lambda||\omega||^2$,其中$\gamma T$通过叶子节点树及其系数控制树的复杂度，$\frac{1}{2}||\omega||^2$为L2正则化项，用于控制叶子节点的权重分数。
* 目标优化：
$$
\begin{aligned}
Obj &=\sum_{i=1}^nL(y_i,\hat{y}_i)+\sum_{k=1}^K\Omega(f_k)\\
    &=\sum_{i=1}^nL(y_i,\hat{y}_i^{(s-1)}+f_s(x_i))+\sum_{k=1}^K\Omega(f_k)\\
    &\approx\sum_{i=1}^n[L(y_i,\hat{y}_i^{(s-1)})+g_if_s(x_i)+\frac{1}{2}h_if_s^2(x_i)]+\sum_{k=1}^K\Omega(f_k)\\
    &=\sum_{i=1}^n[g_if_s(x_i)+\frac{1}{2}h_if_s^2(x_i)]+\sum_{k=1}^K\gamma T+\frac{1}{2}\lambda||\omega||^2\\
\end{aligned}
$$
将$\hat{y}_i^{(s-1)}$看作$x$，将$f_s(x_i)$看作增量$\Delta x$,泰勒二阶展开如上，其中$g_i$为一阶梯度，$h_i$为二阶梯度
## 二·深度学习相关
## 三·项目实习经历
## 四·常见问答
### 4.1 LayerNormalization和BatchNNormalization区别？