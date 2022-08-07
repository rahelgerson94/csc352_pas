#1. Write a bash command to print out a 
#text representation of all of the pop assembly 
#instructions from an ELF file named runme.

dir='~/experims/pa8'
gcc_args='-Wall -Werror -std=c11'

#generate object code
gcc $(gcc_args) 3d.o generator.c -g -S -o generator.s #generate assembly code
as generator.s -o generator.o #generate object code

#different ways to view data about the object code
readelf -a generator.o > generator_readelf.txt #save
objdump -D -S -t generator.o > generator_objdump.txt #save output of objdump. this has the assembly commands. -D displays the assembly code

#display only the pop commands
generator_objdump.txt | grep pop
