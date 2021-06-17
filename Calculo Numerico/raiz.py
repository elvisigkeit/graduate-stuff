def raiz_babilonica ():
	print "Insira o valor"
	valor = float(raw_input())
	r = 1
	while r*r<valor:
		r+=1
	r-=1
	for i in range (0, 5):
		r = (r+(valor/r))/2
	print "Raiz aproximada: ", r

raiz_babilonica()
raiz_babilonica()
raiz_babilonica()

