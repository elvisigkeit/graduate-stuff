import subprocess
import argparse
import os.path

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
p = subprocess.call(["javac", "-encoding", "UTF-8", "Sistema.java"])
p = subprocess.call(["java", "Sistema", argumentos.arqLog, str(argumentos.nrAssentos)])

###########################################################
# A partir daqui lemos o arquivo de log

arquivo = open(argumentos.arqLog, 'r')

for linha in arquivo:
	operacao, mapa = linha.split('[')
	print (operacao)
	print (mapa)

