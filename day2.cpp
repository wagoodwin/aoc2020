
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


// declare yuh function globally so we can use it in main():
std::vector <std::string> yuh(char a, std::vector <std::string> b);

int main() {


// grab the file and put in our
// object we've called input2
std::ifstream input2;
input2.open("input2.txt");

// initialize the vector we'll use to store
// the data
std::vector <std::string> input2Vec = {};

// initialize our dummy variable called value
std::string value;

// lil loop that enters in each value from input2
// to value and then fills inputVec with value.
while (input2 >> value) { 
    input2Vec.push_back(value); 
}

// test to see output
//for(int i = 0; i < input2Vec.size(); i = i + 1) {
//std::cout << input2Vec[i] << "\n";
//}

/*
Interesting observation:
the entries in the data are separated by spaces, so it turns out that
every n, n + 3, n + 6, ... entry is our npl, every n + 1, n + 4, n + 7, ...
entry is our policy_letter, and every n + 2, n + 5, n + 8, ... entry
is our password. We might be able to big-brain this problem and not have
to use anything super complex.


Brainstorming our approach:

1. get the data into cpp as a string
2. convert the number parts of the data to numbers
3. define the letter after the left space
as the policy_letter
4. Scan the password for the number of policy letters
npl
5. Say that if npl > lower bound and < upper bound,
do valid_passwords = valid_passwords + 1
6. output valid_passwords at the end and yeet in
the answer

*/

std::vector <std::string> pl_limit = {}; // pl_limit = policy letter limit, col 1
std::vector <std::string> pl = {}; // pl = policy letter, col 2
std::vector <std::string> password = {}; // col 3


// create a loop that fills up our vectors.

/* Something for which to watch out:

You need to divide the size of input2Vec by 3 when filling up the vectors.
That's because we're splitting the entries of input2Vec into three
equally-sized vectors, so we want our loop to run only while we've got 
values for which to fill our vectors.

If we don't divide input2Vec.size() by 3, pl_limit, for example,
will fill up a third of the way through the total number of loops we run.
The other two thirds of loop won't do anything, and the computer will
get confused, because it doesn't know what to put in the vector for 
that remaining two thirds of iterations. 

I think that's why we were getting an error std:bad_alloc, which
means that the compooter ran out of memory.


*/


for(int n = 0; n < input2Vec.size()/3; n = n + 1){

    pl_limit.push_back(input2Vec[3*n]);
    pl.push_back(input2Vec[1 + 3*n]);
    password.push_back(input2Vec[2 + 3*n]);

    //std::cout << input2Vec[1 + 3*n] << "\n";

}


// Now we're gonna start altering our vectors. 

// First, we're gonna get rid of the colon after each letter
// in the pl vector.

// Here's something to note: vectors of strings can be referenced by
// entry through vec[m], but they can also be referenced by position
// in a specific entry. For example, if you have an n-dimensional 
// vector vec, vec[0][0] will give you the 0th value in the 0th
// entry of the vector.

// This fact is handy to us, because we want to get rid of the 
// colons in the pl vector.

// example:
//std::cout << pl[2][1] << "\n";  

// creating plnew, which is pl, but without :. Using the function
// we made below called yuh to get rid of the colon.
// turns out I didn't have to do this lol
std::vector <std::string> plnew = yuh(':',pl); 

// test
//std::cout << plnew[2] << "\n";

// Now that we've fixed pl and made it plnew, we've gotta make
// our npl vector. Our npl vector is a vector of integers
// that tells you the number of policy letters in a password.

// npl = number of policy letters
std::vector <int> npl(1000);
// setting a pre-defined size for npl; we know it has to be the 
// size of the password vector

// build npl vector

for (int i = 0; i < 1000; i = i + 1) {

    for (int j = 0; j < password[i].length(); j = j + 1) {

        if(password[i][j] == pl[i][0]) {

            npl[i] = npl[i] + 1;

        }

    }
}

/*
// testing to see npl's output
for (int p = 0; p < npl.size(); p = p + 1) {
    std::cout << npl[p] << "\n";
}
*/

// Now, we need to turn pl_limit into a list of integers
// so we can compare it to npl. We're gonna turn it into
// two vectors: one vector will have the lower limit
// and the other vector will have the upper limit.

// We're using a constructor here to set our vectors
// with a predefined size. This method is different
// than initializing an empty vector. This choice
// will be explaiend later.
std::vector <std::string> pl_limit_lower(pl_limit.size());
std::vector <std::string> pl_limit_upper(pl_limit.size());

/*


Procedure: 
1. Scan through pl_limit. If we hit a dash,
2. put the numbers before the dash in pl_limit_lower
3. put the numbers after the dash in pl_limit_upper
4. Should end up with two vectors of integers


Alternate approach:

1. turn pl_limit into a string without the dashes
2. turn pl_limit into an integer vector
3. Make three cases (switch statement?) to sort stuff
4. If pl_limit[i].length() = 2, 
put pl_limit[i][j] in pl_limit_lower and pl_limit[i][j + 1] in pl_limit_upper
5. If pl_limit[i].length() = 3,
put pl_limit[i][j] in pl_limit_lower and put the rest in pl_limit_upper
6. If pl_limit[i].length() = 4,
put the first half of pl_limit in pl_limit_lower and the rest in pl_limit_upper
7. We'll end up with two sorted and equally-sized vectors


*/ 

// First, we'll apply yuh to get rid of the dashes:

std::vector <std::string> pl_limit_new = yuh('-' , pl_limit);

std::cout << pl_limit_new[0] << "\n"; //test code


// Now,  we're gonna
// institute our lil algorithm to sort the integers into
// either pl_limit_lower or pl_limit_upper. Everything
// is still a string at this point.


for (int i = 0; i < pl_limit.size(); i = i + 1) {


    if( pl_limit_new[i].length() == 2) {

        pl_limit_lower[i][0] = pl_limit_new[i][0];
        pl_limit_upper[i][0] = pl_limit_new[i][1];

    }

    else if (pl_limit_new[i].length() == 3) {

        pl_limit_lower[i][0] = pl_limit_new[i][0];

        pl_limit_upper[i][0] = pl_limit_new[i][1];
        pl_limit_upper[i][1] = pl_limit_new[i][2];


    }

    else if (pl_limit_new[i].length() == 4) {

        pl_limit_lower[i][0] = pl_limit_new[i][0];
        pl_limit_lower[i][1] = pl_limit_new[i][1];

        pl_limit_upper[i][0] = pl_limit_new[i][2];
        pl_limit_upper[i][1] = pl_limit_new[i][3];

    }

}

// test output
//for (int i = 0; i < pl_limit_lower.size(); i++) {std::cout << pl_limit_lower[i] << "\n";}
std::cout << pl_limit_lower[6][0] << "\n"; // seems to be working
std:: cout << pl_limit_upper[0][0] << "\n"; // this one doesn't. Will have to investigate


// Next, we'll turn pl_limit_upper and pl_limit_lower from vectors of strings
// to vectors of ints.
// Code modded from user1601401 on StackO

// might have to fix loop.

    std::vector<int> pl_limit_lower_ints;
    for (int i=0; i<= 999; i++)
    {
     int num = atoi(pl_limit_lower.at(i).c_str());
     pl_limit_lower_ints.push_back(num);
    }

//test
std::cout << "pl_limit_lower ints: " << pl_limit_lower_ints[0] << "\n";


// And we'll do it again for pl_limit_upper: 


   std::vector<int> pl_limit_upper_ints;
    for (int i=0; i<= 999; i++)
    {
     int num = atoi(pl_limit_upper.at(i).c_str());
     pl_limit_upper_ints.push_back(num);
    }

/* 

//test
std::cout << "pl_limit_upper ints: " << pl_limit_upper_ints[1];

// more testing
for (int i = 0; i < pl_limit_upper_ints.size(); i++) {

    std::cout << pl_limit_upper_ints[i] << "\n";
}



*/









/*
pl_limit_lower.push_back(pl_limit_new[0]);

// Brutal scene.
std::cout << pl_limit_new[0][0] << "\n";
std::cout << pl_limit_lower[0] << "\n";

std::vector <std::string> swag(20);
swag[0][0] = pl_limit_new[0][0];
std::cout << swag[0][0];

*/


// so push_back() doesn't let you add on specific characters.
// more specifically: push_back() doesn't allow more than 1 overload. 
// Thus, we have to pre-size our vector and reference specific entries.

int valid_passwords = 0;

for (int i = 0; i < 1000; i = i + 1 ) {

    if (npl[i] >= pl_limit_lower_ints[i] and npl[i] <= pl_limit_upper_ints[i] )

        valid_passwords = valid_passwords + 1;

    else {

        valid_passwords = valid_passwords;
    }

}

std::cout << "Number of valid passwords:" << valid_passwords << "\n";


// Okay. We have an answer, but it's too low, apparantly.

// test to make sure vectors are working. Seems like we're good.
//std::cout << pl_limit_lower_ints[800] << "\n";
//std::cout << pl_limit_upper_ints[800] << "\n\n";

// My guess is that we have an issue with npl.
// inspect npl vector
//for(int i = 0; i < npl.size(); i++) {std::cout << npl[i] << "\n";}

// yup. The issue is npl. Gotta fix it.
// fixed npl

//std::cout << npl[998];






// PART 2



/*

The problem here is shaped differently. Here's how a valid password
is determined now:

1. First column: character positiosn for a password
2. Second column: policy letter
3. For a password to be valid, the policy needs to be in ONLY ONE,
not more or fewer, of the outlined character positions in column 1.


*/


int valid_passwords_p2 = 0;

for (int i = 0; i < 1000; i++) {


   // for (int j = 0; j < password[i].length(); j = j + 1) {


        if ( plnew[i][0] != password[i][pl_limit_lower_ints[i]-1] and plnew[i][0] == password[i][pl_limit_upper_ints[i]-1] ) {

            valid_passwords_p2 = valid_passwords_p2 + 1;

        }

        else if ( plnew[i][0] == password[i][pl_limit_lower_ints[i]-1] and plnew[i][0] != password[i][pl_limit_upper_ints[i]-1] ) {

            // issue. When we get to i = 1000, we end up referencign pl_limit_lower_ints[1001], which doesn't exist. Gotta fix that.
            // Note that the problem is that we're using zero-indexing for a problem that uses 1-indexing. 

            valid_passwords_p2 = valid_passwords_p2 + 1;
        }

        else {

            valid_passwords_p2 = valid_passwords_p2;


        }

    //}

}


// 388 is the correct answer!
std::cout << "Part 2, valid passwords: " << valid_passwords_p2 << "\n";



// When you return, comment this code and then peruse the other solutions.








return 0;


}









// function that takes out specific characters from a string

// function inputs: character you want to remove, vector of strings
// function output: new vector with removed characters
// yuh: yuh

// guts of this function came from Oliver Poulin on SO

std::vector <std::string> yuh(char a, std::vector <std::string> b) {

// outer loop scans through every entry (like each column) of the vector
for(int k = 0; k < b.size(); k = k + 1) {

    // inner loop scans through every value of each column
    for(int l = 0; l < b[k].length(); l = l + 1) {
        
        // if, in some column, the value == the character we blacklisted,
        // use the erase function to delete that character
        if ( b[k][l] == a ) {

            // erase: first argument is the position of the first character
            // you want to erase. Second argument is the number of 
            // characters you want to erase.
            b[k].erase(l,1);

            // We have to tick down l so we can get out of the if statement.
            // Once l goes under 0, the computer moves a level up and starts
            // to scan the next letter (I think?)
            l = l - 1;
        }
    }
}

return b;


}





// CAN WE OVERLOAD YUH SO IT ALSO WORKS ON INTS? CHECK BODEBADEMY

