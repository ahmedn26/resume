using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Net.NetworkInformation;

namespace Server
{
    class Server
    {
        //static List<Socket> sockets = new List<Socket>();
        static Dictionary<string, Socket> sockets = new Dictionary<string, Socket>();

        static void ServerRoom()
        {
            TcpListener server = new TcpListener(IPAddress.Loopback, 5000);
            server.Start();

            Console.WriteLine("Waiting for connection...");
            while (true)
            {
                Thread t = new Thread(handleConnections);
                Socket client = server.AcceptSocket();
                t.Start(client);
            }

            server.Stop();

        }
        static Socket pingConnections(object socket)
        { 
            Socket client = (Socket)socket;
            Console.WriteLine($"Connection accepted from {client.RemoteEndPoint}");
            return client;

        }

        static void Main(string[] args)
        {
            ServerRoom();
        }

        static void handleConnections(object socket)
        {
            Socket client = pingConnections(socket);
            byte[] buffer = new byte[1024];
            int k = client.Receive(buffer);
            string username = Encoding.ASCII.GetString(buffer, 0, k);
            sockets[username] = client;
            while (true)
            {
                try
                {
                    k = client.Receive(buffer);
                    foreach (KeyValuePair<string, Socket> otherClient in sockets)
                    {
                        if (otherClient.Value != client) //stops the echo
                        {
                            string clientData = $"[{username}] - " + Encoding.ASCII.GetString(buffer, 0, k);
                            otherClient.Value.Send(Encoding.ASCII.GetBytes(clientData));
                        }
                    }
                    Console.WriteLine($"{username} said: " + Encoding.ASCII.GetString(buffer, 0, k));
                }
                catch (Exception e)
                {
                    sockets.Remove(username);
                    break;
                }
            

            }
            client.Close();
        }
    }
}
