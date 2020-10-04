dic = {}
def fib(n):
  if n <=2: return 1
  if n not in dic:
    dic[n] = fib(n - 1) + fib(n - 2)
  return dic[n]
print (fib(100))

from functools import lru_cache

@lru_cache(maxsize=None)
def fib(n):
  print (n)
  if n <= 2: return 1
  return fib(n - 1) + fib(n - 2)
print(fib(100))

def mdc(a, b):
  return a if not b else mdc(b, a % b)


def ivs(s):
  return s if s == "" else s[-1] + ivs(s[:-1])


def soma(n):
    n = str(n)
    return int(n[-1]) + soma(n[:-1]) if len(n) != 0 else return 0


def pot(n, b):
    return 1 if b == 0 else n * pot(n, b - 1)
    
    
