# stone_compiler_cplus
stone_compiler c++ version converted from java

## 0.3  整体debug时候注意
1， 可以打印整个parser的结构，在main里面调用 Parser.program.printMyself(); 
	注意 EXPR 和 Block 是循环引用的，所以要避免打印这两个（在parser.h里面禁止了Block的打印，直接找出的地址，在expr的printMyself()阻止了循环打印）
2， Parser.print_BP_ele();可以打印出每一个Parser的地址
3， LineNumberReader下设置了一行最多读取多少
4， Parser的运行过程 先组装Parser -> 读取一行 -> 选择Parser -> 利用选好的Parser进行parse -> 在ast上执行
5， 可以利用Parser.cpp 下选择Parser进行cout输出，找bug
6， 打印结构以后，可以用vscode 等编辑器进行format，看的更加清晰
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

## 0.1 语法上注意：
1，一定要有足够的空格


2，block里面不能有单独的Name，比如这里的sum
if i < 20 {
  sum = sum + 1
  sum
}



