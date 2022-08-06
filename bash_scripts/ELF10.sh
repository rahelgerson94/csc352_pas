#1. Write a bash command to print out a 
#text representation of all of the pop assembly 
#instructions from an ELF file named runme.

dir='~/experims/pa8'
CFLAGS='-Wall -Werror -std=c11'
cd ${dir}
gcc 3d.o generator.c -S -o /temp/generator.s
as /temp/generator.s -o /temp/generator.o

