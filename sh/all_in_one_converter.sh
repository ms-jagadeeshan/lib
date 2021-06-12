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

# echo like ...  with  flag type  and display message  colors
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

#creating text file in sorted
sortf() {
    read -p "Do you want to sort the file?(By default a-z)(Y/n): " op
    if [ $op == 'Y' -o $op == 'y' ]; then
        PS3='Enter your choice(1-6): '
        sort=("Oldest to newest" "Newest to oldest" "A-Z" "Z-A" "Largest to smallest" "Smallest to larges")
        select SORT_OPTION in "${sort[@]}"; do
            case $SORT_OPTION in
                "Oldest to newest")
                    ls *$FILE_TYPE -1tr  > ${WRK_DIR}/filelist.txt
                    prompt -i "File order"
                    prompt -i $(ls *$FILE_TYPE -tr)
                    break
                ;;
                "Newest to oldest")
                    ls *$FILE_TYPE -1tr > ${WRK_DIR}/filelist.txt
                    prompt -i "File order"
                    prompt -i $(ls *$FILE_TYPE -t)
                    break
                ;;
                "A-Z")
                    ls *$FILE_TYPE -1 > ${WRK_DIR}/filelist.txt
                    prompt -i "File order"
                    prompt -i $(ls *$FILE_TYPE)
                    break
                ;;
                "Z-A")
                    ls *$FILE_TYPE -1r  > ${WRK_DIR}/filelist.txt
                    prompt -i "File order"
                    prompt -i $(ls *$FILE_TYPE -r)
                    break
                ;;
                "Largest to smallest")
                    ls *$FILE_TYPE -1S > ${WRK_DIR}/filelist.txt
                    prompt -i "File order"
                    prompt -i $(ls *$FILE_TYPE -S)
                    break
                ;;
                "Smallest to larges")
                    ls *$FILE_TYPE -1Sr  > ${WRK_DIR}/filelist.txt
                    prompt -i "File order"
                    prompt -i $(ls *$FILE_TYPE -Sr)
                    break
                ;;
                *) echo "invalid option $REPLY";;
            esac
        done
    else
        ls *$FILE_TYPE -1 > ${WRK_DIR}/filelist.txt
        prompt -i "File order"
        prompt -i $(ls *$FILE_TYPE)
    fi
}

read -p "Enter your project name: "  PROJECT_NAME
prompt -i "\nChecking for the existence of program's working directory..."
prompt -i "All processing happens in \".all_in_one\" folder and output saved in \"all_in_one\" folder in your home directory\n"
[[ -d "${HOME}/.all_in_one/${PROJECT_NAME}" ]] ||mkdir -p "${HOME}/.all_in_one/${PROJECT_NAME}"
WRK_DIR="${HOME}/.all_in_one/${PROJECT_NAME}"



PS3='Enter your choice(1-6): '
types=("Image to pdf" "Compress pdf" "Pdf to image" "Merge pdfs" "Split pdf" "Append image to pdf" "Quick convert")
select TYPE in "${types[@]}"; do
    case $TYPE in
        "Image to pdf")
            flag=0
            while [ $flag -eq 0 ]; do
                read -p "Enter the folder path of images(relative path from your home folder e.g Photos/screenshots): " DIR
                if [ -d "${HOME}/${DIR}" ]; then
                    DIR="${HOME}/${DIR}"
                    cd "${DIR}"
                    echo "Directory $DIR exists."
                    flag=1
                else
                    prompt -e "[ Error! ] -> Directory ${HOME}/${DIR} does not exists.\n"
                fi
            done
            
            #option to specify file type
            read -p "Do you want to specify image type(Y/n): " op
            if [ $op == 'Y' -o $op == 'y' ]; then
                PS3='Enter your choice(1-5): '
                sort=("png" "jpg" "jpeg" "tiff" "webp" )
                select SORT_OPTION in "${sort[@]}"; do
                    case $SORT_OPTION in
                        "png")
                            FILE_TYPE=".png"
                            break
                        ;;
                        "jpg")
                            FILE_TYPE=".jpg"
                            break
                        ;;
                        "jpeg")
                            FILE_TYPE=".jpeg"
                            break
                        ;;
                        "tiff")
                            FILE_TYPE=".tiff"
                            break
                        ;;
                        "webp")
                            FILE_TYPE=".webp"
                            break
                        ;;
                        *) echo "invalid option $REPLY";;
                    esac
                done
            else
                
                prompt -w "Warning: Please make sure given folder doesn't contain any other format than image format(if you have any other, stop the program by pressing Ctrl + C) "
                prompt -i "Waiting 10 seconds\n"
                sleep 10;
                FILE_TYPE=""
            fi
            
            
            #sort options
            sortf
            
            mkdir ${WRK_DIR}/intermediate
            
            #fixed width
            while read -r line; do
                width=$(identify -format '%w' $line)
                height=$(identify -format '%h' $line)
                if [ width!=1080 ]; then
                    height=$((height*1080/width))
                    height=$(echo $height | awk '{print int($1)}')
                    convert $line -resize 1080x$height ${WRK_DIR}/intermediate/$line
                fi
                prompt -s "successfully changed the resoulution(to fixed width) of $line"
            done < ${WRK_DIR}/filelist.txt
            
            [[ -d "${HOME}/all_in_one/${PROJECT_NAME}" ]] || mkdir -p "${HOME}/all_in_one/${PROJECT_NAME}"
            OUT_DIR="${HOME}/all_in_one/${PROJECT_NAME}"
            
            #reading output file name
            read -p "Enter the output file name(without extension): " OUTPUT
            
            cd "$WRK_DIR/intermediate"
            prompt -i "\nConverting to pdf\n"
            
            #converting images to pdf using img2pdf
            ls -tr | tr '\n' ' '  | sed 's/$/\ --output\ my.pdf/' | xargs img2pdf
            
            #moving output to output folder
            mv my.pdf ${OUT_DIR}/${OUTPUT}.pdf
            
            #deleting the files in intermediate
            if [[ -d "$WRK_DIR/intermediate" ]] ; then
                rm *
            fi
            
            #success prompt
            prompt -s "Successfully converted!!!"
            break
        ;;
        "Compress pdf")
            flag=0
            while [ $flag -eq 0 ]; do
                read -p "Enter the folder path of images(relative path from your home folder e.g Photos/screenshots): " DIR
                if [ -d "${HOME}/${DIR}" ]; then
                    DIR=${HOME}/${DIR}
                    cd "${DIR}"
                    echo "Directory $DIR exists."
                    flag=1
                else
                    prompt -e "[ Error! ] -> Directory ${HOME}/${DIR} does not exists.\n"
                fi
            done
            FILE_TYPE=".pdf"
            ls *$FILE_TYPE -1 > ${WRK_DIR}/filelist.txt
            prompt -i "Pdfs going to be compressed"
            prompt -i $(ls *$FILE_TYPE )
            
            
            #option to select how much compression
            PS3='Enter your choice(1-3): '
            com_type=("Has a lower quality and smaller size. (72 dpi)" "Has a better quality, but has a slightly larger size (150 dpi)" "Output is of a higher size and quality (300 dpi)")
            select COMPRESSION in "${com_type[@]}"; do
                case $COMPRESSION in
                    "Has a lower quality and smaller size. (72 dpi)")
                        COM_TYPE="screen"
                        break
                    ;;
                    "Has a better quality, but has a slightly larger size (150 dpi)")
                        COM_TYPE="ebook"
                        break
                    ;;
                    "Output is of a higher size and quality (300 dpi)")
                        COM_TYPE="printer"
                        break
                    ;;
                    *) echo "invalid option $REPLY";;
                esac
            done
            
            [[ -d "${HOME}/all_in_one/${PROJECT_NAME}" ]] || mkdir -p "${HOME}/all_in_one/${PROJECT_NAME}"
            OUT_DIR="${HOME}/all_in_one/${PROJECT_NAME}"
            cd $OUT_DIR
            #compressing using ghost script tool
            if [[ -d "$OUT_DIR" ]] ; then
                while read -r line;
                do
                    echo gs -sDEVICE=pdfwrite -dCompatibilityLevel=1.4 -dPDFSETTINGS=/$COM_TYPE -dNOPAUSE -dQUIET -dBATCH -sOutputFile="$line" "$DIR/$line"
                    gs -sDEVICE=pdfwrite -dCompatibilityLevel=1.4 -dPDFSETTINGS=/$COM_TYPE -dNOPAUSE -dQUIET -dBATCH -sOutputFile="$line" "$DIR/$line"
                    prompt -s "Successfully compressed $line...."
                done < ${WRK_DIR}/filelist.txt
            fi
            break
        ;;
        "Pdf to image")
            ls *$FILE_TYPE -1 > ${WRK_DIR}/filelist.txt
            prompt -i "File order"
            prompt -i $(ls *$FILE_TYPE)
            break
        ;;
        "Z-A")
            ls *$FILE_TYPE -1r  > ${WRK_DIR}/filelist.txt
            prompt -i "File order"
            prompt -i $(ls *$FILE_TYPE -r)
            break
        ;;
        "Largest to smallest")
            ls *$FILE_TYPE -1S  > ${WRK_DIR}/filelist.txt
            prompt -i "File order"
            prompt -i $(ls *$FILE_TYPE -S)
            break
        ;;
        "Smallest to larges")
            ls *$FILE_TYPE -1Sr > ${WRK_DIR}/filelist.txt
            prompt -i "File order"
            prompt -i $(ls *$FILE_TYPE -Sr)
            break
        ;;
        *) echo "invalid option $REPLY";;
    esac
done
