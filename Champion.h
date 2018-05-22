#pragma once
#include "Coordinates.hpp"
#include "Board.h"
#include "Player.h"

class Champion: public Player {
public:
	bool reverse = false;

	const string name() const override { return "Arad Zekler"; }
	const Coordinates play (Board& board) override;
};