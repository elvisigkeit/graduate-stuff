--Laboratorio 1, lista 1, exercicio 1
--Elvis Nobrega

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

for nome, sobrenome in pairs(tabela) do
	print (nome, sobrenome)
end
--Mostra no console a tabela, de acordo com a ordem dela mesma
