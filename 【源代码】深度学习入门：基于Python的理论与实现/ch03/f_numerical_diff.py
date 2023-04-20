import matplotlib.pyplot as plt
import numpy as np

# 从[-1,1]中等距去50个数作为x的取值
x = np.linspace(-1, 1, 50)
y1 = 2*x + 1
y2 = 2**x + 1

# 请求一个新的figure对象
plt.figure()
# 第一个是横坐标的值，第二个是纵坐标的值
plt.plot(x, y1)  

# 设置轴线的lable（标签）
plt.xlabel("I am x")
plt.ylabel("I am y")

plt.show()
