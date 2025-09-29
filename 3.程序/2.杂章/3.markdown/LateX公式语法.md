# LaTeX公式语法

LaTeX 是排版数学公式的强大工具，其公式语法丰富且严谨。以下按类别详细整理常用语法，涵盖基础到进阶用法，并标注必要的宏包依赖（多数需导入 `amsmath` 和 `amssymb` 宏包）。

## 一、公式环境基础

LaTeX 公式分为**行内公式**（嵌入文本）和**行间公式**（单独成行），核心区别在于排版位置和大小。

| 类型       | 语法                          | 说明                                  | 示例                                  |
|------------|-------------------------------|---------------------------------------|---------------------------------------|
| 行内公式   | `$...$` 或 `\(...\)`          | 嵌入文本，字号较小                    | `$a + b = c$` 显示为 $a + b = c$      |
| 行间公式   | `$$...$$` 或 `\[...\]`        | 单独成行，居中，字号较大              | `$$E = mc^2$$` 显示为 $$E = mc^2$$    |
| 带编号公式 | `\begin{equation}...\end{equation}` | 单独成行，自动编号（可交叉引用）      | ```\begin{equation} a^2 + b^2 = c^2 \end{equation}``` 显示为带编号的公式 |

## 二、基础符号与运算

### 1. 常用运算符

| 运算       | 语法          | 示例（显示效果）               |
|------------|---------------|--------------------------------|
| 加         | `+`           | $a + b$                        |
| 减         | `-`           | $a - b$                        |
| 乘（点乘） | `\cdot`       | $a \cdot b$                    |
| 乘（叉乘） | `\times`      | $a \times b$                   |
| 除         | `/` 或 `\div` | $a / b$ 或 $a \div b$          |
| 等于       | `=`           | $a = b$                        |
| 不等于     | `\neq`        | $a \neq b$                     |
| 约等于     | `\approx`     | $a \approx b$                  |
| 全等       | `\cong`       | $a \cong b$                    |
| 正比于     | `\propto`     | $a \propto b$                  |

### 2. 比较运算符

| 符号       | 语法          | 示例（显示效果）               |
|------------|---------------|--------------------------------|
| 小于       | `<` 或 `\lt`  | $a < b$ 或 $a \lt b$           |
| 大于       | `>` 或 `\gt`  | $a > b$ 或 $a \gt b$           |
| 小于等于   | `\leq`        | $a \leq b$                     |
| 大于等于   | `\geq`        | $a \geq b$                     |
| 远小于     | `\ll`         | $a \ll b$                      |
| 远大于     | `\gg`         | $a \gg b$                      |

## 三、上下标与装饰

### 1. 上下标

- 下标：`_`（单个字符可直接跟，多个字符需用 `{}` 包裹）
- 上标：`^`（规则同上）

| 语法                  | 示例（显示效果）               |
|-----------------------|--------------------------------|
| `a_i`                 | $a_i$（单个下标）              |
| `a_{i,j}`             | $a_{i,j}$（多个下标）          |
| `a^2`                 | $a^2$（单个上标）              |
| `a^{i+j}`             | $a^{i+j}$（多个上标）          |
| `a_i^2` 或 `a^2_i`    | $a_i^2$（上下标共存，顺序无关）|
| `x^{y^z}`             | $x^{y^z}$（上标嵌套）          |

### 2. 装饰符号（上下划线、波浪线等）

| 装饰类型   | 语法              | 示例（显示效果）               |
|------------|-------------------|--------------------------------|
| 上划线     | `\overline{...}`  | $\overline{abc}$               |
| 下划线     | `\underline{...}` | $\underline{abc}$              |
| 波浪线（宽） | `\widetilde{...}` | $\widetilde{abc}$              |
| 波浪线（窄） | `\widehat{...}`   | $\widehat{abc}$                |
| 向量箭头   | `\vec{...}`       | $\vec{a}$                      |
| 长向量箭头 | `\overrightarrow{...}` | $\overrightarrow{AB}$       |
| 点符号（导数） | `\dot{...}`（一阶）、`\ddot{...}`（二阶） | $\dot{x}$、$\ddot{x}$ |
| 帽子       | `\hat{...}`       | $\hat{a}$                      |
| 横线（短） | `\bar{...}`       | $\bar{a}$                      |

## 四、分式与根号

### 1. 分式

- 基础分式：`\frac{分子}{分母}`（自动适应大小）
- 大分式（行间用）：`\dfrac{分子}{分母}`（需 `amsmath` 宏包）
- 小分式（行内用）：`\tfrac{分子}{分母}`（需 `amsmath` 宏包）

| 语法                          | 示例（显示效果）               |
|-------------------------------|--------------------------------|
| `\frac{a}{b}`                 | $\frac{a}{b}$                  |
| `\dfrac{a + b}{c + d}`        | $\dfrac{a + b}{c + d}$         |
| `\tfrac{a}{b}`                | $\tfrac{a}{b}$（行内更紧凑）   |
| `1 + \frac{1}{1 + \frac{1}{2}}` | $1 + \frac{1}{1 + \frac{1}{2}}$（连分数） |

### 2. 根号

- 平方根：`\sqrt{...}`
- n 次方根：`\sqrt[n]{...}`

| 语法                  | 示例（显示效果）               |
|-----------------------|--------------------------------|
| `\sqrt{a}`            | $\sqrt{a}$                     |
| `\sqrt{a + b}`        | $\sqrt{a + b}$                 |
| `\sqrt[3]{a}`         | $\sqrt[3]{a}$（立方根）        |
| `\sqrt[n]{a + b}`     | $\sqrt[n]{a + b}$（n次方根）   |
| `\sqrt{\sqrt{a}}`     | $\sqrt{\sqrt{a}}$（嵌套根号）  |

## 五、大型运算符（求和、积分等）

大型运算符通常带上下限，行内公式中上下限在右侧，行间公式中上下限在上下方。

| 运算符   | 语法                  | 示例（显示效果）               |
|----------|-----------------------|--------------------------------|
| 求和     | `\sum_{下限}^{上限}`  | $\sum_{i=1}^n i$（行内）；$$\sum_{i=1}^n i$$（行间） |
| 乘积     | `\prod_{下限}^{上限}` | $\prod_{i=1}^n i$              |
| 积分     | `\int_{下限}^{上限}`  | $\int_a^b f(x) dx$；$$\int_a^b f(x) dx$$ |
| 双重积分 | `\iint`               | $\iint_D f(x,y) dxdy$          |
| 三重积分 | `\iiint`              | $\iiint_\Omega f(x,y,z) dxdydz$ |
| 环路积分 | `\oint`               | $\oint_C f(x) dx$              |
| 极限     | `\lim_{变量 \to 目标}` | $\lim_{x \to 0} \frac{\sin x}{x}$ |
| 最大值   | `\max_{条件}`         | $\max_{i} a_i$                 |
| 最小值   | `\min_{条件}`         | $\min_{i} a_i$                 |
| 并集     | `\bigcup_{下限}^{上限}` | $\bigcup_{i=1}^n A_i$          |
| 交集     | `\bigcap_{下限}^{上限}` | $\bigcap_{i=1}^n A_i$          |

## 六、矩阵与行列式

需导入 `amsmath` 宏包，用 `matrix` 环境（无括号）及衍生环境（带括号）。

### 1. 基础矩阵

| 环境         | 说明               | 语法示例                                  | 显示效果                                  |
|--------------|--------------------|-------------------------------------------|-------------------------------------------|
| `matrix`     | 无括号             | `\begin{matrix} 1 & 2 \\ 3 & 4 \end{matrix}` | $\begin{matrix} 1 & 2 \\ 3 & 4 \end{matrix}$ |
| `pmatrix`    | 圆括号 `()`        | `\begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix}` | $\begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix}$ |
| `bmatrix`    | 方括号 `[]`        | `\begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix}` | $\begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix}$ |
| `Bmatrix`    | 花括号 `{}`        | `\begin{Bmatrix} 1 & 2 \\ 3 & 4 \end{Bmatrix}` | $\begin{Bmatrix} 1 & 2 \\ 3 & 4 \end{Bmatrix}$ |
| `vmatrix`    | 单竖线（行列式）   | `\begin{vmatrix} 1 & 2 \\ 3 & 4 \end{vmatrix}` | $\begin{vmatrix} 1 & 2 \\ 3 & 4 \end{vmatrix}$ |
| `Vmatrix`    | 双竖线（范数）     | `\begin{Vmatrix} 1 & 2 \\ 3 & 4 \end{Vmatrix}` | $\begin{Vmatrix} 1 & 2 \\ 3 & 4 \end{Vmatrix}$ |

- 规则：用 `&` 分隔列，`\\` 换行；
- 省略号：`\cdots`（横向）、`\vdots`（纵向）、`\ddots`（对角线），例如：

  ```latex
  \begin{pmatrix}
  a_{11} & a_{12} & \cdots & a_{1n} \\
  a_{21} & a_{22} & \cdots & a_{2n} \\
  \vdots & \vdots & \ddots & \vdots \\
  a_{n1} & a_{n2} & \cdots & a_{nn}
  \end{pmatrix}
  ```

  显示为：
  $$\begin{pmatrix}
  a_{11} & a_{12} & \cdots & a_{1n} \\
  a_{21} & a_{22} & \cdots & a_{2n} \\
  \vdots & \vdots & \ddots & \vdots \\
  a_{n1} & a_{n2} & \cdots & a_{nn}
  \end{pmatrix}$$

## 七、分段函数与方程组

### 1. 分段函数（`cases` 环境，需 `amsmath`）

语法：

```latex
f(x) = \begin{cases}
表达式1 & 条件1 \\
表达式2 & 条件2 \\
\vdots & \vdots \\
表达式n & 条件n
\end{cases}
```

示例：

```latex
f(x) = \begin{cases}
x & x \geq 0 \\
-x & x < 0
\end{cases}
```

显示为：
$$f(x) = \begin{cases}
x & x \geq 0 \\
-x & x < 0
\end{cases}$$

### 2. 方程组（`align` 或 `gather` 环境，需 `amsmath`）
- `align`：多行公式对齐（通常在等号处），用 `&` 标记对齐位置；
- `gather`：多行公式居中对齐，无对齐标记。

示例（`align`，带编号）：
```latex
\begin{align}
a + b &= c \\
x \cdot y &= z
\end{align}
```
显示为：
\begin{align}
a + b &= c \\
x \cdot y &= z
\end{align}

示例（`gather`，取消编号用 `\notag`）：
```latex
\begin{gather}
a + b = c \\
x \cdot y = z \notag
\end{gather}
```
显示为：
\begin{gather}
a + b = c \\
x \cdot y = z \notag
\end{gather}

## 八、希腊字母
希腊字母是数学公式的常用符号，大小写命令不同（小写全小写，大写首字母大写）。

| 小写命令   | 显示 | 大写命令   | 显示 | 小写命令   | 显示 | 大写命令   | 显示 |
|------------|------|------------|------|------------|------|------------|------|
| `\alpha`   | $\alpha$ | `\Alpha`   | $\Alpha$ | `\nu`      | $\nu$ | `\Nu`      | $\Nu$ |
| `\beta`    | $\beta$ | `\Beta`    | $\Beta$ | `\xi`      | $\xi$ | `\Xi`      | $\Xi$ |
| `\gamma`   | $\gamma$ | `\Gamma`   | $\Gamma$ | `\pi`      | $\pi$ | `\Pi`      | $\Pi$ |
| `\delta`   | $\delta$ | `\Delta`   | $\Delta$ | `\rho`     | $\rho$ | `\Rho`     | $\Rho$ |
| `\epsilon` | $\epsilon$ | `\Epsilon` | $\Epsilon$ | `\sigma`   | $\sigma$ | `\Sigma`   | $\Sigma$ |
| `\zeta`    | $\zeta$ | `\Zeta`    | $\Zeta$ | `\tau`     | $\tau$ | `\Tau`     | $\Tau$ |
| `\eta`     | $\eta$ | `\Eta`     | $\Eta$ | `\upsilon` | $\upsilon$ | `\Upsilon` | $\Upsilon$ |
| `\theta`   | $\theta$ | `\Theta`   | $\Theta$ | `\phi`     | $\phi$ | `\Phi`     | $\Phi$ |
| `\iota`    | $\iota$ | `\Iota`    | $\Iota$ | `\chi`     | $\chi$ | `\Chi`     | $\Chi$ |
| `\kappa`   | $\kappa$ | `\Kappa`   | $\Kappa$ | `\psi`     | $\psi$ | `\Psi`     | $\Psi$ |
| `\lambda`  | $\lambda$ | `\Lambda`  | $\Lambda$ | `\omega`   | $\omega$ | `\Omega`   | $\Omega$ |
| `\mu`      | $\mu$ | `\Mu`      | $\Mu$ |            |      |            |      |

- 特殊变体：`\vartheta`（$\vartheta$）、`\varsigma`（$\varsigma$）、`\varphi`（$\varphi$）。

## 九、集合与逻辑符号
需导入 `amssymb` 宏包。

### 1. 集合符号
| 符号       | 语法          | 示例（显示效果）               |
|------------|---------------|--------------------------------|
| 空集       | `\emptyset`   | $\emptyset$                    |
| 属于       | `\in`         | $a \in A$                      |
| 不属于     | `\notin`      | $a \notin A$                   |
| 包含于     | `\subseteq`   | $A \subseteq B$                |
| 真包含于   | `\subsetneq`  | $A \subsetneq B$               |
| 包含       | `\supseteq`   | $A \supseteq B$                |
| 真包含     | `\supsetneq`  | $A \supsetneq B$               |
| 并集       | `\cup`        | $A \cup B$                     |
| 交集       | `\cap`        | $A \cap B$                     |
| 补集       | `\complement` | $\complement_U A$              |
| 实数集     | `\mathbb{R}`  | $\mathbb{R}$（需 `amsfonts` 宏包） |
| 整数集     | `\mathbb{Z}`  | $\mathbb{Z}$                   |

### 2. 逻辑符号
| 符号       | 语法          | 示例（显示效果）               |
|------------|---------------|--------------------------------|
| 存在       | `\exists`     | $\exists x$                    |
| 任意       | `\forall`     | $\forall x$                    |
| 蕴含       | `\implies`    | $a \implies b$                 |
| 等价       | `\iff`        | $a \iff b$                     |
| 因为       | `\because`    | $\because a = b$               |
| 所以       | `\therefore`  | $\therefore c = d$             |

## 十、箭头符号
| 箭头方向   | 语法                  | 示例（显示效果）               |
|------------|-----------------------|--------------------------------|
| 右箭头     | `\rightarrow` 或 `\to` | $a \rightarrow b$ 或 $a \to b$ |
| 左箭头     | `\leftarrow`          | $a \leftarrow b$               |
| 双箭头（右） | `\Rightarrow`         | $a \Rightarrow b$              |
| 双箭头（左） | `\Leftarrow`          | $a \Leftarrow b$               |
| 双向箭头   | `\leftrightarrow`     | $a \leftrightarrow b$          |
| 双向双箭头 | `\Leftrightarrow`     | $a \Leftrightarrow b$          |
| 长箭头     | `\longrightarrow`     | $a \longrightarrow b$          |
| 带文字箭头 | `\xrightarrow{文字}`  | $a \xrightarrow{f} b$          |

## 十一、括号与分组
### 1. 基础括号
| 括号类型 | 语法          | 示例（显示效果）               |
|----------|---------------|--------------------------------|
| 圆括号   | `()`          | $(a + b)$                      |
| 方括号   | `[]`          | $[a + b]$                      |
| 花括号   | `\{...\}`     | $\{a + b\}$（需转义符 `\`）    |
| 尖括号   | `\langle...\rangle` | $\langle a + b \rangle$      |

### 2. 自动调整大小的括号（`\left` 和 `\right`）
当括号内内容高度变化时，用 `\left` 和 `\right` 自动匹配大小（必须成对使用）。

| 语法                                  | 示例（显示效果）               |
|---------------------------------------|--------------------------------|
| `\left( \frac{a}{b} \right)`          | $\left( \frac{a}{b} \right)$    |
| `\left[ \sum_{i=1}^n a_i \right]`     | $\left[ \sum_{i=1}^n a_i \right]$ |
| `\left\{ \begin{aligned} ... \end{aligned} \right.` | 单侧括号（用 `.` 补全另一侧） |

示例（单侧括号）：
```latex
\left. \frac{df}{dx} \right|_{x=0}
```
显示为：
$$\left. \frac{df}{dx} \right|_{x=0}$$

## 十二、数学函数与特殊符号
### 1. 常用数学函数
函数名需用命令（而非直接写字母），确保正确排版（斜体）。

| 函数       | 语法          | 示例（显示效果）               |
|------------|---------------|--------------------------------|
| 正弦       | `\sin`        | $\sin x$                       |
| 余弦       | `\cos`        | $\cos x$                       |
| 正切       | `\tan`        | $\tan x$                       |
| 反正弦     | `\arcsin`     | $\arcsin x$                    |
| 自然对数   | `\ln`         | $\ln x$                        |
| 对数（底a） | `\log_a`      | $\log_a x$                     |
| 常用对数   | `\lg`         | $\lg x$                        |
| 指数       | `\exp`        | $\exp(x)$                      |
| 绝对值     | `\lvert...\rvert` | $\lvert x \rvert$             |
| 范数       | `\lVert...\rVert` | $\lVert x \rVert$             |
| 阶乘       | `!`           | $n!$                           |
| 组合数     | `\binom{n}{k}` | $\binom{n}{k}$（需 `amsmath`） |

### 2. 特殊符号
| 符号       | 语法          | 示例（显示效果）               |
|------------|---------------|--------------------------------|
| 无穷大     | `\infty`      | $\infty$                       |
| 梯度       | `\nabla`      | $\nabla$                       |
| 偏微分     | `\partial`    | $\partial x$                   |
| 度数       | `^\circ`      | $30^\circ$                     |
| 加减       | `\pm`         | $a \pm b$                      |
| 减加       | `\mp`         | $a \mp b$                      |
| 复数虚部   | `i` 或 `\mathrm{i}` | $i$ 或 $\mathrm{i}$（纯虚数单位） |

## 十三、字体样式
数学模式中可指定字体样式（需相应宏包）：

| 样式       | 语法          | 示例（显示效果）               |
|------------|---------------|--------------------------------|
| 罗马体（正体） | `\mathrm{...}` | $\mathrm{sin}$（非斜体）       |
| 粗体       | `\mathbf{...}` | $\mathbf{a}$（向量常用）       |
| 花体（集合） | `\mathcal{...}` | $\mathcal{A}$（需 `amsfonts`）  |
| 手写体     | `\mathscr{...}` | $\mathscr{L}$（需 `mathrsfs` 宏包） |
| 粗体希腊字母 | `\boldsymbol{\alpha}` | $\boldsymbol{\alpha}$（需 `amsmath`） |

## 十四、间距调整
公式中默认间距由LaTeX自动处理，如需手动调整：

| 间距类型   | 语法          | 说明（相对字符宽度）           |
|------------|---------------|--------------------------------|
| 负间距     | `\!`          | 约 -1/6 字符宽                 |
| 小间距     | `\,`          | 约 1/6 字符宽                  |
| 中等间距   | `\;`          | 约 2/6 字符宽                  |
| 大间距     | `\quad`       | 1 字符宽                       |
| 超大间距   | `\qquad`      | 2 字符宽                       |

示例：
```latex
a \! + \, b \; + \quad c \qquad + d
```
显示为：
$a \! + \, b \; + \quad c \qquad + d$

## 总结
LaTeX公式语法的核心是“用命令描述结构”，需注意：
1. 多数高级功能依赖 `amsmath`、`amssymb` 等宏包，开头需添加：
   ```latex
   \usepackage{amsmath, amssymb}
   ```
2. 符号区分大小写（如 `\alpha` 是小写，`\Alpha` 是大写）；
3. 多字符组合需用 `{}` 包裹（如上标、下标、分式等）；
4. 复杂公式建议用行间环境，排版更清晰。

掌握这些语法可满足绝大多数数学公式的排版需求，进一步复杂的场景（如张量、电路图等）可参考专门的宏包（如 `tensor`、`circuitikz`）。
