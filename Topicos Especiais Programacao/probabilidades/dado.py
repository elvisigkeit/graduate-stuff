import numpy as np
import random
import matplotlib.pyplot as plt

n1 = 1
n2 = 1
n3 = 1
n4 = 1
n5 = 1
n6 = 1
esp_amostral = n1 + n2 + n3 + n4 + n5 + n6
numero_rodadas = 1000

print ("Dado que a distribuição do dado é:")
print (f"P(d = 1) = {n1}/{esp_amostral}")
print (f"P(d = 2) = {n2}/{esp_amostral}")
print (f"P(d = 3) = {n3}/{esp_amostral}")
print (f"P(d = 4) = {n4}/{esp_amostral}")
print (f"P(d = 5) = {n5}/{esp_amostral}")
print (f"P(d = 6) = {n6}/{esp_amostral}")

tres_iguais = np.zeros(numero_rodadas, dtype=int)
pares_iguais = np.zeros(numero_rodadas, dtype=int)

for j in range(1,numero_rodadas):  
  dados = np.random.randint(esp_amostral, size=(4))
  acumulativo = 0
  for i in range(0,4):
    if(dados[i] < n1):
        dados[i] = 1
    elif(dados[i] < n1+n2):
        dados[i] = 2
    elif(dados[i] < n1+n2+n3):
        dados[i] = 3
    elif(dados[i] < n1+n2+n3+n4):
        dados[i] = 4
    elif(dados[i] < n1+n2+n3+n4+n5):
        dados[i] = 5
    else:
        dados[i] = 6
  if(dados[0] == dados[1] == dados[2]):
      tres_iguais[j] = 1
  if(dados[0] == dados[1] and dados[2] == dados[3]):
      pares_iguais[j] = 1

print("Probabilidade de tres dados seguidos: ", np.average(tres_iguais))
print("Probabilidade de dois pares iguais", np.average(pares_iguais))

print("\nAo variar a distribuição a probabilidade se comporta desse modo: ")
print("Aumentando-se a probabilidade de um dos dados, aumenta-se ambas as probabilidades, mas a probabilidade de tres dados iguais se destaca")
print("O mesmo acontece se aumentar a probabilidade de dois dos dados")
print("Porém, se aumentam a probabilidade de 3 dados, as probabilidades vão diminuindo e se aproximando")
print("Até o momento onde as probabilidade são aumentadas igualmente, chegando à situação inicial")