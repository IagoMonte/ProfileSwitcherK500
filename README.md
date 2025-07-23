# Profile Switcher MACHENIKE K500-B61

A simple C utility to send custom key mapping and lighting profiles to the MACHENIKE K500-B61 keyboard over USB.

Uma ferramenta simples em C para enviar perfis personalizados de mapeamento e iluminação para o MACHENIKE K500-B61 via USB.

---
## Getting Started

### 1. Install dependencies

Install the `libusb` library:

**For Arch Linux:**
```bash
sudo pacman -S libusb
```

**For Debian/Ubuntu:**
```bash
sudo apt install libusb-1.0-0-dev
```

---

### 2. Compile the C code

Build the USB file sender tool:
```bash
gcc packageTransfer.c -o lib_usb_fileSend -lusb-1.0
```

---

### 3. Install the binary to your system

Copy the binary to a directory in your `PATH`:
```bash
sudo cp lib_usb_fileSend /usr/local/bin/
sudo chmod +x /usr/local/bin/lib_usb_fileSend
```

---

### 4. Install the profile switcher script

Copy the script to your `PATH`:
```bash
sudo cp ProfileSwitcher.sh /usr/local/bin/k500ProfileSwitcher
sudo chmod +x /usr/local/bin/k500ProfileSwitcher
```

---

## How to Use

### 1. Create the profiles directory

```bash
mkdir -p ~/.config/k500Profiles/
```

### 2. Add your profiles

Create a folder for each profile under `~/.config/k500Profiles/` containing the following files:

```
~/.config/k500Profiles/<Profile_Name>/
├── KEY_MAP.hex
├── RGB_COLOR.hex
└── RGB_EFFECT.hex
```

---

### 3. Run the script

To apply a profile, run:
```bash
k500ProfileSwitcher <Profile_Name>
```

---

## Example

```bash
k500ProfileSwitcher gamer
```

This command will apply the profile located at:

```
~/.config/k500Profiles/gamer/
```

---

## Comecando

### 1. Instale as dependências

Instale a biblioteca `libusb`:

**Para Arch based:**
```bash
sudo pacman -S libusb
```

**Para Debian/Ubuntu based:**
```bash
sudo apt install libusb-1.0-0-dev
```

---

### 2. Compile o código C

Compile o programa de envio via USB:
```bash
gcc packageTransfer.c -o lib_usb_fileSend -lusb-1.0
```

---

### 3. Instale o binário no sistema

Copie o binário para um diretório do `PATH`:
```bash
sudo cp lib_usb_fileSend /usr/local/bin/
sudo chmod +x /usr/local/bin/lib_usb_fileSend
```

---

### 4. Instale o script de troca de perfil

Copie o script para o sistema:
```bash
sudo cp ProfileSwitcher.sh /usr/local/bin/k500ProfileSwitcher
sudo chmod +x /usr/local/bin/k500ProfileSwitcher
```

---

## Como usar

### 1. Crie o diretório de perfis

```bash
mkdir -p ~/.config/k500Profiles/
```

### 2. Adicione os perfis

Crie uma pasta para cada perfil dentro de `~/.config/k500Profiles/`, contendo os seguintes arquivos:

```
~/.config/k500Profiles/<Nome_Do_Perfil>/
├── KEY_MAP.hex
├── RGB_COLOR.hex
└── RGB_EFFECT.hex
```

---

### 3. Execute o script

Para aplicar um perfil, use:
```bash
k500ProfileSwitcher <Nome_Do_Perfil>
```

---

## Exemplo

```bash
k500ProfileSwitcher gamer
```

Este comando irá aplicar o perfil localizado em:

```
~/.config/k500Profiles/gamer/
```

---
Bom Uso!!
Enjoy!!

For generate .HEX FILES:Coming soon

░▒▓█▓▒░░▒▓██████▓▒░ ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓███████▓▒░▒▓████████▓▒░ 
░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░     
░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░     
░▒▓█▓▒░▒▓████████▓▒░▒▓█▓▒▒▓███▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░     
░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░     
░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░     
░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓███████▓▒░  ░▒▓█▓▒░ 






!!use 
USER ALL=(ALL) NOPASSWD: /usr/local/bin/lib_usb_fileSend for run it without password
