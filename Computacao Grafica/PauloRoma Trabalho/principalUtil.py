# -*- coding: utf-8 -*-
"""
Created on Thu Mar  9 18:06:27 2017

@author: arctos
"""
from gl.ConfigUtil import *
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
selecionado = 0

ray = Line(Point(), Point(1.0)) #starting a global picking ray

image = 0

textured = [False, False, False, False, False]
hexahedron = Hexahedron()
hexTex = {}
dodecahedron = Dodecahedron()
dodecaTex = {}
tetrahedron = Tetrahedron()
tetraTex = {}
icosahedron = Icosahedron()
icosaTex = {}
octahedron = Octahedron()
octaTex = {}


def draw():
    global angle, solidoEscolhido, selecionado

    glClearColor(0.0, 0.0, 0.0, 1.0)
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)	
    if textured[solidoEscolhido]:
        textureConfig(image)


    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
					
    glTranslated(0, 0, -window.afastamento)
    
    glMultMatrixf(g_Transform);


    if (solidoEscolhido == 0): 
        drawHexahedron(hexahedron, textured[0], hexTex)
    if (solidoEscolhido == 1): 
        drawDodecahedron(dodecahedron, textured[1], dodecaTex)
    if (solidoEscolhido == 2):
        drawTetrahedron(tetrahedron, textured[2], tetraTex)
    if (solidoEscolhido == 3):
        drawOctahedron(octahedron, textured[3], octaTex)
    if (solidoEscolhido == 4):
        drawIcosahedron(icosahedron, textured[4], icosaTex)
            

    if angle==100.0:
        angle = 1.0
    angle += 1

 
    glDisable(GL_TEXTURE_2D)
    glutSwapBuffers()
    return

def Upon_Drag (cursor_x, cursor_y):
    
    global g_isDragging, g_LastRot, g_Transform, g_ThisRot, ray

    if (g_isDragging):
        mouse_pt = Point2fT (cursor_x, cursor_y)
        ThisQuat = g_ArcBall.drag (mouse_pt)						# // Update End Vector And Get Rotation As Quaternion
        g_ThisRot = Matrix3fSetRotationFromQuat4f (ThisQuat)		# // Convert Quaternion Into Matrix3fT
        # Use correct Linear Algebra matrix multiplication C = A * B
        g_ThisRot = Matrix3fMulMatrix3f (g_LastRot, g_ThisRot)		# // Accumulate Last Rotation Into This One
        g_Transform = Matrix4fSetRotationFromMatrix3f (g_Transform, g_ThisRot)	# // Set Our Final Transform's Rotation From This One
    return

def Upon_Click (button, button_state, cursor_x, cursor_y):
    global g_isDragging, g_LastRot, g_Transform, g_ThisRot, solidoEscolhido, ray, hexahedron, dodecahedron, octahedron, tetrahedron, icosahedron
 
    
    g_isDragging = False

    if (button == GLUT_RIGHT_BUTTON and button_state == GLUT_UP):
        #reset the transformations        
        if (solidoEscolhido == 0): 
            hexahedron = Hexahedron()
        if (solidoEscolhido == 1): 
            dodecahedron = Dodecahedron()
        if (solidoEscolhido == 2):
            tetrahedron = Tetrahedron()
        if (solidoEscolhido == 3):
            octahedron = Octahedron()
        if (solidoEscolhido == 4):
            icosahedron = Icosahedron()
        
        # Right button click
        g_LastRot = Matrix3fSetIdentity ();							# // Reset Rotation
        g_ThisRot = Matrix3fSetIdentity ();							# // Reset Rotation
        g_Transform = Matrix4fSetRotationFromMatrix3f (g_Transform, g_ThisRot);	# // Reset Rotation
    elif (button == GLUT_LEFT_BUTTON and button_state == GLUT_UP):
        # Left button released
        g_LastRot = copy.copy (g_ThisRot);							# // Set Last Static Rotation To Last Dynamic One
    elif (button == GLUT_LEFT_BUTTON and button_state == GLUT_DOWN):       
        #picking ray
        ray = getPickingRay(cursor_x, cursor_y, g_Transform)
        if (solidoEscolhido == 0): 
            pick = pickFace(ray, hexahedron)
            if pick != '':
                openSolid(pick, hexahedron)
        if (solidoEscolhido == 1): 
            pick = pickFace(ray, dodecahedron)
            if pick != '':
                openSolid(pick, dodecahedron)
        if (solidoEscolhido == 2):
            pick = pickFace(ray, tetrahedron)
            if pick != '':
                openSolid(pick, tetrahedron)
        if (solidoEscolhido == 3):
            pick = pickFace(ray, octahedron)
            if pick != '':
                openSolid(pick, octahedron)
        if (solidoEscolhido == 4):
            pick = pickFace(ray, icosahedron)
            if pick != '':
                openSolid(pick, icosahedron)
        
        # Arcball
        g_LastRot = copy.copy (g_ThisRot);							# // Set Last Static Rotation To Last Dynamic One
        g_isDragging = True											# // Prepare For Dragging
        mouse_pt = Point2fT (cursor_x, cursor_y)
        g_ArcBall.click (mouse_pt);								# // Update Start Vector And Prepare For Dragging

    return



def keyboard(key, x, y):
    global solidoEscolhido, hexTex, dodecaTex, tetraTex, octaTex, icosaTex, textured
    
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
    if (key == '6'): #none
        solidoEscolhido = 5
            
    if key == 't' or key == 'T':
        if (solidoEscolhido == 0 and not textured[0]):
            hexTex = applyTexture(hexahedron)
            textured[0] = True
        else:
            textured[0] = False
            
        if (solidoEscolhido == 1 and not textured[1]):
            dodecaTex = applyTexture(dodecahedron)
            textured[1] = True
        else:
            textured[1] = False
            
        if (solidoEscolhido == 2 and not textured[2]):
            tetraTex = applyTexture(tetrahedron)
            textured[2] = True
        else:
            textured[2] = False
            
        if (solidoEscolhido == 3 and not textured[3]):
            octaTex = applyTexture(octahedron)
            textured[3] = True
        else:
            textured[3] = False
            
        if (solidoEscolhido == 4 and not textured[4]):
            icosaTex = applyTexture(icosahedron)
            textured[4] = True
        else:
            textured[4] = False
        
    if (key == '\x1b'): #exits on a escape click
        exit(0)

def main():
    global g_quadratic, image
    #configGlut()
    configGlut(1366, 768, " ", True)

    config3D()
    configLight()
    image = loadImage()

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
