# -*- coding: utf-8 -*-
"""
Created on Thu Mar  9 18:06:27 2017

@author: arctos
"""
from gl.Config import *
from gl.ArcBall import *

def reshape(width, height):
    if window.fullscreen:
        return
    glutReshapeWindow(window.width,  window.height) #makes the screen always with his size
    return

try:
	True
except NameError:
	True = 1==1

g_Transform = Matrix4fT ()
g_LastRot = Matrix3fT ()
g_ThisRot = Matrix3fT ()

g_ArcBall = ArcBallT (640, 480)
g_isDragging = False
g_quadratic = None
 
solidoEscolhido = 0
faceSelecionada = 'a'
corPickada = ''
selecionado = 0

tetrahedron = Tetrahedron()
hexahedron = Hexahedron()
dodecahedron = Dodecahedron()


def draw():
    global angle, solidoEscolhido, selecionado

    glClearColor(0.0, 0.0, 0.0, 1.0)
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)	
    glShadeModel (GL_FLAT);	
    glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST)

#    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, [0.9, 0.9, 0.9])

    glEnable(GL_DEPTH_TEST)
    glEnable(GL_COLOR_MATERIAL)
    glEnable(GL_LIGHTING)
    glEnable(GL_LIGHT0)
    glEnable(GL_COLOR_MATERIAL)    
    
    ambientLight = [0.1, 0.1, 0.1, 1.0]
    diffuseLight = [0.9, 0.9, 0.9, 1.0]
    specularLight = [0.5, 0.5, 0.5, 1.0]

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);


    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
					
    glTranslated(0, 0, -600)
    
    if (selecionado == 0):
        glMultMatrixf(g_Transform);

    if (solidoEscolhido == 0): 
        if (selecionado == 0):
            drawHexahedron(libVectors.cubeVectors)
        else:
            hexahedron.drawOpen(faceSelecionada);
    if (solidoEscolhido == 1): 
        if (selecionado == 0):
            drawDodecahedron(libVectors.dodecaVectors)
        else:
            dodecahedron.drawOpen('k', angle)
    if (solidoEscolhido == 2): 
        if (selecionado == 0):
            drawTetrahedron(libVectors.tetraVectors)
        else:
            tetrahedron.drawOpen(faceSelecionada)
    if (solidoEscolhido == 3): 
        if (selecionado == 0):
            drawOctahedron(libVectors.octaVectors)
    if (solidoEscolhido == 4): 
        if (selecionado == 0):
            drawIcosahedron(libVectors.icosaVectors)

    if angle==100.0:
        angle = 1.0
    angle += 1

 
    glutSwapBuffers()
    return

def Upon_Drag (cursor_x, cursor_y):
    
	global g_isDragging, g_LastRot, g_Transform, g_ThisRot

	if (g_isDragging):
		mouse_pt = Point2fT (cursor_x, cursor_y)
		ThisQuat = g_ArcBall.drag (mouse_pt)						# // Update End Vector And Get Rotation As Quaternion
		g_ThisRot = Matrix3fSetRotationFromQuat4f (ThisQuat)		# // Convert Quaternion Into Matrix3fT
		# Use correct Linear Algebra matrix multiplication C = A * B
		g_ThisRot = Matrix3fMulMatrix3f (g_LastRot, g_ThisRot)		# // Accumulate Last Rotation Into This One
		g_Transform = Matrix4fSetRotationFromMatrix3f (g_Transform, g_ThisRot)	# // Set Our Final Transform's Rotation From This One
	return

def Upon_Click (button, button_state, cursor_x, cursor_y):
    
    global g_isDragging, g_LastRot, g_Transform, g_ThisRot, corPickada, selecionado, solidoEscolhido, faceSelecionada
        
    g_isDragging = False
     
    if (button == GLUT_LEFT_BUTTON and button_state == GLUT_DOWN):
        glFlush()
        corPickada = glReadPixels(cursor_x, cursor_y, 1, 1, GL_RGB, GL_FLOAT)
        corPickada = corPickada[0][0][0]+corPickada[0][0][1]+corPickada[0][0][2]
        print corPickada
        if (selecionado == 0 and corPickada>0):            
            selecionado = 1
            faceSelecionada = colorToFace(corPickada, solidoEscolhido)
        else:
            selecionado = 0

    if (button == GLUT_RIGHT_BUTTON and button_state == GLUT_UP):
        # Right button click
        g_LastRot = Matrix3fSetIdentity ();							# // Reset Rotation
        g_ThisRot = Matrix3fSetIdentity ();							# // Reset Rotation
        g_Transform = Matrix4fSetRotationFromMatrix3f (g_Transform, g_ThisRot);	# // Reset Rotation
    elif (button == GLUT_LEFT_BUTTON and button_state == GLUT_UP):
        # Left button released
        g_LastRot = copy.copy (g_ThisRot);							# // Set Last Static Rotation To Last Dynamic One
    elif (button == GLUT_LEFT_BUTTON and button_state == GLUT_DOWN):
        # Left button clicked down
        g_LastRot = copy.copy (g_ThisRot);							# // Set Last Static Rotation To Last Dynamic One
        g_isDragging = True											# // Prepare For Dragging
        mouse_pt = Point2fT (cursor_x, cursor_y)
        g_ArcBall.click (mouse_pt);								# // Update Start Vector And Prepare For Dragging

    return



def keyboard(key, x, y):
    global solidoEscolhido
    
    if (key == '1'): #cube
        solidoEscolhido = 0
    if (key == '2'): #dodecahedron
        solidoEscolhido = 1
    if (key == '3'): #tetrahedron
        solidoEscolhido = 2
    if (key == '4'): #octahedron
        solidoEscolhido = 3
    if (key == '5'): #icosahedron
        solidoEscolhido = 4
        
    if (key == '\x1b'): #exits on a escape click
        exit(0)

def main():
    global g_quadratic
    #configGlut()
    configGlut(1366, 768, " ", True)

    config3D()

    g_quadratic = gluNewQuadric();
    gluQuadricNormals(g_quadratic, GLU_SMOOTH);
    gluQuadricDrawStyle(g_quadratic, GLU_FILL);    
    g_ArcBall.setBounds (1366, 768)	
    glutMouseFunc (Upon_Click)
    glutMotionFunc (Upon_Drag)
 
    glutReshapeFunc(reshape)
    glutKeyboardFunc(keyboard)
    glutDisplayFunc(draw)
    glutIdleFunc(draw)

    glutMainLoop()
    return

main()
