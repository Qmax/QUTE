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
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Windows.Forms;
using CyDesigner.Extensions.Gde;


namespace RTOS.RTX51.RTX51Tiny_v1_0
{
    public class CyRTX51Parameters
    {
        #region Variables

        readonly ICyInstEdit_v1 m_inst;

        private byte m_SchedulingMode = 0;
        private byte m_RoundRobinTimeout = 5;
        private bool m_LongUsrIntEnable = true;
        private bool m_StackCheckEnable = false;
        private byte m_FreeStackLimit = 20;
        private string m_StackErrorMacro = "";
        private bool m_StackErrorMacroEn = false;

        #endregion Variables

        #region Properties

        public byte SchedulingMode
        {
            get { return m_SchedulingMode; }
            set
            {
                if (value != m_SchedulingMode)
                {
                    m_SchedulingMode = value;
                    SetParam("SchedulingMode");
                    CommitParams();
                }
            }
        }

        public byte RoundRobinTimeout
        {
            get { return m_RoundRobinTimeout; }
            set
            {
                if (value != m_RoundRobinTimeout)
                {
                    m_RoundRobinTimeout = value;
                    SetParam("RoundRobinTimeout");
                    CommitParams();
                }
            }
        }

        public byte FreeStackLimit
        {
            get { return m_FreeStackLimit; }
            set
            {
                if (value != m_FreeStackLimit)
                {
                    m_FreeStackLimit = value;
                    SetParam("FreeStackLimit");
                    CommitParams();
                }
            }
        }

        public string StackErrorMacro
        {
            get { return m_StackErrorMacro; }
            set
            {
                if (value != m_StackErrorMacro)
                {
                    m_StackErrorMacro = value;
                    SetParam("StackErrorMacro");
                    CommitParams();
                }
            }
        }

        public bool StackErrorMacroEn
        {
            get { return m_StackErrorMacroEn; }
            set
            {
                if (value != m_StackErrorMacroEn)
                {
                    m_StackErrorMacroEn = value;
                    SetParam("StackErrorMacroEn");
                    CommitParams();
                }
            }
        }

        public bool LongUsrIntEnable
        {
            get { return m_LongUsrIntEnable; }
            set
            {
                if (value != m_LongUsrIntEnable)
                {
                    m_LongUsrIntEnable = value;
                    SetParam("LongUsrIntEnable");
                    CommitParams();
                }
            }
        }

        public bool StackCheckEnable
        {
            get { return m_StackCheckEnable; }
            set
            {
                if (value != m_StackCheckEnable)
                {
                    m_StackCheckEnable = value;
                    SetParam("StackCheckEnable");
                    CommitParams();
                }
            }
        }

        #endregion Properties

        #region Constructors

        public CyRTX51Parameters()
        {
        }

        public CyRTX51Parameters(ICyInstEdit_v1 inst)
        {
            if (inst != null)
            {
                m_inst = inst;
                GetParams();
            }
        }

        #endregion Constructors

        #region Common

        private void GetParams()
        {
            if (m_inst != null)
            {
                m_SchedulingMode = Convert.ToByte(m_inst.GetCommittedParam("SchedulingMode").Value);
                m_RoundRobinTimeout = Convert.ToByte(m_inst.GetCommittedParam("RoundRobinTimeout").Value);
                m_FreeStackLimit = Convert.ToByte(m_inst.GetCommittedParam("FreeStackLimit").Value);
                m_StackErrorMacro = m_inst.GetCommittedParam("StackErrorMacro").Value;
                m_StackCheckEnable = ((m_inst.GetCommittedParam("StackCheckEnable").Value) == "true") ? true : false;
                m_StackErrorMacroEn = ((m_inst.GetCommittedParam("StackErrorMacroEn").Value) == "true") ? true : false;
                m_LongUsrIntEnable = ((m_inst.GetCommittedParam("LongUsrIntEnable").Value) == "true") ? true : false;
            }
        }

        public void SetParam(string paramName)
        {
            if (m_inst != null)
            {
                switch (paramName)
                {
                    case "SchedulingMode":
                        m_inst.SetParamExpr("SchedulingMode", SchedulingMode.ToString());
                        break;
                    case "RoundRobinTimeout":
                        m_inst.SetParamExpr("RoundRobinTimeout", RoundRobinTimeout.ToString());
                        break;
                    case "FreeStackLimit":
                        m_inst.SetParamExpr("FreeStackLimit", FreeStackLimit.ToString());
                        break;
                    case "StackErrorMacro":
                        m_inst.SetParamExpr("StackErrorMacro", StackErrorMacro);
                        break;
                    case "StackCheckEnable":
                        m_inst.SetParamExpr("StackCheckEnable", StackCheckEnable.ToString());
                        break;
                    case "StackErrorMacroEn":
                        m_inst.SetParamExpr("StackErrorMacroEn", StackErrorMacroEn.ToString());
                        break;
                    case "LongUsrIntEnable":
                        m_inst.SetParamExpr("LongUsrIntEnable", LongUsrIntEnable.ToString());
                        break;

                    default:
                        break;
                }
            }
        }

        public void SetParams()
        {
            if (m_inst != null)
            {
                m_inst.SetParamExpr("SchedulingMode", SchedulingMode.ToString());
                m_inst.SetParamExpr("RoundRobinTimeout", RoundRobinTimeout.ToString());
                m_inst.SetParamExpr("FreeStackLimit", FreeStackLimit.ToString());
                m_inst.SetParamExpr("StackErrorMacro", StackErrorMacro);
                m_inst.SetParamExpr("StackCheckEnable", StackCheckEnable.ToString());
                m_inst.SetParamExpr("StackErrorMacroEn", StackErrorMacroEn.ToString());
                m_inst.SetParamExpr("LongUsrIntEnable", LongUsrIntEnable.ToString());
            }
        }

        public void CommitParams()
        {
            if (m_inst != null)
            {
                if (!m_inst.CommitParamExprs())
                {
                    if (m_inst.GetCommittedParam("SchedulingMode").ErrorCount > 0)
                        MessageBox.Show("Error in Committing SchedulingMode");

                    if (m_inst.GetCommittedParam("RoundRobinTimeout").ErrorCount > 0)
                        MessageBox.Show("Error in Committing RoundRobinTimeout");

                    if (m_inst.GetCommittedParam("FreeStackLimit").ErrorCount > 0)
                        MessageBox.Show("Error in Committing FreeStackLimit");

                    if (m_inst.GetCommittedParam("StackErrorMacro").ErrorCount > 0)
                        MessageBox.Show("Error in Committing StackErrorMacro");

                    if (m_inst.GetCommittedParam("StackCheckEnable").ErrorCount > 0)
                        MessageBox.Show("Error in Committing StackCheckEnable");

                    if (m_inst.GetCommittedParam("StackErrorMacroEn").ErrorCount > 0)
                        MessageBox.Show("Error in Committing StackErrorMacroEn");

                    if (m_inst.GetCommittedParam("LongUsrIntEnable").ErrorCount > 0)
                        MessageBox.Show("Error in Committing LongUsrIntEnable");
                }
            }
        }

        #endregion Common
    }
}
