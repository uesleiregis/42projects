# Explicação linha a linha do arquivo `script`

## Linguagem identificada
- O arquivo atual é um script **Bash** (indicado por `#!/bin/bash`).

## Explicação por linha

1. `#!/bin/bash` — Define o interpretador do script como Bash.
2. *(linha em branco)* — Separação visual de blocos.
3. `# ARCH` — Comentário indicando o bloco de arquitetura.
4. `arch=$(uname -a)` — Captura informações completas do sistema/kernel em `arch`.
5. *(linha em branco)* — Separação visual.
6. `# CPU PHYSICAL` — Comentário do bloco de CPU física.
7. `cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)` — Conta quantos IDs físicos de CPU aparecem em `/proc/cpuinfo`.
8. *(linha em branco)* — Separação visual.
9. `# CPU VIRTUAL` — Comentário do bloco de CPUs lógicas.
10. `cpuv=$(grep "processor" /proc/cpuinfo | wc -l)` — Conta processadores lógicos (vCPUs).
11. *(linha em branco)* — Separação visual.
12. `# RAM` — Comentário do bloco de memória.
13. `ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')` — Obtém RAM total (MB).
14. `ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')` — Obtém RAM usada (MB).
15. `ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')` — Calcula percentual de uso de RAM com 2 casas decimais.
16. *(linha em branco)* — Separação visual.
17. `# DISK` — Comentário do bloco de disco.
18. `disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')` — Soma o tamanho total (MB) das partições em `/dev/`, exclui `/boot`, converte para GB e formata.
19. `disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')` — Soma o espaço usado (MB) dessas partições.
20. `disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')` — Calcula percentual inteiro de uso de disco.
21. *(linha em branco)* — Separação visual.
22. `# CPU LOAD` — Comentário do bloco de carga de CPU.
23. `cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')` — Lê a coluna `%idle` da última amostra do `vmstat`.
24. `cpu_op=$(expr 100 - $cpul)` — Converte idle em uso de CPU (`100 - idle`).
25. `cpu_fin=$(printf "%.1f" $cpu_op)` — Formata uso de CPU com 1 casa decimal.
26. *(linha em branco)* — Separação visual.
27. `# LAST BOOT` — Comentário do bloco de último boot.
28. `lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')` — Captura data e hora do último boot.
29. *(linha em branco)* — Separação visual.
30. `# LVM USE` — Comentário do bloco de LVM.
31. `lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)` — Verifica se existe volume LVM e retorna `yes` ou `no`.
32. *(linha em branco)* — Separação visual.
33. `# TCP CONNEXIONS` — Comentário do bloco de conexões TCP (há um erro ortográfico em “CONNEXIONS”).
34. `tcpc=$(ss -ta | grep ESTAB | wc -l)` — Conta conexões TCP em estado estabelecido.
35. *(linha em branco)* — Separação visual.
36. `# USER LOG` — Comentário do bloco de usuários logados.
37. `ulog=$(users | wc -w)` — Conta usuários atualmente conectados.
38. *(linha em branco)* — Separação visual.
39. `# NETWORK` — Comentário do bloco de rede.
40. `ip=$(hostname -I)` — Captura IP(s) do host.
41. `mac=$(ip link | grep "link/ether" | awk '{print $2}')` — Captura endereço(s) MAC das interfaces.
42. *(linha em branco)* — Separação visual.
43. `# SUDO` — Comentário do bloco de sudo.
44. `cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)` — Conta comandos sudo registrados no journal.
45. *(linha em branco)* — Separação visual.
46. `wall "\tArchitecture: $arch` — Inicia mensagem enviada a todos os usuários com `wall` e imprime arquitetura.
47. `\tCPU physical: $cpuf` — Exibe número de CPUs físicas.
48. `\tvCPU: $cpuv` — Exibe número de vCPUs.
49. `\tMemory Usage: $ram_use/${ram_total}MB ($ram_percent%)` — Exibe uso de memória absoluto e percentual.
50. `\tDisk Usage: $disk_use/${disk_total} ($disk_percent%)` — Exibe uso de disco absoluto e percentual.
51. `\tCPU load: $cpu_fin%` — Exibe carga de CPU calculada.
52. `\tLast boot: $lb` — Exibe data/hora do último boot.
53. `\tLVM use: $lvmu` — Exibe se há uso de LVM.
54. `\tConnections TCP: $tcpc ESTABLISHED` — Exibe total de conexões TCP estabelecidas.
55. `\tUser log: $ulog` — Exibe total de usuários logados.
56. `\tNetwork: IP $ip ($mac)` — Exibe IP e MAC coletados.
57. `\tSudo: $cmnd cmd"` — Exibe quantidade de comandos sudo e encerra a string do `wall`.
58. *(linha em branco, se presente no final do arquivo)* — Apenas término/EOF com quebra de linha final.

## Observação
- Se você quiser, no próximo passo eu também posso renomear o arquivo original de `script` para `script.sh` (extensão correta de Bash).