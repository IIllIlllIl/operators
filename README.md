# operators

详见https://github.com/IIllIlllIl/operators.git

该项目实现SQL查询执行中的关系算子部分。

涉及算法如下：
单轮算法：排序、选择、投影、乘积、连接；
多路归并：排序、乘积、连接；
索引：连接算子。

整体设计：
底层存储采用yaml/json存放关系表。
segment即为block，是IO的最小单元。并设计有对应block的基本关系操作。
table为多个block组成的一张表。基于block的关系操作实现关系算子操作。

优化：
流处理优化一元单轮算法。
使用多线程优化多路归并算法。
