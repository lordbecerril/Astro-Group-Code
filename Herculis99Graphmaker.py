import csv
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
from matplotlib.ticker import MaxNLocator # added 
import numpy as np
import random
import decimal
import math

time = []
i1 = []
i2 = []
i3 = []
o1 = []
o2 = []
o3 = []
e_vec = []
e_time = []

#The loops below are for the time.dat files. Don't leave <Pathname> there but replace it with the actual path of where
#the time.dat file is found.
with open(<Pathname>, 'r') as h:          #pathname could be '/Users/becerrilblas/Documents//time.dat'
    lines_after_Juan = h.readlines()[1:]
    for x in lines_after_Juan:
        time.append(x.split()[0])
        i1.append(x.split()[4])
        i2.append(x.split()[5])
        i3.append(x.split()[6])
        o1.append(x.split()[7])
        o2.append(x.split()[8])
        o3.append(x.split()[9])
    h.close()
 
 #Below is for the binary.dat file if the eccentricity vector is needed
 with open(<pahtname for binary.dat>) as f:
    lines_after_1 = f.readlines()[1:]
    for x in lines_after_1:
        e_vec.append(x.split()[4])
    f.close()
    
#The maths for the eccentricity vector
count = 0
for v in e_vec:
    v = float(v)
    v = v * 180
    v = v / math.pi
    v = v + 90
    if v > 180:
        v = v - 360
    e_vec[count] = v
    count = count + 1


#Calulating what I am going to divide for orbital period
#Gconst = 6.67408 * 10 ** (-11)
M = 1.4
a = 16.5
Divider = (2*math.pi)/ math.sqrt((M) / (a**3))

#Maths below
count = 0
for t in time:
    t = float(t)
    t = t / Divider
    time[count] = t
    count = count + 1

count = 0
for inc in i1:
    inc = float(inc)
    inc =inc *180
    inc = inc / math.pi
    i1[count] = inc
    count = count + 1
        
count = 0
for inc in i2:
    inc = float(inc)
    inc =inc *180
    inc = inc / math.pi
    i2[count] = inc
    count = count + 1
    
    
count = 0
for inc in i3:
    inc = float(inc)
    inc =inc *180
    inc = inc / math.pi
    i3[count] = inc
    count = count + 1
    
    
count = 0
for o in o1:
    o = float(o)
    o =o *180
    o = o / math.pi
    o = o + 90
    if o > 180:
        o = o-360
    o1[count] = o
    count = count + 1
    
count = 0
for o in o2:
    o = float(o)
    o =o *180
    o = o / math.pi
    o = o + 90
    if o > 180:
        o = o-360
    o2[count] = o
    count = count + 1
    
count = 0
for o in o3:
    o = float(o)
    o =o *180
    o = o / math.pi
    o = o + 90
    if o > 180:
        o = o-360
    o3[count] = o
    count = count + 1
    
#Graphing time below    
f, (ax1,ax2) = plt.subplots(2, sharex=True, sharey=False, figsize = (8,8), dpi = 100)
ax1.set_ylim([0, 150])
ax1.set_xlim([0, 1000])
ptr = 80

font = {'family' : 'monospace',
        'weight' : 'normal',
        'size'   : 15}

plt.rc('font', **font)

ax1.plot(time,i1,'g',linewidth=1) #,markersize=1) #Analysis at r1
ax1.plot(time,i2,'k',linewidth=1) #, markersize=1)  #Analysis at r2
ax1.plot(time,i3,'b', linewidth=1)#, markersize=.5)  #Analysis at r3
ax1.set(ylabel='i/\u00B0')
#ax1.set_xticklabels([0, 200, 400, 600, 800, 1000])

#nbins = len(ax1.get_xticklabels()) # added 
#print(nbins)

ax2.set_ylim([-150,100])
ax2.yaxis.set_major_locator(MaxNLocator(nbins=6, prune='upper')) #makes sure numbers in the y axis dont overlap
ax2.plot(time,o1,'g',linewidth=1)#Analysis at r1
ax2.plot(time,o2,'k',linewidth=1)#Analysis at r2
ax2.plot(time,o3,'b', linewidth=1)# markersize=1)  #Analysis at r3
#ax2.plot(time, e_vec, 'r--', linewidth = 1) #Uncomment if you want the Eccentricty vector. Comment out if you dont
ax2.set(xlabel='t/P', ylabel='\u03C6/\u00B0')

f.subplots_adjust(hspace=0)
plt.setp([ab.get_xticklabels() for ab in f.axes[:-1]], visible= True)
#plt.show()
plt.savefig('<Path where you want this saved>/Graph.eps', format='eps', dpi=1000) 

 
    
