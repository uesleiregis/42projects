# Born2beroot

This project has been created as part of the 42 curriculum by uregis-d.

## Description
- System administration project focused on virtualization, hardening, minimal services, and monitoring.
- Based on the official subject `born.pdf` (version 5.2).
- I preferred Debian over Rocky due to its greater simplicity and richer documentation.
- Regarding the firewall, I chose UFW over Firewalld. UFW is simpler and recommended for beginners.
- Between SELinux and AppArmor, I did not even consider SELinux because the documentation was extremely complex. Since there was no need for extreme security, I chose AppArmor, which gave me easier management, especially when using Debian.
- Not least, VirtualBox was chosen for project submission because I was already familiar with the tool and because of the x86 architecture. In parallel, I also completed the project on UTM using an ARM Debian version. I could only install this architecture on my personal computer, since that is its architecture. I still do not know whether it would be possible to install an x86 VM on an ARM notebook, but all my attempts failed.

## Goal
- Configure a virtual machine according to Born2beroot subject requirements.
- Implement and schedule a script that displays system health information for all logged-in users.

## Mandatory Checklist (subject)
- Use `VirtualBox` (or `UTM` if needed).
- OS: stable Debian (recommended) **or** stable Rocky.
- Do not install a graphical interface (`X.org`, `Wayland`, or equivalent).
- AppArmor enabled on Debian (or SELinux enabled on Rocky).
- At least 2 encrypted partitions using `LVM`.
- `SSH` enabled on port `4242`, with root login over SSH disabled.
- Active firewall (`UFW` on Debian / `firewalld` on Rocky) with only port `4242` open.
- Hostname in `yourlogin42` format.
- User with your login must exist and belong to `user42` and `sudo` groups.
- Strong password policy according to the subject (expiration, complexity, and history rules).
- `sudo` rules according to subject: limited attempts, custom message, I/O logs in `/var/log/sudo/`, `requiretty`, and `secure_path`.
- Bash monitoring script displaying information on boot and every 10 minutes via `cron` + `wall` (at `/usr/local/sbin/monitoring.sh`).

## Important Files and Commands
- `monitoring.sh`: collects metrics and sends a global `wall` broadcast (all logged-in users).
- `crontab`: viewed with `sudo cat /var/spool/cron/crontabs/root` and edited with `sudo crontab -u root -e` or `crontab -e`.
- `signature.txt`: contains the VM virtual disk signature, ensuring the VM was not changed after submission. Any change to any file inside the VM changes the signature and makes it outdated.
- `sudo_config` located at `/etc/sudoers.d/` contains important commands to limit login attempts, set a custom error message, and other important rules such as logging everything done with sudo, restricting secure paths, and enforcing TTY so sudo can be used over SSH.

## Official Submission
- In Born2beroot, 42 requires `signature.txt` at the repository root.
- `signature.txt` must contain the VM virtual disk signature. It must be the same signature as the VM used in the evaluation (`shasum` + file).
- There must be no snapshots at the beginning of the evaluation.

## Expected Output (summary)
- System architecture.
- Physical and virtual CPUs.
- RAM and disk usage.
- CPU load.
- Last boot.
- LVM usage.
- Established TCP connections.
- Logged-in users.
- IP and MAC.
- Total commands executed with `sudo`.

## Important Notes

- During the defense, you must explain each configured item (SSH, firewall, sudo, password policy, LVM, and script).
- The script must run without errors, and you must also know how to stop the scheduling without editing the script file.

---

## Resources
- `subject.pdf`: provided by 42 Porto.
- `man` documentation, Debian Wiki, and Rocky Linux Docs.

SSH Installation
```bash
sudo apt update
sudo apt install openssh-server
sudo service ssh status
```

Access via machine terminal
```bash
ssh uregis-d@<IP_OR localhost> -p 4241
```
Note: `ssh your_user@localhost -p 4241` in VirtualBox automatically forwards to `4242`, the VM internal port, exactly as requested by the subject.

## Important Questions About the Project

### 1. Operating System
**Why did you choose Debian/Rocky?**
- Debian: simpler, stable, huge community, ideal for beginners
- Rocky: RHEL clone, more used in enterprise environments, native SELinux

**Difference between apt and aptitude?**
- `apt`: basic command-line interface, faster
- `aptitude`: higher-level interface, resolves dependencies more intelligently, has a TUI interface

**What is AppArmor (Debian)?**
- Mandatory Access Control (MAC) system based on profiles
- Restricts programs to a limited set of resources
- Commands: `sudo aa-status`

**What is SELinux (Rocky)?**
- Security-Enhanced Linux, another MAC system
- More complex than AppArmor, with more granular policies
- Commands: `getenforce`, `sestatus`

### 2. Virtualization
**What is a VM?**
- An isolated operating system running inside another OS
- Shares host hardware resources

**Difference between VirtualBox and UTM?**
- VirtualBox: cross-platform, uses x86/AMD64 virtualization
- UTM: for Mac M1/M2 (ARM), uses QEMU

### 3. LVM (Logical Volume Manager)
**What is LVM?**
- Abstraction layer between physical disks and partitions
- Allows dynamic volume resizing

**How to check whether LVM is active?**
```bash
lsblk
lvdisplay
vgdisplay
```

**Why use encrypted partitions?**
- Protects data in case of physical disk access

### 4. SSH
**What is SSH?**
- Secure Shell: protocol for secure remote access

**Why port 4242 instead of 22?**
- Security through obscurity: reduces automated attacks on the default port

**How to connect via SSH?**
```bash
ssh usuario@localhost -p 4242
```

**Why not allow root login via SSH?**
- Principle of least privilege: reduces risk of full access in brute-force scenarios

**Configuration files:**
- `/etc/ssh/sshd_config`
- Check: `Port 4242`, `PermitRootLogin no`

### 5. Firewall (UFW/firewalld)
**What is UFW?**
- Uncomplicated Firewall: simplified frontend for iptables (Debian)

**What is firewalld?**
- Dynamic firewall for RedHat/Rocky systems

**Important commands (UFW):**
```bash
sudo ufw status
sudo ufw allow 4242
sudo ufw enable
```

**Important commands (firewalld):**
```bash
sudo firewall-cmd --list-all
sudo firewall-cmd --add-port=4242/tcp --permanent
```

### 6. Sudo
**Why use sudo instead of root?**
- Traceability: logs who executed each command
- Security: temporary access, not permanent

**Where is sudo configured?**
- `/etc/sudoers` (edit with `visudo`)
- `/etc/sudoers.d/` (additional files)

**Implemented rules (according to subject):**
- Maximum 3 password attempts (`Defaults passwd_tries=3`)
- Custom error message (`Defaults badpass_message="..."`)
- I/O logs in `/var/log/sudo/` (`Defaults logfile="/var/log/sudo/sudo.log"`, `Defaults log_input, log_output`)
- Mandatory TTY (`Defaults requiretty`)
- Secure path (`Defaults secure_path="..."`)

**How to view sudo logs?**
```bash
sudo cat /var/log/sudo/sudo.log
journalctl _COMM=sudo
```

### 7. Password Policy
**Where to configure policy?**
- `/etc/login.defs` (expiration)
- `/etc/pam.d/common-password` (complexity with `libpam-pwquality`)

**Implemented rules:**
- Expires every 30 days (`PASS_MAX_DAYS 30`)
- Minimum 2 days between changes (`PASS_MIN_DAYS 2`)
- Warning 7 days before expiration (`PASS_WARN_AGE 7`)
- Minimum 10 characters, uppercase, lowercase, number
- Maximum 3 consecutive identical characters
- Must not contain username
- 7 characters must differ from previous password (does not apply to root)

**How to change a user password?**
```bash
sudo passwd nomedousuario
```

**How to verify applied policy?**
```bash
sudo chage -l nomedousuario
```

### 8. Groups and Users
**Create a new user:**
```bash
sudo adduser nomedousuario
```

**Add user to a group:**
```bash
sudo usermod -aG groupname username
```

**Check a user’s groups:**
```bash
groups username
id username
```

**Mandatory groups:**
- `user42`
- `sudo`

**Create group:**
```bash
sudo groupadd user42
```

### 9. Hostname
**Check hostname:**
```bash
hostname
hostnamectl
```

**Change hostname:**
```bash
sudo hostnamectl set-hostname novohostname
# Or edit /etc/hostname
```

**Mandatory format:**
- `yourlogin42` (example: `uregis-d42`)

### 10. Monitoring Script (monitoring.sh)
**Where should it be?**
- Common location: `/usr/local/sbin/monitoring.sh` or `/usr/local/bin/`

**How does cron work?**
- Schedules tasks to run at specific times
- Edit with `crontab -e`

**Configuration to run every 10 min:**
```bash
*/10 * * * * /caminho/para/monitoring.sh
```

**How to stop it without modifying the file?**
```bash
# Option 1: Comment line in crontab
sudo crontab -e
# Add # in front of the line

# Option 2: Stop cron service
sudo systemctl stop cron    # Debian
sudo systemctl stop crond   # Rocky
```

**What must the script display?**
- Architecture and kernel version
- Physical and virtual CPUs
- RAM (usage and %)
- Disk (usage and %)
- CPU load (%)
- Last reboot date/time
- LVM active (yes/no)
- Established TCP connections
- Logged-in users
- IP and MAC
- Executed sudo commands

**wall command:**
- Sends a broadcast message to all open terminals

### 11. Checks During Defense
**Commands the evaluator may ask for:**
```bash
# Check partitions and LVM
lsblk

# Check firewall
sudo ufw status                  # Debian
sudo firewall-cmd --list-all     # Rocky

# Check SSH
sudo systemctl status ssh
cat /etc/ssh/sshd_config | grep Port

# Check AppArmor/SELinux
sudo aa-status      # Debian
getenforce          # Rocky

# Check cron
sudo crontab -l

# Create user and add to group
sudo adduser testeuser
sudo usermod -aG sudo,user42 testeuser
groups testeuser

# Remove a user and remove home/mail
sudo userdel -r testeuser

```

### 12. Snapshots
**Important rule:**
- There must be no snapshots at the beginning of the evaluation
- During the defense, a snapshot may be created for tests

### 13. Signature.txt
**How to generate:**
```bash
# Shut down VM first!
shasum ~/VirtualBox\ VMs/Born2beRoot/Born2beRoot.vdi
```

**Attention:**
- Signature changes with any VM modification
- If you boot the VM after generating, you need to generate it again

---
