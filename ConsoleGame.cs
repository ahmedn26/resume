//Name:     Nusra Ahmed
//Date:     09/24/2019
//Class:    Object-Oriented Programming
//Descr:    Homework #2

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameHW2
{
    class Enemy
    {
        private int enemyHealth = 100;
        private string enemyType = "";
        protected Random rnd = new Random();

        public int Health
        {
            get { return enemyHealth; }
            set { enemyHealth = value; }
        }
        public string Type
        {
            get { return enemyType; }
            set { enemyType = value; }
        }

        public virtual void Speak()
        {
            
        }

        public virtual void Attack(Player p)
        {
            
        }
    }

    class SubZero : Enemy
    {
        
        public override void Speak()
        {
            Console.WriteLine("\n\tI will freeze your fire.\n");
            base.Speak();
        }

        public override void Attack(Player p)
        {
            int attackValue = rnd.Next(70);
            p.Health -= attackValue;
        }
    }

    class Mileena : Enemy
    {
        public override void Speak()
        {
            Console.WriteLine("\n\tDid that hurt?\n"); 
            base.Speak();
        }

        public override void Attack(Player p)
        {
            int attackValue = rnd.Next(70);
            p.Health -= attackValue;
        }

    }

    class Player
    {
        private int playerHealth = 100;
        private Random rnd = new Random();

        public int Health
        {
            get { return playerHealth; }
            set { playerHealth = value; }
        }

        public void Attack(Enemy e)
        {
            int attackValue = rnd.Next(100);
            e.Health -= attackValue; 
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            SubZero subZero = new SubZero();
            subZero.Type = "Sub-Zero";
            Mileena mileena = new Mileena();
            mileena.Type = "Mileena";
            Player player = new Player();

            Console.WriteLine($"Round 1, fight!\n");


            Console.WriteLine("Sub-Zero has attacked the player.");
            subZero.Speak();
            subZero.Attack(player);
            Console.WriteLine($"Player has attacked Mileena");
            player.Attack(mileena);
            Console.WriteLine("Mileena has attacked the player.");
            mileena.Speak();
            subZero.Attack(player);
            Console.WriteLine($"Player has attacked Sub-Zero\n");
            player.Attack(subZero);

            Console.WriteLine($"Player's Health = {player.Health}");
            Console.WriteLine($"Sub-Zero's Health = {subZero.Health}");
            Console.WriteLine($"Mileena's Health = {mileena.Health}");

            if (player.Health <= 0)
                Console.WriteLine("\nFATALITY! Player has died");
        }
    }
}
