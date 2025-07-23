#!/bin/bash
VID="258a"
PID="0049"
BmRT="21"
bRqst="09"
wValue="0305"
wIndex="0001"
Profile=$1
ProfileLocals=$HOME/.config/k500Profiles/$1

KEYMAP=$ProfileLocals/KEY_MAP.hex
RGBCOLOR=$ProfileLocals/RGB_COLOR.hex
RGBEFFECT=$ProfileLocals/RGB_EFFECT.hex

if [ ! -f "$KEYMAP" ] || [ ! -f "$RGBCOLOR" ] || [ ! -f "$RGBEFFECT" ]; then
    echo "Erro: Um ou mais arquivos do perfil '$Profile' não foram encontrados."
    exit 1
fi


PackageSend() {
    FILE=$1
    sudo lib_usb_fileSend $VID $PID $BmRT $bRqst $wValue $wIndex $FILE
    sleep 0.5
}

PackageSend $KEYMAP
PackageSend $RGBCOLOR
PackageSend $RGBEFFECT