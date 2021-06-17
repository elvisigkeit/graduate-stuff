#Trabalho 1, versão 1
#Elvis Nobrega

use warnings;
use strict;

#Leio o texto do e-mail, primeiramente um e-mail padrão
open (my $email, "<", "email.txt") or die "Arquivo nao encontrado";

#Variáveis que salvam linhas importantes para evaluação
my $remetente;

#Variáveis de evaluação 
my $numPalvChave = 0;
my $limChaves = 2;
my $emailSuspeito = 0;
my $SPAM = 0;

#Variáveis de lista, as quais serão comparadas
my @listaNegra = ("wxyz2012\@dominio.br", "wxyz2011\@dominio.br", "wxyz2010\@dominio.br", "wxyz2009\@dominio.br");

#Então executa o teste para cada frase
foreach (<$email>) {
	#Salva a linha que contém o remetente
	$remetente = $_ if (/From/);
	
	#Verifica se existe uma palavra chave na frase, 
	#sendo ignorada, por substituição, qualquer variação de maiúscula/minúscula
	#no caso Viagra, pode ser colocada qualquer palavra.
	s/viagra/Viagra/gi;
	$numPalvChave++ if (/Viagra/);
}

#Verificação do limite de palavras chave baseado em um limite pré-estabelecido
$SPAM=1 if ($numPalvChave > $limChaves);

#Verificação de uma suspeita de SPAM,
#a intenção é que a função retorne o remetente no caso de uma suspeita
$emailSuspeito = 1 if ($numPalvChave > 0);

#Implementação da blacklist, compara-se o remetente com todos os e-mails da listaNegra
#Funcionamento de uma implementação de uma whitelist é o mesmo, para outra lista e valor SPAM invertido
foreach (@listaNegra) {
	$SPAM=1 if ($remetente =~ /$_/);
}

print "Resultado:\n";
print "Quantidade de palavras chave:\t", $numPalvChave, "\n";
print "Esse e-mail eh SPAM!" if ($SPAM);

#fecha o arquivo
close $email or die "Nao foi possivel fechar o arquivo";