## 枚举策略
大部分题目对 C/C++ 的时间限制是 1000 ms，1000 ms 大概可以进行 10<sup>7</sup> 次运算。

不同的时间复杂度在 1000 ms 内可以支持的数据量如下：
| 复杂度            | 数据量             |
| ---------------- | ----------------- |
| O(n!)            | 10                |
| O(2<sup>n</sup>) | 20                |
| O(n<sup>3</sup>) | 200               |
| O(n<sup>2</sup>) | 3000              |
| O(nlogn)         | 10<sup>6</sup>    |
| O(n)             | 10<sup>7</sup>    |
| O($\sqrt{n}$)    | 10<sup>14</sup>   |
| O(logn)          | > 10<sup>20</sup> |

几个特殊的时间复杂度分析：

1) 1 + 2 + 2<sup>2</sup> + ... + 2<sup>n</sup> = O(2<sup>n</sup>)

2) 1 + $\frac{1}{2}$ + $\frac{1}{2^2}$ + ... + $\frac{1}{2^n}$ = O(1)

3) 1 + 2<sup>2</sup> + 3<sup>2</sup> + ... + n<sup>2</sup> = O(n<sup>3</sup>)

4) 1 + $\frac{1}{2}$ + $\frac{1}{3}$ + ... + $\frac{1}{n}$ = O(logn)

5) log1+ 1og2 + log3 + ... + logn = O(nlogn)

