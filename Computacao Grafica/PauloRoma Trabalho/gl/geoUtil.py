#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
## @package geometry
#
#  Classes and geometric utilities commonly used in computational geometry, such as: 
#  point, line, polygon, triangle and box.
#
#  @author Flavia Cavalcanti
#  @date 01/02/2017 
#
from random import random
from math import sqrt,cos,sin,asin,tan,radians, acos, atan, pi
import math, numpy
import numpy as np 

## Tolerance used for checking equalities.
EPS = 0.001

def ccw3(A, B, C, N):
    """Tests whether the angle formed by 3D points A, B, C and normal N is ccw."""
    return (N.tripleProd(B-A,C-A) > 0)

def ccw(A, B, C):
    """Tests whether the angle formed by 2D points A, B, and C is ccw."""
    return ((B-A).crossProd2d(C-A) > 0)

def intersect(a1, b1, a2, b2):
    """Returns True if the line segments a1b1 and a2b2 intersect."""
    return (ccw(a1, b1, a2) != ccw(a1, b1, b2)
            and ccw(a2, b2, a1) != ccw(a2, b2, b1))

def close(a,b,epsilon=EPS):
    """Returns whether two floats a and b are equal."""
    return abs(a-b) < epsilon

######################################################################################### 

## Implements a 3D point or vector.
#  
#  Points are locations in space.
#  Vectors are displacements in space.
#
#  A point in n-dimensional space is given by an n-tuple P=(p1,p2,...pn),
#  where each coordinate pi is a scalar number. 
#
#  A vector represents magnitude and direction in space, 
#  and is given by an n-tuple v=(v1,v2,...vn)=(vi), where each coordinate vi is a scalar. 
#
#  - vector + vector = vector.
#  - vector - vector = vector.
#  - point + vector = point.
#  - point - point = vector.
#  - point + point is undefined.
#
class Point(object):
    """A class representing a point or a vector."""

    ## Point constructor.
    def __init__(self, x=0.0, y=0.0, z = 0.0):
        ## X coordinate
        self.x = x
        ## Y coordinate
        self.y = y
        ## Z coordinate
        self.z = z

    def getV(self):
        return([self.x, self.y, self.z])
        
    def get4V(self):
        return([self.x, self.y, self.z, 1])

    ## Print object.
    def __repr__(self):
        return "(" + str(self.x) + ", " + str(self.y) + ", " + str(self.z) + ")"

    ## Operator ==
    def __eq__(self, other):
        return isinstance(other, self.__class__) and \
               self.x == other.x and \
               self.y == other.y and \
               self.z == other.z

    ## Should return the same value for objects that are equal. 
    #  It also shouldn't change over the lifetime of the object; 
    #  generally you only implement it for immutable objects.
    def __hash__(self):
        return hash((self.x, self.y, self.z))

    ## Indexing operator.
    def __getitem__(self, ind):
        if ind == 0:
           return self.x
        elif ind == 1:
           return self.y
        elif ind == 2:
           return self.z
        else:
           return None

    ## Indexing operator.
    def __setitem__(self, ind, val):
        if ind == 0:
           self.x = val
        elif ind == 1:
           self.y = val
        elif ind == 2:
           self.z = val
        return val

    ## Operator +
    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y, self.z + other.z)

    ## Operator negation (-self)
    def __neg__ (self):
        return Point(-self.x, -self.y, -self.z)

    ## Operator -
    def __sub__(self, other):
        return self + -other

    ## Operator self * c
    def __rmul__(self, c):
        return Point(c * self.x, c * self.y, c * self.z)

    ## Operator c * self
    def __lmul__(self, c):
        return self * c

    ## Operator *=
    def __imul__ (self,c):
        self.x *= c
        self.y *= c
        self.z *= c
        return self
    
    ## Division by integer
    def __div__ (self, c):
        return Point(self.x/c, self.y/c, self.z/c)

    def close(self, that, epsilon=EPS):
        """Returns whether this point is close to the given point."""
        return self.dist(that) < epsilon

    def dist(self, that):
        """Returns the distance between this and a given point."""
        return sqrt(self.sqrDist(that))

    def sqrDist(self, that):
        """Returns the square of the distance between this and a given point."""
        d = self - that
        return d.dotProd(d)

    def np3(self):
        """Returns the point's Numpy point representation"""
        return numpy.array([self.x, self.y, self.z])

    def np(self):
        """Returns the point's Numpy point representation"""
        return numpy.array([self.x, self.y, self.z, 1])

    def dotProd (self, vec):
        """Returns the dot product between this vector and vec.""" 
        return (self.x * vec.x) + (vec.y * self.y) + (vec.z * self.z)

    def crossProd2d (self, vec):
        """Returns the bi-dimensional cross product between this vector and vec.""" 
        return (self.x * vec.y) - (vec.x * self.y)

    def crossProd (self, vec):
        """Returns the tri-dimensional cross product between this vector and vec.

           More generally, the magnitude of the product equals the area of a parallelogram,
           with the vectors for sides, or two times the area of the triangle.

           cross product: |self| |vec| sin(??) n 

           @see https://www.khanacademy.org/math/basic-geo/basic-geo-area-and-perimeter/parallelogram-area/a/area-of-parallelogram
        """ 
        return Point ( (self.y * vec.z) - (self.z * vec.y),
                       (self.z * vec.x) - (self.x * vec.z),
                       (self.x * vec.y) - (self.y * vec.x) )

    def tripleProd (self,vec0,vec1):
        """Returns the triple product of three 3D vectors.

           The scalar triple product (also called the mixed product, box product, or triple scalar product) 
           is defined as the dot product of one of the vectors with the cross product of the other two:
               triple product: this.(vec0 X vec1).

           Geometrically, the scalar triple product is the (signed) volume 
           of the parallelepiped defined by the three vectors given, or six
           times the volume of the tetrahedron (the volume of any pyramid is 
           one third the area of the base times the height). 

           Here, the parentheses may be omitted without causing ambiguity, 
           since the dot product cannot be evaluated first. 
           If it were, it would leave the cross product of a scalar and a vector, which is not defined.

           @see https://en.wikipedia.org/wiki/Triple_product
           @see http://mathcentral.uregina.ca/QQ/database/QQ.09.06/s/anurag1.html
         """
        return self.dotProd ( vec0.crossProd ( vec1 ) )

    def len(self):
        """Return this vector length."""
        return sqrt(self.dotProd(self))

    def normalize(self):
        "Make this a unit vector.""" 
        d = self.len()
        if d > 0:
           self *= 1.0/d
        return self
  
######################################################################################### 

## Two points define a straight line. 
#  A line is represented by a starting (or origin) and ending points, thus defining a direction.
#
class Line(object):
    """A class representing a line."""

    def __init__(self, p1, p2):
        if p1.close(p2):
           raise ValueError("Degenerated line")

        ## line starting point
        self.p1 = p1
        ## line ending point
        self.p2 = p2
        ## line direction 
        self.dir = p2 - p1 

    def __repr__(self):
        return str(self.p1) + " + " + str(self.dir) + "*t"  

    def __eq__(self, other):
        return self.p1 == other.p1 and self.dir == other.dir

    def atT(self, t):
        """Evaluates this line at parameter t."""

        return Point(self.p1, self.p1 + t*self.dir)

    def distance(self, p):
        """Computes the distance from this line to a given point.

           @see http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html
        """

        numerator = (p - self.p1).crossProd(p - self.p2)
        denominator = self.p2 - self.p1

        return numerator.len()/denominator.len()

##
#   Calculate the line segment PaPb that is the shortest route between
#   two lines P1P2 and P3P4. Calculate also the values of mua and mub where
#           Pa = P1 + mua (P2 - P1)
#           Pb = P3 + mub (P4 - P3)
#   Return None if no solution exists.
#
    def shortestPathToLine(self, that):
        """Return the shortest segment between two lines.

           @see http://paulbourke.net/geometry/pointlineplane/
        """

        p1 = self.p1 
        p2 = self.p2 
        p3 = that.p1 
        p4 = that.p2 

        # p3 == p4 or p1 == p2
        if p3.close(p4) or p1.close(p2):  # line constructor already do this
           return None

        p13 = p1 - p3
        p43 = p4 - p3
        p21 = p2 - p1

        d1343 = p13.x * p43.x + p13.y * p43.y + p13.z * p43.z
        d4321 = p43.x * p21.x + p43.y * p21.y + p43.z * p21.z
        d1321 = p13.x * p21.x + p13.y * p21.y + p13.z * p21.z
        d4343 = p43.x * p43.x + p43.y * p43.y + p43.z * p43.z
        d2121 = p21.x * p21.x + p21.y * p21.y + p21.z * p21.z

        denom = d2121 * d4343 - d4321 * d4321
        if close(denom,0.0):
           return None

        numer = d1343 * d4321 - d1321 * d4343

        mua = numer / denom
        mub = (d1343 + d4321 * mua) / d4343

        pa = Point( p1.x + mua * p21.x, p1.y + mua * p21.y, p1.z + mua * p21.z )
        pb = Point( p3.x + mub * p43.x, p3.y + mub * p43.y, p3.z + mub * p43.z )

        try:
           l = Line(pa, pb)
        except ValueError:
           l = None

        return (l, mua, mub)

    def distanceToLine (self, that):
        """Returns the distance between two lines."""

        (l,ta,tb) = self.shortestPathToLine(that)
        if l is None:
           return 0.0
        else:
           return l.len()

    def intersection(self, that):
        """Returns the intersection point between two lines."""

        (l,ta,tb) = self.shortestPathToLine(that)
        if l is None:
           return self.atT(ta)
        else:
           None  

    def midpoint(self):
        """Returns the middle point of this segment."""

        x = float(self.p1.x + self.p2.x) / 2
        y = float(self.p1.y + self.p2.y) / 2
        z = float(self.p1.z + self.p2.z) / 2
        return Point(x, y, z)

    def intersectToPlane (self, poly):
        """Returns the intersection between this line and a given polygon plane."""

        p1 = self.p1
        p2 = self.p2
        p3 = poly.points[0]
        N = poly.normal

        p13 = p3 - p1
        p12 = p2 - p1

        numer = N.dotProd(p13)
        denom = N.dotProd(p12)

        if (close(denom, 0.0)): # line is parallel to plane
            return None
        else:
            u = numer/denom
        return (p1 + u * p12, u)  # why it isn't wrong?
#        return (p1+(u*p2), u)

######################################################################################### 

## In elementary geometry, a polygon is a plane figure that is 
#  bounded by a finite chain of straight line segments, closing in 
#  a loop, to form a closed polygonal chain or circuit. 
#
#  These segments are called its edges or sides, and the points where 
#  two edges meet are the polygon's vertices (singular: vertex) or corners. 
#
class Polygon(object):
    """A class representing a polygon."""

    def __init__(self, points):
        """Constructor. Throws an exception if less than three points are given."""

        if len(points) < 3:
            raise ValueError("Polygon must have at least three vertices.")

        ## number of vertices
        self.n = len(points)
        ## list of indexes of vertices
        self.points = points
        ## normal vector of the given polygon
        self.normal = self.compNormal().normalize()

    def __repr__(self):
        """String representation of this polygon.""" 

        s = ""
        for point in self.points:
            if s:
                s += " -> "
            s += str(point)
        return s

    def __hash__(self):
        """The hash is a tuple of all points sorted on x."""
        return hash(tuple(sorted(self.points, key=lambda p: p.x)))

    ## Calculating a Surface Normal for a triangle or a 3D polygon. 
    #
    #  A surface normal for a triangle can be calculated by taking the vector cross product 
    #  of two edges of that triangle. The order of the vertices used in the calculation will 
    #  affect the direction of the normal (in or out of the face w.r.t. winding).
    #  Also you can use a Newell's method for an arbitrary 3D polygon.
    #
    #  @return normal.
    #  @see https://www.khronos.org/opengl/wiki/Calculating_a_Surface_Normal 
    #
    def compNormal(self):
        """Newell's method for getting polygon normal."""

        normal = Point(0.0,0.0,0.0)
        for i in range(0, self.n):
             j = (i+1)%self.n
             a = (self.points[i]-self.points[j])
             b = (self.points[i]+self.points[j])
             p = Point ( a.y*b.z, a.z*b.x, a.x*b.y )
             normal += p

        return normal 

    def contains(self, p):
        """Returns True if p is inside this polygon.

           @see http://geomalgorithms.com/a03-_inclusion.html
        """
        if p is None:
            return False
        # calculate winding number
        wn = 0.0
        v0 = self.points[0] - p
        v0.normalize()

        for i in range(1, self.n+1):
            v1 = self.points[i%self.n] - p 
            v1.normalize()
            product = v0.dotProd(v1)
            if product > 1.0:
                product = 1.0
            angle = math.acos ( product )
#            angle = math.acos ( v0.dotProd(v1) )
            if (self.normal.tripleProd(v0,v1) < 0): 
                angle = -angle
            wn += angle
            v0 = v1

        return close(wn,2.0*math.pi)

    def isConvex(self):
        """Returns whether this polygon is convex."""

        target = None
        for i in range(self.n):
            # Check every triplet of points
            A = self.points[i % self.n]
            B = self.points[(i + 1) % self.n]
            C = self.points[(i + 2) % self.n]

            if not target:
                target = ccw3(A, B, C, self.normal)
            else:
                if ccw3(A, B, C,self.normal) != target:
                    return False

        return True

    def doesLineCrossPolygon(self, line):
        """Returns whether this polygon is crossed by a given line."""
        if line.intersectToPlane(self):
            p, t = line.intersectToPlane(self)
            return (self.contains(p), p, t)
        return (False, Point(), 0.0)

    def ccw(self):
        """Returns True if the points are provided in CCW order."""
        return ccw(self.points[0], self.points[1], self.points[2])

##
#       calculates the area of a planar polygon.
#       The algorithm is as follows:<br>
#           Traverse the loop of coordinates, assuming that it is in
#           clockwise order, computing the components of the "area" of the
#           enclosed polygon.  The total "area" components are computed by
#           adding "area" components (cross product components) of
#           triangles sides formed by the first, previous, and current
#           vertices.  If the loop is not convex, some of the triangle
#           areas might be negative, but those will be compensated by other
#           positive triangle areas so that the final area is positive.<br>
#
#       Note: area here is actually twice the area. <br>
#             positive here means in the direction of the face normal.
#
#       @return twice the polygon area.
#
    def area(self):
        """Returns the area of the polygon."""
     
        n = Point ( 0.0, 0.0, 0.0 )
        v0 = self.points[1]-self.points[0]

        for i in range(2, self.n):
             v1 = self.points[i]-self.points[0]
             n += v0.crossProd ( v1 )
             v0 = v1

        return n

    def interiorPoint(self):
        """Returns a random interior point via rejection sampling."""

        box = Box()
        for p in self.points:
            box.add(p) 

        l = box.len()
        r = lambda i: box[0][i] + random() * l[i]

        # Get a random point into the bounding box.
        # While it is not into the polygon, get another one.
        p = Point(r(0), r(1), r(2))
        while not self.contains(p):
            p = Point(r(0), r(1), r(2))

        return p

    def exteriorPoint(self):
        """Returns a random exterior point near the polygon."""

        box = Box()
        for p in self.points:
            box.add(p)

        off = lambda: 1 - 2 * random()

        l = box.len()
        r = lambda i: box[0][i] + random() * l[i] + off()

        # Get a random point outside the bounding box.
        # While it is into the polygon, get another one.
        p = Point(r(0), r(1), r(2))
        while self.contains(p):
            p = Point(r(0), r(1), r(2))

        return p

######################################################################################### 

## A triangle is a polygon with three edges and three vertices. 
#  It is one of the basic shapes in geometry. 
#  A triangle with vertices A, B, and C is denoted ??? A B C.
#
#  Three non-collinear points define a unique triangle and a unique plane.
#
class Triangle(Polygon):
    """Just a triangle, the simplest polygon possible."""

    def __init__(self, A, B, C):
        Polygon.__init__(self, [A, B, C])

    def area(self):
        """Returns triangle area."""
        A = self.points[0]
        B = self.points[1]
        C = self.points[2]
        l = (B-A).crossProd(C-A)
        return l.len() * 0.5

    def interiorPoint(self):
        """Returns a random point into triangle."""
        A = self.points[0]
        B = self.points[1]
        C = self.points[2]
        r1 = random()
        r2 = random()
        # 1 - sqrt(r1) + sqrt(r1) * (1 - r2) + r2 * sqrt(r1) = 1 (baricentric coordinates) 
        return (1 - sqrt(r1)) * A + sqrt(r1) * (1 - r2) * B + r2 * sqrt(r1) * C

######################################################################################### 

## A bounging box is the smallest rectangle, aligned with the coordinate axes,
#  which contain a given set of points. In CG, it can be used as an approximation
#  for a geometric shape.
#
class Box(object):
	"""A class for computing bounding boxes."""

	def __init__(self):
		"""Constructs an invalid bouding box."""

		## Set for lazy calculation of normalization parameters. 
		self.ready = False
		## A list with two points: the lower left corner and upper right corner of this box.
		self.bbox = []

	def __getitem__(self, ind):
		"""Indexing operator."""
		return self.bbox[ind]

	def __setitem__(self, ind, val):
		"""Indexing operator."""
		self.bbox[ind] = val
		return val

	def __str__(self):
		"Return a string representation of this box."""  
		return "%s, %s" % (self[0], self[1])

	def __cmp__(self,b):
		"""Return < 0 if self < b, 
                  > 0 if self > b,
                    0 if self = b
		"""

		raise("Undefined")

	def add(self,p):
		"""Adds a new point to the bounding box."""

		if not self.bbox:
			p1 = Point(p.x,p.y,p.z)
			p2 = Point(p.x,p.y,p.z)
			self.bbox += [p1,p2]
		else:	
			self.bbox[0].x = min(p.x,self.bbox[0].x)
			self.bbox[1].x = max(p.x,self.bbox[1].x)
			self.bbox[0].y = min(p.y,self.bbox[0].y)
			self.bbox[1].y = max(p.y,self.bbox[1].y)
			self.bbox[0].z = min(p.z,self.bbox[0].z)
			self.bbox[1].z = max(p.z,self.bbox[1].z)
		return self.bbox

	def contains(self,p):
		"""Return whether this box contains point p."""

		return self[0].x <= p.x and p.x <= self[1].x and \
               self[0].y <= p.y and p.y <= self[1].y and \
               self[0].z <= p.z and p.z <= self[1].z

	def contains2(self,p):
		"""Return whether this box contains point p."""

		return self[0].x <= p.x and p.x <= self[1].x and \
               self[0].y <= p.y and p.y <= self[1].y

	def centre(self):
		"""Return the centre of the box."""
		return 0.5*(self[0]+self[1])

	def len(self):
		"""Return the length (a vector) of the box."""	
		return self[1]-self[0]

	def outsidePosition(self):
		"""Return a point outside the box."""

		return [self.centre().x, self.centre().y, self.centre().z + 5*self.len().z, 1.0 ]

	def setParameters(self):
		"""Calculates the parameters to a normalized box."""

		## Scale factor x.
		self.sx = 1.0 / (self[1].x-self[0].x)
		## Translation factor x.
		self.tx = -self[0].x * self.sx

		## Scale factor y.
		self.sy = 1.0 / (self[1].y-self[0].y)
		## Translation factor y.
		self.ty = -self[0].y * self.sy

		return (self.sx, self.sy, self.tx, self.ty)

	def normalize(self,p):
		"""Normalize the given point."""

		#if not self.contains2(p):
		#	print("Box: %s, p: %s" % (self,p))
		#	return None

		if not self.ready:
			self.setParameters()
			self.ready = True

		return Point(p.x*self.sx + self.tx, p.y*self.sy + self.ty)
  
  
## Returns a translation matrix.
#
#  @param dx x translation.
#  @param dy y translation.
#  @param dz z translation.
#  @return translation matrix.
#
def translate(dx,dy,dz):
	M = identity()

	M[0,3] = dx
	M[1,3] = dy
	M[2,3] = dz

	return M

## Returns a scale matrix.
#
#  @param sx x scale.
#  @param sy y scale.
#  @param sz z scale.
#  @return scale matrix.
#
def scale(sx,sy,sz):
	M = identity()

	M[0,0] = sx
	M[1,1] = sy
	M[2,2] = sz

	return M

## Returns a rotation matrix.
#
#  @param ang rotation angle in degrees.
#  @param x rotation axis (x vector component).
#  @param y rotation axis (y vector component).
#  @param z rotation axis (z vector component).
#  @return rotation matrix.
#
def rotate(ang, x,y,z):
    ang = np.deg2rad(ang)
    c=cos(ang)
    s=sin(ang)
    t=1-c

    len = math.sqrt(x * x + y * y + z * z)
    len = 1 / len
    x *= len
    y *= len
    z *= len

    M = np.matrix([
        [t*x*x+c,    t*x*y-s*z,  t*x*z+s*y,  0],
        [t*x*y+s*z,  t*y*y+c,    t*y*z-s*x,  0],
        [t*x*z-s*y,  t*y*z+s*x,  t*z*z+c,    0],
        [0,  0,  0,  1],
    ])

    return M

def rotateRad(ang, x,y,z):
    c=cos(ang)
    s=sin(ang)
    t=1-c

    len = math.sqrt(x * x + y * y + z * z)
    if len == 0:
        return identity()
    len = 1 / len
    x *= len
    y *= len
    z *= len

    M = np.matrix([
        [t*x*x+c,    t*x*y-s*z,  t*x*z+s*y,  0],
        [t*x*y+s*z,  t*y*y+c,    t*y*z-s*x,  0],
        [t*x*z-s*y,  t*y*z+s*x,  t*z*z+c,    0],
        [0,  0,  0,  1],
    ])

    return M

## Returns an identity matrix.
#
#  Same as:
#    glPushMatrix()
#    glLoadIdentity()
#    c = glGetDoublev ( GL_MODELVIEW_MATRIX )
#    glPopMatrix()
#    return c
#
#  @return identity matrix.
#
def identity():
    M = np.matrix(np.identity(4))

    return M

## Matrix multiplication.
#  The matrix objects are a subclass of the numpy arrays (ndarray). 
#  The matrix objects inherit all the attributes and methods of ndarray. 
#  Another difference is that numpy matrices are strictly 2-dimensional, 
#  while numpy arrays can be of any dimension, i.e. they are n-dimensional. 
#
#  The most important advantage of matrices is that they provide convenient 
#  notations for the matrix multiplication. If X and Y are two Matrices then 
#  X * Y defines the matrix multiplication. While on the other hand, 
#  if X and Y are ndarrays, X * Y define an element by element multiplication.
#
#  If we want to perform matrix multiplication with two numpy arrays (ndarray), 
#  we have to use the dot product.
#
#  Same as:
#    glPushMatrix()
#    glLoadMatrixf(a)
#    glMultMatrixf(b)
#    c = glGetDoublev ( GL_MODELVIEW_MATRIX )
#    glPopMatrix()
#    return c
#
#  @see http://www.python-course.eu/matrix_arithmetic.php
#  @param a first matrix.
#  @param b second matrix.
#  @return a x b.
#
def dot(a,b):
	return np.dot(a,b)

## Rotate around an axis, passing through a given point.
#
#   Same as:
#     glPushMatrix()
#     glLoadIdentity()
#     glTranslate(p.x,p.y,p.z)
#     glRotate(ang, axix.x, axis.y, axis.z)
#     glTranslate(-p.x,-p.y,-p.z)
#     T = glGetDoublev ( GL_MODELVIEW_MATRIX )
#     glPopMatrix()
#     return T 
#
#   @param ang rotation angle.
#   @param p point the axix passes through.
#   @param axis rotation axis.
#   @return rotation matrix: T.R.-T
#
def translateAndRotate(ang, p, axis):
	T = translate(p.x,p.y,p.z) * \
        rotate(ang, axis.x, axis.y, axis.z) * \
        translate(-p.x,-p.y,-p.z)
	return T

## Apply a given transformation t, using p as the fixed point.
def translateAndTransform(t, p):
	T = translate(p.x,p.y,p.z) * t * translate(-p.x,-p.y,-p.z)
	return T

## Return a rotation matrix, given three angles in the order: ZYX (apply Z first, then Y, then X).
#  When the rotation is specified as rotations about three distinct 
#  axes (e.g. X-Y-Z), they should be called Tait????????Bryan angles, 
#  but the popular term is still Euler angles. Therefore, we are going 
#  to call them Euler angles as well.
#
#  The industry standard is Z-Y-X because that corresponds to yaw, pitch and roll.
#
#  Note that: @f$(XYZ)^T = Z^T(a_z)\ Y^T(a_y)\ X^T(a_x) = Z(-a_z)\ Y(-a_y)\ X(-a_x)@f$
#
#  @see http://www.chrobotics.com/library/understanding-euler-angles
#  @see https://www.learnopencv.com/rotation-matrix-to-euler-angles/
#  @param angles a list with angle x, y and z.
#  @return a matrix X * Y * Z to be applied on column vectors (vector is on the right).
#
def rotateZYX(angles):
	return rotateXYZ(angles).T

## Return a rotation matrix, given three angles in the order: XYZ (apply X first, then Y, then Z).
#
#  @see http://www.chrobotics.com/library/understanding-euler-angles
#  @param angles a list with angle x, y and z.
#  @return a matrix Z * Y * X to be applied on column vectors (vector is on the right).
#
def rotateXYZ(angles):
	rx = rotate(angles[0], 1.0, 0.0, 0.0)
	ry = rotate(angles[1], 0.0, 1.0, 0.0)
	rz = rotate(angles[2], 0.0, 0.0, 1.0)
	# rz * ry * rx
	m = dot(rz,dot(ry,rx))
	return np.asarray(m)

## Returns a rotation matrix about a given axis.
#
#  @param angle rotation angle in degrees.
#  @param axis: 0 - x, 1 - y, 2 - z
#  @return rotation matrix.
#
def getRotationMatrix(angle, axis):
	if axis == 0:
		return rotate(angle, 1.0, 0.0, 0.0)
	elif axis == 1:
		return rotate(angle, 0.0, 1.0, 0.0)
	else:
		return rotate(angle, 0.0, 0.0, 1.0)

		