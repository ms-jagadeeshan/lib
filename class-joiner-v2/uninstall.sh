#! /bin/bash
#COLORS
CDEF=" \033[0m"      # default color
CCIN=" \033[0;36m"   # info color
CGSC=" \033[0;32m"   # success color
CRER=" \033[0;31m"   # error color
CWAR=" \033[0;33m"   # waring color
b_CDEF=" \033[1;37m" # bold default color
b_CCIN=" \033[1;36m" # bold info color
b_CGSC=" \033[1;32m" # bold success color
b_CRER=" \033[1;31m" # bold error color
b_CWAR=" \033[1;33m" # bold warning color

rm -vf "${HOME}/.local/bin/classjoiner"
rm -vf "${HOME}/.local/bin/cjdaemon.sh"
rm -vf "${HOME}/.config/autostart/cjdaemon.desktop"
rm -vf "$HOME/.local/share/applications/classjoiner.desktop"
rm -vf "${HOME}/.local/share/icons/class-joiner.png"
echo -e "${b_CGSC}Uninstalled Successfully!!${CDEF}"
