import numpy as np
import matplotlib.pyplot as plt

archivo = np.genfromtxt('advection.txt')
x = archivo[:,0]
u0 = archivo[:,1]
u1 = archivo[:,2]
u2 = archivo[:,3]
u3 = archivo[:,4]
u4 = archivo[:,5]

plt.plot(x,u0, color = 'r', label = 't=0')
plt.plot(x,u1, color = 'g', label = 't=175')
plt.plot(x,u2, color = 'b', label = 't=350')
plt.plot(x,u3, color = 'y', label = 't=525')
plt.plot(x,u4, color = 'c', label = 't=700')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.savefig('tiempos.png')
