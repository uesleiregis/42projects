# Born2beroot

*This project has been created as part of the 42 curriculum by uregis-d.*

## Description
- Born2beroot is a system administration project focused on virtualization, hardening, minimal services, and monitoring.
- This work follows the official subject document `born.pdf` (version 5.2).
- I chose Debian over Rocky because it is simpler to operate and has broader beginner-friendly documentation.
- For the firewall layer, I chose UFW over firewalld because UFW is more straightforward for first-time setup.
- For MAC security, I chose AppArmor over SELinux due to lower complexity and better fit for this project scope.
- I submitted with VirtualBox (x86), and I also replicated the setup in UTM (ARM) for practice.

## Objective
- Configure a virtual machine according to Born2beroot mandatory requirements.
- Implement and schedule a monitoring script that broadcasts system health information to logged-in users.

## Mandatory Checklist (Subject)
- Use `VirtualBox` (or `UTM` if VirtualBox is not available).
- OS: stable Debian (recommended) **or** stable Rocky.
- Do not install a graphical interface (`X.org`, `Wayland`, or equivalent).
- AppArmor enabled on Debian (or SELinux enabled on Rocky).
- At least 2 encrypted partitions using `LVM`.
- `SSH` running on port `4242` with root SSH login disabled.
- Active firewall (`UFW` on Debian / `firewalld` on Rocky), allowing only port `4242` in the mandatory part.
- Hostname format: `yourlogin42`.
- Your login user must exist and belong to `user42` and `sudo`.
- Password policy must follow subject constraints (expiration, complexity, history).
- `sudo` hardening must include limited attempts, custom error message, I/O logging in `/var/log/sudo/`, `requiretty`, and `secure_path`.
- A Bash monitoring script must run at boot and every 10 minutes via `cron` + `wall` (path used: `/usr/local/sbin/monitoring.sh`).

## Important Files and Commands
- `monitoring.sh`: collects metrics and broadcasts them with `wall` to all logged-in users.
- `crontab`: inspect with `sudo cat /var/spool/cron/crontabs/root`; edit with `sudo crontab -u root -e` or `crontab -e`.
- `signature.txt`: stores the VM disk signature. Any VM disk change invalidates the previous signature.
- `sudo_config` in `/etc/sudoers.d/`: contains sudo hardening rules (attempt limits, custom message, logging, secure paths, TTY requirement).

## Official Submission
- Born2beroot submission requires `README.md` and `signature.txt` at repository root.
- `signature.txt` must match the exact VM disk used during evaluation (`shasum` + disk file).
- No snapshots are allowed at the beginning of the evaluation.

## Expected Monitoring Output (Summary)
- System architecture and kernel.
- Physical CPU count and virtual CPU count.
- RAM usage and percentage.
- Disk usage and percentage.
- CPU load percentage.
- Last boot date/time.
- LVM status.
- Active TCP connections.
- Logged-in user count.
- IPv4 and MAC address.
- Number of commands executed with `sudo`.

## Important Notes
- During defense, you must explain each configured component (SSH, firewall, sudo, password policy, LVM, script).
- The script must run without errors, and you should be able to stop scheduling without editing the script file.

---

## Resources
- `subject.pdf` (42 Porto)
- `man` pages, Debian Wiki, Rocky Linux documentation

### SSH Installation
```bash
sudo apt update
sudo apt install openssh-server
sudo service ssh status
```

### Access from Host Terminal
```bash
ssh uregis-d@<IP_OR_LOCALHOST> -p 4241
```
Note: In VirtualBox, `ssh your_user@localhost -p 4241` is typically port-forwarded to internal VM port `4242`, which matches the subject requirement.

## Key Defense Questions

### 1) Operating System
**Why Debian vs Rocky?**
- Debian: easier setup, stable ecosystem, stronger beginner documentation.
- Rocky: RHEL-like enterprise profile, SELinux-first security model.

**`apt` vs `aptitude`**
- `apt`: standard CLI package management workflow.
- `aptitude`: higher-level resolver with TUI support.

**AppArmor (Debian)**
- Profile-based MAC; restricts process capabilities/resources.
- Check with: `sudo aa-status`.

**SELinux (Rocky)**
- Label/policy-based MAC; finer control and higher complexity.
- Check with: `getenforce`, `sestatus`.

### 2) Virtualization
**What is a VM?**
- An isolated OS instance running on host hardware through virtualization.

**VirtualBox vs UTM**
- VirtualBox: common x86/AMD64 desktop hypervisor.
- UTM: convenient option on Apple Silicon (QEMU-based).

### 3) LVM
**What is LVM?**
- Logical volume abstraction over physical storage, enabling flexible resizing.

**How to validate LVM**
```bash
lsblk
lvdisplay
vgdisplay
```

### 4) SSH
**What is SSH?**
- Secure protocol for encrypted remote shell access.

**Why port 4242?**
- Subject requirement; also reduces generic scans on port 22.

**Connect**
```bash
ssh username@localhost -p 4242
```

**Why disable root SSH login?**
- Reduces high-impact brute-force and direct privileged access risk.

**Config file**
- `/etc/ssh/sshd_config`
- Required checks: `Port 4242`, `PermitRootLogin no`

### 5) Firewall
**UFW (Debian)**
- Simple iptables frontend.

**firewalld (Rocky)**
- Dynamic firewall service with zones/services.

**UFW commands**
```bash
sudo ufw status
sudo ufw allow 4242
sudo ufw enable
```

**firewalld commands**
```bash
sudo firewall-cmd --list-all
sudo firewall-cmd --add-port=4242/tcp --permanent
```

### 6) Sudo
**Why sudo over root account usage?**
- Accountability and auditable privileged actions.

**Where to configure**
- `/etc/sudoers` (via `visudo`)
- `/etc/sudoers.d/` (modular files)

**Required hardening examples**
- `Defaults passwd_tries=3`
- `Defaults badpass_message="..."`
- `Defaults logfile="/var/log/sudo/sudo.log"`
- `Defaults log_input,log_output`
- `Defaults requiretty`
- `Defaults secure_path="..."`

**Check logs**
```bash
sudo cat /var/log/sudo/sudo.log
journalctl _COMM=sudo
```

### 7) Password Policy
**Where to configure**
- `/etc/login.defs` (aging)
- `/etc/pam.d/common-password` (`libpam-pwquality`)

**Required rules (subject)**
- Max age 30 days (`PASS_MAX_DAYS 30`)
- Min age 2 days (`PASS_MIN_DAYS 2`)
- Warning 7 days (`PASS_WARN_AGE 7`)
- Minimum 10 chars with upper/lower/digit
- Max 3 repeated consecutive chars
- Must not contain username
- 7 new chars vs old password (`difok=7`) for non-root

**Change password**
```bash
sudo passwd username
```

**Validate aging**
```bash
sudo chage -l username
```

### 8) Users and Groups
**Create user**
```bash
sudo adduser username
```

**Add to group**
```bash
sudo usermod -aG groupname username
```

**Check membership**
```bash
groups username
id username
```

**Required groups**
- `user42`
- `sudo`

**Create group**
```bash
sudo groupadd user42
```

### 9) Hostname
**Check**
```bash
hostname
hostnamectl
```

**Set**
```bash
sudo hostnamectl set-hostname newhostname
# or edit /etc/hostname
```

**Required format**
- `yourlogin42` (example: `uregis-d42`)

### 10) Monitoring Script (`monitoring.sh`)
**Typical location**
- `/usr/local/sbin/monitoring.sh` or `/usr/local/bin/`

**Cron scheduling**
- Edit with `crontab -e`
- Every 10 minutes:
```bash
*/10 * * * * /path/to/monitoring.sh
```

**Stop scheduling without editing script**
```bash
# Option 1: comment the cron line
sudo crontab -e

# Option 2: stop cron service
sudo systemctl stop cron    # Debian
sudo systemctl stop crond   # Rocky
```

### 11) Defense Validation Commands
```bash
# Storage/LVM
lsblk

# Firewall
sudo ufw status                  # Debian
sudo firewall-cmd --list-all     # Rocky

# SSH
sudo systemctl status ssh
grep -E '^(Port|PermitRootLogin)' /etc/ssh/sshd_config

# AppArmor/SELinux
sudo aa-status                   # Debian
getenforce                       # Rocky

# Cron
sudo crontab -l

# User/group test
sudo adduser testuser
sudo usermod -aG sudo,user42 testuser
groups testuser

# Remove test user and home/mail
sudo userdel -r testuser
```

### 12) Snapshots
- No snapshots at the start of evaluation.
- During defense, a temporary snapshot may be created for testing and then removed.

### 13) `signature.txt`
**Generate signature**
```bash
# VM must be powered off first
shasum ~/VirtualBox\ VMs/Born2beRoot/Born2beRoot.vdi
```

**Important**
- Any VM disk change updates the hash/signature.
- If VM is started after generating the signature, regenerate it.

---
