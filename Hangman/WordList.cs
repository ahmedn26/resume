﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows;
using System.Reflection;
using System.Windows.Forms;

namespace Hangman
{
    class WordList
    {
        private static string []words = { "admiral", "anaconda", "beekeeper", "blabbering", "bummer", "buzzer", "difficult", "dizzy", 
                            "fizzy", "fuzzy", "fluffy", "hound", "joking", "joker", "overjoyed", "poncho", "yellow", 
                            "zigzagging", "sausage", "blubber", "pencil", "cloud", "moon", "water", "computer", "school", 
                            "network", "hammer", "walking", "mediocre", "literature", "chair", "window", "cords", "musical",
                            "zebra", "xylophone", "penguin", "home", "hound", "final", "inked", "teacher", "funny", "website", 
                            "banana", "uncle", "softly", "awesome", "attach", "blue", "internet", "bottle", "tight", 
                            "zone", "tomato", "prison", "hydro", "cleaning", "telivision", "send", "frog", "coffee", 
                            "book", "zooming", "falling", "evily", "gamer", "juice", "moniter", "captain", "bonding", 
                            "loudly", "thudding", "guitar", "shaving", "hair", "soccer", "water", "racket", "table", 
                            "late", "media", "desktop", "flipper", "club", "flying", "smooth", "monster", "purple", 
                            "guardian", "bold", "hyperlink", "presenter", "world", "national", "comment", "element", 
                            "magic", "lion", "sand", "crust", "toast", "hunter", "forest", "foraging", "silent", "pong", 
                            "waves" };


        public static string GetWord()
        {
            Random r = new Random();
            return words[r.Next(0, words.Length)];
        }

    }

}
