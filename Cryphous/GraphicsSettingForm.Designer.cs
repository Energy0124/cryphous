﻿namespace Cryphous
{
    partial class GraphicsSettingForm
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
            this.numericUpDownPointSize = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.numericUpDownPointAlpha = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.numericUpDownLineSize = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownLineAlpha = new System.Windows.Forms.NumericUpDown();
            this.checkBoxShowAbsorbedPhotons = new System.Windows.Forms.CheckBox();
            this.numericUpDownPhotonAlpha = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.numericUpDownPhotonSize = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPointSize)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPointAlpha)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownLineSize)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownLineAlpha)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPhotonAlpha)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPhotonSize)).BeginInit();
            this.SuspendLayout();
            // 
            // numericUpDownPointSize
            // 
            this.numericUpDownPointSize.Location = new System.Drawing.Point(93, 26);
            this.numericUpDownPointSize.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownPointSize.Name = "numericUpDownPointSize";
            this.numericUpDownPointSize.Size = new System.Drawing.Size(41, 19);
            this.numericUpDownPointSize.TabIndex = 1;
            this.numericUpDownPointSize.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownPointSize.ValueChanged += new System.EventHandler(this.numericUpDownPointSize_ValueChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(27, 28);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 12);
            this.label2.TabIndex = 2;
            this.label2.Text = "PointSize";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(27, 64);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(60, 12);
            this.label1.TabIndex = 3;
            this.label1.Text = "PointAlpha";
            // 
            // numericUpDownPointAlpha
            // 
            this.numericUpDownPointAlpha.Location = new System.Drawing.Point(93, 62);
            this.numericUpDownPointAlpha.Name = "numericUpDownPointAlpha";
            this.numericUpDownPointAlpha.Size = new System.Drawing.Size(41, 19);
            this.numericUpDownPointAlpha.TabIndex = 4;
            this.numericUpDownPointAlpha.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownPointAlpha.ValueChanged += new System.EventHandler(this.numericUpDownPointAlpha_ValueChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(164, 28);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 12);
            this.label3.TabIndex = 5;
            this.label3.Text = "LineSize";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(164, 64);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(55, 12);
            this.label4.TabIndex = 6;
            this.label4.Text = "LineAlpha";
            // 
            // numericUpDownLineSize
            // 
            this.numericUpDownLineSize.Location = new System.Drawing.Point(231, 26);
            this.numericUpDownLineSize.Name = "numericUpDownLineSize";
            this.numericUpDownLineSize.Size = new System.Drawing.Size(41, 19);
            this.numericUpDownLineSize.TabIndex = 7;
            this.numericUpDownLineSize.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownLineSize.ValueChanged += new System.EventHandler(this.numericUpDownLineSize_ValueChanged);
            // 
            // numericUpDownLineAlpha
            // 
            this.numericUpDownLineAlpha.Location = new System.Drawing.Point(230, 64);
            this.numericUpDownLineAlpha.Name = "numericUpDownLineAlpha";
            this.numericUpDownLineAlpha.Size = new System.Drawing.Size(41, 19);
            this.numericUpDownLineAlpha.TabIndex = 8;
            this.numericUpDownLineAlpha.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownLineAlpha.ValueChanged += new System.EventHandler(this.numericUpDownLineAlpha_ValueChanged);
            // 
            // checkBoxShowAbsorbedPhotons
            // 
            this.checkBoxShowAbsorbedPhotons.AutoSize = true;
            this.checkBoxShowAbsorbedPhotons.Location = new System.Drawing.Point(160, 119);
            this.checkBoxShowAbsorbedPhotons.Name = "checkBoxShowAbsorbedPhotons";
            this.checkBoxShowAbsorbedPhotons.Size = new System.Drawing.Size(111, 16);
            this.checkBoxShowAbsorbedPhotons.TabIndex = 9;
            this.checkBoxShowAbsorbedPhotons.Text = "absorbedPhotons";
            this.checkBoxShowAbsorbedPhotons.UseVisualStyleBackColor = true;
            this.checkBoxShowAbsorbedPhotons.CheckedChanged += new System.EventHandler(this.checkBoxShowAbsorbedPhotons_CheckedChanged);
            // 
            // numericUpDownPhotonAlpha
            // 
            this.numericUpDownPhotonAlpha.Location = new System.Drawing.Point(93, 130);
            this.numericUpDownPhotonAlpha.Name = "numericUpDownPhotonAlpha";
            this.numericUpDownPhotonAlpha.Size = new System.Drawing.Size(41, 19);
            this.numericUpDownPhotonAlpha.TabIndex = 13;
            this.numericUpDownPhotonAlpha.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownPhotonAlpha.ValueChanged += new System.EventHandler(this.numericUpDownPhotonAlpha_ValueChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(27, 132);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(69, 12);
            this.label5.TabIndex = 12;
            this.label5.Text = "PhotonAlpha";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(27, 96);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(61, 12);
            this.label6.TabIndex = 11;
            this.label6.Text = "PhotonSize";
            // 
            // numericUpDownPhotonSize
            // 
            this.numericUpDownPhotonSize.Location = new System.Drawing.Point(93, 94);
            this.numericUpDownPhotonSize.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownPhotonSize.Name = "numericUpDownPhotonSize";
            this.numericUpDownPhotonSize.Size = new System.Drawing.Size(41, 19);
            this.numericUpDownPhotonSize.TabIndex = 10;
            this.numericUpDownPhotonSize.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownPhotonSize.ValueChanged += new System.EventHandler(this.numericUpDownPhotonSize_ValueChanged);
            // 
            // GraphicsSettingForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 155);
            this.Controls.Add(this.numericUpDownPhotonAlpha);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.numericUpDownPhotonSize);
            this.Controls.Add(this.checkBoxShowAbsorbedPhotons);
            this.Controls.Add(this.numericUpDownLineAlpha);
            this.Controls.Add(this.numericUpDownLineSize);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.numericUpDownPointAlpha);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.numericUpDownPointSize);
            this.Name = "GraphicsSettingForm";
            this.Text = "GraphicsSettingForm";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.GraphicsSettingForm_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPointSize)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPointAlpha)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownLineSize)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownLineAlpha)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPhotonAlpha)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPhotonSize)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NumericUpDown numericUpDownPointSize;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown numericUpDownPointAlpha;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown numericUpDownLineSize;
        private System.Windows.Forms.NumericUpDown numericUpDownLineAlpha;
        private System.Windows.Forms.CheckBox checkBoxShowAbsorbedPhotons;
        private System.Windows.Forms.NumericUpDown numericUpDownPhotonAlpha;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.NumericUpDown numericUpDownPhotonSize;
    }
}