#!/bin/dash



##############################	exo1	##############################
##############################	Q 1.1)	##############################
creationMakefileTest(){
echo '
CC=gcc
CFLAGS=-Wall -std=c99 -g
LDFLAGS=-g
TARGET=test_date_movie

all: $(TARGET)

$(TARGET): main.o date.o movie.o
	$(CC) $(LDFLAGS) $^ -o $@ 
main.o movie.o : movie.h date.h
date.o : date.h

%.o : %.c	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o
mrproper: clean
	rm -f $(TARGET)'>Makefile
}
creationMakefileTest $@




##############################	exo2	##############################
##############################	Q 2.1)	##############################
synopsis="usage : ./generateMakefile.sh [OPTION]..."
commandeHelp (){
	if test $# -eq 1 && test "$1" = "--help";then
		echo $synopsis
		echo 
		echo "Generates a Makefile from a project written in C language."
		echo
		echo "OPTIONS
	--help		Show help and exit.
	-d ROOTDIR	Set the root directory of the project.
			Without this option, the current directory is used.
	-o PROGNAME	Set the name of the executable binary file to produce.
			Without this option, the name 'a.out' is used."
		exit 1
	fi
}
commandeHelp $@



##############################	exo3	##############################
##############################	Q 3.1)	##############################
echo "Q 3.1)"
grep "#include" $1
echo
##############################	Q 3.2)	##############################
echo "Q 3.2)"
grep "#include" $1 | grep -v ">$"
echo
##############################	Q 3.3)	##############################
echo "Q 3.3)"
grep "#include" $1 | grep -v ">$"  | sed -e 's/#include "\(.*\)"/\1/'
echo
##############################	Q 3.4)	##############################
echo "Q 3.4)"
grep "#include" $1 | grep -v ">$"  | sed -e 's/#include "\(.*\)"/\1/' | tr '\n' ' '
echo







##############################    not mine        ################################
##############################################################

commandeOption(){
	PresenceOptionD=0
	PresenceOptionO=0
	compteurOptionD=0
	compteurOptionO=0
	
	
	for I in $@;do
		if test $I != "-d" && test $I != "-o" && test $PresenceOptionD -eq 0 && test $PresenceOptionO -eq 0 && test $PresenceOptionD -eq 0 && test $PresenceOptionO -eq 0 ;then 
			echo "Erreur : option $I isn't correct ">&2
			echo $synopsis
			exit 2
		fi	
		if test $I = "-d" || test $PresenceOptionD -eq 1;then 
			if test $I = "-d";then 
				compteurOptionD=$((compteurOptionD+1))
			fi 		
			if test $compteurOptionD -ge 2; then 
				
				echo "Erreur : you can have only one option -d">&2
				echo $synopsis
				exit 3
			fi
			if test $PresenceOptionD -eq 1; then 
				directory="$I"
                OptionD
				PresenceOptionD=2	
			else 
				PresenceOptionD=1
			fi
		fi
		if test $I = "-o" || test $PresenceOptionO -eq 1; then 
			if test $I = "-o";then 
				compteurOptionO=$((compteurOptionO+1))
			fi 	
			if test $compteurOptionO -ge 2; then 
				echo "Erreur : you can have only one option -o">&2
				echo $synopsis
				exit 4
			fi
			if test $PresenceOptionO -eq 1; then 
				OptionO $I 
				PresenceOptionO=0
			else 
				PresenceOptionO=1
			fi
		fi	
	done 
	
	if test ! $PresenceOptionD -eq 2;then 
		OptionD 
	fi
}

OptionD(){
	if test ! -d $directory; then 
		echo 'Erreur: bad usage of option. Look option --help'>&2
		exit 5
	fi
	
	command=$(ls $directory | grep -E '.c$'| wc -w)

	if test $command -eq 0 ;  then 
		echo 'Erreur: file type c doesn t exist'>&2
		exit 6
	fi
	
	cd $directory
}

OptionO(){

	command=$(echo $1|grep -E "^[^.]([a-zA-Z0-9._-])+")
	if test -z $command ; then 
		echo " Erreur : $1 doesn\'t have a good syntax or is a name of a hide file">&2
		exit 7
	fi
	
  	PROGNAME=$1
}


echo -n "" > file.txt

fct () {

    # nom des fichiers .h dans le fichier .c
	
    actualDeps=$(grep "#include" $1 | grep -v "^#include <" | sed -e 's/#include "\(.*\)"/\1/' | tr '\n' ' ')
    nbDeps=$(echo $actualDeps | wc -w)
    
    if test $nbDeps -gt 0; then
        for j in $actualDeps; do  
            echo "$directory/$j" >> file.txt
            fct $j
        done
    fi
}


# Appel la fonction pour plusieurs fichiers contenus dans un string

fct2 () {
    echo -n "" > "makefile.txt"
    for i in $(ls *.c); do
        oName=$(echo $i | sed 's/.c/.o : /g')
        echo -n "$directory/$oName" >> "makefile.txt"
        fct $i
        deps=$(sort file.txt | uniq | tr '\n' ' ')
        echo "$deps" >> "makefile.txt"
	
        echo -n "" > "file.txt"
    done

    rm -f "file.txt"
}


#PROGNAME="PROGNAME"
#directory="."

#commandeOption $@

#listeC=$(ls *.c)
#listeO=$(echo $listeC | sed 's/.c/.o/g')

#fct2
