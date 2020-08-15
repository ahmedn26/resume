using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Life
{
    public partial class Form1 : Form
    {
        Generation game = new Generation(); 
        public Form1()
        {
            InitializeComponent();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("By Nusra Ahmed.");
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            game.DrawGame(e.Graphics);
        }

        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {
            game.PlaceOrganism(e.X / 20, e.Y / 20); //use a CONSTANT (not 20)!!!
            pictureBox1.Invalidate();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            game.MarkCells(); //figure out who lives/dies
            game.ApplyMarks(); //kill and spawn 
            pictureBox1.Invalidate();
        }

        private void startToolStripMenuItem_Click(object sender, EventArgs e)
        {
            timer1.Start();
        }

        private void stopToolStripMenuItem_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            game.Reset();
            pictureBox1.Invalidate();
        }

        private void steadyStateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            game.Reset();

            game.PlaceOrganism(15, 8);
            game.PlaceOrganism(15, 9);
            game.PlaceOrganism(16, 8);
            game.PlaceOrganism(17, 11);
            game.PlaceOrganism(18, 11);
            game.PlaceOrganism(18, 10);
            pictureBox1.Invalidate();
        }

        private void verticalOscillationToolStripMenuItem_Click(object sender, EventArgs e)
        {
            game.Reset();

            game.PlaceOrganism(15, 8);
            game.PlaceOrganism(15, 9);
            game.PlaceOrganism(15, 10);
            pictureBox1.Invalidate();
        }

        private void rPentominoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            game.Reset();

            game.PlaceOrganism(16, 8);
            game.PlaceOrganism(17, 8);
            game.PlaceOrganism(15, 9);
            game.PlaceOrganism(16, 9);
            game.PlaceOrganism(16, 10);
            pictureBox1.Invalidate();
        }
    }
}
