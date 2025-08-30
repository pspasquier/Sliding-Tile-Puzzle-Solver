#!/bin/bash
# Este script resolve todas as instâncias do 8-puzzle utilizando o algoritmo desejado.
# O resultado é salvo em um arquivo CSV dentro de "results".
# Uso: ./script1 algoritmo

input_file="instances/8puzzle_instances.txt"
algorithm=$1
ulimit -v 4194304    # limite de memória (4 GB)
timeout_duration=600 # limite de tempo (10 min)

# algoritmos suportados
valid_algorithms=("bfs" "idfs" "astar" "idastar" "gbfs")

if [ -z "$algorithm" ]; then
    echo "Uso: $0 algoritmo"
    echo "Algoritmos válidos: ${valid_algorithms[*]}"
    exit 1
fi

# checa se o algoritmo está na lista
if [[ ! " ${valid_algorithms[@]} " =~ " ${algorithm} " ]]; then
    echo "Erro: algoritmo inválido '$algorithm'"
    echo "Algoritmos válidos: ${valid_algorithms[*]}"
    exit 1
fi

if [ ! -f "$input_file" ]; then
    echo "Erro: arquivo '$input_file' não encontrado."
    exit 1
fi

# cria diretório results caso não exista
mkdir -p results

# prepara os dados: transforma linhas em argumentos separados por vírgula
modified_data=$(tr '\n' ',' < "$input_file" | sed 's/,$//')

# executa o programa com limite de tempo e memória
timeout "$timeout_duration" ./build/main "-$algorithm" "$modified_data" > "results/$algorithm.csv"
exit_code=$?

if [ $exit_code -eq 124 ]; then
    echo "Erro: execução ultrapassou o limite de tempo ($timeout_duration segundos)."
elif [ $exit_code -eq 137 ]; then
    echo "Erro: execução foi morta (provavelmente ultrapassou o limite de memória de 4GB)."
elif [ $exit_code -ne 0 ]; then
    echo "Erro: execução falhou com código $exit_code."
else
    echo "Resultados salvos em results/$algorithm.csv"
fi