// ========================================
//
// Copyright Cypress Semiconductor Corporation, 2009
// All Rights Reserved
// UNPUBLISHED, LICENSED SOFTWARE.
//
// CONFIDENTIAL AND PROPRIETARY INFORMATION
// WHICH IS THE PROPERTY OF CYPRESS.
//
// Use of this file is governed
// by the license agreement included in the file
//
//     <install>/license/license.txt
//
// where <install> is the Cypress software
// installation root directory path.
//
// ========================================

using System;
using System.Diagnostics;
using System.Windows.Forms;

namespace RTOS.RTX51.RTX51Tiny_v1_0
{
    public partial class CyBasicConfiguration : UserControl
    {
        public CyRTX51Parameters Parameters;

        public CyBasicConfiguration()
        {
            InitializeComponent();

            Parameters = new CyRTX51Parameters();
        }

        public CyBasicConfiguration(CyRTX51Parameters parameters)
        {
            InitializeComponent();

            this.Parameters = parameters;
            LoadValuesFromParameters();
        }

        private void LoadValuesFromParameters()
        {
            comboBoxSchedulingMode.SelectedIndex = Parameters.SchedulingMode;
            numUpDownRoundRobinTimeout.Value = Parameters.RoundRobinTimeout;
            numUpDownFreeStackLimit.Value = Parameters.FreeStackLimit;
            chbxLongUsrIntEn.Checked = Parameters.LongUsrIntEnable;
            chbxStackCheckEn.Checked = Parameters.StackCheckEnable;
            textBoxStackErrorMacro.Text = Parameters.StackErrorMacro;

            if (chbxStackCheckEn.Checked)
            {
                groupBox3.Enabled = true;

                if (Parameters.StackErrorMacro == "")
                {
                    Parameters.StackErrorMacroEn = false;
                }
                else
                {
                    Parameters.StackErrorMacroEn = true;
                }
            }
            else
            {
                groupBox3.Enabled = false;
                Parameters.StackErrorMacroEn = false;
            }
        }

        private void comboBoxSchedulingMode_SelectedIndexChanged(object sender, EventArgs e)
        {
            Parameters.SchedulingMode = (byte)comboBoxSchedulingMode.SelectedIndex;
            if (comboBoxSchedulingMode.SelectedIndex == 0)
            {
                numUpDownRoundRobinTimeout.Enabled = false;
            }
            else
            {
                numUpDownRoundRobinTimeout.Enabled = true;
            }
        }

        private void numUpDownRoundRobinTimeout_ValueChanged(object sender, EventArgs e)
        {
            Parameters.RoundRobinTimeout = (byte)numUpDownRoundRobinTimeout.Value;
        }

        private void numUpDownFreeStackLimit_ValueChanged(object sender, EventArgs e)
        {
            Parameters.FreeStackLimit = (byte)numUpDownFreeStackLimit.Value;
        }

        private void textBoxStackErrorMacro_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar != (char)Keys.Enter) && (e.KeyChar != (char)Keys.Back))
            {
                if ((e.KeyChar != '_') &&
                    ((e.KeyChar < '0') || (e.KeyChar > '9')) &&
                    ((e.KeyChar < 'A') || (e.KeyChar > 'Z')) &&
                    ((e.KeyChar < 'a') || (e.KeyChar > 'z')))
                {
                    e.Handled = true;
                }
            }
        }

        private void textBoxStackErrorMacro_TextChanged(object sender, EventArgs e)
        {
            try
            {
                Parameters.StackErrorMacro = textBoxStackErrorMacro.Text;

                if (Parameters.StackErrorMacro == "")
                {
                    Parameters.StackErrorMacroEn = false;
                }
                else
                {
                    Parameters.StackErrorMacroEn = true;
                }
            }
            catch
            {
                //MessageBox.Show("Wrong symbol");
            }
        }

        private void chbxLongUsrIntEn_CheckedChanged(object sender, EventArgs e)
        {
            if (this.ContainsFocus)
            {
                Parameters.LongUsrIntEnable = chbxLongUsrIntEn.Checked;
            }
        }

        private void chbxStackCheckEn_CheckedChanged(object sender, EventArgs e)
        {
            if (this.ContainsFocus)
            {
                Parameters.StackCheckEnable = chbxStackCheckEn.Checked;

                if (chbxStackCheckEn.Checked)
                {
                    groupBox3.Enabled = true;

                    if (Parameters.StackErrorMacro == "")
                    {
                        Parameters.StackErrorMacroEn = false;
                    }
                    else
                    {
                        Parameters.StackErrorMacroEn = true;
                    }
                }
                else
                {
                    groupBox3.Enabled = false;
                    Parameters.StackErrorMacroEn = false;
                }
            }
        }
    }
}
