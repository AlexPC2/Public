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

        private void button1_Click(object sender, EventArgs e)              // Кнопка нажата
        
        {
           // String analog = textBox1.Text;


            string a = textBox1.Text;                                        // Ввод строки
            var c = Encoding.Default.GetChars(Encoding.Default.GetBytes(a)); // Получаю массив char[]

            char[] noDouble = c.Distinct().ToArray();                        // Массив из уникальных букв (Алфавит)
            double countOfBite = Math.Log(noDouble.Length, 2);               // Требуемое число бит для кодировки слова
            String result = null;                                            // Результат - переведенная строка
     
            for (int i = 0; i < c.Length; i++)                               // Перебор всех букв исходной строки
            {
                for(int j = 0; j < noDouble.Length; j++)                     // Каждую букву исходной строки сравниваем с алфавитом
                {
                    if (c[i] == noDouble[j])                                 // Находим номер символа в алфавите
                    {/*
                        String strNull = "";
                        for (int n = 0; n < Convert.ToInt32(countOfBite) - Convert.ToInt32(Math.Log(j+1,2) - 1); n++ )
                        // while (Convert.ToDouble(Convert.ToString(j, 2).Length) < countOfBite)
                        {
                            strNull = strNull + "0";
                        }
                        result =   result strNull+ Convert.ToString(j, 2) + " ";
                        */
                        result =  result + Convert.ToString(j, 2) + " ";      // К строке результата добавляем новый символ по номеру исходного в алфавите
                    }
                }
                
            }
            textBox2.Text = result;                                           // Вывод результата в строке вывода
         // textBox2.Text = Convert.ToString(noDouble.Length);  //конвертирую обратно
           

        }
    }
}
