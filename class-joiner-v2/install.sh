#!/bin/bash

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

prompt() {
    case ${1} in
    "-s" | "--success")
        echo -e "${b_CGSC}${@/-s/}${CDEF}"
        ;; # print success message
    "-e" | "--error")
        echo -e "${b_CRER}${@/-e/}${CDEF}"
        ;; # print error message
    "-w" | "--warning")
        echo -e "${b_CWAR}${@/-w/}${CDEF}"
        ;; # print warning message
    "-i" | "--info")
        echo -e "${b_CCIN}${@/-i/}${CDEF}"
        ;; # print info message
    *)
        echo -e "$@"
        ;;
    esac
}

install() {
    mkdir -p --verbose $HOME/.config/autostart
    echo -e "[Desktop Entry]\nType=Application\nExec=sh -c $HOME/.local/bin/cjdaemon.sh\nHidden=false\nNoDisplay=false\nX-GNOME-Autostart-enabled=true\nName[en_US]=Class joiner Daemon\nName=Class Joiner Daemon" >"$HOME/.config/autostart/cjdaemon.desktop"
    if [[ ! -d "$HOME/.local/share/icons" ]]; then
        mkdir "$HOME/.local/share/icons"
    fi
    cp "class-joiner.png" "$HOME/.local/share/icons/class-joiner.png"
    echo -e "[Desktop Entry]\nTerminal=true\nName=Class Joiner v2\nNoDisplay=false\nExec=\"$HOME/.local/bin/classjoiner\"\nIcon=class-joiner\nType=Application" >"$HOME/.local/share/applications/classjoiner.desktop"
    prompt -i "Desktop shotcut created successfully!!"
    prompt -s "That's it everything oK, use 'classjoiner --help' for more details"
    bash $HOME/.local/bin/cjdaemon.sh &
    disown -a
}

prompt -i "Welcome, This is one time setup for class joiner\n"
prompt -e "Please make sure your current directory is lib/class-jointer-v2"
for i in {1,2,3,4,5}; do
    printf "*"
    sleep 1
done

echo -e "\n\n<-----DAA Lab---->"
PS3='Choose your DAA Lab link(1-2): '
daal=("DAA Lab Link 1" "DAA Lab Link 2")
select DAA_OP in "${daal[@]}"; do
    case $DAA_OP in
    "DAA Lab Link 1")
        search2="daalabid = 2"
        replace2="daalabid = 1"
        break
        ;;
    "DAA Lab Link 2")
        search2="daalabid = 1"
        replace2="daalabid = 2"
        break
        ;;

    *) echo "invalid option $REPLY" ;;
    esac
done

echo -e "\n\n<-----Oops theory---->"
PS3='Choose your Oops theory link(1-2): '
oops=("Oops theory Link 1" "Oops theory Link 2")
select OOPS_OP in "${oops[@]}"; do
    case $OOPS_OP in
    "Oops theory Link 1")
        search3="oopsid = 2"
        replace3="oopsid = 1"
        break
        ;;
    "Oops theory Link 2")
        search3="oopsid = 1"
        replace3="oopsid = 2"
        break
        ;;

    *) echo "invalid option $REPLY" ;;
    esac
done

echo -e "\n\n<-----Oops Lab---->"
PS3='Choose your Oops Lab link(1-2): '
oopl=("Oops Lab Link 1" "Oops Lab Link 2")
select OOPL_OP in "${oopl[@]}"; do
    case $OOPL_OP in
    "Oops Lab Link 1")
        search4="ooplabid = 2"
        replace4="ooplabid = 1"
        break
        ;;
    "Oops Lab Link 2")
        search4="ooplabid = 1"
        replace4="ooplabid = 2"
        break
        ;;

    *) echo "invalid option $REPLY" ;;
    esac
done

echo -e "\n\n<-----authuser value---->"
echo -e "Sample meet link: https://meet.google.com/nfn-xiwj-vpg?authuser=1\nIn the above link 'authuser=1' is for, which google account have to be used for joining"
echo -e "So open this link (https://meet.google.com/nfn-xiwj-vpg) join with college mail id, see  and choose the authuser value"
PS3='Choose your authuser value(1-3): '
auth=("authuser=0" "authuser=1" "authuser=2")
select AUTH_OP in "${auth[@]}"; do
    case $AUTH_OP in
    "authuser=0")
        search5="authuser=1"
        replace5="authuser=0"
        break
        ;;
    "authuser=1")
        search5="authuser=0"
        replace5="authuser=1"
        break
        ;;
    "authuser=2")
        search5="authuser=1"
        replace5="authuser=2"
        break
        ;;
    *) echo "invalid option $REPLY" ;;
    esac
done

filename="classjoiner.cpp"

if [[ $search2 != "" && $replace2 != "" ]]; then
    sed -i "s/$search2/$replace2/" $filename
    prompt -s "DAA Lab link changed sucessfully!!!"

fi

if [[ $search3 != "" && $replace3 != "" ]]; then
    sed -i "s/$search3/$replace3/" $filename
    prompt -s "Oops theory link changed sucessfully!!!"

fi

if [[ $search4 != "" && $replace4 != "" ]]; then
    sed -i "s/$search4/$replace4/" $filename
    prompt -s "Oops Lab link changed sucessfully!!!"

fi

if [[ $search5 != "" && $replace5 != "" ]]; then
    sed -i "s/$search5/$replace5/" $filename
    prompt -s "authuser value changed sucessfully!!!\n"

fi

g++ $filename -ofast -o classjoiner
prompt -i "Compiling $filename...."
mkdir -p "$HOME/.local/bin"
ln -sf --verbose "$PWD/classjoiner" "$HOME/.local/bin/"
ln -sf --verbose "$PWD/cjdaemon.sh" "$HOME/.local/bin/"
if [[ "$PATH" =~ (^|:)"$HOME/.local/bin"(|/)(:|$) ]]; then
    prompt -i "$HOME/.local/bin is already added to PATH"
    install

else
	shell=$(basename $(echo $SHELL))
    if [ "$shell" = "bash" ]; then
        echo 'export PATH=$HOME/.local/bin:$PATH' >>~/.bashrc
        prompt -i "Adding $HOME/.local/bin to PATH variable"
        install
    elif [ "$shell" = "zsh" ]; then
        echo 'export PATH=$HOME/.local/bin:$PATH' >>~/.zshrc
        prompt -i "Adding $HOME/.local/bin to PATH variable"
        install
    else
        prompt -w "$HOME/.local/bin is not in PATH variable"
        prompt -i "Please manually add the $HOME/.local/bin to PATH variable"
    fi

fi
