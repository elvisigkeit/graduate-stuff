#!/bin/python
import subprocess
import argparse
import os.path
import time

###########################################################
# Essa parte do programa lida com os argumentos

parser = argparse.ArgumentParser(usage='''
  Usar o programa com as duas entradas
  Primeiro o nome do arquivo de log
  Segundo a quantidade de assentos
\n''')
parser.add_argument('arqLog')
parser.add_argument('nrAssentos', type=int)

argumentos = parser.parse_args()

###########################################################
# Nesse ponto ele compila e executa o código

if (not os.path.exists('Sistema.java')):
	print ("Por favor, abra esse script na pasta do trabalho, com os java's")
	quit()
#p = subprocess.call(["javac", "-encoding", "UTF-8", "Sistema.java"])
p = subprocess.call(["javac", "-encoding", "ISO-8859-1", "Sistema.java"])
open(argumentos.arqLog, 'w+')
p = subprocess.call(["java", "Sistema", argumentos.arqLog, str(argumentos.nrAssentos)])
time.sleep(1);

###########################################################
# A partir daqui lemos o arquivo de log

arquivo = open(argumentos.arqLog, 'r')

primeiro = True
mapaAnterior = ""
for linha in arquivo:
	if (linha == ""):
		continue
	operacao, mapa = linha.split('[')
	operacao = operacao.split(',')
	mapa = mapa.split(',')
	mapa[-1] = mapa[-1][0]
	if (primeiro == True):
		primeiro = False
		mapaAnterior = mapa
		continue
	if (operacao[0] == '1'):
		print("\nThread: ", operacao[1])
		print("Verificacao")
		if (mapa != mapaAnterior):
			print("ERRO!!\nVERIFICACAO NAO DEVE MUDAR")
	if (operacao[0] == '2'):
		print("\nThread: ", operacao[1])
		print("Aloca Aleatorio")
		if (mapaAnterior[int(operacao[2])-1] != '0'):
			if (mapaAnterior != mapa):
				print("ERRO!!\nNAO SE DEVE MODIFICAR LOCAL RESERVADO")
		elif (mapa[int(operacao[2])-1] != operacao[1]):
			print("ERRO!!\nTHREAD DEVERIA TER SIDO REGISTRADA")
	if (operacao[0] == '3'):
		print("\nThread: ", operacao[1])
		print("Aloca Assento")
		if (mapaAnterior[int(operacao[2])-1] != '0'):
			if (mapaAnterior != mapa):
				print("ERRO!!\nNAO SE DEVE MODIFICAR LOCAL RESERVADO")
		elif (mapa[int(operacao[2])-1] != operacao[1]):
			print("ERRO!!\nTHREAD DEVERIA TER SIDO REGISTRADA")
	if (operacao[0] == '4'):
		print("\nThread: ", operacao[1])
		print("Desaloca")
		if (mapaAnterior[int(operacao[2])-1] != operacao[1]):
			if (mapaAnterior != mapa):
				print("ERRO!!\nNAO SE DEVE MODIFICAR LOCAL NAO RESERVADO POR ELE MESMO")
		elif (mapa[int(operacao[2])-1] != '0'):
			print("ERRO!!\nASSENTO DEVERIA TER SIDO CANCELADO")
	mapaAnterior = mapa

print()
