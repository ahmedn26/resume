using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW3
{
    class GameBoard
    {
        private Cell cell = new Cell();
        static int dimensions = 9;
        private Region region;

        private void randomBoard()
        {

        }
        private void DrawBoard()
        {
            //create a 2d array
        }

        public Cell Cell {

            get { return cell; }
        }

        public Region Region
        {
            get { return region; }
        }
        
    }

    class Cell
    {
        private int val;
        private bool flag = false;
        private int[,] cellLocation;
        public int Value
        {
            get { return val; }
            set { val = value; }
        }

        public bool Flag
        {
            get { return flag; }
            set { flag = value; }
        }

        public int[,] CellLocation
        {
            get { return cellLocation; }
            set { cellLocation = value; }
        }

    }


    class GamePlay
    {
        private GameBoard gameBoard;
        private int score;

        public void startGame()
        {

        }

        public void endGame()
        {

        }

        public void selectCell(int [,] currentCell)
        {
            gameBoard.Cell.CellLocation = currentCell;
        }

        public void placeValue()
        {
            if (gameBoard.Region.checkAll(gameBoard.Cell.CellLocation))
                Console.WriteLine("The number entered is correct");
            else
                Console.WriteLine("The number entered is incorrect");
        }

        public void calcScore()
        {
            
        }
    }

    class Region
    {
        private int[] horizontalValues;
        private int[] verticalValues;
        private int[] sectionValues;

        public bool checkHorizontal()
        {
            if (horizontalValues.Distinct().Count() != horizontalValues.Count())
            {
                return false;
            }
            else return true;
        }

        public bool checkVertical()
        {
            if (verticalValues.Distinct().Count() != verticalValues.Count())
            {
                return false;
            }
            else return true;
        }

        public bool checkSection()
        {
            if (sectionValues.Distinct().Count() != sectionValues.Count())
            {
                return false;
            }
            else return true;
        }

        public bool checkAll(int [,] currentCell)
        {
            if (checkHorizontal() && checkVertical() & checkSection())
                return true;
            else
                return false;

        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            GamePlay g1 = new GamePlay();
            g1.startGame();
        }
    }
}
