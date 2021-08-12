#!/bin/bash

#COLORS
CDEF=" \033[0m"                                     # default color
CCIN=" \033[0;36m"                                  # info color
CGSC=" \033[0;32m"                                  # success color
CRER=" \033[0;31m"                                  # error color
CWAR=" \033[0;33m"                                  # waring color
b_CDEF=" \033[1;37m"                                # bold default color
b_CCIN=" \033[1;36m"                                # bold info color
b_CGSC=" \033[1;32m"                                # bold success color
b_CRER=" \033[1;31m"                                # bold error color
b_CWAR=" \033[1;33m"                                # bold warning color

prompt () {
    case ${1} in
        "-s"|"--success")
        echo -e "${b_CGSC}${@/-s/}${CDEF}";;          # print success message
        "-e"|"--error")
        echo -e "${b_CRER}${@/-e/}${CDEF}";;          # print error message
        "-w"|"--warning")
        echo -e "${b_CWAR}${@/-w/}${CDEF}";;          # print warning message
        "-i"|"--info")
        echo -e "${b_CCIN}${@/-i/}${CDEF}";;          # print info message
        *)
            echo -e "$@"
        ;;
    esac
}
prompt -i "Welcome, This is one time setup for class joiner"
prompt -w "Please make sure your current directory is lib/class-jointer-v2"
echo -e "\n\n<-----DSD---->"
PS3='Choose your DSD link(1-2): '
dsd=("DSD Link 1" "DSD Link 2" )
select DSD_OP in "${dsd[@]}"; do
    case $DSD_OP in
        "DSD Link 1")
            search1="dsdid = 2"
            replace1="dsdid = 1"
            break
        ;;
        "DSD Link 2")
            search1="dsdid = 1"
            replace1="dsdid = 2"
            break
        ;;
        
        *) echo "invalid option $REPLY";;
    esac
done

echo -e "\n\n<-----DAA Lab---->"
PS3='Choose your DAA Lab link(1-2): '
daal=("DAA Lab Link 1" "DAA Lab Link 2" )
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
        
        *) echo "invalid option $REPLY";;
    esac
done

echo -e "\n\n<-----authuser value---->"
echo -e "Sample meet link: https://meet.google.com/nfn-xiwj-vpg?authuser=1\nIn the above link 'authuser=1' is for, which google account used to log in"
echo -e "So open this link (https://meet.google.com/nfn-xiwj-vpg) join with college mail id, see and choose the authuser value"
PS3='Choose your authuser value(1-3): '
auth=("authuser=0" "authuser=1" "authuser=2")
select AUTH_OP in "${auth[@]}"; do
    case $AUTH_OP in
        "authuser=0")
            search3="authuser=1"
            replace3="authuser=0"
            break
        ;;
        "authuser=1")
            search3=""
            replace3=""
            break
        ;;
        "authuser=2")
            search3="authuser=1"
            replace3="authuser=2"
            break
        ;;
        *) echo "invalid option $REPLY";;
    esac
done


filename="test1.cpp"

if [[ $search1 != "" && $replace1 != "" ]]; then
    sed -i "s/$search1/$replace1/" $filename
    prompt -s "\nDSD link changed sucessfully!!!"
fi

if [[ $search2 != "" && $replace2 != "" ]]; then
    sed -i "s/$search2/$replace2/" $filename
    prompt -s "DAA Lab link changed sucessfully!!!"
    
fi

if [[ $search3 != "" && $replace3 != "" ]]; then
    sed -i "s/$search3/$replace3/" $filename
    prompt -s "authuser value changed sucessfully!!!\n"
    
fi

g++ test1.cpp -ofast -o test1
prompt -i "Compiling text1.cpp...."
mkdir -p "$HOME/.local/bin"
ln -sf --verbose "$PWD/test1" "$HOME/.local/bin/"
if [[ "$PATH" =~ (^|:)"$HOME/.local/bin"(|/)(:|$) ]]; then
    prompt -i "$HOME/.local/bin is already added to PATH"
    
    prompt -s "That's it everything oK"
else
    prompt -e "$HOME/.local/bin is not in PATH"
fi
