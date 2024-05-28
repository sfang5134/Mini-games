#include <iostream>
using namespace std;
//Print all the line with a cout
int gameMenu() {
	cout << "***************************************************";
	cout << "\n                  Welcome!                       ";
	cout << "\n";
	cout << "\nPlease choose a number from the following options:";
	cout << "\n";
	cout << "\n1.Choose Your Own Adventure game(type 1)";
	cout << "\n2.Madlib game(type 2)";
	cout << "\n3. Exit.(type 3)";
	cout << "\n";
	cout << "\n***************************************************\n";
	return 0;
}
int advenGame() {

	char choice;
	// Let the user choose their adventure
	cout << "Welcome to the Jungle Adventure!\n";
	cout << "You find yourself in a dense jungle. What do you do?\n";
	cout << "A. Explore deeper into the jungle\n";
	cout << "B. Climb a tree to get a better view\n";
	cout << "C. Build a shelter and rest for a while\n";
	cout << "Enter your choice (A, B, or C): ";
	cin >> choice;
	// Use switch statement to handle different choices
	switch (choice) {
	case 'A':
	case 'a':
		//give the user a choice to swim across the river, look for a safer way to cross, or turn back and explore a different path
		cout << "You decide to explore deeper into the jungle.\n";
		cout << "After walking for a while, you encounter a river.\n";
		cout << "What do you do?\n";
		cout << "A. Try to swim across the river\n";
		cout << "B. Look for a safer way to cross\n";
		cout << "C. Turn back and explore a different path\n";
		cout << "Enter your choice (A, B, or C): ";
		cin >> choice;
		// Use if else if else to handle different choices
		if (choice == 'A' || choice == 'a') {
			cout << "You attempt to swim across the river but get caught in a strong current.\n";
			cout << "What would you do now?\n";
			cout << "A. Keep swimming\n";
			cout << "B. Grab onto a nearby rock or tree\n";
			cout << "Enter your choice (A or B): ";
			cin >> choice;
			if (choice == 'A' || choice == 'a') {
				cout << "You struggle to keep swimming but get swept away by the current.\n";
				cout << "Unfortunately, you drown. Game Over.\n";
			}
			else {
				cout << "You grab onto a nearby rock and manage to pull yourself to safety.\n";
				cout << "Congratulations! You've survived the river.\n";
				cout << "You continue your adventure deeper into the jungle.\n";
			}
		}
		else if (choice == 'B' || choice == 'b') {
			cout << "You find a sturdy fallen tree and use it to cross the river safely.\n";
			cout << "Congratulations! You successfully cross the river.\n";
			cout << "You continue your adventure deeper into the jungle.\n";
		}
		else {
			cout << "You decide to turn back and explore a different path.\n";
			cout << "As you explore, you stumble upon an ancient temple.\n";
			cout << "You enter the temple and find hidden treasure!\n";
			cout << "Congratulations! You've completed your adventure!\n";
		}
		break;
	case 'B':
	case 'b':
		cout << "You decide to climb a tree to get a better view.\n";
		cout << "From the top of the tree, you spot a river in the distance.\n";
		cout << "What do you do?\n";
		cout << "A. Try to jump from tree to tree to get closer to the river\n";
		cout << "B. Climb down and head towards the river\n";
		cout << "C. Look around for other points of interest\n";
		cout << "Enter your choice (A, B, or C): ";
		cin >> choice;
		if (choice == 'A' || choice == 'a') {
			cout << "You attempt to jump from tree to tree but slip and fall.\n";
			cout << "Unfortunately, you injure yourself badly. Game Over.\n";
		}
		else if (choice == 'B' || choice == 'b') {
			cout << "You climb down from the tree and start heading towards the river.\n";
			cout << "As you get closer, you hear rushing water and see a beautiful waterfall.\n";
			cout << "You decide to take a refreshing swim in the river. What a great adventure!\n";
		}
		else {
			cout << "You look around and spot a cave nearby.\n";
			cout << "You enter the cave and find it filled with bats!\n";
			cout << "Startled, you quickly exit the cave and decide to explore a different area.\n";
			cout << "Your adventure continues...\n";
		}
		break;
	case 'C':
	case 'c':
		cout << "You decide to build a shelter and rest for a while.\n";
		cout << "After setting up camp, you hear strange noises in the distance.\n";
		cout << "What do you do?\n";
		cout << "A. Investigate the source of the noises\n";
		cout << "B. Stay inside the shelter and wait\n";
		cout << "C. Pack up and leave immediately\n";
		cout << "Enter your choice (A, B, or C): ";
		cin >> choice;
		if (choice == 'A' || choice == 'a') {
			cout << "You cautiously approach the source of the noises and discover a family of monkeys playing.\n";
			cout << "Relieved, you spend some time observing the monkeys before returning to your shelter.\n";
			cout << "It's been a peaceful night in the jungle.\n";
		}
		else if (choice == 'B' || choice == 'b') {
			cout << "You decide to stay inside the shelter and wait.\n";
			cout << "The noises eventually fade away, and you have a restful night.\n";
			cout << "In the morning, you wake up feeling refreshed and ready to continue your adventure.\n";
		}
		else {
			cout << "You quickly pack up your belongings and leave the area.\n";
			cout << "As you're leaving, you come across a hidden path leading to a beautiful waterfall.\n";
			cout << "You take a moment to enjoy the scenery before continuing your journey.\n";
		}
		break;
	default:
		cout << "Invalid choice! Please enter A, B, or C.\n";
		break;
	}
	return 0;
}
int malibGame() {
	//Declare the input variable
	string noun, verb, adjective, adverb;
	// Ask the user to input the noun, verb, adjective and adverb
	cout << "Enter a noun: ";
	cin >> noun;
	cout << "Enter a verb: ";
	cin >> verb;
	cout << "Enter an adjective: ";
	cin >> adjective;
	cout << "Enter an adverb: ";
	cin >> adverb;
	//Generate a story
	cout << "Once upon a time, there was a " << adjective << " " << noun << " who loved to " << verb << " " << adverb << ".\n";
	cout << "Every day, the " << noun << " would " << verb << " " << adverb << " around the " << adjective << " town.\n";
	cout << "People admired the " << adjective << " " << noun << "'s " << adverb << " " << verb << "ing skills.\n";
	cout << "One day, while " << adverb << " " << verb << "ing, the " << noun << " stumbled upon a magical " << noun << ".\n";
	cout << "From that day on, the " << adjective << " " << noun << " lived happily ever after!\n";
	return 0;
}

int main() {
	char userChoice;
	//Find do/while loop on W3school
	do {
		gameMenu();
		cout << "Enter your choice: \n";
		cin >> userChoice;
		switch (userChoice)
		{
		case '1':
			advenGame();
			break;
		case '2':
			malibGame();
			break;
		case '3':
			cout << "Goodbye!";
			return 0;
		default:
			cout << "Invalid choice! Please enter 1, 2, or 3.\n";
			break;
		}
	} while (userChoice != '3');

	return 0;
}