
import sys, os
sys.path.append(os.pardir)
import numpy as np

def sigmoid(x):
	return 1 / (1 + np.exp(-x))
	
def softmax(x):
	if x.ndim == 2:
		x = x.T
		x = x - np.max(x,axis=0)
		y = np.exp(x) / np.sum(np.exp(x), axis=0)
		return y.T
		
	x = x - np.max(x)
	return np.exp(x) / np.sum(np.exp(x))
	
def numerical_gradient(f, x):
	h = 1e-4
	grad = np.zeros_like(x)
	
	it = np.nditer(x, )

class TwoLayerNetTwo:
	def __init__(self, input_size, hidden_size, output_size, weight_init_std=0.01):
		#初始化权重
		self.params = {}
		self.params['W1'] = weight_init_std * np.random.randn(input_size, hidden_size)
		self.params['b1'] = np.zeros(hidden_size)
		self.params['W2'] = weight_init_std * np.random.randn(hidden_size, output_size)
		self.params['b2'] = np.zeros(output_size)
		
	def predict(self, x):
		W1, W2 = self.params['W1'], self.params['W2']
		b1, b2 = self.params['b1'], self.params['b2']
		
		a1 = np.dot(x, W1) + b1
		z1 = sigmoid(a1)
		a2 = np.dot(z1, W2) + b2
		y = softmax(a2)
		
		return y
	# x:输入数据， t:监督数据
	def loss(self, x, t):
		y = self.predict(x)
		
		return cross_entropy_error(y, t)
		
	def accuracy(self, x, t):
		y = self.predict(x)
		y = np.argmax(y, axis=1)
		t = np.argmax(t, axis=1)
		
		accuracy = np.sum(y == t) / float(x.shape[0])
		return accuracy
		
	
	def numerical_gradient(self, x, t):
		loss_W = lambda W: self.loss(x, t)
		
		grads = {}
		grads['W1'] = numerical_gradient(loss_W, self.params['W1'])
		grads['b1'] = numerical_gradient(loss_W, self.params['b1'])
		grads['W2'] = numerical_gradient(loss_W, self.params['W2'])
		grads['b2'] = numerical_gradient(loss_W, self.params['b2'])
		
		return grads
		
	def gradient
	
