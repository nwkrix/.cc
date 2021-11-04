import numpy as np
import matplotlib.pyplot as plt
n = 5000
GRIDSIZE = 50
def logistic(beta,x0):
	x =  np.empty(n, dtype=object)
	t =  np.empty(n, dtype=object)
	x[0] = x0
	for i in range(0,n-1):
		t[i] = i
		x[i+1] = 2 * beta -x[i]**2 / beta
	return t, x 

def modulo(x):
	return np.floor(x % 8)

def motion_direction(x,y,idx):
	if(idx==0):
		return (x, y+1) if (0 <= x < GRIDSIZE) and (0 <= y+1 < GRIDSIZE) else (x,y)
	if(idx==1):
		return (x+np.sqrt(2), y+np.sqrt(2)) if 0 <= x+np.sqrt(2) < GRIDSIZE and 0 <= y+np.sqrt(2) < GRIDSIZE else (x,y)
	if(idx==2):
		return (x+1, y) if 0 <= x+1 < GRIDSIZE and 0 <= y < GRIDSIZE else (x,y) 
	if(idx==3):
		return (x+np.sqrt(2),y-np.sqrt(2)) if 0 <= x+np.sqrt(2) < GRIDSIZE and 0 <= y-np.sqrt(2) < GRIDSIZE else (x,y) 
	if(idx==4):
		return (x, y-1) if 0 <= x < GRIDSIZE and 0 <= y-1 < GRIDSIZE else (x,y) 
	if(idx==5):
		return (x-np.sqrt(2),y-np.sqrt(2)) if 0 <= x-np.sqrt(2) < GRIDSIZE and 0 <= y-np.sqrt(2) < GRIDSIZE else (x,y) 
	if(idx==6):
		return (x-1, y) if 0 <= x-1 < GRIDSIZE and 0 <= y < GRIDSIZE else (x,y) 
	if(idx==7):
		return (x-np.sqrt(2),y+np.sqrt(2)) if 0 <= x-np.sqrt(2) < GRIDSIZE and 0 <= y+np.sqrt(2) < GRIDSIZE else (x,y) 

# MY TIME HAS COME, LET THE MANIFESTATION BEGIN -- MONDAY FASTING 6 - 2 PM
def generatePath(x_initial_pos,y_initial_pos):
	t , c_state = logistic(10**7,10**6)
	X = modulo(c_state)
	len = np.size(X)
	x = np.empty(len,dtype = object)
	y = np.empty(len,dtype = object)
	x[0] = x_initial_pos
	y[0] = y_initial_pos
	for i in range(0,len-1):
		x[i+1], y[i+1] = motion_direction(x[i],y[i],X[i])
	return x, y
x, y = generatePath(1,1)
plt.plot(x,y)
plt.grid(b=True, which='major', axis='both')
plt.minorticks_on()
plt.grid(b=True, which='minor', axis='both')
plt.show()
