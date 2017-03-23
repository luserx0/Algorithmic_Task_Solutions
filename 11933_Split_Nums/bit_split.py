N = int(input())
while( N != 0 ):

   binaryN = bin(N)[2:].zfill(32)
   
   binaryN = binaryN[::-1] # reverse it

   a = list('00' * 16)
   b = list('00' * 16)
    
   switch = 0
   for index, i in enumerate(binaryN):
      if i == '1':
         if switch == 0:
            a[index] = i
            switch = 1
         else:
            b[index] = i
            switch = 0

   a = ['0b'] + a[::-1]
   b = ['0b'] + b[::-1]

   a = int(''.join(a),2)
   b = int(''.join(b),2)

   print( a, b )
   
   N = int(input())



