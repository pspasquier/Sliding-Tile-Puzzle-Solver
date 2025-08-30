#!/bin/bash
# Resolve todas as instâncias do 15-puzzle usando A*.
# Resultados em results/astar15.csv
# Uso: ./15-puzzle_benchmark.sh

input_file="instances/15puzzle_instances.txt"
timeout_duration=30
memory_limit_kb=8388608

if [ ! -f "$input_file" ]; then
    echo "Error: File '$input_file' not found."
    exit 1
fi

mkdir -p results
: > results/astar15.csv

while IFS= read -r line; do
    trimmed_line=$(echo "$line" | awk '{$1=$1};1')

    # Limite de memória por processo
    ulimit -v "$memory_limit_kb"

    # Executa com timeout
    if ! output=$(timeout "$timeout_duration" ./build/main -astar "$trimmed_line" 2>/dev/null); then
        # Timeout ou falha → escreve linha nula
        echo "-,-,-,-,-" >> results/astar15.csv
    else
        echo "$output" >> results/astar15.csv
    fi
done < "$input_file"