// Nusra Ahmed
// HW4
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Net;
using System.Net.Sockets;

namespace Chatroom
{
    class Chatroom
    {
       

        static void ReadData(object socket)
        {
            TcpClient client = (TcpClient)socket;
            while (true)
            {
                byte[] buffer = new byte[1024];
                int k = client.GetStream().Read(buffer, 0, buffer.Length);
                Console.WriteLine("\t\t{0}", Encoding.ASCII.GetString(buffer, 0, k));
            }
        }

        public static TcpClient AddConnection()
        {
            TcpClient client = new TcpClient();
            client.Connect(IPAddress.Loopback, 5000);
            Thread t = new Thread(ReadData);
            t.Start(client);
            ChatRoom(ref client);
            return client;

        }

        static void ChatRoom(ref TcpClient client)
        {
            Console.WriteLine("Enter your username: ");
            string username = Console.ReadLine();
            // FIX: handle if the user inputs an empty string
            if (username == "")
            {
                // add code to generate random username using Unix time
                // https://stackoverflow.com/questions/17632584/how-to-get-the-unix-timestamp-in-c-sharp
                string unixTimestamp = Convert.ToString((DateTime.UtcNow.Subtract(new DateTime(1970, 1, 1))).TotalSeconds);
                byte[] msg = Encoding.ASCII.GetBytes($"user.{unixTimestamp}");
                client.GetStream().Write(msg, 0, msg.Length);
            }
            else
            {
                byte[] msg = Encoding.ASCII.GetBytes(username);
                client.GetStream().Write(msg, 0, msg.Length);
            }
        }

        public static void Message(TcpClient client)
        {
            //Console.WriteLine("Please input a string to send");
            string input = Console.ReadLine();
            byte[] msg = Encoding.ASCII.GetBytes(input);
            client.GetStream().Write(msg, 0, msg.Length);

        }

        static void Main(string[] args)
        {
            TcpClient client = AddConnection();
            while (true)
            {
                Message(client);
            }
        }
    }
}
