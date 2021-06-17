##Laboratorio 1, lista 1, exercicio 2
##Elvis Nobrega

open (my $arqNomes, "<", "nomes.txt") or die "Arquivo nao encontrado";
#abre o arquivo para a variável arqNomes

my %tabela;
my $n = 0;
my $atual;
while (<$arqNomes>) {
	$n = $n + 1;
	if (($n%2) != 0) {
		$tabela{$_} = 'a';
		$atual = $_;
	}else{
		$tabela{$atual} = $_;
	}
}
$n = $n/2;

#n pega a quantidade de nomes
#guarda todas as linhas na hash %tabela. 
#Ímpares -> Nomes, Pares -> Sobrenomes

print %tabela;
#Mostra na tela os nomes e depois os sobrenomes

close $arqNomes or die "Nao foi possivel fechar o arquivo";