namespace AAAA
{
    partial class Ale
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title1 = new System.Windows.Forms.DataVisualization.Charting.Title();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Ale));
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.lbl_carg = new System.Windows.Forms.Label();
            this.lbl_qui = new System.Windows.Forms.Label();
            this.txt_numr = new System.Windows.Forms.TextBox();
            this.lbl_numr = new System.Windows.Forms.Label();
            this.btn_numr = new System.Windows.Forms.Button();
            this.chart3 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.btn_ver = new System.Windows.Forms.Button();
            this.btn_normal = new System.Windows.Forms.Button();
            this.btn_exp = new System.Windows.Forms.Button();
            this.txt_alpha = new System.Windows.Forms.TextBox();
            this.lbl_alpha = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.chart3)).BeginInit();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(12, 276);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(120, 108);
            this.listBox1.TabIndex = 13;
            this.listBox1.Visible = false;
            // 
            // lbl_carg
            // 
            this.lbl_carg.AutoSize = true;
            this.lbl_carg.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbl_carg.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_carg.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.lbl_carg.Location = new System.Drawing.Point(698, 9);
            this.lbl_carg.Name = "lbl_carg";
            this.lbl_carg.Size = new System.Drawing.Size(126, 23);
            this.lbl_carg.TabIndex = 12;
            this.lbl_carg.Text = "Carregando ...";
            // 
            // lbl_qui
            // 
            this.lbl_qui.AutoSize = true;
            this.lbl_qui.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbl_qui.Font = new System.Drawing.Font("Times New Roman", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_qui.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.lbl_qui.Location = new System.Drawing.Point(138, 276);
            this.lbl_qui.Name = "lbl_qui";
            this.lbl_qui.Size = new System.Drawing.Size(25, 15);
            this.lbl_qui.TabIndex = 11;
            this.lbl_qui.Text = "___";
            this.lbl_qui.Visible = false;
            // 
            // txt_numr
            // 
            this.txt_numr.Location = new System.Drawing.Point(233, 118);
            this.txt_numr.Name = "txt_numr";
            this.txt_numr.Size = new System.Drawing.Size(108, 20);
            this.txt_numr.TabIndex = 10;
            this.txt_numr.Visible = false;
            // 
            // lbl_numr
            // 
            this.lbl_numr.AutoSize = true;
            this.lbl_numr.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbl_numr.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_numr.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.lbl_numr.Location = new System.Drawing.Point(9, 119);
            this.lbl_numr.Name = "lbl_numr";
            this.lbl_numr.Size = new System.Drawing.Size(218, 19);
            this.lbl_numr.TabIndex = 9;
            this.lbl_numr.Text = "Quantidade de números aleatórios:";
            this.lbl_numr.Visible = false;
            // 
            // btn_numr
            // 
            this.btn_numr.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btn_numr.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btn_numr.Location = new System.Drawing.Point(372, 119);
            this.btn_numr.Name = "btn_numr";
            this.btn_numr.Size = new System.Drawing.Size(75, 55);
            this.btn_numr.TabIndex = 8;
            this.btn_numr.Text = "Confirmar";
            this.btn_numr.UseVisualStyleBackColor = false;
            this.btn_numr.Visible = false;
            this.btn_numr.Click += new System.EventHandler(this.btn_numr_Click);
            // 
            // chart3
            // 
            chartArea1.AxisX.Title = "Intervalos de valores";
            chartArea1.AxisX.TitleFont = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            chartArea1.AxisY.Title = "Qtd de valores em cada intervalo";
            chartArea1.AxisY.TitleFont = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            chartArea1.Name = "ChartArea1";
            this.chart3.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chart3.Legends.Add(legend1);
            this.chart3.Location = new System.Drawing.Point(522, 35);
            this.chart3.Name = "chart3";
            series1.BorderColor = System.Drawing.Color.Black;
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Point;
            series1.IsValueShownAsLabel = true;
            series1.Legend = "Legend1";
            series1.MarkerBorderColor = System.Drawing.Color.Indigo;
            series1.MarkerBorderWidth = 6;
            series1.MarkerStyle = System.Windows.Forms.DataVisualization.Charting.MarkerStyle.Circle;
            series1.Name = "Intervalos";
            this.chart3.Series.Add(series1);
            this.chart3.Size = new System.Drawing.Size(492, 420);
            this.chart3.TabIndex = 7;
            this.chart3.Text = "chart1";
            title1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            title1.Name = "Title1";
            title1.Text = "Gráfico da verificação de números randômicos";
            this.chart3.Titles.Add(title1);
            this.chart3.Visible = false;
            // 
            // timer1
            // 
            this.timer1.Interval = 1;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.button1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button1.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(12, 390);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(87, 65);
            this.button1.TabIndex = 14;
            this.button1.Text = "Voltar p/ menu principal";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.button2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button2.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.Location = new System.Drawing.Point(105, 390);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(92, 65);
            this.button2.TabIndex = 15;
            this.button2.Text = "Informações";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // btn_ver
            // 
            this.btn_ver.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btn_ver.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btn_ver.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_ver.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.btn_ver.Location = new System.Drawing.Point(13, 33);
            this.btn_ver.Name = "btn_ver";
            this.btn_ver.Size = new System.Drawing.Size(110, 48);
            this.btn_ver.TabIndex = 16;
            this.btn_ver.Text = "Verificação";
            this.btn_ver.UseVisualStyleBackColor = false;
            this.btn_ver.Click += new System.EventHandler(this.btn_ver_Click);
            // 
            // btn_normal
            // 
            this.btn_normal.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btn_normal.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btn_normal.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_normal.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.btn_normal.Location = new System.Drawing.Point(337, 33);
            this.btn_normal.Name = "btn_normal";
            this.btn_normal.Size = new System.Drawing.Size(110, 48);
            this.btn_normal.TabIndex = 17;
            this.btn_normal.Text = "Modelo Normal";
            this.btn_normal.UseVisualStyleBackColor = false;
            this.btn_normal.Click += new System.EventHandler(this.btn_normal_Click);
            // 
            // btn_exp
            // 
            this.btn_exp.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btn_exp.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btn_exp.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_exp.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.btn_exp.Location = new System.Drawing.Point(178, 33);
            this.btn_exp.Name = "btn_exp";
            this.btn_exp.Size = new System.Drawing.Size(110, 48);
            this.btn_exp.TabIndex = 18;
            this.btn_exp.Text = "Modelo Exponencial";
            this.btn_exp.UseVisualStyleBackColor = false;
            this.btn_exp.Click += new System.EventHandler(this.btn_exp_Click);
            // 
            // txt_alpha
            // 
            this.txt_alpha.Location = new System.Drawing.Point(233, 154);
            this.txt_alpha.Name = "txt_alpha";
            this.txt_alpha.Size = new System.Drawing.Size(108, 20);
            this.txt_alpha.TabIndex = 19;
            this.txt_alpha.Visible = false;
            // 
            // lbl_alpha
            // 
            this.lbl_alpha.AutoSize = true;
            this.lbl_alpha.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbl_alpha.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_alpha.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.lbl_alpha.Location = new System.Drawing.Point(8, 155);
            this.lbl_alpha.Name = "lbl_alpha";
            this.lbl_alpha.Size = new System.Drawing.Size(48, 19);
            this.lbl_alpha.TabIndex = 20;
            this.lbl_alpha.Text = "Alpha:";
            this.lbl_alpha.Visible = false;
            // 
            // Ale
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::AAAA.Properties.Resources._1_3_VIKD_Ywkx3FeIlDtNknw1;
            this.ClientSize = new System.Drawing.Size(1026, 467);
            this.Controls.Add(this.lbl_alpha);
            this.Controls.Add(this.txt_alpha);
            this.Controls.Add(this.btn_exp);
            this.Controls.Add(this.btn_normal);
            this.Controls.Add(this.btn_ver);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.lbl_carg);
            this.Controls.Add(this.lbl_qui);
            this.Controls.Add(this.txt_numr);
            this.Controls.Add(this.lbl_numr);
            this.Controls.Add(this.btn_numr);
            this.Controls.Add(this.chart3);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Ale";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Simulação de números randômicos";
            ((System.ComponentModel.ISupportInitialize)(this.chart3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label lbl_carg;
        private System.Windows.Forms.Label lbl_qui;
        private System.Windows.Forms.TextBox txt_numr;
        private System.Windows.Forms.Label lbl_numr;
        private System.Windows.Forms.Button btn_numr;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart3;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button btn_ver;
        private System.Windows.Forms.Button btn_normal;
        private System.Windows.Forms.Button btn_exp;
        private System.Windows.Forms.TextBox txt_alpha;
        private System.Windows.Forms.Label lbl_alpha;
    }
}