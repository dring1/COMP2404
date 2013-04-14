Devon Ring
100801142

To compilate type cd into assignment folder
type make
to run type
./run

The program will loop through the scenario and display the outcomes

Programmed at linux 64-bit then copied to lambda server compiled. Copy and pasted into this folder.

While running valgrind alongside with curses valgrind chunks hard.
ncurses leak is quite significant.


With a full screen terminal at 1200x800 resolution the memory leak is constantly
HEAP SUMMARY:
==11724==     in use at exit: 157,044 bytes in 210 blocks
==11724==   total heap usage: 230 allocs, 20 frees, 161,583 bytes allocated

160k bytes at exit curses leaking like crazy at a 1200x800 resolution terminal.

Program can be ran at 600x600 pixels, but chose 1200x800 as it is more easily obtainable on monitors

When I did valgrind in a much smaller terminal the usage at exit dropped to 40k
Added start screen and insert any key into the game.

Once the program is complete hit a key to end the game : )

Cheers,
Devon.
