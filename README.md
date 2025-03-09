# inet3101-lab2
Author: Hayat Muhumed collaborate with Sulekha Abdi

This program is a simple menu-based system that keeps track of parts using dynamic memory. 
Users can add new parts, delete the last one, print all parts, see how many parts are stored,
 and check the database size. The program uses malloc() and free() to manage memory, 
 so all data is lost when the program exits.
The menu makes it easy to use. You type a number to pick an option, like adding a part or printing the list.
 If there are no parts, it tells you. If you try to delete when there’s nothing left, 
 it warns you. 
 To run it, first compile with gcc -o lab2 lab2.c, then start it with ./lab2.