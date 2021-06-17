# -*- coding: utf-8 -*-
"""
Created on Thu Mar  9 18:06:27 2017

@author: arctos
"""

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from gl.Vector import *

angle = 0

def genFace(nrVerts, lVector, indexes, color):
    glColor3dv(libVectors.colors[color].getVector())
    glNormal3dv(createNormal(lVector[indexes[0]], lVector[indexes[1]], lVector[indexes[2]]))
    for i in range (0, nrVerts):
        glVertex3dv(lVector[indexes[i]].getVector())


def coolRotatingCubes(cubeVectors, angle):

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(90, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cubeVectors)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(90.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cubeVectors)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(180.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cubeVectors)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(270.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cubeVectors)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(45.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cubeVectors)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(135.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cubeVectors)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(225.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cubeVectors)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(315.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cubeVectors)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(270, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cubeVectors)
    glPopMatrix()


def drawHexahedron(lVector):

    glPushMatrix()
    glTranslate(-50, -50, 50.0)
    glBegin(GL_QUADS)
    genFace(4, lVector, [0, 1, 2, 3], 0)
    genFace(4, lVector, [0, 3, 7, 4], 1)
    genFace(4, lVector, [0, 4, 5, 1], 2)
    genFace(4, lVector, [4, 7, 6, 5], 3)
    genFace(4, lVector, [5, 6, 2, 1], 4)
    genFace(4, lVector, [7, 3, 2, 6], 5)
    glEnd()
    glPopMatrix()


def drawTetrahedron(lVector):

    glBegin(GL_TRIANGLES)
    genFace(3, lVector, [1, 3, 2], 0)
    genFace(3, lVector, [1, 2, 0], 1)
    genFace(3, lVector, [3, 0, 2], 2)
    genFace(3, lVector, [0, 3, 1], 8)
    glEnd()

def drawIcosahedron(lVector):

    glBegin(GL_TRIANGLES)
    genFace(3, lVector, [6, 1, 2], 0)
    genFace(3, lVector, [2, 1, 7], 1)
    genFace(3, lVector, [5, 3, 4], 2)
    genFace(3, lVector, [8, 4, 3], 3)
    genFace(3, lVector, [11, 6, 5], 4)
    genFace(3, lVector, [10, 5, 6], 5)
    genFace(3, lVector, [2, 9, 10], 6)
    genFace(3, lVector, [3, 10, 9], 7)
    genFace(3, lVector, [9, 7, 8], 8)
    genFace(3, lVector, [0, 8, 7], 9)
    genFace(3, lVector, [1, 11, 0], 10)
    genFace(3, lVector, [4, 0, 11], 11)
    genFace(3, lVector, [10, 6, 2], 12)
    genFace(3, lVector, [11, 1, 6], 13)
    genFace(3, lVector, [10, 3, 5], 14)
    genFace(3, lVector, [11, 5, 4], 15)
    genFace(3, lVector, [9, 2, 7], 16)
    genFace(3, lVector, [0, 7, 1], 17)
    genFace(3, lVector, [8, 3, 9], 18)
    genFace(3, lVector, [0, 4, 8], 19)
    glEnd()


def drawDodecahedron (lVector):

    glBegin(GL_POLYGON)
    genFace(5, lVector, [1, 14, 11, 18, 2], 0)
    glEnd()
    glBegin(GL_POLYGON)
    genFace(5, lVector, [1, 2, 17, 7, 13], 1)
    glEnd()
    glBegin(GL_POLYGON)
    genFace(5, lVector, [3, 15, 8, 19, 4], 2)
    glEnd()
    glBegin(GL_POLYGON)
    genFace(5, lVector, [3, 4, 0, 12, 16], 3)
    glEnd()
    glBegin(GL_POLYGON)
    genFace(5, lVector, [3, 16, 5, 6, 15], 4)
    glEnd()
    glBegin(GL_POLYGON)
    genFace(5, lVector, [1, 13, 6, 5, 14], 5)
    glEnd()
    glBegin(GL_POLYGON)
    genFace(5, lVector, [2, 18, 10, 9, 17], 6)
    glEnd()
    glBegin(GL_POLYGON)
    genFace(5, lVector, [4, 19, 9, 10, 0], 7)
    glEnd()
    glBegin(GL_POLYGON)
    genFace(5, lVector, [7, 17, 9, 19, 8], 8)
    glEnd()
    glBegin(GL_POLYGON)
    genFace(5, lVector, [6, 13, 7, 8, 15], 9)
    glEnd()
    glBegin(GL_POLYGON)
    genFace(5, lVector, [5, 16, 12, 11, 14], 10)
    glEnd()
    glBegin(GL_POLYGON)
    genFace(5, lVector, [10, 18, 11, 12, 0], 11)
    glEnd()


def drawOctahedron (lVector):

    glBegin(GL_TRIANGLES)
    genFace(3, lVector, [4, 1, 0], 0)
    genFace(3, lVector, [4, 2, 1], 1)
    genFace(3, lVector, [4, 3, 2], 2)
    genFace(3, lVector, [4, 0, 3], 3)
    genFace(3, lVector, [5, 0, 1], 4)
    genFace(3, lVector, [5, 1, 2], 5)
    genFace(3, lVector, [5, 2, 3], 6)
    genFace(3, lVector, [5, 3, 0], 7)
    glEnd()

class libVectors ():
    colors = [Vector(1.0, 0.1, 1.0)]
    colors.append(Vector(1.0, 1.0, 0.15))
    colors.append(Vector(0.2, 1.0, 1.0))
    colors.append(Vector(1.0, 0.25, 1.0))
    colors.append(Vector(1.0, 1.0, 0.3))
    colors.append(Vector(0.35, 1.0, 1.0))
    colors.append(Vector(1.0, 0.4, 1.0))
    colors.append(Vector(1.0, 1.0, 0.45))
    colors.append(Vector(0.5, 1.0, 1.0))
    colors.append(Vector(1.0, 0.55, 1.0))
    colors.append(Vector(1.0, 1.0, 0.6))
    colors.append(Vector(0.65, 1.0, 1.0))
    colors.append(Vector(1.0, 0.7, 1.0))
    colors.append(Vector(1.0, 1.0, 0.75))
    colors.append(Vector(0.8, 1.0, 1.0))
    colors.append(Vector(1.0, 0.85, 1.0))
    colors.append(Vector(1.0, 1.0, 0.9))
    colors.append(Vector(0.95, 1.0, 1.0))
    colors.append(Vector(1.0, 1.0, 1.0))
    colors.append(Vector(1.0, 1.0, 0.5))

    tetraVectors = [Vector(-50.0, -50.0, -50.0)]
    tetraVectors.append(Vector(50.0, 50.0, -50.0))
    tetraVectors.append(Vector(50.0, -50.0, 50.0))
    tetraVectors.append(Vector(-50.0, 50.0, 50.0))

    cubeVectors = [Vector()]
    cubeVectors.append(Vector(0.0, 0.0, -100.0))
    cubeVectors.append(Vector(100.0, 0.0, -100.0))
    cubeVectors.append(Vector(100.0, 0.0, 0.0))
    cubeVectors.append(Vector(0.0, 100.0, 0.0))
    cubeVectors.append(Vector(0.0, 100.0, -100.0))
    cubeVectors.append(Vector(100.0, 100.0, -100.0))
    cubeVectors.append(Vector(100.0, 100.0, 0.0))

    icosaVectors = [Vector(0, -052.5731, 085.0651)]
    icosaVectors.append(Vector(085.0651, 0, 052.5731))
    icosaVectors.append(Vector(085.0651, 0, -052.5731))
    icosaVectors.append(Vector(-085.0651, 0, -052.5731))
    icosaVectors.append(Vector(-085.0651, 0, 052.5731))
    icosaVectors.append(Vector(-052.5731, 085.0651, 0))
    icosaVectors.append(Vector(052.5731, 085.0651, 0))
    icosaVectors.append(Vector(052.5731, -085.0651, 0))
    icosaVectors.append(Vector(-052.5731, -085.0651, 0))
    icosaVectors.append(Vector(0, -052.5731, -085.0651))
    icosaVectors.append(Vector(0, 052.5731, -085.0651))
    icosaVectors.append(Vector(0, 052.5731, 085.0651))

    dodecaVectors = [Vector(-057.735, -057.735, 057.735)]
    dodecaVectors.append(Vector(093.4172, 035.6822, 0))
    dodecaVectors.append(Vector(093.4172, -035.6822, 0))
    dodecaVectors.append(Vector(-093.4172, 035.6822, 0))
    dodecaVectors.append(Vector(-093.4172, -035.6822, 0))
    dodecaVectors.append(Vector(0, 093.4172, 035.6822))
    dodecaVectors.append(Vector(0, 093.4172, -035.6822))
    dodecaVectors.append(Vector(035.6822, 0, -093.4172))
    dodecaVectors.append(Vector(-035.6822, 0, -093.4172))
    dodecaVectors.append(Vector(0, -093.4172, -035.6822))
    dodecaVectors.append(Vector(0, -093.4172, 035.6822))
    dodecaVectors.append(Vector(035.6822, 0, 093.4172))
    dodecaVectors.append(Vector(-035.6822, 0, 093.4172))
    dodecaVectors.append(Vector(057.735, 057.735, -057.735))
    dodecaVectors.append(Vector(057.735, 057.735, 057.735))
    dodecaVectors.append(Vector(-057.735, 057.735, -057.735))
    dodecaVectors.append(Vector(-057.735, 057.735, 057.735))
    dodecaVectors.append(Vector(057.735, -057.735, -057.735))
    dodecaVectors.append(Vector(057.735, -057.735, 057.735))
    dodecaVectors.append(Vector(-057.735, -057.735, -057.735))

    octaVectors = [Vector(100, 0, 0)]
    octaVectors.append(Vector(0, -100, 0))
    octaVectors.append(Vector(-100, 0, 0))
    octaVectors.append(Vector(0, 100, 0))
    octaVectors.append(Vector(0, 0, 100))
    octaVectors.append(Vector(0, 0, -100))

class Window:
    def __init__ (self, width = 800.0, height = 600.0, name = " ", fullscreen = False):
        self.width = width
        self.height = height
        self.name = name
        self.fullscreen = fullscreen
        self.id = 0
        self.ratio = width/height
        if self.ratio == 0:
            self.ratio = 1

#The window is a global class that passes through all the program
window = Window()

def config3D():
    glLoadIdentity()
    glViewport(0, 0, window.width, window.height)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(60.0, window.ratio, 1, 1000)


def config2D():
    glViewport(0, 0, window.width, window.height)

    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(0, window.width, 0, window.height, -300, 300)
    return

def configGlut(width = 800, height = 600, name = " ", fullscreen = False):
    window.width = width
    window.height = height
    window.name = name
    window.fullscreen = fullscreen
    window.ratio = width*1.0/height

    glutInit()
    glutInitWindowPosition(20, 20)
    glutInitWindowSize(window.width, window.height)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH)
    window.id = glutCreateWindow(window.name)
    if (window.fullscreen):
        glutFullScreen()

def colorToFace (color, solidoEscolhido):
    result = 0

    if ((color-1.88627)<0.0001 and (color-1.88627)>-0.0001):
        result = 0
    if ((color-1.92941)<0.0001 and (color-1.92941)>-0.0001):
        result = 1
    if ((color-1.97647)<0.0001 and (color-1.97647)>-0.0001):
        result = 2
    if ((color-2.01961)<0.0001 and (color-2.01961)>-0.0001):
        result = 3
    if ((color-2.06667)<0.0001 and (color-2.06667)>-0.0001):
        result = 4
    if ((color-2.1098)<0.0001 and (color-2.1098)>-0.0001):
        result = 5

    if ((color-2.24706)<0.0001 and (color-2.24706)>-0.0001):
        result = 8

    if solidoEscolhido == 0:
        if result == 0:
            return 'a'
        if result == 1:
            return 'b'
        if result == 2:
            return 'c'
        if result == 3:
            return 'd'
        if result == 4:
            return 'e'
        if result == 5:
            return 'f'

    if solidoEscolhido == 2:
        if result == 0:
            return 'a'
        if result == 1:
            return 'b'
        if result == 2:
            return 'c'
        if result == 8:
            return 'd'

class Tetrahedron:
    def __init__(self):
        self.a = Face('a', 3, 0)
        self.b = Face('b', 3, 1)
        self.c = Face('c', 3, 2)
        self.d = Face('d', 3, 8)
        self.a.defineVertices(libVectors.tetraVectors, [1, 3, 2])
        self.b.defineVertices(libVectors.tetraVectors, [1, 2, 0])
        self.c.defineVertices(libVectors.tetraVectors, [3, 0, 2])
        self.d.defineVertices(libVectors.tetraVectors, [0, 3, 1])
        self.faces = {'a': self.a, 'b': self.b, 'c': self.c, 'd': self.d}
        self.graph = {'a': ['b', 'c', 'd'],
                      'b': ['a', 'c', 'd'],
                      'c': ['a', 'b', 'd'],
                      'd': ['a', 'b', 'c']}

    def drawOpen(self, center):
        normal = self.faces[center].normal
        crossNormal = Vector(normal[0], normal[1], normal[2])*Vector(0.0, 0.0, 1.0)
        average = Vector()
        for i in range(0, self.faces[center].nrVerts):
            average = average + self.faces[center].vertices[i]
        average.x = average.x/3
        average.y = average.y/3
        average.z = average.z/3

        glBegin(GL_TRIANGLES)
        glColor3dv(libVectors.colors[self.faces[center].color].getVector())
        glNormal3dv(self.faces[center].normal)
        self.faces[center].getVertices()
        glEnd()

        for a in self.graph[self.faces[center].label]:
            newNormal = self.faces[a].normal
            crossNormal = Vector(normal[0], normal[1], normal[2])*Vector(newNormal[0], newNormal[1], newNormal[2])

            averageA = Vector()
            for i in range(0, self.faces[a].nrVerts):
                averageA = averageA + self.faces[a].vertices[i]

            diff = average-averageA

            glPushMatrix()
            glTranslated(-diff.x+(normal[0]*58), -diff.y+(normal[1]*58), -diff.z+(normal[2]*58))
            glRotated(250, crossNormal.x, crossNormal.y, crossNormal.z)
            glBegin(GL_TRIANGLES)
            glColor3dv(libVectors.colors[self.faces[a].color].getVector())
            glNormal3dv(self.faces[a].normal)
            self.faces[a].getVertices()
            glEnd()

            glPopMatrix()


class Hexahedron:
    def __init__(self):
        self.a = Face('a', 4, 0)
        self.b = Face('b', 4, 1)
        self.c = Face('c', 4, 2)
        self.d = Face('d', 4, 3)
        self.e = Face('e', 4, 4)
        self.f = Face('f', 4, 5)
        self.a.defineVertices(libVectors.cubeVectors, [0, 1, 2, 3])
        self.b.defineVertices(libVectors.cubeVectors, [0, 3, 7, 4])
        self.c.defineVertices(libVectors.cubeVectors, [0, 4, 5, 1])
        self.d.defineVertices(libVectors.cubeVectors, [4, 7, 6, 5])
        self.e.defineVertices(libVectors.cubeVectors, [5, 6, 2, 1])
        self.f.defineVertices(libVectors.cubeVectors, [7, 3, 2, 6])
        self.faces = {'a': self.a, 'b': self.b, 'c': self.c, 'd': self.d, 'e': self.e, 'f': self.f}
        self.graph = {'a': ['b', 'c', 'e', 'f'],
                      'b': ['a', 'c', 'd', 'f'],
                      'c': ['a', 'b', 'd', 'e'],
                      'd': ['b', 'c', 'e', 'f'],
                      'e': ['a', 'c', 'd', 'f'],
                      'f': ['a', 'b', 'd', 'e']}

    def drawOpen(self, center):
        passed = {self.faces[center].label}
        normal = self.faces[center].normal
        crossNormal = Vector(normal[0], normal[1], normal[2])*Vector(0.0, 0.0, 1.0)
        average = Vector()
        for i in range(0, self.faces[center].nrVerts):
            average = average + self.faces[center].vertices[i]
        average.x = average.x/4
        average.y = average.y/4
        average.z = average.z/4

        glTranslate(-50, -50, 50.0)

        glBegin(GL_QUADS)
        glColor3dv(libVectors.colors[self.faces[center].color].getVector())
        glNormal3dv(self.faces[center].normal)
        self.faces[center].getVertices()
        glEnd()

        for a in self.graph[self.faces[center].label]:
            passed.add(self.faces[a].label)
            newNormal = self.faces[a].normal
            crossNormal = Vector(normal[0], normal[1], normal[2])*Vector(newNormal[0], newNormal[1], newNormal[2])

            averageA = Vector()
            for i in range(0, self.faces[a].nrVerts):
                averageA = averageA + self.faces[a].vertices[i]
            averageA.x /= 4
            averageA.y /= 4
            averageA.z /= 4

            diff = average-averageA

            glPushMatrix()
            glTranslated(-diff.x+(normal[0]*100), -diff.y+(normal[1]*100), -diff.z+(normal[2]*100))
            glTranslate(50, 50, -50.0)
            glTranslated(newNormal[0]*(50), newNormal[1]*(50), newNormal[2]*(50))
            glRotated(-90, crossNormal.x, crossNormal.y, crossNormal.z)
            glTranslated(newNormal[0]*(-50), newNormal[1]*(-50), newNormal[2]*(-50))
            glTranslate(-50, -50, 50.0)
            glBegin(GL_QUADS)
            glColor3dv(libVectors.colors[self.faces[a].color].getVector())
            glNormal3dv(self.faces[a].normal)
            self.faces[a].getVertices()
            glEnd()

            glPopMatrix()

        for a in self.graph[self.faces[center].label]:
            for b in self.graph[self.faces[a].label]:
                if self.faces[b].label in passed:
                    continue
                normal = self.faces[b].normal
                crossNormal = Vector(normal[0], normal[1], normal[2])*Vector(0.0, 0.0, 1.0)
                if crossNormal.x < 0.01 and crossNormal.y < 0.01 and crossNormal.z < 0.01:
                    crossNormal = Vector(0.0, 1.0, 0.0)
                if center == 'd':
                    crossNormal = Vector(0.0, 0.0, 1.0)

                glPushMatrix()
                glTranslated(200*crossNormal.x, 200*crossNormal.y, 200*crossNormal.z)
                glTranslated(-100*normal[0], -100*normal[1], -100*normal[2])

                glBegin(GL_QUADS)
                glColor3dv(libVectors.colors[self.faces[b].color].getVector())
                glNormal3dv(self.faces[b].normal)
                self.faces[b].getVertices()
                glEnd()
                glPopMatrix()

class Dodecahedron:
    def __init__(self):
        self.a = Face('a', 5, 0)
        self.b = Face('b', 5, 1)
        self.c = Face('c', 5, 2)
        self.d = Face('d', 5, 3)
        self.e = Face('e', 5, 4)
        self.f = Face('f', 5, 5)
        self.g = Face('g', 5, 6)
        self.h = Face('h', 5, 7)
        self.i = Face('i', 5, 8)
        self.j = Face('j', 5, 9)
        self.k = Face('k', 5, 10)
        self.l = Face('l', 5, 11)
        self.a.defineVertices(libVectors.dodecaVectors, [1, 14, 11, 18, 2])
        self.b.defineVertices(libVectors.dodecaVectors, [1, 2, 17, 7, 13])
        self.c.defineVertices(libVectors.dodecaVectors, [3, 15, 8, 19, 4])
        self.d.defineVertices(libVectors.dodecaVectors, [3, 4, 0, 12, 16])
        self.e.defineVertices(libVectors.dodecaVectors, [3, 16, 5, 6, 15])
        self.f.defineVertices(libVectors.dodecaVectors, [1, 13, 6, 5, 14])
        self.g.defineVertices(libVectors.dodecaVectors, [2, 18, 10, 9, 17])
        self.h.defineVertices(libVectors.dodecaVectors, [4, 19, 9, 10, 0])
        self.i.defineVertices(libVectors.dodecaVectors, [7, 17, 9, 19, 8])
        self.j.defineVertices(libVectors.dodecaVectors, [6, 13, 7, 8, 15])
        self.k.defineVertices(libVectors.dodecaVectors, [5, 16, 12, 11, 14])
        self.l.defineVertices(libVectors.dodecaVectors, [10, 18, 11, 12, 0])
        self.faces = {'a': self.a, 'b': self.b, 'c': self.c, 'd': self.d, 'e': self.e, 'f': self.f,
                      'g': self.g, 'h': self.h, 'i': self.i, 'j': self.j, 'k': self.k, 'l': self.l}
        self.graph = {'a': ['b', 'f', 'k', 'l', 'g'],
                      'b': ['f', 'j', 'a', 'i', ''],
                      'c': ['b', 'i', 'j', 'e', 'd'],
                      'd': ['c', 'e', 'k', 'l', 'h'],
                      'e': ['h', 'c', 'j', 'k', 'd'],
                      'f': ['a', 'b', 'j', 'k', 'g'],
                      'g': ['f', 'a', 'l', 'i', 'h'],
                      'h': ['l', 'g', 'd', 'i', 'e'],
                      'i': ['j', 'h', 'g', 'c', 'b'],
                      'j': ['i', 'b', 'c', 'e', 'f'],
                      'k': ['a', 'e', 'd', 'f', 'l'],
                      'l': ['a', 'k', 'd', 'h', 'g']}


    def drawOpen(self, center, angle):
        passed = {self.faces[center].label}
        normal = self.faces[center].normal
        crossNormal = Vector(normal[0], normal[1], normal[2])*Vector(0.0, 0.0, 1.0)
        average = Vector()
        for i in range(0, self.faces[center].nrVerts):
            average = average + self.faces[center].vertices[i]
        average.x = average.x/5
        average.y = average.y/5
        average.z = average.z/5

        glBegin(GL_POLYGON)
        glColor3dv(libVectors.colors[self.faces[center].color].getVector())
        glNormal3dv(self.faces[center].normal)
        self.faces[center].getVertices()
        glEnd()

        for a in self.graph[self.faces[center].label]:
            passed.add(self.faces[a].label)
            newNormal = self.faces[a].normal
            crossNormal = Vector(normal[0], normal[1], normal[2])*Vector(newNormal[0], newNormal[1], newNormal[2])

            averageA = Vector()
            for i in range(0, self.faces[a].nrVerts):
                averageA = averageA + self.faces[a].vertices[i]
            averageA.x /= 5
            averageA.y /= 5
            averageA.z /= 5

            diff = average-averageA

            glPushMatrix()
            glTranslated(-diff.x+(normal[0]*62), -diff.y+(normal[1]*62), -diff.z+(normal[2]*62))
            glTranslated(newNormal[0]*(31), newNormal[1]*(31), newNormal[2]*(31))
            glRotated(-64.7, crossNormal.x, crossNormal.y, crossNormal.z)
            glTranslated(newNormal[0]*(-31), newNormal[1]*(-31), newNormal[2]*(-31))
            glBegin(GL_POLYGON)
            glColor3dv(libVectors.colors[self.faces[a].color].getVector())
            glNormal3dv(self.faces[a].normal)
            self.faces[a].getVertices()
            glEnd()

            glPopMatrix()

        for a in self.graph[self.faces[center].label]:
            averageA = Vector()
            for i in range(0, self.faces[a].nrVerts):
                averageA = averageA + self.faces[a].vertices[i]
            averageA.x /= 5
            averageA.y /= 5
            averageA.z /= 5
            
            for b in self.graph[self.faces[a].label]:
                if self.faces[b].label in passed:
                    continue
                averageB = Vector()
                for i in range(0, self.faces[b].nrVerts):
                    averageB = averageB + self.faces[b].vertices[i]
                averageB.x /= 5
                averageB.y /= 5
                averageB.z /= 5

                diff = averageA-averageB

                normal = self.faces[b].normal
                crossNormal = Vector(normal[0], normal[1], normal[2])*Vector(0.0, 0.0, 1.0)
                if crossNormal.x < 0.01 and crossNormal.y < 0.01 and crossNormal.z < 0.01:
                    crossNormal = Vector(0.0, 1.0, 0.0)


                glPushMatrix()
                glTranslated(-diff.x+(normal[0]*62), -diff.y+(normal[1]*62), -diff.z+(normal[2]*62))
                glTranslated(newNormal[0]*(angle), newNormal[1]*(angle), newNormal[2]*(angle))
                glRotated(-100.7, crossNormal.x, crossNormal.y, crossNormal.z)
                glTranslated(newNormal[0]*(-angle), newNormal[1]*(-angle), newNormal[2]*(-angle))

                glBegin(GL_POLYGON)
                glColor3dv(libVectors.colors[self.faces[b].color].getVector())
                glNormal3dv(self.faces[b].normal)
                self.faces[b].getVertices()
                glEnd()
                glPopMatrix()

class Icosahedron:
    def __init__(self):
        self.a = Face('a', 3, 0)
        self.b = Face('b', 3, 1)
        self.c = Face('c', 3, 2)
        self.d = Face('d', 3, 3)
        self.e = Face('e', 3, 4)
        self.f = Face('f', 3, 5)
        self.g = Face('g', 3, 6)
        self.h = Face('h', 3, 7)
        self.i = Face('i', 3, 8)
        self.j = Face('j', 3, 9)
        self.k = Face('k', 3, 10)
        self.l = Face('l', 3, 11)
        self.faces = {'a': self.a, 'b': self.b, 'c': self.c, 'd': self.d, 'e': self.e, 'f': self.f,
                      'g': self.g, 'h': self.h, 'i': self.i, 'j': self.j, 'k': self.k, 'l': self.l}
        self.graph = {'a': ['b', 'c', 'e', 'f'],
                      'b': ['a', 'c', 'd', 'f'],
                      'c': ['a', 'b', 'd', 'e'],
                      'd': ['b', 'c', 'e', 'f'],
                      'e': ['a', 'c', 'd', 'f'],
                      'f': ['a', 'b', 'd', 'e']}


class Face:
    def __init__(self, label, nrVerts, color):
        self.label = label
        self.nrVerts = nrVerts
        self.vertices = []
        self.normal = []
        self.color = color

    def defineVertices (self, lVector, indexes):
        for i in range (0, self.nrVerts):
            self.vertices.append(lVector[indexes[i]])
        self.normal = createNormal(self.vertices[0], self.vertices[1], self.vertices[2])

    def getVertices (self):
        for i in range (0, self.nrVerts):
            glVertex3dv(self.vertices[i].getVector())

    def __repr__(self):
        return self.label

    def __str__(self):
        return (self.label)

    def __eq__ (self, other):
        return self.label == other.label

    def __hash__ (self):
        return hash(self.label)
