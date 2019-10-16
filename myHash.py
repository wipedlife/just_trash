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
       e=self.W(ord(s))
       c = (v << 8 | e) << (14+12) | (14+12)
       v = ( (v ^ c)^e ) << (14+12) | (14+12)
   return ( (v << (14+12)) ^ (14+12) )
 def B0(self, N):
     return [((N & (0xff << pos*8)) >> pos*8 )^7 for pos in range(14+12)]
 def B1(self, N):
     return [((N & (0xff << pos*8)) >> pos*8 )^2 for pos in reversed( range(14+12) )]
 def B2(self, N):
  N = N << 14
  return [((N & (0xff << pos*8)) >> pos*8 )^N for pos in range(14+12)]

 def W(self,N):
  a1 = self.A1(N)
  a2 = self.A2(N)
  a3 = self.A3(N)
  rv= ((a1+a2+a3)^self.A4(N) << (14+12) ) ^ (14+12)
  return rv

 #TODO: fix much of collisions
 def Z(self, N):
   b0=self.B0(N)
   b1=self.B1(N)
   b2=self.B2(N)
   b = 0
   d = 0
   e = 0
   for num in b0:
       b = (b << 8) | num
   for num in b1:
       d = (d << 8) | num
   for num in b2:
       e = (e << 8) | num
   return self.A1(b^d & e)
     
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
