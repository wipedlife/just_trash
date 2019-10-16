#!/usr/bin/env python3
class myHash:

 def A1(self, N):
     a = N << 7
     b = N << 2
     c = N << 3
     return  (((a & b) | (b & c) | (b & a)) << 7) | 7 
 def A2(self, N):
   N = N << 12
   a = N >> 14
   z = N & a
   c = N | a
   k = z & c
   rv=( ( ( k & c | z | a | N  ) << (14+12) ) )
   return (rv << (14+12) ) | (14+12)
 def A3(self, N):
   bytes_ = []
  # endbytes_ = []
   count = 1
   rv = 0
   while N > 0:
       byte = (N >> count) & (0x01)
       count = count + 1
       bytes_.append(byte)
       N = N >> count 
   for byte in bytes_:
     byte0 = self.A1(byte)
     byte1 = self.A2(byte)
     byte = byte ^ byte0
     byte = byte ^ byte1
   #  endbytes.append(byte)
     rv = (rv << 8) + byte
   return rv
   

 def A4(self, N):
     a = N ^ 7
     b = N ^ 2
     c = N ^ 3
     d = N << 12
     e = N >> 14
     return ((a^b) | (a^c) | (a^d) | (a^e)) ^ ((b^c) | (b^e) | (b^d) | (e^a)) | (14+12)

 def C(self, str):
   v = 0
   for s in str:
       e=self.Z(ord(s))
       c = (v << 8 | e)
       v = ( v + (v ^ c) ) | (14+12)
   return (v)
 def Z(self,N):
  a1 = self.A1(N)
  a2 = self.A2(N)
  a3 = self.A3(N)
  return ((a1+a2+a3)^self.A4(N) << (14+12) ) | (14+12)
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
