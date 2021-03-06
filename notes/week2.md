## Sierpinski Gasket

使用 Chaos game 算法画一个 [Sierpinski gasket](http://en.wikipedia.org/wiki/Sierpinski_triangle)，操作有两步：

1. 用 Chaos game 算法生成点
2. 画出点

这个时候有两种策略：

1. 生成一个就画一个：
  ```
  for number of points:
    generate a point
    display the point
  ```

  这种模式被称为 **immediate mode graphics**，长期使用于交互式图形应用，缺点是不记忆数据，下次绘制需要重新生成
2. 迭代完毕后再绘制：
  ```
  for number of points:
    generate a point
    store the point

  display all points
  ```

  这种模式被称为 **retained mode graphics**，避免了不断向 GPU 传输小量数据带来的 overhead，再次绘制也不需要重新生成。

第二种策略有一个缺陷，如果需要逐渐展示绘制过程，就会每次向 GPU 传输 1, 2, 3, ..., n 个数据（第一种是1, 1, ..., 1），数据的传输过程会造成瓶颈。因此可以改良成先生成所有点，然后**全部 n 个数据暂存到GPU**，这样每次调用显示 call 逐渐绘制的时候，使用的是显存里的数据，没有了传输过程。

## OpenGL 程序会做什么

1. 声明 primitive 的数据
2. 用 shader 计算 primitive 的位置、颜色等
3. Rasterization: primivies -> fragments，相对于屏幕
4. fagment shader 计算每个 fragment 最后显示在屏幕上的颜色和位置
5. 其他操作，比如隐藏部分frgment，融合颜色

OpenGL 程序相当于一个 client，server 则是 OpenGL 的实现（可以跑在一台 workstation 上）

## 写一个 OpenGL 程序的步骤

1. 声明物体的 state
2. 渲染这些物体

### 术语

* Models: 由点、线、三角等 primitive 的 vertex 构成
* Shader: 为 GPU 编写的函数，vertex shader 处理 vertex，fragment shader 处理 rasterizer 生成的 fragment
* framebuffer：放在显存

### Syntax
2uiv 3f
* 函数 `glXxx`, `gluXxx`, `glutXxx`
  * 没有重载，用于声明数据的函数后缀为 `(\d+)(b|f|di|f|d|ub|us|ui)(v?)`
  * $1表示参数个数，$2表示类型，$3表示参数是否为向量
* 类型 `GLxxx`, `GLUxxx`, `GLUTxxx`
  * 帮助解决移植性，主要有 `*int`, `*float`, `*enum` 等
* 常数 `GL_XXX`, `GLU_XXX`, `GLUT_XXX`
  * 定义位于 glcorearb.h 和 glext.h


## 一个图形系统应当提供的函数类别
* primitive
  * points, lines, polygons, pixels, ...
* attribute
  * color, pattern, typefaces, ...
* viewing
  * OpenGL doesn't provide them, need to use shaders or GLU, etc.
* transformation
  * rotation, translation, scaling
* input
* control
* query