# lecture 6 machine level programing 2 control

*  条件码
    * CF 进位标志
        * 用于判断无符号溢出
    * ZF 零标志
        * 最近的操作得出的结果为零 
    * SF 符号标志
        * 用于有符号数的符号判断
    * OF 溢出标志
        * 最近的操作导致一个补码溢出

    * leaq指令不改变任何条件吗
    * 运算和逻辑指令根据运算符隐式的改变条件码

    * 显示的指定条件码的指令
        * cmpq src2 src1
            * **需要注意** 该指令的计算过程为 **src1-src2**
            * 不改变任何寄存器，而是根据结果改变条件码

            * CF （如果最高位发生了进位则设值。）
            * ZF （如果src1 == src2则设值。）
            * SF （如果src1 - src2 M < 0 则设值
            * OF （如果a-b 后发生了溢出 则设值）

        * test 指令
            * 通常用于判断一个数 大于0  等于0 小于0
            * test %rax %rax
            
            * ZF （如果%rax & %rax == 0 ZF会被设值 ）
            * SF （如果 %rax & %rax < 0  SF会被设值）

    * 读取条件码的指令
        * set指令
            * ![set指令](/images/set指令.jpg)
            * 具体例子
            * ```
                int gt (long x, long y)
                {
                    return x > y;
                }

            * 汇编代码
            * ```
                cmpq %rsi, %rdi 	# Compare x:y
                setg %al 		    # Set when >
                movzbl %al, %eax     # Zero rest of %rax
                ret
            

* 跳转指令
    * ![跳转指令](/images/跳转指令.jpg)

    * c语言的goto语句
        * 

    * 条件移动的优化
        * cmovX
        *  基本思想是提前计算好每个分支的结果之后再根据条件返回相应分支的结果。

        * 例子
            * c
                ```
                long absdiff(long x, long y)
                {
                    long result;
                    if (x > y)
                        result = x-y;
                    else
                        result = y-x;
                    return result;
                }
                ```
            *  汇编
                ```
                absdiff:
                    movq %rdi, %rax 	# x
                    subq %rsi, %rax 	# result = x-y
                    movq %rsi, %rdx
                    subq %rdi, %rdx 	# eval = y-x
                    cmpq %rsi, %rdi 	# x:y
                    cmovle %rdx, %rax 	# if <=, result = eval
                    ret
                ```
        * 条件移动只能在限定的条件下，起作用
            * 各个分支的计算很简单
            * 不会有副作用

    * 循环
        
