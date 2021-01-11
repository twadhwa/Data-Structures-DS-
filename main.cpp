#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

// Function to generate a random number

int random_number_generator() {
    srand((signed)  time (0));
    int rand_number = rand()  ;


    return rand_number ;
}


// Function to get input from the user and to store them in an array
int input_getter(int number_of_players, int level){

    // Variable to store the number that will be used in our game
    int random_number ;

    // Variable to store the user input
    int user_input ;

    // Array to store the scores of every player
    int score_array[number_of_players];

    // Loop that will run 1 time for each player
    for (int i =0 ; i < number_of_players  ; i ++ ){


        // Statements for generating the number depending upon the level enter by the user
        if (level == 1 ){

            // %  will generate a number less than the given number
            random_number = random_number_generator() % 20 ;
        }

        if (level == 2 ){
            random_number = random_number_generator() % 50 ;
        }

        if (level == 3){
            random_number = random_number_generator() % 100 ;

        }

        cout<<"PLAYER " << i+1  << " will play now "<<endl;


        // Variable to store the number of turns taken by the player
        int  no_of_guesses = 0  ;


        // Loop for taking input from the user and to compare it with the generated number
        do {
            cout<<"Enter the number you want"<<endl;
            cin>> user_input;
            if (user_input > random_number ){
                cout<<"Please enter a smaller number"<<endl;



            }

            if (user_input < random_number ){
                cout<<"Please enter a larger number"<<endl;



            }

            

            no_of_guesses++;




        }
        while (user_input != random_number);
        score_array[i] = no_of_guesses;




    }


    // Variable to store the least turns
    int least_turns = score_array[0];

    // Variable to store the position of the winner player
    int winner = 1 ;
    for (int i =0 ; i < number_of_players ; i ++ ){
        if (score_array[i] < least_turns){
            least_turns = score_array[i];
            winner = i ;
        }

        cout << "The number of turns of every player "<< i + 1   << " is "<< score_array[i]<< endl;

    }

    cout<<"The winner of the game is player " << winner << " with turns "<< least_turns<< endl;

    return 0 ;





}






int main () {

    int number_of_players ;
    int level ;
    cout<<"Enter the number of players that will play the game "<<endl ;
    cin >> number_of_players;
    cout<<"Enter the level of the game you want to play on "<< endl;
    cin>> level ;

    input_getter(number_of_players, level);
    return 0 ;






}