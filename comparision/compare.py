# start from file dir
# the data for comparison is taken from the folder ./Tests

import subprocess
import os
import matplotlib.pyplot as plt

directory = "./Tests"
files = os.listdir(directory)

files = sorted(files, key = lambda x:(int)((x.split(sep='test')[1]).split(sep='.')[0]))

lru2q = []
IdCache = []

for file_name in files:

    file = open(directory + '/' + file_name, 'r')

    answer = subprocess.check_output('../lru2q/build/lru2q.x', stdin=file)
    lru2q.append(int(answer))
    
    file.close()

    file = open(directory + '/' + file_name, 'r')

    answer = subprocess.check_output('../idcache/build/idCache.x', stdin=file)
    IdCache.append(int(answer))    

    file.close()


x = []


lru2q.sort()
IdCache.sort()

for i in range(len(files)):
    print(str(lru2q[i]) + '  ' + str(IdCache[i]))
    x.append(i)
    
plt.plot(x, lru2q, 'o-r', alpha=0.7, label="lru2q", lw=5, mec='b', mew=2, ms=10)
plt.plot(x, IdCache, 'v-.g', label="IdCache", mec='r', lw=2, mew=2, ms=12)
plt.legend()
plt.grid(True)
plt.savefig("cmp.png");
plt.show()