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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Btn_det aaa = new Btn_det();
            aaa.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form5 jooj = new Form5();
            jooj.Show();
            this.Hide();
        }

        private void btn_close_Click(object sender, EventArgs e)
        {
            Frm_inicio newform2 = new Frm_inicio();
            newform2.Show();
            this.Hide();
        }

        private void btn_ajuda_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Caso queira verificar uma simulação previamente preparada, com dados já adicionados e um gráfico completo, clique no botão 'Simulação com dados previamente preparados'.\nCaso queira adicionar seus próprios valores para simular e gerar um gráfico, clique no botão 'Incluir dados'.", "Como funciona:", MessageBoxButtons.OK,MessageBoxIcon.Question);
        }
    }
}
