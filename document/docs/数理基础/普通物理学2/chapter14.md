# 期中复习
## 重要概念
- 电偶极子
- 电偶极矩
- 电通量
- 磁偶极矩
- 电感（电感器：$L = \frac{N\Phi_{B}}{i}$）
- 互感（我们定义线圈2相对于线圈1的互感为$M_{2 1} = \frac{N_{2}\Phi_{2 1}}{I_{1}}$）
- 阻抗
- 位移电流（密度）: $\overrightarrow{J}= \epsilon_{0}\frac{\partial \overrightarrow{E}}{\partial t}$
- 电磁波
## 基础定律
- 库伦定律：$\overrightarrow{F}=k \frac{q_1q_2}{r^2}\hat{r}$
- 高斯定律：$\epsilon_0 \Phi = \oint \overrightarrow{E} \cdot d\overrightarrow{A} = q_{enc}$
- 高斯定律（微分形式）：$\frac{\rho(r)}{\epsilon_0} = \nabla \cdot \overrightarrow{E}$
- 电场与电势的关系：$\overrightarrow{E} = -\nabla \cdot V$
- 泊松方程：$\nabla^2 V = -\rho(r)/\epsilon_0$
- 洛伦兹力：$\vec{F}=q\vec{v}\times\vec{B}$
- 安培力：$\overrightarrow{F} = i \overrightarrow{L} × \overrightarrow{B}$
- 毕奥-萨伐尔定律：$d \overrightarrow{B} = \frac{\mu_{0}}{4 \pi}\frac{i d \overrightarrow{s} × \overrightarrow{r}}{r^{3}}$
- 安培定律：$\oint \overrightarrow{B} \cdot d \overrightarrow{s} = \mu_{0} i_{e n c}$
- 安培定律（另一种形式）：$\nabla × \overrightarrow{B}(\overrightarrow{r}) = \mu_{0}\overrightarrow{J}(\overrightarrow{r})$
- 法拉第电磁感应定律：$\oint \overrightarrow{E} \cdot d \overrightarrow{s} = - \frac{d \Phi_{B}}{d t} = - \frac{d}{d t} \int \overrightarrow{B} \cdot d \overrightarrow{A}
$
- 法拉第电磁感应定律（微分形式）：$\nabla × \overrightarrow{E} = - \frac{\partial \overrightarrow{B}}{\partial t}$
- 麦克斯韦方程组：
$$
\nabla \cdot \overrightarrow{E} = \frac{\rho}{\epsilon_{0}} ||
\nabla × \overrightarrow{E} = - \frac{\partial \overrightarrow{B}}{\partial t}  ||
\nabla \cdot \overrightarrow{B} = 0  ||
\nabla × \overrightarrow{B} = \mu_{0}\overrightarrow J + \mu_{0}\epsilon_{0}\frac{\partial \overrightarrow{E}}{\partial t}
$$
## 推论
- 电阻率与电导率的关系：$\rho = \frac{1}{\sigma}=\frac{E}{J}$
- 电容的确定：$\epsilon_0\overrightarrow{E}A=q$、$C= \frac{q}{V} = \frac{\epsilon_0\overrightarrow{E}A}{\overrightarrow{E}d} =\frac{\epsilon_0 A}{d}$
- 电容器中储存的能量：$U=\frac{1}{2}CV^2=\frac{q^{2}d}{2\epsilon_0 A}$
- 能量密度u的引入：$U= \frac{1}{2}C V^{2} = \frac{1}{2}\epsilon_{0}E^{2}(A d)$、$u=\frac{1}{2}\epsilon_{0}E^{2}$
- 电流环的扭矩：$\overrightarrow{\tau} = N i \overrightarrow{A} × \overrightarrow{B} = \overrightarrow{\mu} × \overrightarrow{B}$，其中$\overrightarrow{\mu}=N i \overrightarrow{A}$称为线圈的磁偶极矩
- 长直导线外部产生的磁场：$B = \frac{\mu_{0}i}{2 \pi R}$
- 长直导线内部产生的磁场：$B = \frac{\mu_{0}i_{e n c}}{2 \pi r} = \frac{\mu_{0}i}{2 \pi R^{2}}r$
- 螺线管产生的磁场：$B = \mu_0 n i$
- 磁偶极子的能量：$U=-\overrightarrow{\mu} \cdot \overrightarrow{B}$
- 电感器存储的能量：$U_{B} = \frac{1}{2}L i^{2}$
- 磁能密度$u_{B} = \frac{1}{2}\mu_{0}n^{2}i^{2} = \frac{B^{2}}{2 \mu_{0}}$
- 互感电动势：$\mathcal E_{2 1} = - \frac{d(N_{2}\Phi_{2 1})}{d t} = - M_{2 1}\frac{d i_{1}}{d t}$
- 电阻性负载中，$Z̃ = R$
- 在感性负载中，$Z̃ = iω_d L$
- 在容性负载中，$Z̃ = \frac{1 }{i\omega_d C }$
- LRC电路中：$\tilde Z = R + i(\omega_{d}L - \frac{1}{\omega_{d}C})$
- 电磁波$E$始终垂直于$B$。$E×B$给出波传播的方向。
- 电磁波中两种能量：$\frac{\epsilon_{0} E^{2}}{2} = \frac{B^{2}}{2 \mu_{0}}$
## 数学基础
- 梯度： $\nabla \equiv \hat{x}\frac{\partial }{\partial x}+\hat{y}\frac{\partial }{\partial y}+\hat{z}\frac{\partial }{\partial z}$,几何上，梯度指向函数值的最大增大方向
- 旋度： $\nabla \times \vec{v} = \hat{x}(\frac{\partial v_y}{\partial z}-\frac{\partial v_z}{\partial y})+\hat{y}(\frac{\partial v_z}{\partial x}-\frac{\partial v_x}{\partial z})+\hat{z}(\frac{\partial v_x}{\partial y}-\frac{\partial v_y}{\partial x})$
- 散度： $\nabla\cdot\vec{v}=\frac{\partial v_x}{\partial x}+\frac{\partial v_y}{\partial y}+\frac{\partial v_z}{\partial z}$
## 特殊方法/典型题目
- 镜像法解决导体电荷分布问题
- 导线圆弧的磁场推导$B(z) = \frac{\mu_{0}}{2 \pi}\frac{\mu}{(R^{2} + z^{2})^{3 / 2}}$
- 圆柱形电容器计算其电容
- LC振荡电路：
    - 总能量$U = U_{B} + U_{E} = \frac{L i^{2}}{2} + \frac{q^{2}}{2 C}$
    - 通解：$q = Q \cos ( \omega_{0} t + \phi )$ $ω₀ = 1/\sqrt{LC}$

- 判断振荡类型的条件：$1 / \tau = R / (2 L)$($<ω₀$为欠阻尼)