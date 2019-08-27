Core War is a 1984 programming game in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language. 
The goal of the game is to prevent other programs from functionning correctly by any means necessary. 
We first create a virtual machine in which programs (written by players) fight. The objective of each process is to survive, which means to execute a special instruction "live". The programs run simultaneously in the virtual machine and on the same memory space, they can therefore write on each other. 
The winner of the game is the last program who ran a "live" instruction. 

The project is split in three parts :
- The Assembler : Allows to write programs to fight. It will need to understand the assembly language in order to generate binary programs that can be interpreted by the virtual machine. 
- The Virtual Machine : Reads the binary programs (the champions) and provides them with a standard execution environment. It offers a lot of features useful to the fight. It has to be able to run multiple programs simultaneously.
- The Champion : It has to fight and to be the winner of the arena in the virtual machine. It is written in the assembly language needed to run on the virtual machine. 

# Resources
- http://assiste.com.free.fr/p/abc/a/core_war.html
- http://www.sebsauvage.net/comprendre/corewars/index.html
