#include <random>
using namespace std;

#include "random_select_player_move.hpp"

#include "possible_player_moves.hpp"

PossiblePlayerMoves random_move_selector()
{
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist6(0, 2);

	return (PossiblePlayerMoves)dist6(rng);
}
