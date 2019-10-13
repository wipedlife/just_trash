class myHash:
 def C(self, str):
   v = 0
   for s in str:
       v = v + self.Z(ord(s))
   return (v)
 def Z(self,N):
   #if N is str:
   # N = C(N)
   N = N << 12
   a = N >> 14
   z = N & a
   c = N | a
   k = z & c
   rv=( ( ( k & c & c | z | a | N  ) << (14+12) ) )
   return (rv << (14+12) ) | (14+12)


 def strToHex(self,str):
     num = self.Z(self.C( str ))
     print ( num )
     return hex(num)
import sys
def main():
    h = myHash()
    if len(sys.argv) < 2:
        print ("%s STR" % (sys.argv[0]) )
        sys.exit(1)
    print( h.strToHex( sys.argv[1] ) )
main()
