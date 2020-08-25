/*
Name: Nusra Ahmed
Date: 10/15/18
Class: CIS2561
Descr: Hangman game for midterm project. 
 */

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Hangman
{
    public partial class Form1 : Form
    {
        string secretWord;
        List<TextBox> textBoxes = new List<TextBox>();
        HashSet<char> guessedLetters = new HashSet<char>();
        int incorrectGuesses = 0;
        const int MAX_WRONG_GUESSES = 6;

        public Form1()
        {
            InitializeComponent();

            NewGame();
        }

        void NewGame()
        {
            incorrectGuesses = 0;
            guessedLetters.Clear();
            secretWord = WordList.GetWord();
            pictureBox1.Image = global::Hangman.Properties.Resources.image1;
            guessBox.Text = "";
            textBox1.Text = "";
            SetupTextBoxes();
        } //end NewGame()

        /// <summary>
        /// Allocate a textbox for every letter in the secret word
        /// </summary>
        void SetupTextBoxes()
        {
            foreach (TextBox t in textBoxes)
            {
                Controls.Remove(t);
            }

            textBoxes.Clear();

            for (int i = 0; i < secretWord.Length; i++)
            {
                TextBox t = new TextBox();
                t.Location = new Point(100 + i * 20, 225);
                //t.Text = secretWord[i].ToString(); //THIS IS FOR TESTING ONLY
                t.Width = 18;
                Controls.Add(t);
                textBoxes.Add(t); //save a reference to the control
            }
        } //end SetupTextBoxes()

        private void button1_Click(object sender, EventArgs e) //hidden test button
        {
            NewGame(); 
        } //end button1_Click

        //displays the picture of the character in the PictureBox control
        public void NextPicture()
        {
            if (incorrectGuesses == 1)
            {
                pictureBox1.Image = global::Hangman.Properties.Resources.image2;
            }
            else if (incorrectGuesses == 2)
            {
                pictureBox1.Image = global::Hangman.Properties.Resources.image3;
            }
            else if (incorrectGuesses == 3)
            {
                pictureBox1.Image = global::Hangman.Properties.Resources.image4;
            }
            else if (incorrectGuesses == 4)
            {
                pictureBox1.Image = global::Hangman.Properties.Resources.image5;
            }
            else if (incorrectGuesses == 5)
            {
                pictureBox1.Image = global::Hangman.Properties.Resources.image6;
            }
            else if (incorrectGuesses == 6)
            {
                pictureBox1.Image = global::Hangman.Properties.Resources.image7;
            }
        } // end NextPicture() function

        void HandleGuesses()
        {
            if (guessBox.Text.Length > 0) //make sure player entered something
            {
                char ch = guessBox.Text[0]; //get the 1st character in the text
                if (guessedLetters.Contains(ch)) //now you can see if the player has guessed the letter...
                {
                    MessageBox.Show("You've already guessed " + ch + ".");
                }
                else
                {
                    //put the letter in the set of used letters
                    guessedLetters.Add(ch);
                    //show letters that have been guessed
                    textBox1.Text += ch;
                    if (secretWord.ToCharArray().ToList().Contains(ch)) //if it hasn't been guessed, see if it's in the word
                    {
                        //guess was good
                        ShowLetters();
                        if (PlayerWon())
                        {
                            MessageBox.Show("YOU WIN!");
                            MessageBox.Show("Click OK to play again.");
                            NewGame();
                        }
                    }
                    else
                    {
                        //guess was bad
                        incorrectGuesses++;
                        NextPicture();
                        if (incorrectGuesses == MAX_WRONG_GUESSES)
                        {
                            MessageBox.Show("GAME OVER...The word was --> " + secretWord);
                            MessageBox.Show("Click OK to play again.");
                            NewGame();
                        }
                    }
                }
            }
            else
            {
                MessageBox.Show("Please enter a letter a-z");
                return; //bail out of this function
            }
        } //end HandleGuesses()

        private void button2_Click(object sender, EventArgs e)
        {
            HandleGuesses();
            guessBox.Text = "";
        } //end button2_Click

        bool PlayerWon()
        {
            for (int i = 0; i < secretWord.Length; i++)
            {
                if (!guessedLetters.Contains(secretWord[i]))
                    return false;
            }
            return true;
        } //end PlayerWon()

        void ShowLetters()
        {
            for (int i = 0; i < secretWord.Length; i++)
            {
                //has the player guessed letter at index i?
                if (guessedLetters.Contains(secretWord[i]))
                {
                    // FOR YOU TO DO: put secretWord[i] in box[i]’s Text property
                    textBoxes[i].Text = secretWord[i].ToString();
                }
            }
        } //end ShowLetters()

    } // end Form1 class
} //end namespace Hangman


