# 矩阵连乘问题

## 问题描述
给定n个矩阵(A1, A2, A3....An),其中Ai与Ai+1是可以相乘的，由于矩阵乘法满足乘法结合律，因此矩阵连乘可以有不同的计算次序。我们可以通过加括号的方式确定连乘的次序。我们的目标是找一个完全加括号的连乘方式，是的矩阵的计算量最小。

穷举搜索的话，结果是Catlan数的复杂度，也就是指数级别的，并不是一个有效的办法。

## 分析最优子结构
计算A[1,n]的最优解包含着计算矩阵子链A[1,k]和A[k+1,n]的次序也是最优的。因此矩阵连乘计算次序的问题的最优解包含着其子问题的最优解，这种性质成为最优子结构。

## 建立递归关系
m[i][j] = min{m[i][k] + m[k+1][j] + pi-1pkpj} if i < j else 0

## 计算最优值


> 注意
C++ 和C都不能够直接申请二维或者多维数组，需要一层层进行申请。释放与申请嵌套顺序是相反的。除非你是用C++中的vector的构造函数进行申请二维数组申请。