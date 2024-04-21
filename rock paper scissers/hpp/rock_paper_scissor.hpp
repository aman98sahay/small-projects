#pragma once 

#include <cstdint>

enum class PossiblePlayerMoves : int8_t;
enum class CurrentState : int8_t;

class RockPaperScissors {
public:
	RockPaperScissors();

	void StartGame();

private:
	void				UpdateComputerInput();
	PossiblePlayerMoves TakeUserInput();
	void				UpdateCurrentState(PossiblePlayerMoves pPlayerMove, PossiblePlayerMoves pComputerInput);
	CurrentState CurrentStateInfo;
	PossiblePlayerMoves CurrentComputerMove;
};