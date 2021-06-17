import time
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import nltk as nltk
import re
import keras.backend as K
from keras.models import Sequential
from keras.layers import Dense, Embedding, Lambda, Flatten

from nltk.corpus import stopwords
nltk.download('stopwords')

BC4 = pd.read_excel('BC4r.xlsx')


def clean_tokens(tokens):
  sw = set(stopwords.words('english'))
  clean = []
  for token in tokens:
    lower = token.lower()
    if lower not in sw and lower:
      clean.append(lower.upper())
  return clean


def gen_tokens_of_line(token_id, id_token, window_size, entry, prot_names, subcellular_loc, interacts_with, function_cc, polymorph, go_bio, go_cel, go_molec, domain_cc):
  words = []

  name = entry #Name
  words.append(name)

  desc = re.sub('\(|\)', '', re.sub(' [0-9].*?( |$)', '\g<1>', prot_names)) #Descriptions and names
  words = words + desc.split(' ')

  location = re.sub('\{|\}|\.', '', subcellular_loc[22:]) #Location
  words = words + location.split(' ')

  interaction = re.sub('Itself', name, re.sub(';', '', interacts_with)) #Protein interaction
  words = words + interaction.split(' ')

  function = re.sub('\,|\{|\}|\.|\(|\)', '', function_cc[10:]) #Function
  words = words +function.split(' ')

  polymorphism = re.sub('\/', ' ', re.sub('\,|\{|\}|\.|\(|\)', '', polymorph[14:])) #Polymorphism
  words = words + polymorphism.split(' ')

  gobio = re.sub('\[|\]|;', '', go_bio) #GO Bio Process
  words = words + gobio.split(' ')

  gocel = re.sub('\[|\]|;', '', go_cel) #GO Cel Component
  words = words + gocel.split(' ')

  gomolec = re.sub('\[|\]|;', '', go_molec) #GO Molec Function
  words = words + gomolec.split(' ')

  domain = re.sub('DOMAIN: |\.|;|\{|\}|\(|\)', '', domain_cc) #Domain
  words = words + domain.split(' ')

  words = clean_tokens(words)

  for word in words:
    if(token_id.get(word) is None):
      token_id[word] = len(token_id)
      id_token[len(token_id)] = word

  window_size.append(len(words))
  return words


token_id = dict()
id_token = dict()
BC4 = BC4.fillna('')
window_size = []

train_words = BC4.apply(lambda row: gen_tokens_of_line(
    token_id,
    id_token,
    window_size,
    row['Entry'], 
    row['Protein names'],
    row['Subcellular location [CC]'],
    row['Interacts with'],
    row['Function [CC]'],
    row['Polymorphism'],
    row['Gene ontology (biological process)'],
    row['Gene ontology (cellular component)'],
    row['Gene ontology (molecular function)'],
    row['Domain [CC]']
), axis=1)
      
#Getting the highest window size
window_size = sorted(window_size, reverse=True)[0]
vocab_size = len(id_token)

embed_output = 100
cbow = Sequential()
cbow.add(Embedding(input_dim=vocab_size, output_dim=embed_output, input_length=window_size))
cbow.add(Lambda(lambda x: K.mean(x, axis=1), output_shape=(embed_output,)))
cbow.add(Dense(vocab_size, activation='softmax'))
cbow.compile(loss='categorical_crossentropy', optimizer='rmsprop')


def generate_context_word(word_row, token_id, window_size):
  dimension = len(token_id)
  word_vecs = []
  for word in word_row:
    word_vecs.append(token_id[word])
    
  for i in range(len(word_vecs)):
    inp = word_vecs[:i] + word_vecs[i+1:]
    inp = np.repeat(inp, window_size/len(inp))
    fill_size = window_size - len(inp)
    if (fill_size > 0):
      inp = np.hstack((inp, inp[:fill_size]))

    out = np.zeros(dimension)
    out[word_vecs[i]] = 1.0
    yield(
        inp.reshape(1, inp.shape[0]),
        out.reshape(1, dimension)
    )


for epoch in range(0, 8):
    loss = 0.
    print('\nStarting training for', len(BC4), 'rows')
    for i in range(0, len(BC4)):
      for x, y in generate_context_word(train_words[0], token_id, window_size):
        loss += cbow.train_on_batch(x, y)
      print('Finished row', i, 'of epoch', epoch)
    print('\tLoss:', loss, '\n')
    
weights = cbow.get_weights()[0]
print(weights.shape)

word_embeddings_df = pd.DataFrame(weights, index=[id_token[key] for key in sorted(id_token, reverse=True)])
word_embeddings_df.to_csv('word_embeddings.csv')