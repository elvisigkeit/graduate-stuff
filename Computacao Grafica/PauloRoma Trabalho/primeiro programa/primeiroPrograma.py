# -*- coding: utf-8 -*-
"""
Created on Thu Mar  9 18:06:27 2017

@author: arctos
"""

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

class Window:
    def __init__ (self, width, height = 0, name = " "):
        self.width = width
        self.height = height
        self.name = name
        self.fullscreen = (width==-1)
        self.id = 0
        
#The window is a global class that passes through all the program
window = Window(800, 600, "Primeiro programa")
    
def configGlut():
    glutInit()
    glutInitWindowPosition(20, 20)
    glutInitWindowSize(window.width, window.height)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH)
    window.id = glutCreateWindow(window.name)
    if (window.fullscreen):
        glutFullScreen(window.id)

def reshape(width, height):
    glutReshapeWindow(window.width,  window.height) #makes the screen always with his size
    return

def draw():
    print "Redesenhado"
    return
    
def keyboard(key, x, y):
    if (key == '\x1b'): #exits on a escape click
        exit(0)

def main():
    configGlut()
    
    glutReshapeFunc(reshape)
    glutKeyboardFunc(keyboard)
    glutDisplayFunc(draw)    
    
    glutMainLoop()
    return

main()
