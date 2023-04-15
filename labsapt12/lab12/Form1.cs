using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab12
{
    public partial class Form1 : Form
    {
        static WinApiClass.SECURITY_ATTRIBUTES sa = new WinApiClass.SECURITY_ATTRIBUTES();
        static IntPtr handlerSemaphore = WinApiClass.CreateSemaphore(ref sa, 4, 4, "semaphore");
        static uint dwmiliseconds = 200;
        static IntPtr dwSemCount;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            UInt32 dwWaitResult;
            dwWaitResult = WinApiClass.WaitForSingleObject(handlerSemaphore, dwmiliseconds );
            switch (dwWaitResult)
            {
                case WinApiClass.WAIT_OBJECT_0:
                    // Puneti aici codul care deschide fereastra
                    var f2 = new Form();
                    f2.Show();
                    break;
                case WinApiClass.WAIT_TIMEOUT:
                    // Numarul de ferestre este maxim.
                   // if (f2.)
                   // WinApiClass.ReleaseSemaphore(handlerSemaphore, 1, dwSemCount);
                    break;
            }
        }
    }
}
