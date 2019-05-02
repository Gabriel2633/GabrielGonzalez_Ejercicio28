import numpy as np 
import matplotlib.pyplot as plt
import os


os.system("g++ c.cpp")
os.system("./a.out")

pinocho = np.loadtxt("pinocho.dat")
x=np.linspace(0,200,len(pinocho))

plt.figure()
f,(ax1, ax2) = plt.subplots(1, 2, sharey=True)
ax1.plot(x,pinocho)
ax1.set_ylabel('Indice Y')
ax1.set_xlabel('Indice x')
ax1.set_xlim([0,200])
ax1.set_ylim([0,200])

ax2.plot(x,pinocho)
ax2.set_ylabel('Temperatura')
ax2.set_xlabel('Indice x')
ax2.set_xlim([0,200])
ax2.set_ylim([0,200])

plt.savefig("graficas.png")



