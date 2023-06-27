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
    public partial class Frm_exp1 : Form
    {
        String message = "Este experimento visa demonstrar uma simulação de distribuição exponencial. Esta distribuição é um modelo de probabilidade para variáveis aleatórias contínuas.\nNOTAÇÃO: X~Exp(𝛼).\nA fórmula fornecida pelo enunciado foi: 𝑌 =(−1/𝛼)log(1 − 𝑋).\nPortanto, temos f(x) dada por: (−1/𝛼)log(1 − 𝑋), se 0<x<1 e 0, caso contrário.\nA média e a variância são definidas, respectivamente, como: E(X) = 1/𝛼 e V(X) = 1/α^2.\nO parâmetro 𝛼 possui o valor de 0.005.";
        static int tamanho = 50;
        double[] y = new double[tamanho];
        double[] aux = new double[tamanho];
        public Frm_exp1()
        {
            InitializeComponent();
        }
        private void Btn_calc_Click(object sender, EventArgs e)
        {
            double a, x;
            a = 1.0;
            Random rnd = new Random();
            for (int i = 0; i < tamanho; i++)
            {
                x = rnd.NextDouble();
                aux[i] = x;
                y[i] = (-1 / a) * Math.Log(1 - x, 10);
            }
            zed.GraphPane.Title.Text = "Experimento 1 teste";
            zed.GraphPane.AddCurve("Experimento 1", aux, y, Color.Red);
            zed.RestoreScale(zed.GraphPane);
            zed.Refresh();
        }

        private void Btn_fechar2_Click(object sender, EventArgs e)
        {
            Frm_inicio teste = new Frm_inicio();
            teste.Show();
            this.Hide();
        }

        private void Btn_det_Click(object sender, EventArgs e)
        {
            
        }

        private void Frm_exp1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Application.Exit();
        }

        private void Btn_det_MouseMove(object sender, MouseEventArgs e)
        { 
            
        }

        private void Btn_det_MouseLeave(object sender, EventArgs e)
        {
           
        }
    }
}
