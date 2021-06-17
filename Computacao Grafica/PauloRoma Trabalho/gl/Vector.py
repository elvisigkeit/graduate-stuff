# -*- coding: utf-8 -*-
"""
Created on Fri Apr 14 12:48:02 2017

@author: arctos
"""
from math import sqrt

class Vector ():
    def __init__ (self, x=0.0, y=0.0, z=0.0):
        self.x = x
        self.y = y
        self.z = z
        
    def getVector(self):
        return [self.x, self.y, self.z]
        
    def __sub__(self, other):
        result = Vector()
        result.x = self.x - other.x
        result.y = self.y - other.y
        result.z = self.z - other.z
        return result
        
    def __add__(self, other):
        result = Vector()
        result.x = self.x + other.x
        result.y = self.y + other.y
        result.z = self.z + other.z
        return result
        
        
    def module(self):
        return sqrt(self.x*self.x + self.y*self.y + self.z*self.z)        
        
    def __mul__(self, other):
        product = Vector()
        
        product.x = self.y*other.z - self.z*other.y
        product.y = self.z*other.x - self.x*other.z
        product.z = self.x*other.y - self.y*other.x
        
        return product
        

def normalize(vec1):
    size = sqrt(vec1.x*vec1.x + vec1.y*vec1.y + vec1.z*vec1.z)
    return Vector(vec1.x/size, vec1.y/size, vec1.z/size)

    
def createNormal(vec1, vec2, vec3):
    v1 = vec2-vec1
    v2 = vec3-vec1
    normal = v1*v2
    normal = normalize(normal)
    
    return (normal.getVector())
