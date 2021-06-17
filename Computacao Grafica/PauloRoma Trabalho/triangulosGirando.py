# -*- coding: utf-8 -*-
"""
Created on Thu Mar  9 18:06:27 2017

@author: arctos
"""
from gl.Config import *


def reshape(width, height):
    if window.fullscreen:
        return
    glutReshapeWindow(window.width,  window.height) #makes the screen always with his size
    return

angle = 0.0

def draw():
    global angle
    glClearColor(1.0, 1.0, 1.0, 1.0)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    
    glMatrixMode(GL_MODELVIEW)   
    glLoadIdentity()     
 
    glEnable(GL_DEPTH_TEST) 
    
 
    """
    glTranslated(400.0, 10.0, 0.0)
    #glRotated(angle, 0.0, 0.0, 1.0)
    
    glBegin(GL_LINE_LOOP)               
    glColor3d(1.0, 0.0, 0.0)    
    glVertex2d( -100.0, 0.0)    
    glVertex2d( 100.0,  0.0)    
    glVertex2d( 0.0,  173.2)
    glEnd()
    glPopMatrix()
    """
    
    glTranslated(-100, -100, -300)    
    #glRotated(-30, 0.0, 1.0, 0.0)
    
    glPushMatrix()             
    #glTranslated(500.0, 100.0, 0.0)
    glRotated(angle, 1.0, 1.0, 0.0)
    
    glBegin(GL_TRIANGLES)               
    glColor3d(0.0, 0.0, 1.0)    
    glVertex3d( 10.0,  10.0, 0.0)
    glVertex3d( 200.0,  100.0, 0.0)
    glVertex3d( 100.0,  200.0, 100.0)
    glEnd()
    glPopMatrix()
    
    glPushMatrix()             
    #glTranslated(500.0, 100.0, 0.0)
    glRotated(angle, 1.0, 1.0, 0.0)
    
    glBegin(GL_TRIANGLES)               
    glColor3d(0.0, 1.0, 0.0)    
    glVertex3d( 10.0,  10.0, 0.0)
    glVertex3d( 100.0,  200.0, -100.0)
    glVertex3d( 100.0,  200.0, 100.0)
    glEnd()
    glPopMatrix()
    
    glPushMatrix()             
    #glTranslated(400.0, 300.0, 0.0)
    glRotated(angle, 1.0, 1.0, 0.0)
    
    glBegin(GL_TRIANGLES)               
    glColor3d(1.0, 0.0, 0.0)    
    glVertex3d( 10.0,  10.0, 0.0)
    glVertex3d( 100.0,  200.0, -100.0)
    glVertex3d( 200.0,  100.0, 0.0)
    glEnd()
    glPopMatrix()
   
   
    if angle > 360:
        angle = 0.0
    angle += 1.0    
     
    config3D()
    glutSwapBuffers()
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
