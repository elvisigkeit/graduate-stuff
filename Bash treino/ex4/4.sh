#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Por favor insira exatamente um valor"
    exit 1
fi

i=$1
while [ $i -gt 0 ]; do
    echo -n "$i "
    i=$((i-1))
done

echo ""