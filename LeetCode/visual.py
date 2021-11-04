import numpy as np
import matplotlib.pyplot as plt
def stock():
	y1 = np.array([1,2,3,4,5,6,7])
	y2 = np.array([5,6,7,1,2,3,4])
	t = np.array([0,1,2,3,4,5,6])
	plt.plot(t,y1)
	plt.plot(t,y2)
	plt.grid()
	plt.show()
stock()
