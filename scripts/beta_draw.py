import random

f = open("beta_app.csv", "r")
drawList = dict()
userByCenter = dict()

def drawUsers(drawList):
    wonDraw = list()
    for i in range(0,200):
        if(len(drawList) == 0):
            break
        randItem = random.choice(drawList)
        wonDraw.append(randItem)
        drawList.remove(randItem)

    return wonDraw

for line in f.readlines():
    center = line.split(',')[0]
    if(center not in userByCenter.keys()):
        userByCenter[center] = 0
        drawList[center] = list()
    userByCenter[center] += 1
    drawList[center].append(line)

print("Total de alunos no domínio sorteado, por centro")
wonDraw = list()
for key in userByCenter.keys():
    if(userByCenter[key] > 15):
        print(key, " - ", userByCenter[key])
        wonDraw.append(drawUsers(drawList[key]))

f.close()

f = open("beta_app_sorteado.csv", 'w')
for center in wonDraw:
    for user in center:
        f.write(user)

f.close()