namespace AAAA
{
    partial class Frm_exp1
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Frm_exp1));
            this.Btn_calc = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.zed = new ZedGraph.ZedGraphControl();
            this.Btn_det = new System.Windows.Forms.Button();
            this.Btn_fechar2 = new System.Windows.Forms.Button();
            //this.performanceCounter1 = new System.Diagnostics.PerformanceCounter();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            //((System.ComponentModel.ISupportInitialize)(this.performanceCounter1)).BeginInit();
            this.SuspendLayout();
            // 
            // Btn_calc
            // 
            this.Btn_calc.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Btn_calc.Font = new System.Drawing.Font("Times New Roman", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Btn_calc.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Btn_calc.Location = new System.Drawing.Point(12, 291);
            this.Btn_calc.Margin = new System.Windows.Forms.Padding(5);
            this.Btn_calc.Name = "Btn_calc";
            this.Btn_calc.Size = new System.Drawing.Size(198, 85);
            this.Btn_calc.TabIndex = 2;
            this.Btn_calc.Text = "Calcular";
            this.Btn_calc.UseVisualStyleBackColor = false;
            this.Btn_calc.Click += new System.EventHandler(this.Btn_calc_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("MS PGothic", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(169, 158);
            this.label2.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(0, 18);
            this.label2.TabIndex = 3;
            // 
            // zed
            // 
            this.zed.Location = new System.Drawing.Point(608, 14);
            this.zed.Margin = new System.Windows.Forms.Padding(5);
            this.zed.Name = "zed";
            this.zed.ScrollGrace = 0D;
            this.zed.ScrollMaxX = 0D;
            this.zed.ScrollMaxY = 0D;
            this.zed.ScrollMaxY2 = 0D;
            this.zed.ScrollMinX = 0D;
            this.zed.ScrollMinY = 0D;
            this.zed.ScrollMinY2 = 0D;
            this.zed.Size = new System.Drawing.Size(410, 395);
            this.zed.TabIndex = 5;
            this.zed.UseExtendedPrintDialog = true;
            // 
            // Btn_det
            // 
            this.Btn_det.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Btn_det.Font = new System.Drawing.Font("Times New Roman", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Btn_det.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Btn_det.Location = new System.Drawing.Point(12, 425);
            this.Btn_det.Name = "Btn_det";
            this.Btn_det.Size = new System.Drawing.Size(142, 58);
            this.Btn_det.TabIndex = 6;
            this.Btn_det.Text = "Detalhes do experimento";
            this.Btn_det.UseVisualStyleBackColor = false;
            this.Btn_det.Click += new System.EventHandler(this.Btn_det_Click);
            this.Btn_det.MouseLeave += new System.EventHandler(this.Btn_det_MouseLeave);
            this.Btn_det.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Btn_det_MouseMove);
            // 
            // Btn_fechar2
            // 
            this.Btn_fechar2.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Btn_fechar2.Font = new System.Drawing.Font("Times New Roman", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Btn_fechar2.Location = new System.Drawing.Point(900, 423);
            this.Btn_fechar2.Name = "Btn_fechar2";
            this.Btn_fechar2.Size = new System.Drawing.Size(106, 60);
            this.Btn_fechar2.TabIndex = 7;
            this.Btn_fechar2.Text = "Voltar";
            this.Btn_fechar2.UseVisualStyleBackColor = false;
            this.Btn_fechar2.Click += new System.EventHandler(this.Btn_fechar2_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label1.Location = new System.Drawing.Point(220, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(58, 22);
            this.label1.TabIndex = 8;
            this.label1.Text = "label1";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label3.Font = new System.Drawing.Font("Times New Roman", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label3.Location = new System.Drawing.Point(3, 16);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(572, 19);
            this.label3.TabIndex = 9;
            this.label3.Text = " Simulação de distribuição exponencial - Suponha que X seja uma variável aleatóri" +
    "a";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label4.Font = new System.Drawing.Font("Times New Roman", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label4.Location = new System.Drawing.Point(3, 35);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(496, 19);
            this.label4.TabIndex = 10;
            this.label4.Text = "com distribuição uniforme no intervalo [0, 1]. Seja 𝑌 =(−1/𝛼)log(1 − 𝑋).";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label5.Font = new System.Drawing.Font("Times New Roman", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label5.Location = new System.Drawing.Point(3, 77);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(579, 19);
            this.label5.TabIndex = 11;
            this.label5.Text = "Realize um estudo numérico, por meio de simulação de números pseudo-aleatórios,";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label6.Font = new System.Drawing.Font("Times New Roman", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label6.Location = new System.Drawing.Point(3, 96);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(549, 19);
            this.label6.TabIndex = 12;
            this.label6.Text = "para mostrar que a variável Y segue os padrões de uma distribuição exponencial ";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label7.Font = new System.Drawing.Font("Times New Roman", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label7.Location = new System.Drawing.Point(-1, 115);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(553, 19);
            this.label7.TabIndex = 13;
            this.label7.Text = " de parâmetro 𝛼. Faça uma suposição para ilustrar a variável Y num contexto real" +
    ".";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label8.Font = new System.Drawing.Font("Times New Roman", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label8.Location = new System.Drawing.Point(0, 134);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(552, 19);
            this.label8.TabIndex = 14;
            this.label8.Text = " Por exemplo, você pode supor que Y é o tempo de permanência num website de";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label9.Font = new System.Drawing.Font("Times New Roman", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label9.Location = new System.Drawing.Point(0, 153);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(546, 19);
            this.label9.TabIndex = 15;
            this.label9.Text = " compras online. Use tabelas e gráficos para ilustrar os resultados na aplicação." +
    "";
            // 
            // Frm_exp1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.BackgroundImage = global::AAAA.Properties.Resources._1_3_VIKD_Ywkx3FeIlDtNknw1;
            this.ClientSize = new System.Drawing.Size(1032, 495);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Btn_fechar2);
            this.Controls.Add(this.Btn_det);
            this.Controls.Add(this.zed);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Btn_calc);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(5);
            this.Name = "Frm_exp1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Simulação 1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Frm_exp1_FormClosing);
            //((System.ComponentModel.ISupportInitialize)(this.performanceCounter1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button Btn_calc;
        private System.Windows.Forms.Label label2;
        private ZedGraph.ZedGraphControl zed;
        private System.Windows.Forms.Button Btn_det;
        private System.Windows.Forms.Button Btn_fechar2;
        //private System.Diagnostics.PerformanceCounter performanceCounter1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
    }
}

