--Laboratorio 1, lista 1, exercicio 1
--Elvis Nobrega

nrNomes = 0
for a in io.lines("nomes.txt") do
	nrNomes = nrNomes + 1
end
nrNomes = nrNomes/2
--Pega o nr de nomes no arquivo

tabela = {}
n = 0
atual = nil

for linha in io.lines("nomes.txt") do
	n = n + 1
	if ((n%2) ~= 0) then
		tabela[linha] = "a"
		atual = linha
	else
		tabela[atual] = linha
	end
end
--Coloca os nomes numa tabela

n = 0
for i, linha in ipairs(tabela) do
	print (linha)
	n = n + 1
end
