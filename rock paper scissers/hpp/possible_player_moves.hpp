#pragma once 
#include <cstdint>

enum class PossiblePlayerMoves : int8_t {
	ROCK,
	PAPER, 
	SCISSOR 
};

enum class CurrentState : int8_t {
	GAME_IS_NOT_OVER,
	COMPUTER_WON,
	HUMAN_WON
};