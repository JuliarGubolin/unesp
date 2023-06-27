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
    public partial class Frm_inicio : Form
    {
        public Frm_inicio()
        {
            InitializeComponent();
        }

        /*string target = "https://www.ibilce.unesp.br/Home/Departamentos/CiencCompEstatistica/Adriana/distribuicao_quiquadrado.pdf";
            string target2 = "https://www.ibilce.unesp.br/Home/Departamentos/CiencCompEstatistica/Adriana/tabela-normal.gif";
            //Use no more than one assignment when you test this code.
            //string target = "C:\Program Files\Microsoft Visual Studio\INSTALL.HTM";
            try
            {
                System.Diagnostics.Process.Start(target);
                System.Diagnostics.Process.Start(target2);
            }
            catch (System.ComponentModel.Win32Exception noBrowser)
            {
                if (noBrowser.ErrorCode == -2147467259)
                    MessageBox.Show(noBrowser.Message);
            }
            catch (System.Exception other)
            {
                MessageBox.Show(other.Message);
            }*/

        private void label4_Click(object sender, EventArgs e)
        {
            string target = "https://www.ibilce.unesp.br/Home/Departamentos/CiencCompEstatistica/Adriana/distribuicao_quiquadrado.pdf";
            string target2 = "https://www.ibilce.unesp.br/Home/Departamentos/CiencCompEstatistica/Adriana/tabela-normal.gif";
            //Use no more than one assignment when you test this code.
            //string target = "C:\Program Files\Microsoft Visual Studio\INSTALL.HTM";
            try
            {
                System.Diagnostics.Process.Start(target);
                System.Diagnostics.Process.Start(target2);
            }
            catch (System.ComponentModel.Win32Exception noBrowser)
            {
                if (noBrowser.ErrorCode == -2147467259)
                    MessageBox.Show(noBrowser.Message);
            }
            catch (System.Exception other)
            {
                MessageBox.Show(other.Message);
            }
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void label8_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            Form4 teste = new Form4();
            teste.Show();
            this.Hide();
        }

        private void label5_Click(object sender, EventArgs e)
        {
            Form4 teste = new Form4();
            teste.Show();
            this.Hide();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            string target = "https://www.ibilce.unesp.br/Home/Departamentos/CiencCompEstatistica/Adriana/distribuicao_quiquadrado.pdf";
            string target2 = "https://www.ibilce.unesp.br/Home/Departamentos/CiencCompEstatistica/Adriana/tabela-normal.gif";
            //Use no more than one assignment when you test this code.
            //string target = "C:\Program Files\Microsoft Visual Studio\INSTALL.HTM";
            try
            {
                System.Diagnostics.Process.Start(target);
                System.Diagnostics.Process.Start(target2);
            }
            catch (System.ComponentModel.Win32Exception noBrowser)
            {
                if (noBrowser.ErrorCode == -2147467259)
                    MessageBox.Show(noBrowser.Message);
            }
            catch (System.Exception other)
            {
                MessageBox.Show(other.Message);
            }
        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            Ale teste = new Ale();
            teste.Show();
            this.Hide();
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            Exp2 teste = new Exp2();
            teste.Show();
            this.Hide();
        }

        private void label7_Click(object sender, EventArgs e)
        {
            Exp2 teste = new Exp2();
            teste.Show();
            this.Hide();
        }

        private void label6_Click(object sender, EventArgs e)
        {
            Ale teste = new Ale();
            teste.Show();
            this.Hide();
        }
    }
}
