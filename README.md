# DOLLARS-AND-CENTS
You are provided with a sequence of integers of length n. You can make guesses on what that number can be. Once you make a guess in return you will receive 2 outputs i.e. number of ’Cents’ and ’Dollars’.‘Cents’ denote the number of digits guessed which are present in the given sequence but are out of position, whereas ‘Dollars’ represent the number of digits guessed which are present in the sequence at the very position you guessed them at. As you might have guessed it, the game ends when you get exactly n Dollars. Your solution must be optimised enough to run for strings of length 10.

Although I was not able to impliment with ROS I wrote the logic in cpp; How the code works is it outputs the order of the digits and instead of the checker function we behaving as the checker enter the dollars and cents and then this repeats till we reach the solution and congratulation message prints.
The second part of the problem can be solved using the same logic as if we are given x we can convert it into dollars and cents.
Let's say that we receive y as the x count this is assuming we have guessed all the digits present in the code. Then the number od imaginary dollars would be y - (number of digits) and cents would be (number of digits) - dollars. Hence converting the problem into the first one.

This code works ahead when we have guessed all the correct digits present in the number which is doable in case of the first part just by inputting each permutations and if the dollars plus cents reach the number of digits we have our correct set of digits and then the work of the code begins; However this is a fatal flaw in case of when we impliment this code for the second part as guessing if the correct set of digits is present in the current set is a hard task.
Let's say if we input a select permutation and one of the digit is in its correct place then its contribution to x that is 2 may shadaw the no contribution of a digit that is not even in that code and may lead us to beleive that we have the proper set to start trying to arrange them in the correct order.

Otherwise if the string length is 10 both the codes will work perfectly. 
