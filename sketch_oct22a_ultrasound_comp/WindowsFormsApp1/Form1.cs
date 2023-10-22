using System;
using System.IO.Ports;
using System.IO;
using System.Text;

using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        SerialPort sp = new SerialPort("COM6", 9600, Parity.None, 8, StopBits.One);

        delegate void SetTextDelegate(string value);

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, System.EventArgs e)
        {

            if (!sp.IsOpen)
            {
                sp.Open();
                sp.WriteLine("A");
                sp.Close();
            }
            else
            {
                MessageBox.Show("Error opening the serial port!");
            }
            try
            {

                if (!sp.IsOpen)
                    sp.Open();

            }
            catch
            {
                MessageBox.Show("Error opening the serial port!");
            }
            for (int i = 0; i <= 20; i++)
            {
                if (sp.IsOpen)
                {
                    chart1.Series[0].Points.Add(Convert.ToSingle(sp.ReadLine()));

                }
                System.Threading.Thread.Sleep(200); // засыпаем на одну секунду 
            }
        }
    }
}
