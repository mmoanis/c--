/*
 * Copyright (C) 2000-2009 - Xeno Innovations, Inc.
 * User: DSuess
 * Date: 8/8/2009
 * Time: 8:11 PM
 * 
 */
namespace testApp
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.lineNumbers_For_RichTextBox1 = new LineNumbers.LineNumbers_For_RichTextBox();
			this.richTextBox1 = new System.Windows.Forms.RichTextBox();
			this.SuspendLayout();
			// 
			// lineNumbers_For_RichTextBox1
			// 
			this.lineNumbers_For_RichTextBox1._SeeThroughMode_ = false;
			this.lineNumbers_For_RichTextBox1.AutoSizing = true;
			this.lineNumbers_For_RichTextBox1.BackgroundGradient_AlphaColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
			this.lineNumbers_For_RichTextBox1.BackgroundGradient_BetaColor = System.Drawing.Color.LightSteelBlue;
			this.lineNumbers_For_RichTextBox1.BackgroundGradient_Direction = System.Drawing.Drawing2D.LinearGradientMode.Horizontal;
			this.lineNumbers_For_RichTextBox1.BorderLines_Color = System.Drawing.Color.SlateGray;
			this.lineNumbers_For_RichTextBox1.BorderLines_Style = System.Drawing.Drawing2D.DashStyle.Dot;
			this.lineNumbers_For_RichTextBox1.BorderLines_Thickness = 1F;
			this.lineNumbers_For_RichTextBox1.DockSide = LineNumbers.LineNumbers_For_RichTextBox.LineNumberDockSide.Left;
			this.lineNumbers_For_RichTextBox1.GridLines_Color = System.Drawing.Color.SlateGray;
			this.lineNumbers_For_RichTextBox1.GridLines_Style = System.Drawing.Drawing2D.DashStyle.Dot;
			this.lineNumbers_For_RichTextBox1.GridLines_Thickness = 1F;
			this.lineNumbers_For_RichTextBox1.LineNrs_Alignment = System.Drawing.ContentAlignment.TopRight;
			this.lineNumbers_For_RichTextBox1.LineNrs_AntiAlias = true;
			this.lineNumbers_For_RichTextBox1.LineNrs_AsHexadecimal = false;
			this.lineNumbers_For_RichTextBox1.LineNrs_ClippedByItemRectangle = true;
			this.lineNumbers_For_RichTextBox1.LineNrs_LeadingZeroes = true;
			this.lineNumbers_For_RichTextBox1.LineNrs_Offset = new System.Drawing.Size(0, 0);
			this.lineNumbers_For_RichTextBox1.Location = new System.Drawing.Point(11, 9);
			this.lineNumbers_For_RichTextBox1.Margin = new System.Windows.Forms.Padding(0);
			this.lineNumbers_For_RichTextBox1.MarginLines_Color = System.Drawing.Color.SlateGray;
			this.lineNumbers_For_RichTextBox1.MarginLines_Side = LineNumbers.LineNumbers_For_RichTextBox.LineNumberDockSide.Right;
			this.lineNumbers_For_RichTextBox1.MarginLines_Style = System.Drawing.Drawing2D.DashStyle.Solid;
			this.lineNumbers_For_RichTextBox1.MarginLines_Thickness = 1F;
			this.lineNumbers_For_RichTextBox1.Name = "lineNumbers_For_RichTextBox1";
			this.lineNumbers_For_RichTextBox1.Padding = new System.Windows.Forms.Padding(0, 0, 2, 0);
			this.lineNumbers_For_RichTextBox1.ParentRichTextBox = this.richTextBox1;
			this.lineNumbers_For_RichTextBox1.Show_BackgroundGradient = true;
			this.lineNumbers_For_RichTextBox1.Show_BorderLines = true;
			this.lineNumbers_For_RichTextBox1.Show_GridLines = true;
			this.lineNumbers_For_RichTextBox1.Show_LineNrs = true;
			this.lineNumbers_For_RichTextBox1.Show_MarginLines = true;
			this.lineNumbers_For_RichTextBox1.Size = new System.Drawing.Size(17, 176);
			this.lineNumbers_For_RichTextBox1.TabIndex = 0;
			// 
			// richTextBox1
			// 
			this.richTextBox1.Location = new System.Drawing.Point(29, 9);
			this.richTextBox1.Name = "richTextBox1";
			this.richTextBox1.Size = new System.Drawing.Size(251, 176);
			this.richTextBox1.TabIndex = 1;
			this.richTextBox1.Text = "";
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(292, 197);
			this.Controls.Add(this.richTextBox1);
			this.Controls.Add(this.lineNumbers_For_RichTextBox1);
			this.Name = "MainForm";
			this.Text = "testApp";
			this.ResumeLayout(false);
		}
		private System.Windows.Forms.RichTextBox richTextBox1;
		private LineNumbers.LineNumbers_For_RichTextBox lineNumbers_For_RichTextBox1;
	}
}
