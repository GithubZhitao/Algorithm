from numpy import *;
import numpy as np; 
import math

from matplotlib import pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D


def p_1(x_index, bet, dat):
	ex =  math.exp(dat[x_index,:]*bet)
	return ex/(1+ex)
	
def dsubFormula(xi , yi , p1i):
	return -(yi-p1i)*xi

def ddsubFormula(xi , p1i):
	return p1i*(1-p1i)*(xi.T*xi)



data = mat([ 
[0.697, 0.46 ,1],
[0.774 ,0.376,1],
[0.634 ,0.264 ,1],
[0.608 ,0.318 ,1],
[0.556 ,0.215 ,1 ],
[0.403 ,0.237,1 ],
[0.481, 0.149,1 ],
[0.437, 0.211,1 ],
[0.666 ,0.091 ,1 ],
[0.243, 0.0267 ,1 ],
[0.245, 0.057,1 ],
[0.343, 0.099,1 ],
[0.639 ,0.161,1 ],
[0.657 ,0.198 ,1 ],
[0.36, 0.37,1 ],
[0.593, 0.042,1 ],
[0.719 ,0.103 ,1] ]);

y=[1,1,1 ,1,1,1 ,1 ,1 ,0,0,0,0,0,0,0,0,0]

#initialize beta
beta = mat([1,1,1]).T
i =0
d=mat([0,0,0]) 
dd =mat([[1,0,0],[0,1,0],[0,0,1]])
step=0
print y[0]

while (not (i!=0 and abs(step)<0.0001)) : 
	d=mat([0,0,0]) 
	dd=mat([[0,0,0],[0,0,0],[0,0,0]])
	for ti in range(data.shape[0]):
		p1 = p_1(ti,beta,data)
		d=d+ dsubFormula(data[ti,:],y[ti],p1)		
		dd=dd+ddsubFormula(data[ti,:],p1)
	i = i+1
	beta =beta - dd.I*d.T
	descent = dd.I*d.T
	step = pow (descent[0],2)+ pow (descent[1],2)+pow (descent[2],2) 
	print step


print "the beta is "
print beta
print "predicted y vs y_o"

for ri in range(data.shape[0]):
	if(p_1(ri, beta, data) > 0.5):
		print [1 ,y[ri]] 
		
	else:
		print [0 ,y[ri]]

fig = plt.figure()
ax = Axes3D(fig)
#origion data
X_O = data[:,0].T.tolist()
Y_O = data[:,1].T.tolist()

#plt.scatter(X_O[0],Y_O[0])
  
X = np.arange(0, 1, 0.05)
Y = np.arange(0, 1, 0.05) 
X, Y = np.meshgrid(X,Y)


Z =  beta.tolist()[0][0]*X  +  beta.tolist()[1][0]*Y   + ones((20,20))
for ii in range(mat(Z).shape[0]):
	for jj in range(mat(Z).shape[1]):
		tmp =math.exp(Z[ii][jj])
		Z[ii][jj] = tmp/(1+tmp)

ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap='rainbow')
plt.show()	
	
	



	

