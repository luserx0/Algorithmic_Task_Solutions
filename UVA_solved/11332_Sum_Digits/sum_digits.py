def f( N ):
   sum = 0 
   while N > 9:
      sum += (N % 10)
      N = int(N / 10)
   
   sum += N
   return sum

def main():

   N = int(input())
   while N != 0:
      
      K = N
      while K > 9:
         K = f(K)

      print( K )
      N = int(input())

if __name__ == "__main__":
   main()
