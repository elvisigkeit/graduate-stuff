def getNameAndNumber(line):
	if (len(line) < 10):
		return '\n'
	lineSplit = line.split("alt=\"")
	parsing = lineSplit[1].split("\"")
	number = parsing[-1].split("<")
	number[0] = number[0].split(">")
	return parsing[0], number[0][1]

arq = open("saite")
listOfNames = []
for line in arq:
	listOfNames.append(getNameAndNumber(line))

arq = open("250 Melhores Filmes", "a")
for this in listOfNames:
	if (len(this) > 1):
		arq.write(this[1])
		if(int(this[1]) < 10):
			arq.write("   - ")
		elif(int(this[1]) < 100):
			arq.write("  - ")
		else:
			arq.write("  - ")
		arq.write(this[0])
		arq.write("\n")
