import numpy as np
from matplotlib import pyplot as plt
from matplotlib import rc
import pylab

fig, ax = plt.subplots()
ax.grid(True)

# Move left y-axis and bottim x-axis to centre, passing through (0,0)
ax.spines['left'].set_position('zero')
ax.spines['bottom'].set_position('zero')
# Eliminate upper and right axes
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
# Show ticks in the left and lower axes only
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')

x = np.arange(0,500,1/40.)

y1=500-x
ax.plot(x, y1, color='blue', alpha=1.00, label=r'$x + y = 500$')

y2=600-2*x
ax.plot(x, y2, color='orange', alpha=1.00, label=r'$2x + y = 600$')

y = np.minimum(y1,y2)

ax.fill_between(x, 800*np.ones(len(x)), interpolate=True, color='red', alpha=.1)
ax.fill_between(x, y, interpolate=True, color='white', alpha=1)

ax.axvspan(-10, 0, alpha=0.1, color='red')
ax.axhspan(-200, 0, alpha=0.1, color='red')

plt.plot(100,400,'go',label=r'Optimizer x=100, y=400') 
# plt.plot(100,200,'bo',label=r'OK') 

liste = [0, 250, 1000, 2800]
for i in liste:
  zi=-4/2.5*x+i/5
  ax.plot(x, zi, color='r', ls=':',lw=2,alpha=1)#, label=r'$4x_A+5x_B={i}$')

plt.xlabel(r'$x$')
plt.ylabel(r'$y$')

# Shrink current axis by 20%
#box = ax.get_position()
#ax.set_position([box.x0, box.y0, box.width * 0.8, box.height])

# Put a legend to the right of the current axis
#ax.legend(loc='center left', bbox_to_anchor=(1, 0.5))
ax.legend(loc='upper center', bbox_to_anchor=(0.5, 1.05), ncol=3, fancybox=True, shadow=True)

pylab.xlim([-20,450])
pylab.ylim([-20,500])

ax.set_aspect(1)
plt.show()