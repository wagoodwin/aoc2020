
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

// DO WE ALSO HAVE TO CHANGE THE TYPE OF INPUT3? IT WON'T LET US 
// REFERENCE ANY ENTRY WE WANT WITH IFSTREAM, IT SEEMS.




// Next, we'll turn the puzzle input into a giant map of 1s and 0s.
// We'll use an el-classico nested for loop. Here, we'll scan through 
// every row and then every column and switch the characters to 1s or 0s.

// We'll start off by defining our map. Because vectors aren't efficient here,
// apparently, we're gonna make map a multi-dimennsional array instead
// of a bunch of vectors.

std::vector <int> map(323,31);

for (int i = 0; i < 323; i++) {

    for (int j = 0; j < 31; j++) {

        if (input3[i][j] == '#' ) {

            map[i][j] = 1;

        }

        else {

            map[i][j] = 0;

        }

    }
}












return 0;

}
