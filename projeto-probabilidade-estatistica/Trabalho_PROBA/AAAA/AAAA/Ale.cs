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
    
    public partial class Ale : Form
    {
        double alpha;
        int x = 1, verify=0, cont=0, qnt;
        double[] qui_qua = new double[30] { 3.841, 5.991, 7.815, 9.488, 11.070, 12.592, 14.067, 15.507,
        16.919, 18.307, 19.675, 21.026, 22.362, 23.685, 24.996, 26.296, 27.587, 28.869, 30.144, 31.410,
        32.671, 33.924, 35.172, 36.415, 37.652, 38.885, 40.113, 41.337, 42.557, 43.773};
        String message = "Esta área permite utilizar números aleatórios. Para verificar a qualidade do software quanto a essa geração, basta clicar no botão" +
            " 'Verificação', adicionar quantos números aleatórios deseja gerar e pressionar o botão 'Confirmar'.\nPara criar uma curva exponencial com valores de x aleatórios," +
            " basta adicionar quantos valores aleatórios deseja gerar e o valor de alpha e pressionar 'Confirmar'.\n" +
            "Para criar uma curva normal com valores de x aleatórios, basta também preencher o campo em branco com quantos valores quer gerar e pressionar 'Confirmar'.\n" +
            "OBS: Caso a quantidade de valores seja grande, o software demorará um tempo. Basta apenas esperar o gráfico ser mostrado na tela. ";
        public Ale()
        {
            InitializeComponent();
            lbl_carg.Visible = false;
            lbl_qui.Visible = false;
            chart3.Series.Add("linha");
            chart3.Series["linha"].ChartType = SeriesChartType.Spline;
            chart3.Series["linha"].BorderWidth = 2;
            chart3.Series["linha"].Color = Color.Red;
            chart3.Series["linha"].LegendText = "Média";
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Frm_inicio f = new Frm_inicio();
            this.Hide();
            f.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show(message, "Sobre a simulação", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void btn_ver_Click(object sender, EventArgs e)
        {
            listBox1.Visible = true;
            lbl_numr.Visible = true;
            btn_numr.Visible = true;
            txt_numr.Visible = true;
            verify = 1;
            txt_numr.Text = "";
            lbl_alpha.Visible = false;
            txt_alpha.Visible = false;
            listBox1.Items.Clear();
            chart3.Series[0].Points.Clear();
            chart3.Series[1].Points.Clear();
            lbl_qui.Visible = false;
            chart3.Visible = true;
            //Título do gráfico
            chart3.Titles[0].Text = "Gráfico da verificação de números randômicos";
            //Descrição do eixo X
            chart3.ChartAreas[0].Axes[0].Title = "Intervalos de valores em 0.1";
            //Descrição do eixo Y
            chart3.ChartAreas[0].Axes[1].Title = "Qtd de valores em cada intervalo";
            //Legenda da barras
            chart3.Series[0].LegendText = "Quantidades";
            //Lengenda da linha
            chart3.Series[1].Enabled = true;
            chart3.Series[0].IsValueShownAsLabel = true;
        }

        private void btn_normal_Click(object sender, EventArgs e)
        {
            listBox1.Visible = true;
            lbl_numr.Visible = true;
            btn_numr.Visible = true;
            txt_numr.Visible = true;
            lbl_qui.Visible = false;
            chart3.Visible = true;
            lbl_alpha.Visible = false;
            txt_alpha.Visible = false;
            txt_numr.Text = "";
            chart3.Series[0].Points.Clear();
            chart3.Series[1].Points.Clear();
            listBox1.Items.Clear();
            verify = 3;
            //Título do gráfico
            chart3.Titles[0].Text = "Distribuição normal com X aleatório";
            //Descrição do eixo X
            chart3.ChartAreas[0].Axes[0].Title = "X aleatório entre (0,1)";
            //Descrição do eixo Y
            chart3.ChartAreas[0].Axes[1].Title = "Distribuição normal";
            //Legenda da barras
            chart3.Series[0].LegendText = "Pares (x,y)";
            //Lengenda da linha
            chart3.Series[1].Enabled = false;
            chart3.Series[0].IsValueShownAsLabel = false;
        }

        private void btn_exp_Click(object sender, EventArgs e)
        {
            listBox1.Visible = true;
            lbl_numr.Visible = true;
            btn_numr.Visible = true;
            txt_numr.Visible = true;
            lbl_qui.Visible = false;
            chart3.Visible = true;
            lbl_alpha.Visible = true;
            txt_alpha.Visible = true;
            listBox1.Items.Clear();
            txt_numr.Text = "";
            chart3.Series[0].Points.Clear();
            chart3.Series[1].Points.Clear();
            txt_alpha.Text = "";
            verify = 2;
            //Título do gráfico
            chart3.Titles[0].Text = "Distribuição exponencial com X aleatório";
            //Descrição do eixo X
            chart3.ChartAreas[0].Axes[0].Title = "X aleatório entre (0,1)";
            //Descrição do eixo Y
            chart3.ChartAreas[0].Axes[1].Title = "Distribuição exponencial";
            //Legenda da barras
            chart3.Series[0].LegendText = "Pares (x,y)";
            //Lengenda da linha
            chart3.Series[1].Enabled = false;
            chart3.Series[0].IsValueShownAsLabel = false;
        }
        private void btn_numr_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            cont = 0;
            chart3.Series[0].Points.Clear();
            chart3.Series[1].Points.Clear();
            lbl_carg.Visible = true;
            qnt = Convert.ToInt32(txt_numr.Text);
            timer1.Start();
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            cont++;
            Double numrand = new Random().NextDouble();
            double qui = 0;
            listBox1.Items.Add(numrand);
            double media_rand = 0;
            if (cont == qnt && verify == 1)
            {
                    //listBox1.Items.RemoveAt(max);
                    int[] v = new int[10];
                    lbl_qui.Visible = true;
                    timer1.Stop();
                    for (x = 1; x < qnt + 1; x++)
                    {
                        if (Convert.ToDouble(listBox1.Items[x - 1]) < 0.1)
                            v[0]++;
                        else if (Convert.ToDouble(listBox1.Items[x - 1]) < 0.2)
                            v[1]++;
                        else if (Convert.ToDouble(listBox1.Items[x - 1]) < 0.3)
                            v[2]++;
                        else if (Convert.ToDouble(listBox1.Items[x - 1]) < 0.4)
                            v[3]++;
                        else if (Convert.ToDouble(listBox1.Items[x - 1]) < 0.5)
                            v[4]++;
                        else if (Convert.ToDouble(listBox1.Items[x - 1]) < 0.6)
                            v[5]++;
                        else if (Convert.ToDouble(listBox1.Items[x - 1]) < 0.7)
                            v[6]++;
                        else if (Convert.ToDouble(listBox1.Items[x - 1]) < 0.8)
                            v[7]++;
                        else if (Convert.ToDouble(listBox1.Items[x - 1]) < 0.9)
                            v[8]++;
                        else if (Convert.ToDouble(listBox1.Items[x - 1]) < 1.0)
                            v[9]++;
                        media_rand += Convert.ToDouble(listBox1.Items[x - 1]);

                    }
                    media_rand = (v[0] + v[1] + v[2] + v[3] + v[4] + v[5] + v[6] + v[7] + v[8] + v[9]) / 10;
                    for (x = 0; x < 10; x++)
                    {
                        qui = qui + Math.Pow((v[x] - media_rand), 2) / media_rand;//Somar os quis-quadrados
                        chart3.Series[0].Points.AddXY(x, v[x]);
                        chart3.Series[1].Points.AddXY(x, media_rand);
                    }
                    if (qui > qui_qua[8])//Resposta caso seja maior q o qui
                        lbl_qui.Text = "Qui-quadrado calculado: " + Convert.ToString(Math.Round(qui, 3)) +
                        "\nQui-quadrado tabela: " + Convert.ToString(qui_qua[8]) + "\nComo Qui-quadrado calculado > Qui-quadrado da tabela, o modelo é descartado.";

                    else//Resposta caso seja menor q o qui
                        lbl_qui.Text = "Qui-quadrado calculado: " + Convert.ToString(Math.Round(qui, 3)) +
                        "\nQui-quadrado da tabela: " + Convert.ToString(qui_qua[8]) + "\nComo Qui-quadrado calculado < Qui-quadrado da tabela, o modelo é aceito.";
                        chart3.Update();
                lbl_carg.Visible = false;
            }
            else if(cont == qnt && verify == 2)
                {
                    timer1.Stop();
                    alpha = Convert.ToDouble(txt_alpha.Text);
                    for (int i = 0; i < qnt; i++)
                    {
                        chart3.Series[0].Points.AddXY(listBox1.Items[i], (-1 / alpha) * Math.Log(Convert.ToDouble(listBox1.Items[i])));
                        listBox1.Items.Add(-alpha * Math.Log(Convert.ToDouble(listBox1.Items[i])));
                    }
                    chart3.Update();
                lbl_carg.Visible = false;
            }
                else if(cont == qnt && verify == 3)
                {
                    double dp = 0.2, m = 0.5;
                    timer1.Stop();
                    double y;
                    for (int i = 0; i < qnt; i++)
                    {
                        double elevado;
                        y = 1 / Math.Sqrt(2 * Math.PI * Math.Pow(dp, 2));

                        elevado = Math.Pow((Convert.ToDouble(listBox1.Items[i]) - m) / dp, 2);
                        elevado *= -0.5;
                        y = y * Math.Pow(Math.E, elevado);

                        chart3.Series[0].Points.AddXY(Convert.ToDouble(listBox1.Items[i]), y);
                    }
                    chart3.Update();
                lbl_carg.Visible = false;
            }
        }
    }
}
