#!/bin/bash

#make clean
#make

cd `dirname $0`

LENGTHA=100
LENGTHB=5
TESTS=10

if [ "$1" = "" ]
then
 echo "Usage of this script:"
 echo "   ./autotest.sh program operator [length1] [length2]"
 echo "Where:"
 echo " program - the name of program to test - your program"
 echo " operator - the operato that should be used, for example + * ?" 
 echo " length1 - the length of first operand"
 echo " length2 - the length of second operand" 

 echo ""
 echo "Example"
 echo "   ./autotest.sh ./solution1 \"*\" 500 500"
 exit 100
fi
if [ "$2" = "" ]
then
 echo "nalezy podac operator do sprawdzenia (+ albo *)"
 echo "na przyklad"
 echo "  \$ ./autotest.sh matma \"*\""
 exit 100
fi

if [ "$3" != "" ]
then
    LENGTHA=$3
fi

if [ "$4" != "" ]
then
    LENGTHB=$4
fi

TESTAPP="$1"

# wybranie wzorcowej implementacji
if [ $(uname -m) = "x86_64" ] 
then
echo "Test dla 64 bitowego systemu"
APPNAME=math64
else
echo "Test dla 32 bitowego systemu"
APPNAME=math32
fi

mkdir -p /tmp/$USER
FRN1="/tmp/$USER/rn1.tmp"
FRN2="/tmp/$USER/rn2.tmp"



for i in `seq 1 $TESTS`
do
    FNAME=test_${i}_add_in.txt
    RNAME=test_${i}_add_out.txt
    TNAME=test_${i}_add_out.log
    printf "" > $FNAME
    printf "" > $FRN1
    printf "" > $FRN2
    if [ "$(($RANDOM % 2))" = "0" ]
    then
	printf "-" >> $FRN1
    fi
    for i in `seq 1 $LENGTHA`
    do
	printf "%04x" $RANDOM >> $FRN1
    done
    if [ "$(($RANDOM % 2))" = "0" ]
    then
	printf "-" >> $FRN2
    fi
    for i in `seq 1 $LENGTHB`
    do
        printf "%04x" $RANDOM >> $FRN2
    done
    RN1=`cat $FRN1`
    RN2=`cat $FRN2`
    printf "%s %s %s" "$RN1" "$2" "$RN2" >> $FNAME
    cat $FNAME
    printf "\n" >> $FNAME
    printf " = "
    cat $FNAME | ./${APPNAME} | tr -d '\r' > $RNAME
    cat $FNAME | ${TESTAPP} | tr -d '\r' > $TNAME
    cat $TNAME | tr -d '\n' 
    printf " ... "
    diff $RNAME $TNAME > /dev/null
    if [ $? = "0" ] 
    then
	echo "OK"
	rm -f $TNAME $RNAME $FNAME
    else 
	echo "ERROR!"
    fi
done



# przypadek ze rowne
i="00"
FNAME=test_${i}_add_in.txt
RNAME=test_${i}_add_out.txt
TNAME=test_${i}_add_out.log
printf "" > $FNAME
printf "" > $FRN1
printf "" > $FRN2
for i in `seq 1 $LENGTHA`
do
	printf "%04x" $RANDOM >> $FRN1
done
cat $FRN1 > $FRN2

RN1=`cat $FRN1`
RN2=`cat $FRN2`
printf "%s %s %s" "$RN1" "$2" "$RN2" >> $FNAME
cat $FNAME
printf "\n" >> $FNAME
printf " = "
cat $FNAME | ./${APPNAME} | tr -d '\r' > $RNAME
cat $FNAME | ${TESTAPP} | tr -d '\r' > $TNAME
cat $TNAME | tr -d '\n' 
printf " ... "
diff $RNAME $TNAME > /dev/null
if [ $? = "0" ] 
then
echo "OK"
rm -f $TNAME $RNAME $FNAME
else 
echo "ERROR!"
fi


#make clean
