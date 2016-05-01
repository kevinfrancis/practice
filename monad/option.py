#!/usr/bin/env python

# Experimenting with Scala's Option Monad in Python

from abc import ABCMeta, abstractmethod
import math

class Option:
    __meta__=ABCMeta

    @abstractmethod
    def flatMap(f):
        pass

class Some(Option):

    def __init__(self, x):
        self.x = x

    def flatMap(self, f):
        return f(self.x)

    def __str__(self):
        return 'Some(%s)' % str(self.x)

class Nothing(Option):
    def __init__(self):
        pass

    def flatMap(self, f):
        return Nothing()

    def __str__(self):
        return 'Nothing()'

def mysqrt(x):
    if x > 0:
        return Some(math.sqrt(x))
    return Nothing()


def fourth_root(x):
    return mysqrt(x).flatMap(lambda y: mysqrt(y))

def main():
    value = -256
    print mysqrt(value)
    print fourth_root(value)

if __name__=='__main__':
    main()
