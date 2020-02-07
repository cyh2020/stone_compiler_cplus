# stone_compiler_cplus
stone_compiler c++ version converted from java


## 0.1 语法上注意：
1，一定要有足够的空格


2，block里面不能有单独的Name，比如这里的sum
if i < 20 {
  sum = sum + 1
  sum
}

## 0.2  语法上注意：

（block里面不能有单独的Name，比如这里的sum）这个bug已经修复

不能下面这样 （也是一个bug）
```
even = 0
odd = 0
i = 1
while i < 10 {
	if i % 2 == 0 {
		even = even + i
	} else {
		odd = odd + i
	}
	i = i + 1
}
even + odd
```

