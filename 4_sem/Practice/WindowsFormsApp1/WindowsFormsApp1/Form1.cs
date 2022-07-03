using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        private void H(int x, int y, int razmer)//функция отрисовки одной Н
        {
            Random random = new Random();
            Pen myPen = new Pen(Color.FromArgb(random.Next(255), random.Next(255),
                random.Next(255)))
            {
                Width = 1
            };
            Graphics g = Graphics.FromHwnd(pictureBox1.Handle);

            g.DrawLine(myPen, x - razmer, y - razmer, x - razmer, y + razmer);
            g.DrawLine(myPen, x - razmer, y, x + razmer, y);
            g.DrawLine(myPen, x + razmer, y - razmer, x + razmer, y + razmer);
        }

        private void H_fractal(int x1, int y1, int razm_f)
        {
            //вершины фигуры Н
            int x11; int y11;
            int x01; int y01;
            int x00; int y00;
            int x10; int y10;
            x11 = x1 + razm_f;
            y11 = y1 + razm_f;
            x01 = x1 - razm_f;
            y01 = y1 + razm_f;
            x10 = x1 + razm_f;
            y10 = y1 - razm_f;
            x00 = x1 - razm_f;
            y00 = y1 - razm_f;


            tree.Add(x1, y1);
            
            H(x1, y1, razm_f);
            razm_f = razm_f / 2;

            if (razm_f >= 256/Math.Pow(2,n_))
            {
                H_fractal(x11, y11, razm_f);
                H_fractal(x01, y01, razm_f);
                H_fractal(x10, y10, razm_f);
                H_fractal(x00, y00, razm_f);
            }
        }

        private int height_;
        private int width_;
        private int n_;

        BinaryTree<int> tree;
        

        public Form1()
        {
            InitializeComponent();
            height_ = pictureBox1.Height; //высота элемента pictureBox1
            width_ = pictureBox1.Width; // ширина 
        }
        
        private void button1_Click(object sender, EventArgs e)
        {
            tree = new BinaryTree<int>();
            H_fractal(width_ / 2, height_ / 2, 128);

            Form2 newForm = new Form2(this, tree);
            newForm.Show();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            n_ = (int)numericUpDown1.Value;
        }
    }
}