using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace AAAA
{
    public partial class Btn_det : Form
    {
        String message = "O gráfico a esquerda representa os valores observados, retirados de uma pesquisa real. " +
            "Já o gráfico da direita representa os valores esperados. Como é possível notar pelo gráfico de valores observados, é mais" +
            " provável que a variável X = 'Tempo para absorção do fármaco Clonazepam (4 mg) em horas' siga um modelo exponencial.\n" +
            "Tendo isso em mente, os valores esperados (Ei) são calculados para cada intervalo utilizando α = 0.07709. Após este cálculos, é possível, " +
            "então, calcular o valor de Qui-Quadrado e confirmar com certeza se a variável segue ou não o modelo.";
        private void Btn_detalhes_Click(object sender, EventArgs e)
        {
            MessageBox.Show(message, "Informações sobre a simulação:", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void Btn_form_Click(object sender, EventArgs e)
        {
            Form4 newform2 = new Form4();
            newform2.Show();
            this.Hide();
        }
        public Btn_det()
        {
            InitializeComponent();
            string[] x = { "[0,6)", "[6,12)", "[12,18)", "[18,24)", "[24,30)", "[30,36)", "[36,42)" };
            double[] y = { 41.1, 25, 10, 7.5, 4.5, 2.1, 0.6 };
            double[] esp = { 33.62, 21.17, 13.33, 8.39, 5.28, 3.33, 2.09 };
            int i;
            chart1.Series.Add("linha");
            chart1.Series["linha"].ChartType = SeriesChartType.Spline;
            chart1.Series["linha"].BorderWidth = 5;
            chart1.Series["linha"].Color = Color.Red;
            chart1.Series["linha"].LegendText = "Curva de tendência";
            chart2.Series.Add("barraesp");
            chart2.Series["barraesp"].ChartType = SeriesChartType.Spline;
            chart2.Series["barraesp"].BorderWidth = 3;
            chart2.Series["barraesp"].Color = Color.Green;
            chart2.Series["barraesp"].LegendText = "Curva esperada";

            chart1.Series.Add("barra");
            chart1.Series["barra"].ChartType = SeriesChartType.Spline;
            chart1.Series["barra"].BorderWidth = 3;
            chart1.Series["barra"].Color = Color.Green;
            chart1.Series["barra"].LegendText = "Curva esperada";
            richTextBox1.Text = "Freq. esperada para cada intervalo:\n";
            for (i = 0; i < 7; i++)
            {
                chart2.Series[0].Points.AddXY(x[i], esp[i]);
                chart2.Series["barraesp"].Points.AddXY(x[i], esp[i]);
                chart1.Series["barra"].Points.AddXY(x[i], esp[i]);
                chart1.Series[0].Points.AddXY(x[i], y[i]);
                chart1.Series["linha"].Points.AddXY(x[i], y[i]);
                richTextBox1.Text += x[i] +" - "+ esp[i] + "\n";
            }
        }
    }
}