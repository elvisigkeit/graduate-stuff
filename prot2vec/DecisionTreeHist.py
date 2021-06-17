import pandas as pd
import numpy as np
import re
import graphviz
from sklearn import tree

Hist = pd.read_excel('Data/hist_data.ods')

Hist = Hist.dropna()

Hist['gender'] = Hist['gender'].map({'Male': 0, 'Female': 1})
X = Hist.drop('id', axis=1).drop('dead by melanoma', axis=1)
Y = Hist['dead by melanoma']

hist_tree = tree.DecisionTreeClassifier(max_depth=5)
hist_tree.fit(X, Y)

dot_data = tree.export_graphviz(hist_tree, out_file=None, feature_names=X.columns, class_names=["Vivo", "Morto"])
graph = graphviz.Source(dot_data)
graph.render("MortePorMelanoma")
