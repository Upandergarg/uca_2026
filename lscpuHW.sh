#!/bin/bash

arch=$(lscpu | grep "Architecture" | awk '{print $2}')

cores=$(( $(lscpu | grep "Core(s) per socket" | awk '{print $4}') * $(lscpu | grep "Socket(s)" | awk '{print $2}') ))

model=$(lscpu | grep "Model name" | cut -d':' -f2 | sed 's/^ *//')

echo "Architecture: $arch, Cores: $cores, Model: $model"
