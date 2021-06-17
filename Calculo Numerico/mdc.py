def euclidiano ():
	print "Insira o primeiro nr:"
	a = int(raw_input())
	print "Insira o segundo nr:"
	b = int(raw_input())

	temp = a % b
	if temp == 0:
		a = b
	b = temp
	while b!=0:
		temp = b
		b = a % b
		a = temp

	print "O MDC eh: ", a

euclidiano()
euclidiano()
