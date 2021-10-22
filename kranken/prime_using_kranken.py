>>> from kanren import isvar,run,membero
>>> from kanren.core import success,fail,goaleval,condeseq,eq,var
>>> from sympy.ntheory.generate import prime,isprime
>>> import itertools as it
>>> def prime_test(n): #Function to test for prime
if isvar(n):
return condeseq([(eq,n,p)] for p in map(prime,it.count(1)))
else:
return success if isprime(n) else fail
>>> n=var() #Variable to use
>>> set(run(0,n,(membero,n,(12,14,15,19,21,20,22,29,23,30,41,44,62,52,65,85)),(prime_test,n)))
