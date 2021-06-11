
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

/*

Idea here: turn the puzzle input into a giant matrix of 1s and 0s.
Trees will be 1s and open spaces will be 0s. I got this idea from Daniel
Persson on his YT channel.

Then, we can make some sort of loop that looks at each row and checks
the location that the toboggan would hit-- that is, the loop will check
points that the line y = -x/3 intersects. 

If that point is a 1, do tree_number = tree_number + 1. If that point
is 0, do tree_number = tree_numbers.

Then, we'll spit out out output.

*/


/*

Also, I think our slope needs to loop back to the front when it hits the end
of the map bounds. 

The dimensions of the forest are 323 x 31, and those dimensions are such that
we always start at the top left box every time we hit the end of the text. 

Thus, we can define 1 cycle to be the number of rows the toboggan goes before
repeaing. By inspection of the puzzle input, 1 cycle is 10 rows.

*/

int main() {

// make an object of class ifstream called input3
std::ifstream input3;
// use the member function .open() of the class ifstream to load in the file
input3.open("input3.txt");

// make input3Vec. It'll have 323 rows, where each row is a string line.
// We're initializing the number of rows with a constructor.

std::vector <std::string> input3Vec(323);

// initialize our dummy variable called value
std::string value;

// lil loop that enters in each entry from input2
// to value and then fills inputVec with value.
while (input3 >> value) { 
    input3Vec.push_back(value); 
}

// test to see output
//for(int i = 0; i < input3Vec.size(); i = i + 1) {
//std::cout << input3Vec[i] << "\n";
//}


/*

check each line. The position you check
in each line is based on the remainder.

Specifically, because the slope is down 1 right 3,
that means you'll be checking the 0th entry in row 0,
the 3rd entry in row 1, the 6th entry in row 2,
the 9th entry in row 3, etc. until you hit the 30th
entry in row 10. Then, the pattern repeats and you
check the 0th entry in row 11, 3rd entry in row 12, etc.

So, to find which entry we wanna check, we can find
the remainder of 31/row number. Notice that 31/(row = 1)
= 31, so  R = 0, which corresponds to the entry
we wanna check. Also notice that 


323/1 = 323
323/


*/


int trees;

for (int n = 0; n < 11; n++)


for (int i = 0; i < 323; i++) {

    if ( input3Vec[i][0 + 3*n] == '#' ) {

        trees = trees + 1;
    }

    else {

        trees = trees;

    }





}

std::cout << trees;




































// Next, we'll turn the puzzle input into a giant map of 1s and 0s.
// We'll use an el-classico nested for loop. Here, we'll scan through 
// every row and then every column and switch the characters to 1s or 0s.

// We'll start off by defining our map. Because vectors aren't efficient here,
// apparently, we're gonna make map a multi-dimennsional array instead
// of a bunch of vectors.

/*

int input3array[323][31];
int map[323][31];

// Now, take the values from our input file and put then in map

for (int i = 0; i < 323; i++) {

    for (int j = 0; j < 31; j++) {

        if (input3array[i][j] == '#' ) {

            map[i][j] = 1;

        }

        else {

            map[i][j] = 0;

        }

    }
}


std::cout << map[0][0];


*/



return 0;

}
