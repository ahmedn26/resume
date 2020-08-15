using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Life
{
    //one cell on the board
    struct Cell
    {
        public bool hasOrganism; //does this square have a life form?
        public int state; //what will happen to this life form (if present)?
                          //the various states a cell can be in
        public const int EMPTY = 0;
        public const int SURVIVES = 1;
        public const int DEATH_BY_OVERCROWDING = 2;
        public const int DEATH_BY_LONELINESS = 3;
        public const int SPAWNING = 4; //BIRTH
        public const int UNMARKED = 5;
        //constructor for a cell
        public Cell(bool hasOrganism)
        {
            this.hasOrganism = hasOrganism;
            this.state = EMPTY;
        }
    }

    //encapsulate the game 
    class Generation
    {
        const int WIDTH = 40;
        const int HEIGHT = 30;

        Cell[,] grid = new Cell[WIDTH, HEIGHT];

        //count cell's neighbors (figure out what will happen to this cell)
        public void MarkCells()
        {
            for (int i = 0; i < WIDTH; i++)
            {
                for (int j = 0; j < HEIGHT; j++)
                {
                    int neighbors = CountNeighbors(i, j);

                    //set the state flag based on what will happen to this cell
                    if (grid[i, j].hasOrganism)
                    {
                        if (neighbors == 0 || neighbors == 1)
                            grid[i, j].state = Cell.DEATH_BY_LONELINESS;
                        else if (neighbors == 2 || neighbors == 3)
                            grid[i, j].state = Cell.SURVIVES;
                        else if (neighbors >= 4 & neighbors <= 8)
                            grid[i, j].state = Cell.DEATH_BY_OVERCROWDING;
                    }
                    else if (neighbors == 3)
                        grid[i, j].state = Cell.SPAWNING;
                }
            }
        }

        /// <summary>
        /// kill organisms and spawn new ones
        /// </summary>
        public void ApplyMarks()
        {
            for (int i = 0; i < WIDTH; i++)
            {
                for (int j = 0; j < HEIGHT; j++)
                {
                    //kill or spawn based on the state variable
                    //if dies, set hasOrganism to false
                    //if spawns, set hasOrganism to true
                    if (grid[i, j].hasOrganism)
                    {
                        if (grid[i, j].state == Cell.SURVIVES)
                        {
                            //TO-DO
                            //put an organism in the grid at i, j
                            grid[i, j].hasOrganism = true;
                            grid[i, j].state = Cell.UNMARKED;

                        }
                        if (grid[i, j].state == Cell.DEATH_BY_LONELINESS || grid[i, j].state == Cell.DEATH_BY_OVERCROWDING)
                            grid[i, j].hasOrganism = false;

                    }
                    else if (grid[i, j].state == Cell.SPAWNING)
                    {
                        //TO-DO
                        //put an organism in the grid at i, j
                        grid[i, j].hasOrganism = true;
                        grid[i, j].state = Cell.UNMARKED;
                    }
                }
            }
        }

        public void DrawGame(Graphics g)
        {
            for (int i = 0; i < WIDTH; i++)
            {
                for (int j = 0; j < HEIGHT; j++)
                {
                    if (grid[i, j].hasOrganism)
                        g.DrawImage(Properties.Resources.life_unmarked, i*20, j*20);
                    else
                        g.DrawImage(Properties.Resources.life_empty, i * 20, j * 20);
                }
            }
        }

        /// <summary>
        /// Place/Unplace a cell on the board
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        public void PlaceOrganism(int x, int y )
        {
            grid[x, y].hasOrganism = !grid[x, y].hasOrganism;
        }

        //does cell x,y have an organism
        int CountNeighbor(int x, int y)
        {
            if (x < 0 || y < 0 || x>= WIDTH || y >=HEIGHT)
                return 0;

            if (grid[x, y].hasOrganism)
                return 1;
            else
                return 0;
        }

        //find total neighbors
        int CountNeighbors(int x, int y)
        {
            int count = CountNeighbor(x, y - 1) +
                CountNeighbor(x + 1, y - 1) +
                CountNeighbor(x + 1, y) +
                CountNeighbor(x + 1, y + 1) +
                CountNeighbor(x, y + 1) +
                CountNeighbor(x - 1, y + 1) +
                CountNeighbor(x - 1, y) +
                CountNeighbor(x - 1, y - 1);

            return count;
        }

        //reset the grid
        public void Reset() {
            for (int i = 0; i < WIDTH; i++)
            {
                for (int j = 0; j < HEIGHT; j++)
                {
                    grid[i, j].hasOrganism = false;
                }
            }
        }
    }
}
