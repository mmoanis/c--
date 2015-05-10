/*
 * Copyright (C) 2000-2009 - Xeno Innovations, Inc.
 * User: DSuess
 * Date: 8/8/2009
 * Time: 8:11 PM
 * 
 */
using System;
using System.Windows.Forms;

namespace testApp
{
	/// <summary>
	/// Class with program entry point.
	/// </summary>
	internal sealed class Program
	{
		/// <summary>
		/// Program entry point.
		/// </summary>
		[STAThread]
		private static void Main(string[] args)
		{
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			Application.Run(new MainForm());
		}
		
	}
}
