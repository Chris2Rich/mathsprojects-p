import matplotlib.pyplot as plt

n = 25

x = [i for i in map(lambda t: pow(t, 2), range(-n,n+1))] #Equivalent to x = t^2
y = [i for i in map(lambda t: t + 1, range(-n,n+1))] #Equivalent to y = t + 1

plt.plot(x, y)
plt.show()