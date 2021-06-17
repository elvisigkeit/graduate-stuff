--Laboratorio 1, lista 1, exercicio 3
--Elvis Nobrega

function quickSort (vetor, iInicio, iFim)
	i, j = iInicio, iFim
	meio = math.floor((j-i)/2) + i
	pivo = vetor[meio]
	if (pivo ~= nil) then
		while (i<=j) do
			while (vetor[i] < pivo) do
				i = i + 1
			end
			while (vetor[j] > pivo) do
				j = j - 1
			end
			if (i <= j) then
				vetor[i], vetor[j] = vetor[j], vetor[i]
				i = i + 1
				j = j - 1
			end
		end
		if (j>iInicio) then
			quickSort (vetor, iInicio, j)
		end
		if (i<iFim) then
			quickSort (vetor, i, iFim)
		end
	end
end
--funcao do quickSort

array = {1, 3, 24, 7, 14, 42, 4, 9, 16, 72, 27, 34, 99, 24}
--um vetor, "array", que é definido de qualquer valor possivel

tamanho = 0
for a in ipairs(array) do
	tamanho = tamanho + 1
end
--pega o tamanho do vetor, admitindo ele ser qualquer

quickSort(array, 1, tamanho)

for a in ipairs(array) do
	print (array[a])
end

