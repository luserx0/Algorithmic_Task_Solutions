from sys import stdin

for line in stdin: 
   v, t = line.split()
   v = int(v)
   t = int(t)
   t *= 2
   print (v * t)
