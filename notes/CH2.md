## 2.1 Sierpinski Gasket

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

