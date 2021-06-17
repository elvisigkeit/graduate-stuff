# -*- coding: utf-8 -*-
"""
Created on Thu Mar  9 18:06:27 2017

@author: arctos
"""

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from geoUtil import *
try:
    from PIL.Image import open
except ImportError as err:
    from Image import open

angle = 0


def coolRotatingCubes(angle):

    cube = Hexahedron()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(90, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cube)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(90.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cube)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(180.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cube)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(270.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cube)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(45.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cube)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(135.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cube)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(225.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cube)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(315.0, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cube)
    glPopMatrix()

    glPushMatrix()
    glTranslated(0.0, 0.0, -300.0)
    glRotated(270, 0.0, 0.0, -1.0)
    glRotated(angle, 1.0, 1.0, -1.0)
    drawHexahedron(cube)
    glPopMatrix()


def drawHexahedron(hexahedron, textured, hexTex):

    glPushMatrix()
    glBegin(GL_QUADS)
    if textured:
        genFace(hexahedron.faces['a'], textured, hexTex['a'])
        genFace(hexahedron.faces['b'], textured, hexTex['b'])
        genFace(hexahedron.faces['c'], textured, hexTex['c'])
        genFace(hexahedron.faces['d'], textured, hexTex['d'])
        genFace(hexahedron.faces['e'], textured, hexTex['e'])
        genFace(hexahedron.faces['f'], textured, hexTex['f'])
    else:
        genFace(hexahedron.faces['a'], textured)
        genFace(hexahedron.faces['b'], textured)
        genFace(hexahedron.faces['c'], textured)
        genFace(hexahedron.faces['d'], textured)
        genFace(hexahedron.faces['e'], textured)
        genFace(hexahedron.faces['f'], textured)
    glEnd()
    glPopMatrix()


def drawTetrahedron(tetrahedron, textured, tetraTex):

    glBegin(GL_TRIANGLES)
    if textured:
        genFace(tetrahedron.faces['a'], textured, tetraTex['a'])
        genFace(tetrahedron.faces['b'], textured, tetraTex['b'])
        genFace(tetrahedron.faces['c'], textured, tetraTex['c'])
        genFace(tetrahedron.faces['d'], textured, tetraTex['d'])
    else:

        genFace(tetrahedron.faces['a'], textured)
        genFace(tetrahedron.faces['b'], textured)
        genFace(tetrahedron.faces['c'], textured)
        genFace(tetrahedron.faces['d'], textured)
    glEnd()

def drawIcosahedron(icosahedron, textured, icosaTex):

    glBegin(GL_TRIANGLES)
    if textured:
        genFace(icosahedron.faces['a'], textured, icosaTex['a'])
        genFace(icosahedron.faces['b'], textured, icosaTex['b'])
        genFace(icosahedron.faces['c'], textured, icosaTex['c'])
        genFace(icosahedron.faces['d'], textured, icosaTex['d'])
        genFace(icosahedron.faces['e'], textured, icosaTex['e'])
        genFace(icosahedron.faces['f'], textured, icosaTex['f'])
        genFace(icosahedron.faces['g'], textured, icosaTex['g'])
        genFace(icosahedron.faces['h'], textured, icosaTex['h'])
        genFace(icosahedron.faces['i'], textured, icosaTex['i'])
        genFace(icosahedron.faces['j'], textured, icosaTex['j'])
        genFace(icosahedron.faces['k'], textured, icosaTex['k'])
        genFace(icosahedron.faces['l'], textured, icosaTex['l'])
        genFace(icosahedron.faces['m'], textured, icosaTex['m'])
        genFace(icosahedron.faces['n'], textured, icosaTex['n'])
        genFace(icosahedron.faces['o'], textured, icosaTex['o'])
        genFace(icosahedron.faces['p'], textured, icosaTex['p'])
        genFace(icosahedron.faces['q'], textured, icosaTex['q'])
        genFace(icosahedron.faces['r'], textured, icosaTex['r'])
        genFace(icosahedron.faces['s'], textured, icosaTex['s'])
        genFace(icosahedron.faces['t'], textured, icosaTex['t'])
    else:
        genFace(icosahedron.faces['a'])
        genFace(icosahedron.faces['b'])
        genFace(icosahedron.faces['c'])
        genFace(icosahedron.faces['d'])
        genFace(icosahedron.faces['e'])
        genFace(icosahedron.faces['f'])
        genFace(icosahedron.faces['g'])
        genFace(icosahedron.faces['h'])
        genFace(icosahedron.faces['i'])
        genFace(icosahedron.faces['j'])
        genFace(icosahedron.faces['k'])
        genFace(icosahedron.faces['l'])
        genFace(icosahedron.faces['m'])
        genFace(icosahedron.faces['n'])
        genFace(icosahedron.faces['o'])
        genFace(icosahedron.faces['p'])
        genFace(icosahedron.faces['q'])
        genFace(icosahedron.faces['r'])
        genFace(icosahedron.faces['s'])
        genFace(icosahedron.faces['t'])
    glEnd()


def drawDodecahedron (dodecahedron, textured, dodecaTex):

    if textured:
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['a'], textured, dodecaTex['a'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['b'], textured, dodecaTex['b'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['c'], textured, dodecaTex['c'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['d'], textured, dodecaTex['d'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['e'], textured, dodecaTex['e'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['f'], textured, dodecaTex['f'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['g'], textured, dodecaTex['g'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['h'], textured, dodecaTex['h'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['i'], textured, dodecaTex['i'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['j'], textured, dodecaTex['j'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['k'], textured, dodecaTex['k'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['l'], textured, dodecaTex['l'])
        glEnd()
    else:
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['a'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['b'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['c'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['d'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['e'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['f'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['g'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['h'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['i'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['j'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['k'])
        glEnd()
        glBegin(GL_POLYGON)
        genFace(dodecahedron.faces['l'])
        glEnd()


def drawOctahedron (octahedron, textured, octaTex):

    glBegin(GL_TRIANGLES)
    if textured:
        genFace(octahedron.faces['a'], textured, octaTex['a'])
        genFace(octahedron.faces['b'], textured, octaTex['b'])
        genFace(octahedron.faces['c'], textured, octaTex['c'])
        genFace(octahedron.faces['d'], textured, octaTex['d'])
        genFace(octahedron.faces['e'], textured, octaTex['e'])
        genFace(octahedron.faces['f'], textured, octaTex['f'])
        genFace(octahedron.faces['g'], textured, octaTex['g'])
        genFace(octahedron.faces['h'], textured, octaTex['h'])
    else:
        genFace(octahedron.faces['a'])
        genFace(octahedron.faces['b'])
        genFace(octahedron.faces['c'])
        genFace(octahedron.faces['d'])
        genFace(octahedron.faces['e'])
        genFace(octahedron.faces['f'])
        genFace(octahedron.faces['g'])
        genFace(octahedron.faces['h'])
    glEnd()

def drawPickingRay (ray):

    glLineWidth(2.5)
    glColor3f(1.0, 0.0, 0.0)
    glBegin(GL_LINES)
    glVertex3f(0.0,0.0,499)  #500 is the translation of the scene
    glVertex3fv((1000*ray).getV())
    glEnd()

class lib ():
    colors = [Point(1.0, 0.1, 1.0)]
    colors.append(Point(1.0, 1.0, 0.15))
    colors.append(Point(0.2, 1.0, 1.0))
    colors.append(Point(1.0, 0.25, 1.0))
    colors.append(Point(1.0, 1.0, 0.3))
    colors.append(Point(0.35, 1.0, 1.0))
    colors.append(Point(1.0, 0.4, 1.0))
    colors.append(Point(1.0, 1.0, 0.45))
    colors.append(Point(0.5, 1.0, 1.0))
    colors.append(Point(1.0, 0.55, 1.0))
    colors.append(Point(1.0, 1.0, 0.6))
    colors.append(Point(0.65, 1.0, 1.0))
    colors.append(Point(1.0, 0.7, 1.0))
    colors.append(Point(1.0, 1.0, 0.75))
    colors.append(Point(0.8, 1.0, 1.0))
    colors.append(Point(1.0, 0.85, 1.0))
    colors.append(Point(1.0, 1.0, 0.9))
    colors.append(Point(0.95, 1.0, 1.0))
    colors.append(Point(1.0, 1.0, 1.0))
    colors.append(Point(1.0, 1.0, 0.5))

    tetra = [Point(-50.0, -50.0, -50.0)]
    tetra.append(Point(50.0, 50.0, -50.0))
    tetra.append(Point(50.0, -50.0, 50.0))
    tetra.append(Point(-50.0, 50.0, 50.0))

    cube = [Point(-50.0, -50.0, 50.0)]
    cube.append(Point(-50.0, -50.0, -50.0))
    cube.append(Point(50.0, -50.0, -50.0))
    cube.append(Point(50.0, -50.0, 50.0))
    cube.append(Point(-50.0, 50.0, 50.0))
    cube.append(Point(-50.0, 50.0, -50.0))
    cube.append(Point(50.0, 50.0, -50.0))
    cube.append(Point(50.0, 50.0, 50.0))

    icosa = [Point(0, -052.5731, 085.0651)]
    icosa.append(Point(085.0651, 0, 052.5731))
    icosa.append(Point(085.0651, 0, -052.5731))
    icosa.append(Point(-085.0651, 0, -052.5731))
    icosa.append(Point(-085.0651, 0, 052.5731))
    icosa.append(Point(-052.5731, 085.0651, 0))
    icosa.append(Point(052.5731, 085.0651, 0))
    icosa.append(Point(052.5731, -085.0651, 0))
    icosa.append(Point(-052.5731, -085.0651, 0))
    icosa.append(Point(0, -052.5731, -085.0651))
    icosa.append(Point(0, 052.5731, -085.0651))
    icosa.append(Point(0, 052.5731, 085.0651))

    dodeca = [Point(-057.735, -057.735, 057.735)]
    dodeca.append(Point(093.4172, 035.6822, 0))
    dodeca.append(Point(093.4172, -035.6822, 0))
    dodeca.append(Point(-093.4172, 035.6822, 0))
    dodeca.append(Point(-093.4172, -035.6822, 0))
    dodeca.append(Point(0, 093.4172, 035.6822))
    dodeca.append(Point(0, 093.4172, -035.6822))
    dodeca.append(Point(035.6822, 0, -093.4172))
    dodeca.append(Point(-035.6822, 0, -093.4172))
    dodeca.append(Point(0, -093.4172, -035.6822))
    dodeca.append(Point(0, -093.4172, 035.6822))
    dodeca.append(Point(035.6822, 0, 093.4172))
    dodeca.append(Point(-035.6822, 0, 093.4172))
    dodeca.append(Point(057.735, 057.735, -057.735))
    dodeca.append(Point(057.735, 057.735, 057.735))
    dodeca.append(Point(-057.735, 057.735, -057.735))
    dodeca.append(Point(-057.735, 057.735, 057.735))
    dodeca.append(Point(057.735, -057.735, -057.735))
    dodeca.append(Point(057.735, -057.735, 057.735))
    dodeca.append(Point(-057.735, -057.735, -057.735))

    octa = [Point(100, 0, 0)]
    octa.append(Point(0, -100, 0))
    octa.append(Point(-100, 0, 0))
    octa.append(Point(0, 100, 0))
    octa.append(Point(0, 0, 100))
    octa.append(Point(0, 0, -100))

class Window:
    def __init__ (self, width = 800.0, height = 600.0, name = " ", fullscreen = False):
        self.width = width
        self.height = height
        self.name = name
        self.fullscreen = fullscreen
        self.id = 0
        self.ratio = width/height
        self.fovy = 60.0
        self.zNear = 1
        self.zFar = 1000
        self.afastamento = 500
        if self.ratio == 0:
            self.ratio = 1

#The window is a global class that passes through all the program
window = Window()

def loadImage(imageName = "image.png" ):
		"""Load an image file as a 2D texture using PIL"""

		# PIL defines an "open" method which is Image specific!
		im = open(imageName)
		try:
			ix, iy, image = im.size[0], im.size[1], im.tobytes("raw", "RGBA", 0, -1)
		except (SystemError, ValueError):
			ix, iy, image = im.size[0], im.size[1], im.tobytes("raw", "RGBX", 0, -1)
		except AttributeError:
			ix, iy, image = im.size[0], im.size[1], im.tostring("raw", "RGBX", 0, -1)

		# Generate a texture ID
		ID = glGenTextures(1)

		# Make our new texture ID the current 2D texture
		glBindTexture(GL_TEXTURE_2D, ID)
		glPixelStorei(GL_UNPACK_ALIGNMENT,1)

		# Copy the texture data into the current texture ID
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ix, iy, 0, GL_RGBA, GL_UNSIGNED_BYTE, image)

		# Note that only the ID is returned, no reference to the image object or the
		# string data is stored in user space.
		# The data is only present within the GL after this call exits.
		return ID

def textureConfig(image):
    """Render-time texture environment setup"""
    glEnable(GL_TEXTURE_2D)

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST)

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL)
    glBindTexture(GL_TEXTURE_2D, image)

def configLight():

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

def config3D():
    glLoadIdentity()
    glViewport(0, 0, window.width, window.height)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(window.fovy, window.ratio, window.zNear, window.zFar)


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

def getPickingRay(x, y, g_Transform):
    posX = float(x-(window.width/2))/(window.width/2)  #Position Normalized x
    posY = float((window.height/2)-y)/(window.height/2)#Position Normalized y
    clipHeight = tan(radians(window.fovy/2))*window.zNear
    pointRayOri = Point(0.0, 0.0, window.afastamento)
    pointRayDir = Point(posX*clipHeight*window.ratio, clipHeight*posY, -window.zNear+window.afastamento)
    aux = np.array(pointRayOri.get4V()).dot(g_Transform.transpose())
    pointRayOri = Point (aux[0], aux[1], aux[2])
    aux = np.array(pointRayDir.get4V()).dot(g_Transform.transpose())
    pointRayDir = Point (aux[0], aux[1], aux[2])
    return Line(pointRayOri, pointRayDir)

def pickFace(ray, solid, start=None, result=None, seen=None):
    if start is None:
        start = 'a'
    if result is None:
        result = ''
    if seen is None:
        seen = set([])

    if start in seen:
        return result
    seen.add(start)
    crossingPoint = (solid.faces[start]).doesLineCrossPolygon(ray)
    for node in solid.graph[start]:
        result = pickFace(ray, solid, node, result, seen)
    if start == 'a':
        seen.clear()
    if crossingPoint[0]:
        if (ray.p1.dotProd(solid.faces[start].normal) > 0):
            result = start

    solid.facePicked = result

    return result

def translateSolid(solid, translation, start=None, seen=None):
    if start is None:
        start = 'a'
    if seen is None:
        seen = set([])

    if start in seen:
        return
    seen.add(start)

    solid.faces[start].multMatrix(translate(translation[0], translation[1], translation[2]).transpose())

    for node in solid.graph[start]:
        translateSolid(solid, translation, node, seen)

def rotateSolid(solid, rotation, start=None, seen=None):
    if start is None:
        start = 'a'
    if seen is None:
        seen = set([])

    if start in seen:
        return
    seen.add(start)

    solid.faces[start].multMatrix(rotation)

    for node in solid.graph[start]:
        rotateSolid(solid, rotation, node, seen)

def getMaxMin(solid, limits=None, start=None, seen=None):
    if start is None:
        start = 'a'
    if seen is None:
        seen = set([])
    if limits is None:
        limits = [[1000, 1000], [-1000, -1000]]

    if start in seen:
        return
    seen.add(start)

    for point in solid.faces[start].points:
        if point[0] < limits[0][0]:
            limits[0][0] = point[0]
        if point[1] < limits[0][1]:
            limits[0][1] = point[1]
        if point[0] > limits[1][0]:
            limits[1][0] = point[0]
        if point[1] > limits[1][1]:
            limits[1][1] = point[1]

    for node in solid.graph[start]:
        getMaxMin(solid, limits, node, seen)

    return limits

def getMapTexture(solid, minimum, size, start=None, seen=None):
    if start is None:
        start = 'a'
    if seen is None:
        seen = set([])

    texMap = {}
    texMap[start] = []
    if start in seen:
        return
    seen.add(start)

    for point in solid.faces[start].points:
        aux = [point[0], point[1]]
        aux[0]+=abs(minimum[0])
        aux[1]+=abs(minimum[1])
        aux[0]/=size[0]
        aux[1]/=size[1]
        texMap[start].append(aux)

    for node in solid.graph[start]:
        nodeMap = getMapTexture(solid, minimum, size, node, seen)
        if nodeMap is None:
            continue
        texMap.update(nodeMap)

    return texMap

def getEdges(start, solid):
    seen = set([start])
    toSee = [start]
    mapFacesEdges = {start: Point()}

    while (len(toSee)>0):
        for face in solid.graph[toSee[0]]:
            if face in seen:
                continue
            seen.add(face)
            toSee.append(face)
            equalEdge = getAvgEqualEdge(solid.faces[toSee[0]], solid.faces[face])
            if equalEdge != None:
                mapFacesEdges[face] = equalEdge
        toSee.remove(toSee[0])

    return mapFacesEdges

def openSolid(face, solid):
    if solid.open:
        
        return
    solid.open = True


    #Translate the center of the picked face to zero
    average = solid.faces[face].avgPoint()
    translateSolid(solid, ((-1)*average))

    #Gets the correspondence of edge
    faceMap = getEdges(face, solid)


    #Transforms the polygon according to the faces
    seen = set([face])
    toSee = [face]

    mapTransform = {face: identity()}
    while (len(toSee)>0):

        for adj in solid.graph[toSee[0]]:
            if adj in seen:
                continue
            seen.add(adj)
            toSee.append(adj)
            #First translation
            translation = faceMap[adj]
            transMatrix = translate(-translation[0], -translation[1], -translation[2]).transpose()
            solid.faces[adj].latterNormal = solid.faces[adj].normal
            solid.faces[adj].multMatrix(transMatrix)
            mapTransform[adj] = transMatrix

            #and then rotation
            cross = solid.faces[adj].normal.crossProd(solid.faces[toSee[0]].latterNormal)

            rotationMatrix = rotateRad(-solid.angle, cross[0], cross[1], cross[2])
            solid.faces[adj].multMatrix(rotationMatrix)
            mapTransform[adj] *= rotationMatrix

            #finally turning the face to his position
            transMatrix = translate(translation[0], translation[1], translation[2]).transpose()
            solid.faces[adj].multMatrix(transMatrix)
            mapTransform[adj] *= transMatrix


            solid.faces[adj].multMatrix(mapTransform[toSee[0]])
            mapTransform[adj] *= mapTransform[toSee[0]]

        toSee.remove(toSee[0])

def applyTexture(solid):
    #First rotates the solid to get in the plane XY
    cross = solid.faces[solid.facePicked].normal.crossProd(Point(0.0,0.0,1.0))
    dot = solid.faces[solid.facePicked].normal.dotProd(Point(0.0,0.0,1.0))
    angle = -acos(dot)

    rotation = rotateRad(angle, cross[0], cross[1], cross[2])

    rotateSolid(solid, rotation)

    #And then mappes the points according to the domain of the texture
    limits = getMaxMin(solid)

    sizeBox = [abs(limits[0][0])+abs(limits[1][0]), abs(limits[0][1])+abs(limits[1][1])]

    return getMapTexture(solid, limits[0], sizeBox)


def getAvgEqualEdge(face1, face2):
    points = []
    for pointA in face1.points:
        for pointB in face2.points:
            if pointA==pointB:
                points.append(pointA)
    if len(points)!=2:
        return None
    sumPoint = points[0]+points[1]

    return sumPoint/2

class Hexahedron:
    def __init__(self):
        self.open = False
        self.angle = pi/2
        self.facePicked = ''
        self.a = Face('a', 0, [lib.cube[0], lib.cube[1], lib.cube[2], lib.cube[3]])
        self.b = Face('b', 1, [lib.cube[0], lib.cube[3], lib.cube[7], lib.cube[4]])
        self.c = Face('c', 2, [lib.cube[0], lib.cube[4], lib.cube[5], lib.cube[1]])
        self.d = Face('d', 3, [lib.cube[4], lib.cube[7], lib.cube[6], lib.cube[5]])
        self.e = Face('e', 4, [lib.cube[5], lib.cube[6], lib.cube[2], lib.cube[1]])
        self.f = Face('f', 5, [lib.cube[7], lib.cube[3], lib.cube[2], lib.cube[6]])
        self.faces = {'a': self.a, 'b': self.b, 'c': self.c, 'd': self.d, 'e': self.e, 'f': self.f}
        self.graph = {'a': ['b', 'c', 'e', 'f'],
                      'b': ['a', 'c', 'd', 'f'],
                      'c': ['a', 'b', 'd', 'e'],
                      'd': ['b', 'c', 'e', 'f'],
                      'e': ['a', 'c', 'd', 'f'],
                      'f': ['a', 'b', 'd', 'e']}

class Octahedron:
    def __init__(self):
         self.open = False
         self.angle = acos((1.0/3.0))
         self.facePicked = ''
         self.a = Face('a', 0, [lib.octa[4], lib.octa[1], lib.octa[0]])
         self.b = Face('b', 1, [lib.octa[4], lib.octa[2], lib.octa[1]])
         self.c = Face('c', 2, [lib.octa[4], lib.octa[3], lib.octa[2]])
         self.d = Face('d', 3, [lib.octa[4], lib.octa[0], lib.octa[3]])
         self.e = Face('e', 4, [lib.octa[5], lib.octa[0], lib.octa[1]])
         self.f = Face('f', 5, [lib.octa[5], lib.octa[1], lib.octa[2]])
         self.g = Face('g', 6, [lib.octa[5], lib.octa[2], lib.octa[3]])
         self.h = Face('h', 7, [lib.octa[5], lib.octa[3], lib.octa[0]])
         self.faces = {'a': self.a, 'b': self.b, 'c': self.c, 'd': self.d,
                      'e': self.e, 'f': self.f, 'g': self.g, 'h': self.h}
         self.graph = {'a': ['b', 'd', 'e'],
                       'b': ['a', 'c', 'f'],
                       'c': ['b', 'd', 'g'],
                       'd': ['a', 'c', 'h'],
                       'e': ['a', 'f', 'h'],
                       'f': ['b', 'e', 'g'],
                       'g': ['h', 'c', 'f'],
                       'h': ['g', 'd', 'e']}

class Icosahedron:
    def __init__(self):
         self.open = False
         self.angle = acos(sqrt(5)/3)
         self.facePicked = ''
         self.a = Face('a', 0, [lib.icosa[6], lib.icosa[1], lib.icosa[2]])
         self.b = Face('b', 1, [lib.icosa[2], lib.icosa[1], lib.icosa[7]])
         self.c = Face('c', 2, [lib.icosa[5], lib.icosa[3], lib.icosa[4]])
         self.d = Face('d', 3, [lib.icosa[8], lib.icosa[4], lib.icosa[3]])
         self.e = Face('e', 4, [lib.icosa[11], lib.icosa[6], lib.icosa[5]])
         self.f = Face('f', 5, [lib.icosa[10], lib.icosa[5], lib.icosa[6]])
         self.g = Face('g', 6, [lib.icosa[2], lib.icosa[9], lib.icosa[10]])
         self.h = Face('h', 7, [lib.icosa[3], lib.icosa[10], lib.icosa[9]])
         self.i = Face('i', 8, [lib.icosa[9], lib.icosa[7], lib.icosa[8]])
         self.j = Face('j', 9, [lib.icosa[0], lib.icosa[8], lib.icosa[7]])
         self.k = Face('k', 10, [lib.icosa[1], lib.icosa[11], lib.icosa[0]])
         self.l = Face('l', 11, [lib.icosa[4], lib.icosa[0], lib.icosa[11]])
         self.m = Face('m', 12, [lib.icosa[10], lib.icosa[6], lib.icosa[2]])
         self.n = Face('n', 13, [lib.icosa[11], lib.icosa[1], lib.icosa[6]])
         self.o = Face('o', 14, [lib.icosa[10], lib.icosa[3], lib.icosa[5]])
         self.p = Face('p', 15, [lib.icosa[11], lib.icosa[5], lib.icosa[4]])
         self.q = Face('q', 16, [lib.icosa[9], lib.icosa[2], lib.icosa[7]])
         self.r = Face('r', 17, [lib.icosa[0], lib.icosa[7], lib.icosa[1]])
         self.s = Face('s', 18, [lib.icosa[8], lib.icosa[3], lib.icosa[9]])
         self.t = Face('t', 19, [lib.icosa[0], lib.icosa[4], lib.icosa[8]])
         self.faces = {'a': self.a, 'b': self.b, 'c': self.c, 'd': self.d, 'e': self.e, 'f': self.f,
                       'g': self.g, 'h': self.h, 'i': self.i, 'j': self.j, 'k': self.k, 'l': self.l,
                       'm': self.m, 'n': self.n, 'o': self.o, 'p': self.p, 'q': self.q, 'r': self.r,
                       's': self.s, 't': self.t}
         self.graph = {'a': ['b', 'm', 'n'],
                       'b': ['a', 'q', 'r'],
                       'c': ['o', 'p', 'd'],
                       'd': ['c', 's', 't'],
                       'e': ['f', 'p', 'n'],
                       'f': ['e', 'm', 'o'],
                       'g': ['h', 'q', 'm'],
                       'h': ['g', 'o', 's'],
                       'i': ['j', 's', 'q'],
                       'j': ['i', 'r', 't'],
                       'k': ['l', 'n', 'r'],
                       'l': ['k', 'p', 't'],
                       'm': ['a', 'f', 'g'],
                       'n': ['a', 'e', 'k'],
                       'o': ['c', 'f', 'h'],
                       'p': ['c', 'e', 'l'],
                       'q': ['b', 'g', 'i'],
                       'r': ['b', 'j', 'k'],
                       's': ['d', 'h', 'i'],
                       't': ['d', 'j', 'l']}

class Tetrahedron:
    def __init__(self):
         self.open = False
         self.angle = pi-acos((1.0/3.0))
         self.facePicked = ''
         self.a = Face('a', 0, [lib.tetra[1], lib.tetra[3], lib.tetra[2]])
         self.b = Face('b', 1, [lib.tetra[1], lib.tetra[2], lib.tetra[0]])
         self.c = Face('c', 2, [lib.tetra[3], lib.tetra[0], lib.tetra[2]])
         self.d = Face('d', 8, [lib.tetra[0], lib.tetra[3], lib.tetra[1]])
         self.faces = {'a': self.a, 'b': self.b, 'c': self.c, 'd': self.d}
         self.graph = {'a': ['b', 'c', 'd'],
                       'b': ['a', 'c', 'd'],
                       'c': ['a', 'b', 'd'],
                       'd': ['a', 'b', 'c']}


class Dodecahedron:
    def __init__(self):
         self.open = False
         self.angle = atan(2)
         self.facePicked = ''
         self.a = Face('a', 0, [lib.dodeca[1], lib.dodeca[14], lib.dodeca[11], lib.dodeca[18], lib.dodeca[2]])
         self.b = Face('b', 1, [lib.dodeca[1], lib.dodeca[2], lib.dodeca[17], lib.dodeca[7], lib.dodeca[13]])
         self.c = Face('c', 2, [lib.dodeca[3], lib.dodeca[15], lib.dodeca[8], lib.dodeca[19], lib.dodeca[4]])
         self.d = Face('d', 3, [lib.dodeca[3], lib.dodeca[4], lib.dodeca[0], lib.dodeca[12], lib.dodeca[16]])
         self.e = Face('e', 4, [lib.dodeca[3], lib.dodeca[16], lib.dodeca[5], lib.dodeca[6], lib.dodeca[15]])
         self.f = Face('f', 5, [lib.dodeca[1], lib.dodeca[13], lib.dodeca[6], lib.dodeca[5], lib.dodeca[14]])
         self.g = Face('g', 6, [lib.dodeca[2], lib.dodeca[18], lib.dodeca[10], lib.dodeca[9], lib.dodeca[17]])
         self.h = Face('h', 7, [lib.dodeca[4], lib.dodeca[19], lib.dodeca[9], lib.dodeca[10], lib.dodeca[0]])
         self.i = Face('i', 8, [lib.dodeca[7], lib.dodeca[17], lib.dodeca[9], lib.dodeca[19], lib.dodeca[8]])
         self.j = Face('j', 9, [lib.dodeca[6], lib.dodeca[13], lib.dodeca[7], lib.dodeca[8], lib.dodeca[15]])
         self.k = Face('k', 10, [lib.dodeca[5], lib.dodeca[16], lib.dodeca[12], lib.dodeca[11], lib.dodeca[14]])
         self.l = Face('l', 11, [lib.dodeca[10], lib.dodeca[18], lib.dodeca[11], lib.dodeca[12], lib.dodeca[0]])
         self.faces = {'a': self.a, 'b': self.b, 'c': self.c, 'd': self.d, 'e': self.e, 'f': self.f,
                       'g': self.g, 'h': self.h, 'i': self.i, 'j': self.j, 'k': self.k, 'l': self.l}
         self.graph = {'a': ['b', 'f', 'k', 'l', 'g'],
                       'b': ['f', 'j', 'a', 'i', 'g'],
                       'c': ['h', 'i', 'j', 'e', 'd'],
                       'd': ['c', 'e', 'k', 'l', 'h'],
                       'e': ['f', 'c', 'j', 'k', 'd'],
                       'f': ['a', 'b', 'j', 'k', 'e'],
                       'g': ['b', 'a', 'l', 'i', 'h'],
                       'h': ['l', 'g', 'd', 'i', 'c'],
                       'i': ['j', 'h', 'g', 'c', 'b'],
                       'j': ['i', 'b', 'c', 'e', 'f'],
                       'k': ['a', 'e', 'd', 'f', 'l'],
                       'l': ['a', 'k', 'd', 'h', 'g']}

class Face(Polygon):
    def __init__(self, label, color, points):
        self.label = label
        self.colorLabel = color
        self.color = lib.colors[color]
        Polygon.__init__(self, points)
        self.latterNormal = self.normal

    def returnFace(self):
        return Face(self.label, self.colorLabel, self.points)

    def multMatrix(self, matrix):
        newPoints = []
        for point in self.points:
            vec = np.array(point.get4V()).dot(matrix)
            newPoints.append(Point(vec[0,0], vec[0,1], vec[0,2]))
        self.points = newPoints
        self.normal = self.compNormal().normalize()

    def avgPoint(self):
        nrPoints = 0
        sumP = Point()
        for point in self.points:
             sumP = sumP+point
             nrPoints+=1
        return sumP/nrPoints


def genFace(face, textured=False, tex=None):
    glColor3dv(face.color.getV())
    glNormal3dv(face.normal.getV())
    for i in range (0, face.n):
        if textured:
            glTexCoord2f(tex[i][0], tex[i][1])
        glVertex3dv(face.points[i].getV())
