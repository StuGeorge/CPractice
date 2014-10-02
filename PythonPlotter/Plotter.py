# -*- coding: utf-8 -*-
"""
Created on Tue Sep 30 15:00:47 2014

@author: stuart
"""

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


fname = "/Users/stuart/GitHub/CPractice/output_data.txt"

data_file = open(fname, 'r')

data_string = data_file.read()
data_lines = data_string.splitlines()

ts = []
xs = []
ys = []
zs = []

for line in data_lines:
    t,x,y,z = line.split()
    ts.append(t)
    xs.append(x)
    ys.append(y)
    zs.append(z)

fig = plt.figure(1)
fig.clf()

data = np.array([xs,ys,zs])

ax = fig.add_subplot(111,autoscale_on=False,projection='3d')
trace1, = ax.plot(data[0,:],data[1,:],data[2,:],'-b')

