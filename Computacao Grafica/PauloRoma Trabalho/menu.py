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

def responsivePolyMenu ():
    positionY = window.height/4
    sHeight = window.height/8
    tHeight = window.height/100
    thirdWidth = window.width/3
    tenthWidth = window.width/10

    glLineWidth(3.0)

    glPushMatrix()               
    glBegin(GL_LINE_LOOP)               
    glColor3d(1.0, 1.0, 1.0) 
    glVertex2d( thirdWidth+tenthWidth, positionY-sHeight-tHeight )    
    glVertex2d( thirdWidth, positionY-sHeight )    
    glVertex2d( thirdWidth, positionY+sHeight )    
    glVertex2d( thirdWidth+tenthWidth, positionY+sHeight+tHeight )
    glVertex2d( window.width-thirdWidth-tenthWidth, positionY+sHeight+tHeight )
    glVertex2d( window.width-thirdWidth, positionY+sHeight )
    glVertex2d( window.width-thirdWidth, positionY-sHeight )    
    glVertex2d( window.width-thirdWidth-tenthWidth, positionY-sHeight-tHeight )
    glEnd()
    glPopMatrix()
        
    glPushMatrix()               
    glBegin(GL_POLYGON)               
    glColor4d(1.0, 1.0, 1.0, 0.2) 
    glVertex2d( thirdWidth+tenthWidth, selectedY-(sHeight/4)-tHeight )    
    glVertex2d( thirdWidth, selectedY-(sHeight/4) )    
    glVertex2d( thirdWidth, selectedY+(sHeight/4) )    
    glVertex2d( thirdWidth+tenthWidth, selectedY+(sHeight/4)+tHeight )
    glVertex2d( window.width-thirdWidth-tenthWidth, selectedY+(sHeight/4)+tHeight )
    glVertex2d( window.width-thirdWidth, selectedY+(sHeight/4) )
    glVertex2d( window.width-thirdWidth, selectedY-(sHeight/4) )    
    glVertex2d( window.width-thirdWidth-tenthWidth, selectedY-(sHeight/4)-tHeight )
    glEnd()
    glPopMatrix()
    
    return
    
def menuOptions():    
    positionYOption = window.height/4
    positionXOption = window.width/2 - 30
    selectedY = positionYOption+8
    
    
    glPushMatrix()
    glColor3d(1.0, 1.0, 1.0)
    glRasterPos2i(positionXOption, positionYOption);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ord('D'))
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ord('r'))
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ord('a'))
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ord('w'))
    glPopMatrix()    
        
    glPushMatrix()
    glColor3d(1.0, 1.0, 1.0)
    glRasterPos2i(positionXOption, positionYOption-10);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ord('Q'))
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ord('u'))
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ord('i'))
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ord('t'))
    glPopMatrix()   
    
    return

def drawTitle():
    auxLine = [10.0, 20.0, 30.0, 45.0]
    letter = 20.0
    space = -4.0

    #FUNCOES QUE IMPORTAM EM FUNCOES SEGUINTES
    glLineWidth(4.0)
    glColor3d(1, 1, 1)
    
    glEnable(GL_LINE_SMOOTH)
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST)
    
    glShadeModel(GL_FLAT)
    
    glPushMatrix()   
    
    glTranslated(0.0, window.height*0.58, 0.0)
    glScaled(window.ratio*3.95, window.ratio*3.95, 0)
    
    #P
    glTranslated(window.width*0.028, 0.0, 0.0)
    glBegin(GL_LINE_STRIP)
    glVertex2d(0.0, 0.0)
    glVertex2d(0.0, auxLine[3])
    glVertex2d(letter, auxLine[2])
    glVertex2d(0.0, auxLine[1])
    glEnd()
    
    #o
    glTranslated(letter+2*space, 0.0, 0.0)
    glBegin(GL_LINE_LOOP)
    glVertex2d(letter/2, 0.0)
    glVertex2d(0.0, auxLine[0])
    glVertex2d(letter/2, auxLine[1])
    glVertex2d(letter, auxLine[0])
    glEnd()
    
    #l
    glTranslated(letter, 0.0, 0.0)
    glBegin(GL_LINE_STRIP)
    glVertex2d(0.0, 0.0)
    glVertex2d(0.0, auxLine[2])
    glEnd()
    
    #y
    glTranslated(letter/3+space, 0.0, 0.0)
    glBegin(GL_LINE_STRIP)
    glVertex2d(0.0, 0.0)
    glVertex2d(letter/2, auxLine[1])
    glColor4d(1.0, 1.0, 1.0, 0.0)
    glVertex2d(0.0, auxLine[1])
    glColor4d(1.0, 1.0, 1.0, 1.0)
    glVertex2d(letter/4, auxLine[0])
    glEnd()
    
    #D
    glTranslated(letter+space, 0.0, 0.0)
    glBegin(GL_LINE_LOOP)
    glVertex2d(0.0, 0.0)
    glVertex2d(0.0, auxLine[3])
    glVertex2d(letter, auxLine[3]/2)
    glEnd()
    
    #r
    glTranslated(letter, 0.0, 0.0)
    glBegin(GL_LINE_STRIP)
    glVertex2d(0.0, 0.0)
    glVertex2d(0.0, auxLine[1])
    glVertex2d(0.0, auxLine[0])
    glVertex2d(letter/3, auxLine[1])
    glEnd()
    
    #a
    glTranslated(letter/3+space, 0.0, 0.0)
    glBegin(GL_LINE_STRIP)
    glVertex2d(0.0, 0.0)
    glVertex2d(letter/2, auxLine[1])
    glVertex2d(letter, 0.0)
    glColor4d(1.0, 1.0, 1.0, 0.0)
    glVertex2d(letter/4, auxLine[0])
    glColor4d(1.0, 1.0, 1.0, 1.0)
    glVertex2d(3*letter/4, auxLine[0])
    glEnd()
    
    #w
    glTranslated(letter+space, 0.0, 0.0)
    glBegin(GL_LINE_STRIP)
    glVertex2d(0.0, auxLine[1])
    glVertex2d(letter/3, 0.0)
    glVertex2d(letter/2, auxLine[0])
    glVertex2d(2*letter/3, 0.0)
    glVertex2d(letter, auxLine[1])
    glEnd()
    
    glPopMatrix()
    
    return
    
def drawOptions(): 
    auxLine = [10.0, 20.0, 30.0, 45.0]
    letter = 20.0
    space = -4.0

    glLineWidth(2.0)
    #ADMITE-SE QUE ESTÁ DEFINIDO EM DRAW MENU
    #TODAS AS VARIAVEIS DE LARGURA DA LINHA
    #DE GL_FLAT ETC
    glPushMatrix()   
    
    glTranslated(0.0, window.height*0.35, 0.0)
    glScaled(window.ratio*1.0, window.ratio*1.0, 0)
    
    
    #D
    glTranslated(letter+space+window.width/4.5, 0.0, 0.0)
    glBegin(GL_LINE_LOOP)
    glVertex2d(0.0, 0.0)
    glVertex2d(0.0, auxLine[2])
    glVertex2d(letter, auxLine[2]/2)
    glEnd()
    
    #r
    glTranslated(letter, 0.0, 0.0)
    glBegin(GL_LINE_STRIP)
    glVertex2d(0.0, 0.0)
    glVertex2d(0.0, auxLine[1])
    glVertex2d(0.0, auxLine[0])
    glVertex2d(letter/3, auxLine[1])
    glEnd()
    
    #a
    glTranslated(letter/3+space, 0.0, 0.0)
    glBegin(GL_LINE_STRIP)
    glVertex2d(0.0, 0.0)
    glVertex2d(letter/2, auxLine[1])
    glVertex2d(letter, 0.0)
    glColor4d(1.0, 1.0, 1.0, 0.0)
    glVertex2d(letter/4, auxLine[0])
    glColor4d(1.0, 1.0, 1.0, 1.0)
    glVertex2d(3*letter/4, auxLine[0])
    glEnd()
    
    #w
    glTranslated(letter+space, 0.0, 0.0)
    glBegin(GL_LINE_STRIP)
    glVertex2d(0.0, auxLine[1])
    glVertex2d(letter/3, 0.0)
    glVertex2d(letter/2, auxLine[0])
    glVertex2d(2*letter/3, 0.0)
    glVertex2d(letter, auxLine[1])
    glEnd()
    
    glPopMatrix()

    return
    
def draw(): 
    
    glClearColor(0.0, 0.0, 0.0, 1.0)
    glClear(GL_COLOR_BUFFER_BIT)
    glEnable(GL_BLEND)
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
    
    glMatrixMode(GL_MODELVIEW)   
    glLoadIdentity()
            
    glPushMatrix()
    drawTitle()
    drawOptions()
    glPopMatrix()
    
    glutSwapBuffers()
    return
    
def keyboard(key, x, y):
    if (key == '\x1b'): #exits on a escape click
        exit(0)

def mouse(button, state, x, y):
    if state == GLUT_DOWN:
        print "Posicao ", x, " ", y, " do botao", button
    
def main():
    configGlut()
    configGlut(1366, 768, " ", True)
    
    config2D()
    glutMouseFunc(mouse)
    glutReshapeFunc(reshape)
    glutKeyboardFunc(keyboard)
    glutDisplayFunc(draw)    
    glutIdleFunc(draw)
    
    glutMainLoop()
    return

main()
