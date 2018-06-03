#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	Board board;
	cin >> board;
	string fname = board.draw(600);
	cout << fname << endl;
    return 0;
}
