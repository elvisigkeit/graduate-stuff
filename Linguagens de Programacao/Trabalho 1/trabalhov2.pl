#Trabalho 1, versão 1
#Elvis Nobrega

use warnings;
use strict;

#Variáveis que salvam linhas importantes para evaluação
my $remetente;

#Variáveis de evaluação 
my $numPalvChave = 0;
my $limChaves = 2; #por padrão tem o valor de dois, pode ser modificado no arquivo de config.
my $emailSuspeito = 0;
my $SPAM = 0;
my $existeLink = 0;
my $nrLinhas = 0;

#Variáveis de lista, as quais serão comparadas, podem ser usadas toda sorte de listas
my @listaNegra = ("wxyz2012\@dominio.br", "wxyz2011\@dominio.br", "wxyz2010\@dominio.br", "wxyz2009\@dominio.br");

#variaveis do arquivo de configuração
my $arqConfig = "arquivo_configuracao.txt";
my $resposta;
my @linha;

# Leitura do teclado do nome do arquivo de configuração, se for o caso
print "Deseja carregar o arquivo de configuracao padrao?  ";
$resposta = <STDIN>;
chop ($resposta);

if ($resposta =~ /N/i) {
	print "Entre com o nome do arquivo: ";
	$arqConfig = <STDIN>;
	chop ($arqConfig);
}

open  (my $arquivo, "<", "$arqConfig")  or  die  "Arquivo de configuracao nao encontrado";

#Leitura orientada por casos, para o arquivo de configuração
#no caso de ser blacklist, por exemplo, ele muda para o estado de leitura de blacklists
my $caso;
foreach (<$arquivo>) {
	if (/^#/ or /^$/) {
		$caso = "";
		if (/blacklist/i) {
			$caso = "blacklist";
		}
		if (/palavras chave/i){
			$caso = "limChaves";
		}
	}else{
		if ($caso eq "blacklist") {
			chop ($_); #cortar um possível "\n"
			push @listaNegra, $_;
		}
		if ($caso eq "limChaves") {
			$limChaves = $_;
			$limChaves = $limChaves + 0; #definição de limChaves como número
		}
	}
}

close $arquivo or die "Nao foi possivel fechar o arquivo";

#Leio o texto do e-mail, primeiramente um e-mail padrão
open (my $email, "<", "email.txt") or die "Arquivo nao encontrado";

#Então executa o teste para cada frase
foreach (<$email>) {
	#Salva a linha que contém o remetente
	$remetente = $_ if (/From/);
	
	#Verifica se existe uma palavra chave na frase, 
	#sendo ignorada, por substituição, qualquer variação de maiúscula/minúscula
	#no caso Viagra, pode ser colocada qualquer palavra.
	s/viagra/Viagra/gi;
	$numPalvChave++ if (/Viagra/);
	$existeLink = 1 if (/http:/);	
	
	#Por fim, conta o número de linhas do email
	$nrLinhas++;
}

#Verificação do limite de palavras chave baseado em um limite pré-estabelecido
$SPAM=1 if ($numPalvChave > $limChaves);

#Verificação de uma suspeita de SPAM,
#a intenção é que a função retorne o remetente no caso de uma suspeita
#e também verificar que no caso de um email suspeito, ter link significa ser SPAM
$emailSuspeito = 1 if ($numPalvChave > 0 || $nrLinhas < 4);
$SPAM=1 if ($emailSuspeito && $existeLink);

#Implementação da blacklist, compara-se o remetente com todos os e-mails da listaNegra
#Funcionamento de uma implementação de uma whitelist é o mesmo, para outra lista e valor SPAM invertido
foreach (@listaNegra) {
	$SPAM=1 if ($remetente =~ /$_/);
}

print "Resultado:\n";
if ($SPAM) {
	print "Esse e-mail eh SPAM!";
}else{
	print "Esse e-mail nao eh SPAM.";
	print " Mas suspeita-se." if ($emailSuspeito);
}

#fecha o arquivo
close $email or die "Nao foi possivel fechar o arquivo";