# Born2beroot

This project has been created as part of the 42 curriculum by uregis-d.

## Descrição
- Projeto de administração de sistemas com foco em virtualização, hardening, serviços mínimos e monitoramento.
- Baseado no subject oficial `born.pdf` (versão 5.2).
- Preferi o Debian ao Rocky em virtude da maior simplicidade e da riqueza da documentação.
- No que se refere ao firewall, a preferência foi o UFW em vez do Firewalld. O primeiro é mais simplificado e recomendado para iniciantes.
- Entre o SELinux e o AppArmor, sequer cogitei o SELinux, pois a documentação era extremamente complexa. Como não havia necessidade de uma segurança extrema, preferi a segunda opção, que me permitiu uma gestão mais fácil, sobretudo com o uso no Debian.
- Não menos importante, o VirtualBox foi a escolha para o envio do projeto, por já conhecer previamente a ferramenta e por a arquitetura ser x86. Paralelamente, também fiz o projeto no UTM, utilizando uma versão ARM do Debian. Só consegui instalar essa arquitetura no computador pessoal, uma vez que essa é a arquitetura dele. Ainda não sei se seria possível instalar uma VM de arquitetura x86 em um notebook ARM, mas todas as minhas tentativas foram frustradas.

## Objetivo
- Configurar uma máquina virtual conforme os requisitos do subject do Born2beroot.
- Implementar e agendar um script que exiba informações de saúde do sistema para todos os usuários logados.

## Checklist obrigatório (subject)
- Usar `VirtualBox` (ou `UTM` se necessário).
- SO: Debian estável (recomendado) **ou** Rocky estável.
- Não instalar interface gráfica (`X.org`, `Wayland` ou equivalente).
- AppArmor ativo no Debian (ou SELinux ativo no Rocky).
- Mínimo de 2 partições criptografadas com `LVM`.
- `SSH` ativo na porta `4242` e login de root via SSH desabilitado.
- Firewall ativo (`UFW` no Debian / `firewalld` no Rocky) com apenas a porta `4242` aberta.
- Hostname no formato `seulogin42`.
- Usuário com seu login existente e pertencendo aos grupos `user42` e `sudo`.
- Política de senha forte conforme o subject (expiração, complexidade e regras de histórico).
- Regras de `sudo` conforme subject: tentativas limitadas, mensagem customizada, log de I/O em `/var/log/sudo/`, `requiretty` e `secure_path`.
- Script de monitoramento em Bash exibindo informações no boot e a cada 10 minutos via `cron` + `wall` (em `/usr/local/sbin/monitoring.sh`).

## Arquivos e comandos importantes
- `monitoring.sh`: coleta métricas e envia aviso global com `wall` (todos os usuários logados).
- `crontab`: visualizado por meio do comando `sudo cat /var/spool/cron/crontabs/root` e acessado para edição com `sudo crontab -u root -e` ou `crontab -e`.
- `signature.txt`: contém a assinatura do disco virtual da VM, assegurando que a VM não foi alterada depois do envio da atividade. Qualquer alteração em qualquer ficheiro da VM altera a assinatura, tornando-a desatualizada.
- O `sudo_config` localizado em `/etc/sudoers.d/`, contém comandos importantes para limitar o número de tentativas do login, mensagem de erro personalizada, dentre outros comandos importantes como para registrar tudo que é feito com sudo, restrição de caminhos seguros e o TTY que permite utilizar sudo por meio de SSH.


## Entrega oficial
- No projeto Born2beroot, a entrega exigida pela 42 é o arquivo `signature.txt` na raiz do repositório.
- O `signature.txt` deve conter a assinatura do disco virtual da VM. Deve ser a mesma assinatura da VM utilizada na avaliação (`shasum` + arquivo).
- Não pode haver snapshots no início da correção.

## Saída esperada (resumo)
- Arquitetura do sistema.
- CPU física e virtual.
- Uso de RAM e disco.
- Carga de CPU.
- Último boot.
- Uso de LVM.
- Conexões TCP estabelecidas.
- Usuários logados.
- IP e MAC.
- Total de comandos executados com `sudo`.

## Observações importantes

- Durante a defesa, você precisa explicar cada item configurado (SSH, firewall, sudo, senha, LVM e script).
- O script deve funcionar sem erros e também saber como interromper o agendamento sem editar o arquivo.

---

## Recursos
- `subject.pdf`: fornecido pela 42 Porto.
- Documentação `man`, Debian Wiki e Rocky Linux Docs.

Instalação do SSH
```bash
sudo apt update
sudo apt install openssh-server
sudo service ssh status
```

Acesso via terminal da máquina
```bash
ssh uregis-d@<IP_DA ou localhost> -p 4241
```
Obs.: `ssh seu_usuario@localhost -p 4241` no VirtualBox redireciona automaticamente para `4242`, porta interna da VM, exatamente a porta solicitada pelo subject.

## Questões importantes sobre o projeto

### 1. Sistema Operacional
**Por que escolheu Debian/Rocky?**
- Debian: mais simples, estável, grande comunidade, ideal para iniciantes
- Rocky: clone do RHEL, mais usado em ambientes enterprise, SELinux nativo

**Diferença entre apt e aptitude?**
- `apt`: interface de linha de comando básica, mais rápida
- `aptitude`: interface de alto nível, resolve dependências de forma mais inteligente, tem interface TUI

**O que é AppArmor (Debian)?**
- Sistema de controle de acesso obrigatório (MAC) baseado em perfis
- Restringe programas a um conjunto limitado de recursos
- Comandos: `sudo aa-status`

**O que é SELinux (Rocky)?**
- Security-Enhanced Linux, outro sistema MAC
- Mais complexo que AppArmor, políticas mais granulares
- Comandos: `getenforce`, `sestatus`

### 2. Virtualização
**O que é uma VM?**
- Sistema operacional isolado rodando dentro de outro SO
- Compartilha recursos de hardware do host

**Diferença entre VirtualBox e UTM?**
- VirtualBox: multiplataforma, usa virtualização x86/AMD64
- UTM: para Mac M1/M2 (ARM), usa QEMU

### 3. LVM (Logical Volume Manager)
**O que é LVM?**
- Camada de abstração entre discos físicos e partições
- Permite redimensionar volumes dinamicamente

**Como verificar se LVM está ativo?**
```bash
lsblk
lvdisplay
vgdisplay
```

**Por que usar partições encriptadas?**
- Protege dados em caso de acesso físico ao disco

### 4. SSH
**O que é SSH?**
- Secure Shell: protocolo para acesso remoto seguro

**Por que porta 4242 e não 22?**
- Segurança por obscuridade: reduz ataques automatizados na porta padrão

**Como conectar via SSH?**
```bash
ssh usuario@localhost -p 4242
```

**Por que não permitir login root via SSH?**
- Princípio do menor privilégio: reduz risco de acesso total em caso de brute force

**Arquivos de configuração:**
- `/etc/ssh/sshd_config`
- Verificar: `Port 4242`, `PermitRootLogin no`

### 5. Firewall (UFW/firewalld)
**O que é UFW?**
- Uncomplicated Firewall: frontend simplificado para iptables (Debian)

**O que é firewalld?**
- Firewall dinâmico para sistemas RedHat/Rocky

**Comandos importantes (UFW):**
```bash
sudo ufw status
sudo ufw allow 4242
sudo ufw enable

sudo ufw status numbered
sudo ufw delete X
```

**Comandos importantes (firewalld):**
```bash
sudo firewall-cmd --list-all
sudo firewall-cmd --add-port=4242/tcp --permanent
```

### 6. Sudo
**Por que usar sudo em vez de root?**
- Rastreabilidade: logs de quem executou cada comando
- Segurança: acesso temporário, não permanente

**Onde fica a configuração do sudo?**
- `/etc/sudoers` (editar com `visudo`)
- `/etc/sudoers.d/` (arquivos adicionais)

**Regras implementadas (conforme subject):**
- Máximo 3 tentativas de senha (`Defaults passwd_tries=3`)
- Mensagem customizada de erro (`Defaults badpass_message="..."`)
- Log de I/O em `/var/log/sudo/` (`Defaults logfile="/var/log/sudo/sudo.log"`, `Defaults log_input, log_output`)
- TTY obrigatório (`Defaults requiretty`)
- Caminho seguro (`Defaults secure_path="..."`)

**Como ver logs do sudo?**
```bash
sudo cat /var/log/sudo/sudo.log
journalctl _COMM=sudo
```

### 7. Política de Senhas
**Onde configurar a política?**
- `/etc/login.defs` (expiração)
- `/etc/pam.d/common-password` (complexidade com `libpam-pwquality`)

**Regras implementadas:**
- Expiração a cada 30 dias (`PASS_MAX_DAYS 30`)
- Mínimo 2 dias entre mudanças (`PASS_MIN_DAYS 2`)
- Aviso 7 dias antes (`PASS_WARN_AGE 7`)
- Mínimo 10 caracteres, maiúscula, minúscula, número
- Máximo 3 caracteres consecutivos idênticos
- Não conter nome do usuário
- 7 caracteres diferentes da senha anterior (não se aplica a root)

**Como trocar senha de usuário?**
```bash
sudo passwd nomedousuario
```

**Como verificar política aplicada?**
```bash
sudo chage -l nomedousuario
```

### 8. Grupos e Usuários
**Criar novo usuário:**
```bash
sudo adduser nomedousuario
```

**Adicionar usuário a grupo:**
```bash
sudo usermod -aG groupname username
```

**Verificar grupos de um usuário:**
```bash
groups username
id username
```

**Grupos obrigatórios:**
- `user42`
- `sudo`

**Criar grupo:**
```bash
sudo groupadd user42
```

### 9. Hostname
**Verificar hostname:**
```bash
hostname
hostnamectl
```

**Mudar hostname:**
```bash
sudo hostnamectl set-hostname novohostname
# Ou editar /etc/hostname
```

**Formato obrigatório:**
- `seulogin42` (exemplo: `uregis-d42`)

### 10. Script de Monitoramento (monitoring.sh)
**Onde deve ficar?**
- Localização comum: `/usr/local/sbin/monitoring.sh` ou `/usr/local/bin/`

**Como funciona o cron?**
- Agenda tarefas para executar em horários específicos
- Editar com `crontab -e`

**Configuração para rodar a cada 10 min:**
```bash
*/10 * * * * /caminho/para/monitoring.sh
```

**Como interromper sem modificar o arquivo?**
```bash
# Opção 1: Comentar linha no crontab
sudo crontab -e
# Adicionar # na frente da linha

# Opção 2: Parar serviço cron
sudo systemctl stop cron    # Debian
sudo systemctl stop crond   # Rocky
```

**O que o script deve exibir?**
- Arquitetura e versão do kernel
- CPUs físicas e virtuais
- Memória RAM (uso e %)
- Disco (uso e %)
- CPU load (%)
- Data/hora último boot
- LVM ativo (yes/no)
- Conexões TCP estabelecidas
- Usuários logados
- IP e MAC
- Comandos sudo executados

**Comando wall:**
- Envia mensagem broadcast para todos os terminais abertos

### 11. Verificações durante a defesa
**Comandos que o avaliador pode pedir:**
```bash
# Ver partições e LVM
lsblk

# Ver firewall
sudo ufw status                  # Debian
sudo firewall-cmd --list-all     # Rocky

# Ver SSH
sudo systemctl status ssh
cat /etc/ssh/sshd_config | grep Port

# Ver AppArmor/SELinux
sudo aa-status      # Debian
getenforce          # Rocky

# Ver cron
sudo crontab -l

# Criar usuário e adicionar ao grupo
sudo adduser testeuser
sudo usermod -aG sudo,user42 testeuser
groups testeuser

# Remover um usuário e remover o home/mail
sudo userdel -r testeuser

```

### 12. Snapshots
**Regra importante:**
- Não pode haver snapshots no início da avaliação
- Durante a defesa, um snapshot pode ser criado para testes

### 13. Signature.txt
**Como gerar:**
```bash
# Desligar VM primeiro!
shasum ~/VirtualBox\ VMs/Born2beRoot/Born2beRoot.vdi
```

**Atenção:**
- Assinatura muda a cada modificação na VM
- Se ligar a VM após gerar, precisa gerar novamente

---


