# TripleX-
A small command-line game created using C++ following https://www.udemy.com/course/unrealcourse/

Overall functionality is solid, current issues include:

-String and console output not properly wrappin(resulting in text not being visible in windowed mode without scrolling(unlikely to fix)

-First level is not randomized. Could be fixed by making the range window a bit larger, or creating smaller randomization by having the initial level fall between a modulus of 0-3 for a slight bit of variety

-if/else statements are a bit messy. Used to create a bit more variety and uniqueness in the output. There is probably a better way to branch.

-Console output text could be put in a separate document for better readability and editability. 

-The system("pause"); function apparently doesn't exist on Linux. Not sure what the alternative would be. 

-Displaying the level in the introduction function is very hard to see and differentiate from the rest of the text. Ideally you only show the introduction text for the first time the game is run and you have a much smaller more digestable string of texts for every completed level afterwards. 

-Because of the system("pause") function, there is a lot of annoying "press enter to continue..." text present. Ideally replace it with something else, or just format where it displays better. 

-Still not entirely sure how srand(time(NULL)); function works outside of seeding, passing the time function, and then passing NULL. Not sure what NULL does tbh.

For my first CPP project, not too bad considering I was just working on UE4 BPs.

*I forgot how to use GIT Im sorry :(*
