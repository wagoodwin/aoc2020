
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

// Now that we've opened input3, we'll put input3's values in an array.

// Dimension 1 has 323 spots and dimension 2
// has 31 spots. Indexing goes array[row][col], so that means this
// array has 323 rows and 31 columns.

std::string input3array[323][31];

for (int i = 0; i < 323; i++) {

    for (int j = 0; j < 31; j++) {

        input3 >> input3array[i][j];
        // the loop is set up such that we'll every col in row 1,
        // every col in row 2, etc.
        
    }
    
}


std::cout << input3array[1][0] << "\n";

// Next, we'll turn the puzzle input into a giant map of 1s and 0s.
// We'll use an el-classico nested for loop. Here, we'll scan through 
// every row and then every column and switch the characters to 1s or 0s.

// We'll start off by defining our map. Because vectors aren't efficient here,
// apparently, we're gonna make map a multi-dimennsional array instead
// of a bunch of vectors.

/*

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




*/







return 0;

}
