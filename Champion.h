#pragma once
#include "Coordinate.hpp"
#include "Board.h"
#include "Player.h"

class Champion: public Player {
public:
	bool reverse = false;

	const string name() const override { return "Arad Zekler"; }
	const Coordinate play (Board& board) override;
};
