import pandas as pd
import numpy as np
import re
import graphviz
from sklearn import tree

BC2 = pd.read_excel('Data/BC2r.xlsx')


def gen_tokens_functions(token_id, id_token, window_size, go_bio, name, interacts_with):
    words = go_bio.split('; ')

    interaction = re.sub(';', '', interacts_with)
    interaction = interaction.split(' ')

    for word in words:
        if token_id.get(word) is None:
            token_id[word] = len(token_id)
            id_token[len(token_id)] = word

    window_size.append(len(words))
    return [words, interaction, name]


def generate_train_words(bioprocesses, interactions, names, token_id, interest_functions):
    window = len(token_id)
    word_vecs = []
    has_angiogenesis = []
    angiogenesis_prots = []
    index = 0

    for word_row, name in zip(bioprocesses, names):
        row = np.zeros(window)
        row_has_angiogenesis = False

        for function in word_row:
            index = token_id[function]
            if index in interest_functions:
                row_has_angiogenesis = True
                angiogenesis_prots.append(name)
            else:
                row[index] = 1.0

        word_vecs.append(row)
        has_angiogenesis.append(row_has_angiogenesis)

    for i, interacts in enumerate(interactions):
        for connection in interacts:
            if connection in angiogenesis_prots:
                has_angiogenesis[i] = True

    return word_vecs, np.array(has_angiogenesis)


token_id = dict()
id_token = dict()
BC2 = BC2.fillna('')
window_size = []

tokens = BC2.apply(lambda row: gen_tokens_functions(
    token_id,
    id_token,
    window_size,
    row['Gene ontology (biological process)'],
    row['Entry'],
    row['Interacts with']
), axis=1)

bioprocesses = [item[0] for item in tokens]
interactions = [item[1] for item in tokens]
names = [item[2] for item in tokens]

window_size = sorted(window_size, reverse=True)[0]
vocab_size = len(id_token)

interest_functions = [token_id['angiogenesis [GO:0001525]'],
                      token_id['positive regulation of angiogenesis [GO:0045766]'],
                      token_id['negative regulation of angiogenesis [GO:0016525]'],
                      token_id['positive regulation of sprouting angiogenesis [GO:1903672]'],
                      token_id['regulation of angiogenesis [GO:0045765]'],
                      token_id['positive regulation of cell migration involved in sprouting angiogenesis [GO:0090050]']]

X, Y = generate_train_words(bioprocesses, interactions, names, token_id, interest_functions)

labels = sorted(token_id.items(), key=lambda x: x[1])
labels = [item[0] for item in labels]

angiogenesis_tree = tree.DecisionTreeClassifier(max_depth=5)
angiogenesis_tree.fit(X, Y)

dot_data = tree.export_graphviz(angiogenesis_tree, out_file=None, feature_names=labels, class_names=["Não angiogênese", "Angiogênese"])
graph = graphviz.Source(dot_data)
graph.render("Angiogenesis")
