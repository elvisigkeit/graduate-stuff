#!/usr/bin/perl -w

print (`javac -encoding UTF-8 Sistema.java`);
print (`java Sistema $ARGV[0] $ARGV[1]`);

if (-e $ARGV[0]) {
	parseLog();
}

sub parseLog {
	open($arqLog, "<", $ARGV[0]) or die("O arquivo de log não pôde ser aberto");
	foreach $linha (<$arqLog>) {
		($operacao, $assentos) = split(/\[/, $linha);
		chop($operacao);
		chop($assentos);chop($assentos);
	}
	close($arqLog);
}
