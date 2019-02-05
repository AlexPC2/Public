using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
           // String analog = textBox1.Text;


            string a = textBox1.Text;
            var c = Encoding.Default.GetChars(Encoding.Default.GetBytes(a)); //получаю массив char[]

            char[] noDouble = c.Distinct().ToArray();
            double countOfBite = Math.Log(noDouble.Length, 2);
            String result = null;
     
            for (int i = 0; i < c.Length; i++)
            {
                for(int j = 0; j < noDouble.Length; j++)
                {
                    if (c[i] == noDouble[j])
                    {/*
                        String strNull = "";
                        for (int n = 0; n < Convert.ToInt32(countOfBite) - Convert.ToInt32(Math.Log(j+1,2) - 1); n++ )
                        // while (Convert.ToDouble(Convert.ToString(j, 2).Length) < countOfBite)
                        {
                            strNull = strNull + "0";
                        }
                        result =   result strNull+ Convert.ToString(j, 2) + " ";
                        */
                        result =  result + Convert.ToString(j, 2) + " ";
                    }
                }
                
            }
            textBox2.Text = result;
         // textBox2.Text = Convert.ToString(noDouble.Length);  //конвертирую обратно
           

        }
    }
}
