#include<iostream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>
#include<limits>
#undef max

using namespace std;

int countHang; // How many parts of the hanged man
char ch; // Input Variable
bool active, flag, tag;  // check variables
string wordName, wordHint, answer, wordType; // For word

void Main_menu();
void Rules();
void HintWord();
void HangBoard();
void AgainMenu();
void HangCheck();
void QuitGame();

string keyboard =           "\t\t  ___________________________________  \n"
                            "\t\t |             KEYBOARD              | \n"
                            "\t\t |-----------------------------------| \n"
                            "\t\t | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | \n"
                            "\t\t |-----------------------------------| \n"
                            "\t\t | a | b | c | d | e | f | g | h | i | \n"
                            "\t\t |-----------------------------------| \n"
                            "\t\t | j | k | l | m | n | o | p | q | r | \n"
                            "\t\t |-----------------------------------| \n"
                            "\t\t | s | t | u | v | w | x | y | z | 0 | \n"
                            "\t\t |-----------------------------------| \n"
                            "\t\t |___________________________________| \n";


void Main_menu(){
	        // STARTING WINDOW
        active = 1; 
        while (active) {

            cout <<     "\t\t  ____________________________________  \n"
                        "\t\t |              MAIN MENU             | \n"
                        "\t\t |             -----------            | \n"
                        "\t\t |     --XX---            ---XX--     | \n"
                        "\t\t |       :      ~Hangman~     :       | \n"
                        "\t\t |       :                    :       | \n"
                        "\t\t |       O      1.  Play      O       | \n"
                        "\t\t |      /|\\                  /|\\      | \n"
                        "\t\t |      / \\     2.  Rules    / \\      | \n"
                        "\t\t |                                    | \n"
                        "\t\t |              3.  Exit              | \n"
                        "\t\t |____________________________________| \n\n\n"


                "\t\t            -->";
            cin >> ch;   // Choice menu with conditions incase of wrong input
            if (ch == '1') {
                active = 0;
                system("cls");
                HintWord(); 
            }
            else if (ch == '2') {
                active = 0;
                system("cls");
                Rules();
            }
            else if (ch == '3') {
                system("cls");
                active = 0;
                QuitGame();
    			//EXIT
            }
            else {
                system("cls");
                //WRONG CHOICE
            }
        }
}

void Rules() {

        cout << "\n\n\t\t                                        ~WELCOME~                                            \n"
            "\n\n\t\t  ------------------------------------------------------------------------------------------ \n"
            "\n\n\t\t  (1)Choose a person as a 'host'.                                                            \n"
            "\t\t  Host will invent the puzzle and the rest of them have to solve.                                \n\n"
            "\t\t  (2)Host should possess the ability to spell confidently. Otherwise it's too hard to win.       \n\n"
            "\t\t  (3)If you are the host you should choose a secret word. The word should be difficult to guess. \n"
            "\t\t  Those kind of words usually have uncommon letters like 'z', 'q'  and only few vowels.          \n\n"
            "\t\t  (4)If you are a Player start guessing letters. Once the word has been selected game will       \n"
            "\t\t  display how many letters they need,to find the secret word. Begin with selecting relevant      \n"
            "\t\t  letters for the secret word.                                                                   \n\n"
            "\t\t  (5)Whenever guessing a wrong Letter he/ she will get a strike and it will  bring them closer   \n"
            "\t\t  to the ending part.                                                                           \n"
            "\t\t  To show this, the game will display a simple strike figure of a hanging man, it will add       \n"
            "\t\t  an extra Strike for every wrong answer.                                                        \n\n\n"
            "\t\t                                    *** 1.  Go Back.                                             \n"
            "\t\t  ------------------------------------------------------------------------------------------ \n"
            "\t\t                                     -->";
        cin >> ch;
        if (ch == '1') {
            active = 0;
            system("cls");
            Main_menu();
        }
        else {
            system("cls");
            //WRONG CHOICE
        }
}

void HintWord() {
	
		cout  <<  "\t\t   _____________________________________________________________________________________  \n"
		          "\t\t  |                                                                                     | \n"
	              "\t\t  |  Your friend is trapped in a devil's den. You and your team is going to save him.   | \n"
				  "\t\t  |  A password, hint and a category are given to you by your friend.                   | \n"
				  "\t\t  |  If you guess the word correctly he is alive.                                       | \n"
				  "\t\t  |  Otherwise he will be hanged and come to death.                                     | \n"                                           
	              "\t\t  |                                                                                     | \n"
				  "\t\t  |_____________________________________________________________________________________| \n";		
				  
        cout      << "\t\t            ______                     \n"
            "\t\t           |      |                    \n"
            "\t\t           |      :                    \n"
            "\t\t           |                           \n"
            "\t\t           |          \\ O    O       \n"
            "\t\t           |           |\\   /|7       \n"
            "\t\t        ___|___       / \\   / \\      \n";

        cout << "\n\n\t\t *** Host, Enter secret word to be found:  \t\t (*) PLAYERS DON'T LOOK AT THIS SCREEN!!\n"

            "\t\t               --> ";
        cin >> wordName;
        cout << endl;
        cout << "\t\t *** Enter word type e.g Movie,Food/Drink,Song..etc: \n"

            "\t\t               --> ";

        cin.ignore(numeric_limits< streamsize>::max(), '\n');

        getline(cin, wordType);
        cout << endl;

        cout << "\t\t *** Enter hint:                           \n"

            "\t\t               --> ";

        getline(cin, wordHint);

        // Converting all of it into Underscores
        for (unsigned i = 0; i < wordName.length(); ++i)
            answer += "_";


        system("cls");
        HangBoard();  

}

void HangBoard() {

        int i = 0;
        active = 1;

        while (active) {
            HangCheck();
            cout << "\t\t ~TYPE~ \"" << wordType << "\"\t\t  ";
            //Displaying the word as underscores with spaces
            for (unsigned i = 0; i < wordName.length(); ++i) {

                cout << answer[i] << " ";
            }
            //ABC
            cout << "\n\n\t\t ~HINT~ \"" << wordHint << "\"\n\n";
            cout << "\t\t\t\t\t\t\t (*) '#' Shown on the keyboard means it's already tried.";
            cout << "\t\t\t\t\t\t\t\t (*)  Enter '.' to exit.";
            cout << "\n\n" << keyboard;

            // Just wanted to try doing a little fun trick , if they inputted "#" as their first choice of character
            // It would automatically show the first letter of the hidden word , if they use "#" as any other input of character
            // Which isnt the first choice, it wouldn't work :: will mark the trick part with //TRICK comment
            if (flag == 1) {  


                cout << "\t\t     ~X~ -->"; cin >> ch;
            }
            else {
            //TRICK
                cout << "\t\t ;)  ~O~ -->"; cin >> ch;
            }

            if (ch == '.') {
                system("cls");
                Main_menu();
                active = 0;
                break;
            }
            //Converting 
            if (ch <= 90 && ch >= 65)
                ch += 32;

            // incase of input of any of those signs to keep keyboard same outline format , using # sign as letter being taken
            if (ch != '|'&& ch != '_' && ch != '-' && keyboard.find(ch) != std::string::npos)
                keyboard[keyboard.find(ch)] = '#';

            if (ch != '#')
                tag = 0;

            //TRICK
            if (ch == '#' && flag == 1 && tag == 1) {
                ch = wordName[0];
                flag = 0;
            }
            //END of KEYBOARD

            // Checking if correct input here with find function
            i = wordName.find(ch);
            while (wordName.find(ch, i) != std::string::npos) {

                answer[wordName.find(ch, i)] = ch;
                i++;
            }
            if (wordName.find(ch) == std::string::npos) {
                countHang++;
                // testing the basic alarm bell sound for wrong character input
                cout << "\a";
            }
            if (countHang == 6) {
                system("cls");
                AgainMenu();
            }
            else if (answer == wordName) {
                system("cls");
                AgainMenu();
            }

            system("cls");
        }
}


void AgainMenu() {
        active = 1;
        while (active) {
            if (countHang == 6) {

                cout << "\t\t  ____________________________________  \n"
                    "\t\t |             " <<"Your Friend" << " DIED!      | \n"
                    "\t\t |             -----------            | \n"
                    "\t\t |              ( X _ X )             | \n"
                    "\t\t |                                    | \n"
                    "\t\t |                       ________     | \n"
                    "\t\t |                      / Nooo!!!\\    | \n"
                    "\t\t |       _____          \\  ______/    | \n"
                    "\t\t |      (     )     <O>  \\/           | \n"
                    "\t\t |      | RIP |      |                | \n"
                    "\t\t |      |_____|     <<                | \n"
                    "\t\t |   ------------------------------   | \n"
                    "\t\t |                                    | \n"
                    "\t\t |          1.  Play Again            | \n"
                    "\t\t |                                    | \n"
                    "\t\t |          2.  Exit                  | \n"
                    "\t\t |____________________________________| \n\n\n";
            }
            else {
                cout << "\t\t  ____________________________________  \n"
                    "\t\t |            " << "Your Friend" << " LIVES!      | \n"
                    "\t\t |             -----------            | \n"
                    "\t\t |           ________                 | \n"
                    "\t\t |          / I LIVE!\\                | \n"
                    "\t\t |          \\  ______/                | \n"
                    "\t\t |            \\/                      | \n"
                    "\t\t |        |O/                         | \n"
                    "\t\t |         |                          | \n"
                    "\t\t |        / >                         | \n"
                    "\t\t |      _____       \\O>   \\O/         | \n"
                    "\t\t |     /     \\       |     |          | \n"
                    "\t\t |    /       \\     < \\   / \\         | \n"
                    "\t\t |   ------------------------------   | \n"
                    "\t\t |                                    | \n"
                    "\t\t |          1.  Play Again            | \n"
                    "\t\t |                                    | \n"
                    "\t\t |          2.  Exit                  | \n"
                    "\t\t |____________________________________| \n\n\n";
            }
            cout << "\t\t            -->";
            cin >> ch;
            if (ch == '1') {
                active = 0;

                system("cls");
                // Variable resetting
                countHang = 0;
                flag = 1;
                tag = 1;
                wordName = "0";
                wordHint = "0";
                answer = "";
                wordType = "0";

                keyboard = "\t\t  ___________________________________  \n"
                    "\t\t |             KEYBOARD              | \n"
                    "\t\t |-----------------------------------| \n"
                    "\t\t | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | \n"
                    "\t\t |-----------------------------------| \n"
                    "\t\t | a | b | c | d | e | f | g | h | i | \n"
                    "\t\t |-----------------------------------| \n"
                    "\t\t | j | k | l | m | n | o | p | q | r | \n"
                    "\t\t |-----------------------------------| \n"
                    "\t\t | s | t | u | v | w | x | y | z | 0 | \n"
                    "\t\t |-----------------------------------| \n"
                    "\t\t |___________________________________| \n";
                HintWord();
            }
            else if (ch == '2') {
                system("cls");
                active = 0;
                QuitGame();
				//EXIT
            }
            else {
                system("cls");
                //WRONG CHOICE
            }
        }


}

void HangCheck() {

        if (countHang == 0) {
            cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |                           \n"
                "\t\t    |                           \n"
                "\t\t    |                           \n"
                "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 1) {
            cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |      O                    \n"
                "\t\t    |                           \n"
                "\t\t    |                           \n"
                "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 2) {
            cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |      O                    \n"
                "\t\t    |      |                    \n"
                "\t\t    |                           \n"
                "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 3) {
            cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |      O                    \n"
                "\t\t    |      |\\                  \n"
                "\t\t    |                           \n"
                "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 4) {
        	cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |      O                    \n"
                "\t\t    |     /|\\                  \n"
                "\t\t    |                           \n"
                "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 5) {
            cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |      O                    \n"
                "\t\t    |     /|\\                  \n"
                "\t\t    |     /                     \n"
                "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 6) {
            cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |      O                    \n"
                "\t\t    |     /|\\                  \n"
                "\t\t    |     / \\                  \n"
                "\t\t ___|___                        \n\n\n";
        }


}

void QuitGame(){
  
		system("CLS");
		
		cout << endl;cout << endl;
		cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;  
		cout << endl;cout << endl;
		cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl; 
		cout << endl;cout << endl;
		cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl; 
		cout << "     .oooooo.                              .o8       oooooooooo.                        .o. \n";
		cout << "    d8P'  `Y8b                             888       `888'   `Y8b                       888 \n";
		cout << "   888            .ooooo.   .ooooo.   .oooo888        888     888 oooo    ooo  .ooooo.  888 \n";
		cout << "   888           d88' `88b d88' `88b d88' `888        888oooo888'  `88.  .8'  d88' `88b Y8P \n";
		cout << "   888     ooooo 888   888 888   888 888   888        888    `88b   `88..8'   888ooo888 `8' \n";
		cout << "   `88.    .88'  888   888 888   888 888   888        888    .88P    `888'    888    .o .o. \n";
		cout << "    `Y8bood8P'   `Y8bod8P' `Y8bod8P' `Y8bod88P       o888bood8P'      .8'     `Y8bod8P' Y8P \n";
		cout << "                                                                  .o..P'                    \n";
		cout << "                                                                  `Y8P'                     \n";
		cout << endl;cout << endl;
		cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl; 
		cout << endl;cout << endl;
		exit(0);
}



int main(){
	Main_menu();
	Rules();
	HintWord();
	HangBoard();
	AgainMenu();
	HangCheck();
	QuitGame();
	return 0;
}

