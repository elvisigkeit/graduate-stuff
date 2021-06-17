#!/bin/bash

function _teste { 
	saida=0; 
	for arg in "$@";  
	do 
		if [[ $arg == -o ]]; 
			then saida=1; 
		fi; 
		if [[ $saida == 1 ]]; 
			then if [[ $arg == *.c ]]; 
				then echo "POR FAVOR, NÃO SOBRESCREVA O SEU C"; 
				exit; 
			else
				echo "$arg";
			fi

		fi; 
	done;  
}

