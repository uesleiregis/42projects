if [ $# -eq 0 ] ; then
    echo "No arguments supplied"
    exit 0
fi
if [ "$#" -eq 1 ] ; then
    echo "$1"
    exit 0
fi
if [ "$#" -eq 2 ] ; then
    echo "$1"
    echo "$2"
    exit 0
fi
if [ "$#" -gt 2 ] ; then
    echo "$1"
    echo "$2"
    echo "$3"
    exit 0
fi


# descobrir qual o erro deste codigo abaixo
# arg=("$@")
# if (( $# == 0)); then
#     echo "No arguments Supplied"
# fi
# for ((i = 0; i < $#; i++))
# do
#     if ((i >= 3)); then
#         break;
#     fi
#     echo ${arg[i]}
# done