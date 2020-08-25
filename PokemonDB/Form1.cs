using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Xml.Serialization;
using System.IO;

namespace PokemonDB
{
    public partial class Form1 : Form
    {
        PokemonDB pokemonDB = new PokemonDB();
        public Form1()
        {
            InitializeComponent();
            LoadXML();
        }

        void LoadXML()
        {
            WebRequest request = WebRequest.Create("http://mrwrightteacher.net/NianticCorp/PokemonDB.php");
            WebResponse resp = request.GetResponse();
            Stream dataStr = resp.GetResponseStream();

            XmlSerializer serializer = new XmlSerializer(typeof(PokemonDB));
            pokemonDB = (PokemonDB)serializer.Deserialize(dataStr);

            dataGridView4.DataSource = pokemonDB.PlayerTable.Players;
            dataGridView5.DataSource = pokemonDB.PokemonTable.Pokemon;
            dataGridView6.DataSource = pokemonDB.OwnershipTable.Ownership;

            //populate city
            var cityNames = (from c in pokemonDB.PlayerTable.Players
                             select c.City).Distinct();

            //populate combo box
            CityComboBox.Items.AddRange(cityNames.ToArray());

        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("By Nusra Ahmed, 2018");
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        //search by name
        private void SearchButton1_Click(object sender, EventArgs e)
        {
            string nameValue = PlayerNameTextBox.Text.Trim();

            var pokemon = from pl in pokemonDB.PlayerTable.Players
                          join o in pokemonDB.OwnershipTable.Ownership
                          on pl.Id equals o.PlayerId
                          join p in pokemonDB.PokemonTable.Pokemon
                          on o.PokemonId equals p.Id
                          where pl.Name == nameValue
                          select new { p.Name, o.Level, o.NumberOwned };

            dataGridView1.DataSource = pokemon.ToList();
        }

        //search by player id
        private void SearchButton2_Click(object sender, EventArgs e)
        {
            int idValue = Convert.ToInt32(PlayerIdTextBox.Text);

            var pokemon = from p in pokemonDB.PlayerTable.Players
                          join o in pokemonDB.OwnershipTable.Ownership
                          on p.Id equals o.PlayerId
                          join pok in pokemonDB.PokemonTable.Pokemon
                          on o.PokemonId equals pok.Id
                          where p.Id == idValue
                          select new { pok.Name, o.Level, o.NumberOwned };

            dataGridView1.DataSource = pokemon.ToList();
        }

        //filter by city
        private void CityComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            string city = CityComboBox.Items[CityComboBox.SelectedIndex].ToString();

            var players = from p in pokemonDB.PlayerTable.Players
                          where p.City == city
                          orderby p.Paid descending
                          select new { p.Id, p.Name, p.Username, p.City, p.Paid };

            dataGridView2.DataSource = players.ToList();
        }

        //defense filter
        private void FilterButton1_Click(object sender, EventArgs e)
        {
            int defenseValue = Convert.ToInt32(DefenseTextBox.Text);

            var pokemon = from p in pokemonDB.PokemonTable.Pokemon
                          where p.Defense <= defenseValue
                          orderby p.Defense descending
                          select new { p.Id, p.Name, p.Attack, p.Defense };

            dataGridView3.DataSource = pokemon.ToList();
        }

        //attack filter
        private void FilterButton2_Click(object sender, EventArgs e)
        {
            int attackValue = Convert.ToInt32(AttackTextBox.Text);

            var pokemon = from p in pokemonDB.PokemonTable.Pokemon
                          where p.Attack >= attackValue
                          orderby p.Attack descending
                          select new { p.Id, p.Name, p.Attack, p.Defense };

            dataGridView3.DataSource = pokemon.ToList();
        }
    }
}

