#include "Board.h"
using namespace std;

Board::Board(int boardSize)
{
    bsize = boardSize;
    board = new Value *[bsize];
    for (int i = 0; i < bsize; i++)
    {
        board[i] = new Value[bsize]; //dynamic allocating new values
    }
}

Board::Board(const Board &b)
{
    bsize = b.bsize;
    board = new Value *[bsize];
    for (int i = 0; i < bsize; i++)
    {
        board[i] = new Value[bsize];
        for (int j = 0; j < bsize; j++)
        {
            board[i][j] = b.board[i][j];
        }
    }
}

Board::Board()
{
    bsize = 0;
    board = NULL;
}

Board::~Board()
{
    for (int i = 0; i < bsize; i++)
    {
        delete board[i];
    }
    delete board;
}

//getter
int Board::size() const
{
    return bsize;
}

// overloading [] // SET
Value &Board::operator[](Coordinate coor)
{
    if (coor.row >= bsize || coor.row < 0 || coor.col >= bsize || coor.col < 0)
    {
        throw IllegalCoordinateException(coor);
    }
    return board[coor.row][coor.col];
}

Value Board::operator[](Coordinate coor) const
{
    if (coor.row >= bsize || coor.row < 0 || coor.col >= bsize || coor.col < 0)
    {
        throw IllegalCoordinateException(coor);
    }
    return board[coor.row][coor.col];
}

Board &Board::operator=(const Board &board)
{
    bsize = board.bsize;
    this->board = new Value *[bsize];
    for (int i = 0; i < bsize; i++)
    {
        this->board[i] = new Value[bsize];
        for (int j = 0; j < bsize; j++)
        {
            this->board[i][j] = board.board[i][j];
        }
    }
    return *this;
}

Board &Board::operator=(char c)
{
    if (c == '.')
    {
        for (int i = 0; i < bsize; i++)
        {
            for (int j = 0; j < bsize; j++)
            {
                board[i][j] = '.';
            }
        }
    }
    else
    {
        throw IllegalCharException(c);
    }
    return *this;
}

// overloading <<
ostream &operator<<(ostream &out, Board const &obj)
{
    int objSize = obj.bsize;
    for (int i = 0; i < objSize; i++)
    {
        for (int j = 0; j < objSize; j++)
        {
            out << obj.board[i][j];
        }
        out << "\n";
    }
    return out;
}

istream &operator>>(istream &in, Board &obj)
{
    string line;
    cin >> line;
    obj.bsize = line.size();
    obj.board = new Value *[obj.bsize];
    for (int i = 0; i < obj.bsize; i++)
    {
        obj.board[i] = new Value[obj.bsize];
        for (int j = 0; j < obj.bsize; j++)
        {
            obj.board[i][j] = line[j];
        }
        if (i != obj.bsize - 1)
            cin >> line;
    }
    return in;
}

string Board::draw(int size)
{
    int numfile = 0;
    while (true)
    {
        ifstream f(to_string(numfile) + ".ppm");
        if (!f.good()) 
        { // if stream is inturupted
            break;
        }
        else
        {
            numfile++;
        }
    }
    fname = to_string(numfile) + ".ppm";
    const int sizeOfArr = size;
    ofstream imagef(fname, ios::out | ios::binary);

    imagef << "P7" << endl
           << size << " " << size << endl
           << 255 << endl;

    Color **image = new Color *[size];

    for (int i = 0; i < size; i++)
    {
        image[i] = new Color[size];
        for (int j = 0; j < size; j++)
        {
            image[i][j].red = 0;
            image[i][j].green = 0;
            image[i][j].blue = 0;
        }
    }

    drawboard(image, size);
    for (int i = 0; i < bsize; i++) // draw signs accordingly
    {
        for (int j = 0; j < bsize; j++)
        {
            if (board[i][j].val == 'X')
            {
                drawX(image, size, i, j);
            }
            else if (board[i][j].val == 'O')
            {
                drawO(image, size, i, j);
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; ++j)
        {
            imagef.write(reinterpret_cast<char *>(&image[i][j]), size);
        }
    }
    imagef.close();
    for (int i = 0; i < size; i++) // cleaning up
        delete[] image[i];
    delete[] image;

    return fname;
}

void Board::drawboard(Color **image, int size)
{
    int cell = (size - 20 * (bsize - 1)) / bsize;
    for (int i = 0; i < size; ++i)
    {
        for (int k = 1; k <= bsize; k++)
        {
            for (int j = (cell * k) + 20 * (k - 1); j < (cell * k) + 20 * k && j < size; ++j)
            {
                image[j][i].red = 0;
                image[j][i].green = 0;
                image[j][i].blue = 0;
                image[i][j].red = 0;
                image[i][j].green = 0;
                image[i][j].blue = 0;
            }
        }
    }
}

void Board::drawX(Color **image, int size, int k, int j)
{
    int cell = (size - 20 * (bsize - 1)) / bsize;
    for (int i = 0; i < cell; ++i)
    {
        image[(cell + 20) * k + i][(cell + 20) * j + i].red = 255;
        image[(cell + 20) * k + i][(cell + 20) * j + i].green = 0;
        image[(cell + 20) * k + i][(cell + 20) * j + i].blue = 0;

        image[(cell + 20) * k + cell - 1 - i][(cell + 20) * j + i].red = 255;
        image[(cell + 20) * k + cell - 1 - i][(cell + 20) * j + i].green = 0;
        image[(cell + 20) * k + cell - 1 - i][(cell + 20) * j + i].blue = 0;
    }
}

void Board::drawO(Color **image, int size, int k, int j)
{
    int cell = (size - 20 * (bsize - 1)) / bsize;
    int r = cell / 2;
    int xCent = (cell + 20) * k + r;
    int yCent = (cell + 20) * j + r;
    int x = r, y = 0;
    int P = 1 - r;

    image[x + xCent][y + yCent].red = 255;
    image[x + xCent][y + yCent].green = 0;
    image[x + xCent][y + yCent].blue = 0;

    if (r > 0)
    {
        image[x + xCent][-y + yCent].red = 255;
        image[x + xCent][-y + yCent].green = 0;
        image[x + xCent][-y + yCent].blue = 0;
        image[y + xCent][x + yCent].red = 255;
        image[y + xCent][x + yCent].green = 0;
        image[y + xCent][x + yCent].blue = 0;
        image[-y + xCent][x + yCent].red = 255;
        image[-y + xCent][x + yCent].green = 0;
        image[-y + xCent][x + yCent].blue = 0;
    }
    while (x > y)
    {
        y++;
        if (P <= 0)
        {
            P = P + 2 * y + 1;
        }
        else
        {
            x--;
            P = P + 2 * y - 2 * x + 1;
        }
        if (x < y)
        {
            break;
        }
        image[x + xCent][y + yCent].red = 255;
        image[x + xCent][y + yCent].green = 0;
        image[x + xCent][y + yCent].blue = 0;
        image[-x + xCent][y + yCent].red = 255;
        image[-x + xCent][y + yCent].green = 0;
        image[-x + xCent][y + yCent].blue = 0;
        image[x + xCent][-y + yCent].red = 255;
        image[x + xCent][-y + yCent].green = 0;
        image[x + xCent][-y + yCent].blue = 0;
        image[-x + xCent][-y + yCent].red = 255;
        image[-x + xCent][-y + yCent].green = 0;
        image[-x + xCent][-y + yCent].blue = 0;
        if (x != y)
        {
            image[y + xCent][x + yCent].red = 255;
            image[y + xCent][x + yCent].green = 0;
            image[y + xCent][x + yCent].blue = 0;
            image[-y + xCent][x + yCent].red = 255;
            image[-y + xCent][x + yCent].green = 0;
            image[-y + xCent][x + yCent].blue = 0;
            image[y + xCent][-x + yCent].red = 255;
            image[y + xCent][-x + yCent].green = 0;
            image[y + xCent][-x + yCent].blue = 0;
            image[-y + xCent][-x + yCent].red = 255;
            image[-y + xCent][-x + yCent].green = 0;
            image[-y + xCent][-x + yCent].blue = 0;
        }
    }
}
