

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector <int> inputVec = {};
std::ifstream input;

std::vector <int> buildVec(std::ifstream x);

int main() {

// creating an object of type ifstream. Recall that a class
// is just a user-defined type. ifstream has lots of 
// member functions in it that let you operate on files.

// With the oistream class, we make an object
// (fancy variable) called input.

// Then, we open the file "input.txt" with the last
// part. That is, with the object we've called
// input, we're assigning it to the data "input.txt."

// So note: ifstream lets us read a data file. If we
// wanted to write to that data file and change values
// in it or summffin, we'd use ofstream.

input.open ("input.txt");

// this portion of code takes our object called input
// and applies the function .is_open() to it. This 
// function tells you if the function is well, open.

// The ! sign means "is not", which means that if 
// the function is not open, we'll spit out a line
// to the console telling you that.

if (! input.is_open())
	{
		std::cout << "Unable to open file" << "\n";
		return 1;
	}

else {
    std::cout << "esketit" << "\n";
}

// The approach now will invovle taking the data from the
// .txt file and putting everything into a vector here in
// our code. That way, we won't have to re-read the file 
// every time we wanna mess with the data.

// this line says to take the vector inputVec
// and fill it up with the entries from input.

// However, I grabbed the idea of input >> value
// form online, and I don't really know what it means.
// I think it's saying to take each value from 
// input and store it in variable value? Then, we
// do that over and over until we get inputVec filled up.

int value;
while (input >> value) { 
    inputVec.push_back(value); 
}

//std::cout << inputVec[inputVec.size()-1];

// now that we've got our vector of values, we're gonna
// actuallly do the challenge.

// Objective: find the two entries that 
// sum to 2020 and find their product.

// test: print out vector to console

// to find two entries that sum to 2020, we're gonna
// have to test a whole bunch of entries.

// Mathematically, it'll involve taking the first number,
// adding it to every number in the list
// and seeing if any of those numbers summed to 2020. 

// Then, we'll have to repeat that process with
// the next number and the next number until
// we make our way down the entire list.

// Day 2 takes this concept and extends it to 3 numbers.

/*

The algorithm is a bit beefier here. We start with the number
at position 0 and hold it constant. Then, we take the number 
at position 1 and hold that constant, too. Then, we only
change the number at position three and add up those three
numbers, cycling down the list and checking for sum == 2020.

On the next set of iterations, we start with the number at position
0 and hold it constnat. Then, we take the number at position 2 and hold 
it constant. Then, we only chnage the number at position and three
and add up those numbers, checkign for sum == 2020.

Once we've checked combo in this style, we move outside the loop
once more and start with the number at position 1 and hold it constant.
Then, we take the number at position 1 and hold it constant, too. 


// correct answer: 127642310

*/


for (int k = 0; k < inputVec.size(); k = k + 1) {

    for (int j = 1; j < inputVec.size(); j = j + 1) {

	    for (int i = 1; i < inputVec.size(); i = i + 1) {

		    int sum = inputVec[k] + inputVec[k + j] + inputVec[k + j + i];
		    // std::cout << sum << "\n"; 
		    int product = inputVec[k] * inputVec[k + j] * inputVec[i + j + k];

            if (sum == 2020) {
                std::cout << product << "\n";
            }


           }

    }

}

/*


To walk through the code, we start with k = 2 on the first loop and move
to the second loop. We start with j = 1 in the second loop and move to the 
third loop. In the third loop, we start with i = 0. Thus, with i = 0; 
j = 1, and k = 2, we run through our condition, which is to add the entries
inputVec[1] + inputVec[2] + inputVec[3] and check if the sum == 2020.
If the sum == 2020, print out the product of those numbers.

Note that in the inner loop, only i is changing. That means we're taking the 
first number and adding the two numbers in front of it, the second number
and adding the two numbers in front of it, etc. until we've tried all combos.

Then, we move out of the loop and repeat the process with a higher index.

*/

return 0;

}



