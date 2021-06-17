import pandas as pd
import numpy as np

vectorscomp = dict()
vectorsprot = dict()
dotprot = dict()
BC2 = pd.read_excel('Data/BC2r.xlsx')
BC2WE = pd.read_csv('Data/BC2_word_embeddings.csv')


def one_hot_encoding_of_length(length):
    out = []
    values = list(dotprot.keys())
    labels = []
    for i in range(0, length):
        vec = np.zeros(length)
        vec[i] = 1.0
        out.append(vec)
        labels.append(values[i])
    return out, labels


def gen_vectors_complete(protein, vector):
    vectorscomp[protein] = np.array(vector)


def gen_vectors_prot(protein, vector):
    vectorsprot[protein] = np.array(vector)


proteins = BC2['Entry'].tolist()
vectorsdp = BC2WE[BC2WE['word'].isin(proteins)]
vectorsdp = vectorsdp.fillna(0.0)

BC2WE.fillna(0.0).apply(lambda row: gen_vectors_complete(row['word'], row[1:]), raw=True, axis=1)
vectorsdp.apply(lambda row: gen_vectors_prot(row['word'], row[1:]), raw=True, axis=1)

#print(BC2WE.loc[8742]) #"Angiogenic'
#print(vectorscomp['ANGIOGENIC'])

for prot, vec in vectorsprot.items():
    dotprot[prot] = vec.dot(vectorscomp['ANGIOGENIC'])

print(sorted(dotprot.items(), key=lambda x: x[1]))
