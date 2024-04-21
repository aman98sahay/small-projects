#include <iostream>
#include <climits>
#include "rock_paper_scissor.hpp"
#include "random_select_player_move.hpp"
#include "possible_player_moves.hpp"

RockPaperScissors::RockPaperScissors()
	:CurrentStateInfo(CurrentState::GAME_IS_NOT_OVER)
{
}

void RockPaperScissors::StartGame()
{
	PossiblePlayerMoves PlayerMove;
	using std::cout;
	while (CurrentStateInfo == CurrentState::GAME_IS_NOT_OVER) {

		PlayerMove = TakeUserInput();

		switch (PlayerMove)
		{
		case PossiblePlayerMoves::ROCK:
			cout << "You have thrown a ROCK";
			break;
		case PossiblePlayerMoves::PAPER:
			cout << "You have has thrown a PAPER";

			break;
		case PossiblePlayerMoves::SCISSOR:
			cout << "You have has thrown a SCISSOR";
			break;
		}
		
		std::endl(cout);

		UpdateComputerInput(); // updates CurrentComputerMove 
		switch (CurrentComputerMove)
		{
		case PossiblePlayerMoves::ROCK:
			cout << "the computer has thrown a ROCK";
			break;
		case PossiblePlayerMoves::PAPER:
			cout << "the computer has thrown a PAPER";

			break;
		case PossiblePlayerMoves::SCISSOR:
			cout << "the computer has thrown a SCISSOR";
			break;
		}

		std::endl(cout);

		UpdateCurrentState(PlayerMove, CurrentComputerMove); //  updates CurrentStateInfo

		switch (CurrentStateInfo)
		{
		case CurrentState::GAME_IS_NOT_OVER:
			cout << "It is a draw, wonderful lets go again";
			break;
		case CurrentState::COMPUTER_WON:
			cout << "The computer won";
			break;
		case CurrentState::HUMAN_WON:
			cout << "Congratulations you won";
			break;
		}
		std::endl(cout);
	}
}

void RockPaperScissors::UpdateComputerInput()
{
	CurrentComputerMove = random_move_selector();

}

PossiblePlayerMoves RockPaperScissors::TakeUserInput()
{
	using std::cout;
	using std::cin;

	int input = -1;

	cout << "Enter 1 for Rock , 2 for Paper and 3 for Scissors :";
	while (input <= 0 || input >= 4) {

		while (!bool(cin >> input)) {
			endl(cout << "invalid input, please try again:");
			cin.clear(); // clears the error flags
			// this line discards all the input waiting in the stream
			cin.ignore(INT_MAX, '\n');  //as std::numeric_limits<std::streamsize>::max() is not compiling in linux
		}
		if (input <= 0 && input >= 4)
			cout << "Invalid input please try again, please enter values 1, 2 and 3 only";
	}

	return PossiblePlayerMoves(input - 1);
}

void RockPaperScissors::UpdateCurrentState(PossiblePlayerMoves pPlayerMove, PossiblePlayerMoves pComputerInput)
{
	switch (pPlayerMove) {
	case PossiblePlayerMoves::ROCK:
		switch (pComputerInput)
		{
		case PossiblePlayerMoves::ROCK:
			break;
		case PossiblePlayerMoves::PAPER:
			CurrentStateInfo = CurrentState::COMPUTER_WON;
			break;
		case PossiblePlayerMoves::SCISSOR:
			CurrentStateInfo = CurrentState::HUMAN_WON;
			break;
		} break;
	case PossiblePlayerMoves::PAPER:
		switch (pComputerInput)
		{
		case PossiblePlayerMoves::ROCK:
			CurrentStateInfo = CurrentState::HUMAN_WON;
			break;
		case PossiblePlayerMoves::PAPER:
			break;
		case PossiblePlayerMoves::SCISSOR:
			CurrentStateInfo = CurrentState::COMPUTER_WON;

			break;

		}break;
	case PossiblePlayerMoves::SCISSOR:
		switch (pComputerInput)
		{
		case PossiblePlayerMoves::ROCK:
			CurrentStateInfo = CurrentState::COMPUTER_WON;
			break;
		case PossiblePlayerMoves::PAPER:
			CurrentStateInfo = CurrentState::HUMAN_WON;
			break;
		case PossiblePlayerMoves::SCISSOR:
			break;

		}break;
	}
}
