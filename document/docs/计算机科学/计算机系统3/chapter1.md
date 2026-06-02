# 量化研究

## 性能度量

我们在很多情况下都需要衡量计算机系统的性能。性能可以由一个程序的执行时间来度量。

$$
\text{Performance} = \frac{1}{\text{Execution Time}}
$$

CPU的执行时间又与CPU的时钟周期有关。

$$
\text{CPU Execution Time} = \frac{\text{CPU Clock Cycles}}{\text{Clock Rate}}
$$

或者  

$$
\text{CPU Execution Time} = \text{CPU Clock Cycles} \times \text{Clock Period}
$$

CPU的Clock Cycles可以表示为：

$$
\text{CPU Clock Cycles} = \text{CPI} \times \text{Instruction Count}
$$

其中$CPI$表示每条指令的平均循环次数，它由CPU的硬件决定。

如果我们有平均循环次数不同的指令，那么我们可以通过求和的形式求出它们的总循环次数。

$$
\text{Clock Cycles}=\sum_{i=1}^{n}\text{CPI}_i \times \text{Instruction Count}_i
$$

我们也可以通过加权平均的方式求出总的CPI。

$$
\text{CPI}=\frac{\sum_{i=1}^{n}\text{CPI}_i \times \text{Instruction Count}_i}{\sum_{i=1}^{n}\text{Instruction Count}_i}
$$

## 阿姆达尔定律

阿姆达尔定律描述了通过改进计算机的某个方面，使得整体性能获得相应比例的提高。

$$
T_{\text{improved}}=\frac{T_{\text{affected}}}{\text{improvement factor}}+T_{\text{unaffected}}
$$

阿姆达尔定律也定义了使用特定增强特性所能获得的加速比。
$$
\text{Speedup}=\frac{\text{Performance}_{\text{using enhancement}}}{ \text{Performance}_{\text{without enhancement}}}
=\frac{\text{Execution Time}_{\text{without enhancement}}}{\text{Execution Time}_{\text{using enhancement}}}
$$

那我们就可以构建整体加速比和局部加速比的关系。

$$
\text{Excution time}_{\text{new}}=\text{Execution time}_{\text{old}} \times ((1-\text{Fraction}_\text{enhanced})+\frac{\text{Fraction}_\text{enhanced}}{\text{Speedup}_{\text{enhanced}}} )
$$

$$
\text{Speedup}_{\text{overall}}=\frac{\text{Execution time}_{\text{new}}}{\text{Execution time}_{\text{old}}}=
\frac{1}{(1-\text{Fraction}_\text{enhanced})+\frac{\text{Fraction}_\text{enhanced}}{\text{Speedup}_{\text{enhanced}}}}
$$

