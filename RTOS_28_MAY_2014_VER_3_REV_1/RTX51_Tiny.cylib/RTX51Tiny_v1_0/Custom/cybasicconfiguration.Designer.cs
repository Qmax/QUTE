namespace RTOS.RTX51.RTX51Tiny_v1_0
{
    partial class CyBasicConfiguration
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

        #region Component Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.components = new System.ComponentModel.Container();
            this.chbxLongUsrIntEn = new System.Windows.Forms.CheckBox();
            this.chbxStackCheckEn = new System.Windows.Forms.CheckBox();
            this.numUpDownRoundRobinTimeout = new System.Windows.Forms.NumericUpDown();
            this.numUpDownFreeStackLimit = new System.Windows.Forms.NumericUpDown();
            this.labelRoundRobinTimeout = new System.Windows.Forms.Label();
            this.comboBoxSchedulingMode = new System.Windows.Forms.ComboBox();
            this.textBoxStackErrorMacro = new System.Windows.Forms.TextBox();
            this.labelSchedulingMode = new System.Windows.Forms.Label();
            this.labelFreeStackLimit = new System.Windows.Forms.Label();
            this.labelStackErrorMacro = new System.Windows.Forms.Label();
            this.errorProvider = new System.Windows.Forms.ErrorProvider(this.components);
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numUpDownRoundRobinTimeout)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numUpDownFreeStackLimit)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider)).BeginInit();
            this.SuspendLayout();

            //
            // groupBox1
            //
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.labelSchedulingMode);
            this.groupBox1.Controls.Add(this.comboBoxSchedulingMode);
            this.groupBox1.Controls.Add(this.labelRoundRobinTimeout);
            this.groupBox1.Controls.Add(this.numUpDownRoundRobinTimeout);
            this.groupBox1.Location = new System.Drawing.Point(14, 10);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(405, 75);
            this.groupBox1.TabIndex = 60;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Scheduling Options:";

            //
            // groupBox2
            //
            this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox2.Controls.Add(this.chbxLongUsrIntEn);
            this.groupBox2.Controls.Add(this.chbxStackCheckEn);
            this.groupBox2.Controls.Add(this.groupBox3);
            this.groupBox2.Location = new System.Drawing.Point(14, 95);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(405, 150);
            this.groupBox2.TabIndex = 59;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Miscellaneous Options:";

            //
            // chbxLongUsrIntEn
            //
            this.chbxLongUsrIntEn.AutoSize = true;
            this.chbxLongUsrIntEn.Location = new System.Drawing.Point(32, 17);
            this.chbxLongUsrIntEn.Name = "chbxLongUsrIntEn";
            this.chbxLongUsrIntEn.Size = new System.Drawing.Size(131, 17);
            this.chbxLongUsrIntEn.TabIndex = 58;
            this.chbxLongUsrIntEn.Text = "Enable Long User ISR Support";
            this.chbxLongUsrIntEn.UseVisualStyleBackColor = true;
            this.chbxLongUsrIntEn.CheckedChanged += new System.EventHandler(this.chbxLongUsrIntEn_CheckedChanged);

            //
            // chbxStackCheckEn
            //
            this.chbxStackCheckEn.AutoSize = true;
            this.chbxStackCheckEn.Location = new System.Drawing.Point(32, 37);
            this.chbxStackCheckEn.Name = "chbxStackCheckEn";
            this.chbxStackCheckEn.Size = new System.Drawing.Size(144, 77);
            this.chbxStackCheckEn.TabIndex = 61;
            this.chbxStackCheckEn.Text = "Enable Stack Check Support";
            this.chbxStackCheckEn.UseVisualStyleBackColor = true;
            this.chbxStackCheckEn.CheckedChanged += new System.EventHandler(this.chbxStackCheckEn_CheckedChanged);

            //
            // numUpDownRoundRobinTimeout
            //
            this.numUpDownRoundRobinTimeout.Location = new System.Drawing.Point(151, 40);
            this.numUpDownRoundRobinTimeout.Name = "numUpDownRoundRobinTimeout";
            this.numUpDownRoundRobinTimeout.Size = new System.Drawing.Size(227, 20);
            this.numUpDownRoundRobinTimeout.TabIndex = 41;
            this.numUpDownRoundRobinTimeout.Minimum = 1;
            this.numUpDownRoundRobinTimeout.Maximum = 255;
            this.numUpDownRoundRobinTimeout.ValueChanged += new System.EventHandler(this.numUpDownRoundRobinTimeout_ValueChanged);

            //
            // labelRoundRobinTimeout
            //
            this.labelRoundRobinTimeout.AutoSize = true;
            this.labelRoundRobinTimeout.Location = new System.Drawing.Point(32, 44);
            this.labelRoundRobinTimeout.Name = "labelRoundRobinTimeout";
            this.labelRoundRobinTimeout.Size = new System.Drawing.Size(113, 13);
            this.labelRoundRobinTimeout.TabIndex = 27;
            this.labelRoundRobinTimeout.Text = "Round-Robin Timeout:";
            this.labelRoundRobinTimeout.TextAlign = System.Drawing.ContentAlignment.MiddleRight;

            //
            // comboBoxSchedulingMode
            //
            this.comboBoxSchedulingMode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxSchedulingMode.FormattingEnabled = true;
            this.comboBoxSchedulingMode.Items.AddRange(new object[] {
            "Co-Operative",
            "Round Robin"});
            this.comboBoxSchedulingMode.Location = new System.Drawing.Point(151, 13);
            this.comboBoxSchedulingMode.Name = "comboBoxSchedulingMode";
            this.comboBoxSchedulingMode.Size = new System.Drawing.Size(227, 20);
            this.comboBoxSchedulingMode.TabIndex = 1;
            this.comboBoxSchedulingMode.SelectedIndexChanged += new System.EventHandler(this.comboBoxSchedulingMode_SelectedIndexChanged);

            //
            // labelSchedulingMode
            //
            this.labelSchedulingMode.AutoSize = true;
            this.labelSchedulingMode.Location = new System.Drawing.Point(32, 17);
            this.labelSchedulingMode.Name = "labelSchedulingMode";
            this.labelSchedulingMode.Size = new System.Drawing.Size(113, 13);
            this.labelSchedulingMode.TabIndex = 23;
            this.labelSchedulingMode.Text = "Scheduling Mode:";
            this.labelSchedulingMode.TextAlign = System.Drawing.ContentAlignment.MiddleRight;

            //
            // groupBox3
            //
            this.groupBox3.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox3.Controls.Add(this.labelFreeStackLimit);
            this.groupBox3.Controls.Add(this.numUpDownFreeStackLimit);
            this.groupBox3.Controls.Add(this.labelStackErrorMacro);
            this.groupBox3.Controls.Add(this.textBoxStackErrorMacro);
            this.groupBox3.Location = new System.Drawing.Point(32, 57);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(360, 75);
            this.groupBox3.TabIndex = 73;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Stack Error Check Options:";

            //
            // numUpDownFreeStackLimit
            //
            this.numUpDownFreeStackLimit.Location = new System.Drawing.Point(151, 13);
            this.numUpDownFreeStackLimit.Name = "numUpDownFreeStackLimit";
            this.numUpDownFreeStackLimit.Size = new System.Drawing.Size(227, 20);
            this.numUpDownFreeStackLimit.TabIndex = 74;
            this.numUpDownFreeStackLimit.Minimum = 1;
            this.numUpDownFreeStackLimit.Maximum = 50;
            this.numUpDownFreeStackLimit.ValueChanged += new System.EventHandler(this.numUpDownFreeStackLimit_ValueChanged);

            //
            // textBoxStackErrorMacro
            //
            this.textBoxStackErrorMacro.Location = new System.Drawing.Point(151, 40);
            this.textBoxStackErrorMacro.Name = "textBoxStackErrorMacro";
            this.textBoxStackErrorMacro.Size = new System.Drawing.Size(227, 20);
            this.textBoxStackErrorMacro.TabIndex = 1;
            this.textBoxStackErrorMacro.TextChanged += new System.EventHandler(this.textBoxStackErrorMacro_TextChanged);
            this.textBoxStackErrorMacro.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxStackErrorMacro_KeyPress);

            //
            // labelFreeStackLimit
            //
            this.labelFreeStackLimit.AutoSize = true;
            this.labelFreeStackLimit.Location = new System.Drawing.Point(32, 17);
            this.labelFreeStackLimit.Name = "labelFreeStackLimit";
            this.labelFreeStackLimit.Size = new System.Drawing.Size(113, 13);
            this.labelFreeStackLimit.TabIndex = 70;
            this.labelFreeStackLimit.Text = "Free Stack Limit:";
            this.labelFreeStackLimit.TextAlign = System.Drawing.ContentAlignment.MiddleRight;

            //
            // labelStackErrorMacro
            //
            this.labelStackErrorMacro.AutoSize = true;
            this.labelStackErrorMacro.Location = new System.Drawing.Point(32, 44);
            this.labelStackErrorMacro.Name = "labelStackErrorMacro";
            this.labelStackErrorMacro.Size = new System.Drawing.Size(113, 13);
            this.labelStackErrorMacro.TabIndex = 71;
            this.labelStackErrorMacro.Text = "Stack Error Handler:";
            this.labelStackErrorMacro.TextAlign = System.Drawing.ContentAlignment.MiddleRight;

            //
            // errorProvider
            //
            this.errorProvider.ContainerControl = this;

            //
            // CyBasicConfiguration
            //
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupBox2);
            this.Name = "CyBasicConfiguration";
            this.Size = new System.Drawing.Size(446, 300);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numUpDownRoundRobinTimeout)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numUpDownFreeStackLimit)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NumericUpDown numUpDownRoundRobinTimeout;
        private System.Windows.Forms.NumericUpDown numUpDownFreeStackLimit;
        private System.Windows.Forms.Label labelRoundRobinTimeout;
        private System.Windows.Forms.ComboBox comboBoxSchedulingMode;
        private System.Windows.Forms.TextBox textBoxStackErrorMacro;
        private System.Windows.Forms.Label labelSchedulingMode;
        private System.Windows.Forms.Label labelFreeStackLimit;
        private System.Windows.Forms.Label labelStackErrorMacro;
        private System.Windows.Forms.ErrorProvider errorProvider;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.CheckBox chbxLongUsrIntEn;
        private System.Windows.Forms.CheckBox chbxStackCheckEn;
    }
}
