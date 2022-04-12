## 进制转换
- 10 -> N: 除 N 取余，逆序输出
- M -> 10: 对每个数位循环计算 d * m + s[i]
- M -> N: M -> 10, 10 -> N

## 最大公约数(Greatest Common Divisor, GCD)
辗转相除法(欧几里得算法)
### 举例
GCD(3139, 2117) = 73
```
1) 3139 % 2117 = 1022
2)        2117 % 1022 = 73
3)               1022 % 73 = 0
```

### 证明
GCD(a, b) = GCD(b, r) = g
```
a = g * l     |
b = g * m     | --> | g * l = g * m * k + r  
a = b * k + r |     | r = g * (l - m * l)
```

## 最小公倍数(Least Common Multiple, LCM)
LCM(a, b) = a * b / GCD(a, b)
