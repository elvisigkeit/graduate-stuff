import numpy as np
import random
import matplotlib.pyplot as plt

esp_amostral = 3
numero_rodadas = 500

rodadas = np.ones(numero_rodadas, dtype=int)

for j in range(1,numero_rodadas+1):
  moedas = np.random.randint(esp_amostral, size=(200))
  acumulativo = 0
  for i in range(1,199):
    if(moedas[i] != 0):
        acumulativo += 1
        if (acumulativo >= 5):
            rodadas[j-1] = i
            break

print ("Número médio até se obter cinco caras: ", np.average(rodadas))

for j in range(1,numero_rodadas+1):
  moedas = np.random.randint(esp_amostral, size=(60))
  seguido = 0
  ocorrencia = 0
  for i in range(1,59):
    if(moedas[i] == 0):
        seguido = 0
    else:
        seguido += 1
        if (seguido >= 2):
            ocorrencia += 1
            seguido = 0
            if (ocorrencia >= 2):
                rodadas[j-1] = i
                break

print ("Número médio até se obter duas caras seguidas duas vezes: ", np.average(rodadas))
      
print ("Ao variar p, a ocorrencia de duas moedas seguidas duas vezes vai ficando mais fácil, enquanto a ocorrencia de cinco moedas também aumenta, mas não tão rápido")