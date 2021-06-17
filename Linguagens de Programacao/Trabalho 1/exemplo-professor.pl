##########################
# Autor: Miguel
# Exemplo para Trabalho 1
##########################

use warnings;
use strict;

my $configFile;
my $answer;
my @line;
my %testsHash;

# Parâmetros para atribuir nota ao e-mail
my $nota = 0;
my $notaFinal = 0;
my $count = 0;

# Leitura do teclado da palavra buscada
print "Deseja carregar o arquivo de configuração padrão? (S/N) ";
$answer = <STDIN>;
chop ($answer);

# Escolha do arquivo de configuração
if ($answer =~ /N/) {
	print "Entre com o nome do arquivo: ";
	$configFile = <STDIN>;
	print "Abrindo arquivo: ", $configFile;
	chop ($configFile);
} else {
	$configFile = "arquivo_configuracao.txt";
}

# Abertura do arquivo de configuração
print "Abrindo arquivo: ", $configFile, "\n";
open  (CONFIGFILE,  "<$configFile")  or  die  "Não  foi  possivel abrir $configFile: $!";
# Leitura do arquivo de configuração
while (<CONFIGFILE>) {
	my %newHash;
	# Condição 1: Primeiro caractere (^) é tralha
	# Condição 2: Primeiro caractere (^) é seguido pelo último ($) --linha em branco
	if (/^#/ or /^$/) {
		print "Comentário ou linha em branco...	\n";
	} else {
		@line = split (/\s+/);
		%newHash = ($line[0], $line[1]);
		%testsHash = (%testsHash, %newHash);
		print "Não é comentário $line[0]\n";
	}
}

# Impressão dos testes a serem realizados
foreach (keys %testsHash) {
	print "Teste $_ e valor $testsHash{$_}\n";
}

# Abre o e-mail examinado para leitura
open(MYEMAIL,  "<email.txt") or die "Can't open arquivo.txt: $!";

# Inspeciona o e-mail
while (<MYEMAIL>) {
	print "Lido: ", $_;
	# Divide em palavras separadas por espaços em branco \s+
	@line = split (/\s+/);
	
	foreach (@line) {
		if (/Viagra/) {
			$count++;
		}
	}
}

print "\n\nForam encontradas $count ocorrências\n\n\n";

# Atribuição da nota baseada nos pesos dos critérios avaliados
if ($count > 1) {
	$nota = $testsHash{Viagra};
	$notaFinal += $nota;
}

# Nota final
if ($notaFinal >= 20) {
	print "É SPAM!\n\n\n";
}

#Fechando os arquivos abertos
close CONFIGFILE;
close MYEMAIL;