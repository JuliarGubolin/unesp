using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AAAA
{
    public partial class Exp2 : Form
    {
        int cont = 0, a = 97;
        double b, qnt = 0;
        int[] vet = new int[10];
        public Exp2()
        {
            InitializeComponent();
            trackBar1.Maximum = 4;
            trackBar1.Minimum = 1;
            lbl_track.Text = "1";
            chart1.Series[0].Points.Clear();
            lbl_track.Text = trackBar1.Value.ToString();
            int a_aux = a;
            int[] prim_vet = new int[] { 1, 1, 2, 2, 2, 1, 1};
            for (int i = 0; i < 7; i++)
            {
                chart1.Series[0].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", prim_vet[i]);
                chart1.Series[1].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", prim_vet[i]);
                a_aux++;
            }
            a_aux = a;
            int[] ult_vet = new int[] { 0, 1, 4, 4, 1, 0, 0 };
            for (int i = 0; i < 7; i++)
            {
                chart2.Series[0].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", prim_vet[i]);
                chart2.Series[1].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", prim_vet[i]);
                
                a_aux++;
            }
            chart3.Series[0].Points.AddXY(1, 96, 103, 99, 101);
            chart3.Series[1].Points.AddXY(1, 95);
            groupBox1.Visible = true;
            //timer1.Start();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Frm_inicio lala = new Frm_inicio();
            lala.Show();
            this.Hide();
        }

        private void label11_Click(object sender, EventArgs e)
        {
            groupBox1.Visible = false;
            groupBox3.Visible = false;
            groupBox4.Visible = false;
            groupBox5.Visible = false;
            groupBox2.Visible = true;
        }

        private void label13_Click(object sender, EventArgs e)
        {
            groupBox1.Visible = true;
            groupBox3.Visible = false;
            groupBox4.Visible = false;
            groupBox5.Visible = false;
            groupBox2.Visible = false;
        }

        private void label36_Click(object sender, EventArgs e)
        {
            groupBox4.Visible = true;
            groupBox3.Visible = false;
            groupBox2.Visible = false;
            groupBox5.Visible = false;
            groupBox1.Visible = false;
        }

        private void label42_Click(object sender, EventArgs e)
        {
            groupBox4.Visible = false;
            groupBox3.Visible = false;
            groupBox2.Visible = false;
            groupBox5.Visible = true;
            groupBox1.Visible = false;
        }

        private void label41_Click(object sender, EventArgs e)
        {
            groupBox4.Visible = false;
            groupBox3.Visible = true;
            groupBox2.Visible = false;
            groupBox5.Visible = false;
            groupBox1.Visible = false;
        }

        private void label44_Click(object sender, EventArgs e)
        {
            groupBox4.Visible = true;
            groupBox3.Visible = false;
            groupBox2.Visible = false;
            groupBox5.Visible = false;
            groupBox1.Visible = false;
        }

        private void label43_Click(object sender, EventArgs e)
        {
            groupBox4.Visible = false;
            groupBox3.Visible = false;
            groupBox2.Visible = true;
            groupBox5.Visible = false;
            groupBox1.Visible = false;
        }

        private void label12_Click(object sender, EventArgs e)
        {
            groupBox4.Visible = false;
            groupBox3.Visible = true;
            groupBox2.Visible = false;
            groupBox5.Visible = false;
            groupBox1.Visible = false;
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            if (trackBar1.Value.ToString() == "1")
            {
                chart1.Series[0].Points.Clear();
                chart1.Series[1].Points.Clear();
                lbl_track.Text = trackBar1.Value.ToString();
                int a_aux = a;
                int[] prim_vet = new int[] {1, 1, 2, 2, 2, 1, 1};
                for (int i = 0; i < 7; i++)
                {
                    chart1.Series[0].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", prim_vet[i]);
                    chart1.Series[1].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", prim_vet[i]);
                    a_aux++;
                }

            }
            else if (trackBar1.Value.ToString() == "2")
            {
                chart1.Series[0].Points.Clear();
                chart1.Series[1].Points.Clear();
                lbl_track.Text = trackBar1.Value.ToString();
                int a_aux = a;
                int[] sec_vet = new int[] { 0,    2 ,    2 ,    4,     2 ,     0,     0 };
                for (int i = 0; i < 7; i++)
                {
                    chart1.Series[0].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", sec_vet[i]);
                    chart1.Series[1].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", sec_vet[i]);
                    a_aux++;
                }
            }
            else if (trackBar1.Value.ToString() == "3")
            {
                lbl_track.Text = "5";
                chart1.Series[0].Points.Clear();
                chart1.Series[1].Points.Clear();
                int a_aux = a;
                int[] terc_vet = new int[] { 0,    2,     2,     5 ,    1,      0,     0 };
                for (int i = 0; i < 7; i++)
                {
                    chart1.Series[0].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", terc_vet[i]);
                    chart1.Series[1].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", terc_vet[i]);
                    a_aux++;
                }
            }
            else if (trackBar1.Value.ToString() == "4")
            {
                lbl_track.Text = "10";
                chart1.Series[0].Points.Clear();
                chart1.Series[1].Points.Clear();
                int a_aux = a;
                int[] quart_vet = new int[] { 0 ,   1,     4,     4,     1,      0,     0 };
                for (int i = 0; i < 7; i++)
                {
                    chart1.Series[0].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", quart_vet[i]);
                    chart1.Series[1].Points.AddXY("[" + a_aux + ";" + (a_aux + 1) + ")", quart_vet[i]);
                    a_aux++;
                }
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            cont++;
            Double numrand = new Random().NextDouble();
            //listBox1.Items.Add(numrand);

            if (cont == qnt)
            {
                for (int i = 0; i < qnt; i++)
                {
                    //chart1.Series[0].Points.AddXY(i, Math.Round(a + (b - a) * Convert.ToDouble(listBox1.Items[i]), 0));
                    //listBox1.Items.Add(a + (b - a) * Convert.ToDouble(listBox1.Items[i]));
                }
                chart1.Update();
                timer1.Stop();
            }
        }
    }
}
