import numpy as np
import random
import matplotlib.pyplot as plt

jogadores = np.ones(500, dtype=int)*100

for rodada in range(1,100):
  moedas = np.random.randint(2, size=(500*500))
  for jogada in range(1,499):
    for i in range(jogada, 500):
      moeda = moedas[i+(jogada-1)*500]
      if(jogadores[jogada-1] == 0 or jogadores[i] == 0):
        continue
      if(moeda == 0):
        jogadores[jogada-1] += 1
        jogadores[i] -= 1
      else:
        jogadores[jogada-1] -= 1
        jogadores[i] += 1
      
maximo = jogadores.max()
R = [0]*10
X = np.arange(10)

for jogador in range(0,499):
  if  (jogadores[jogador] <= maximo/10):
    R[0] += 1
  elif(jogadores[jogador] <= 2*maximo/10):
    R[1] += 1
  elif(jogadores[jogador] <= 3*maximo/10):
    R[2] += 1
  elif(jogadores[jogador] <= 4*maximo/10):
    R[3] += 1
  elif(jogadores[jogador] <= 5*maximo/10):
    R[4] += 1
  elif(jogadores[jogador] <= 6*maximo/10):
    R[5] += 1
  elif(jogadores[jogador] <= 7*maximo/10):
    R[6] += 1
  elif(jogadores[jogador] <= 8*maximo/10):
    R[7] += 1
  elif(jogadores[jogador] <= 9*maximo/10):
    R[8] += 1
  else:
    R[9] += 1
    
plt.hist(R)
plt.show()
