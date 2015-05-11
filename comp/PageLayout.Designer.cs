namespace comp
{
    partial class PageLayout
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
            this.codeTextBox = new System.Windows.Forms.RichTextBox();
            this.lineNumbersTextBox = new LineNumbers.LineNumbers_For_RichTextBox();
            this.SuspendLayout();
            // 
            // codeTextBox
            // 
            this.codeTextBox.Location = new System.Drawing.Point(18, 0);
            this.codeTextBox.Name = "codeTextBox";
            this.codeTextBox.Size = new System.Drawing.Size(649, 322);
            this.codeTextBox.TabIndex = 11;
            this.codeTextBox.Text = "";
            this.codeTextBox.TextChanged += new System.EventHandler(this.codeTextBox_TextChanged);
            // 
            // lineNumbersTextBox
            // 
            this.lineNumbersTextBox._SeeThroughMode_ = false;
            this.lineNumbersTextBox.AutoSizing = true;
            this.lineNumbersTextBox.BackgroundGradient_AlphaColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.lineNumbersTextBox.BackgroundGradient_BetaColor = System.Drawing.Color.LightSteelBlue;
            this.lineNumbersTextBox.BackgroundGradient_Direction = System.Drawing.Drawing2D.LinearGradientMode.Horizontal;
            this.lineNumbersTextBox.BorderLines_Color = System.Drawing.Color.SlateGray;
            this.lineNumbersTextBox.BorderLines_Style = System.Drawing.Drawing2D.DashStyle.Dot;
            this.lineNumbersTextBox.BorderLines_Thickness = 1F;
            this.lineNumbersTextBox.DockSide = LineNumbers.LineNumbers_For_RichTextBox.LineNumberDockSide.Left;
            this.lineNumbersTextBox.GridLines_Color = System.Drawing.Color.SlateGray;
            this.lineNumbersTextBox.GridLines_Style = System.Drawing.Drawing2D.DashStyle.Dot;
            this.lineNumbersTextBox.GridLines_Thickness = 1F;
            this.lineNumbersTextBox.LineNrs_Alignment = System.Drawing.ContentAlignment.TopRight;
            this.lineNumbersTextBox.LineNrs_AntiAlias = true;
            this.lineNumbersTextBox.LineNrs_AsHexadecimal = false;
            this.lineNumbersTextBox.LineNrs_ClippedByItemRectangle = true;
            this.lineNumbersTextBox.LineNrs_LeadingZeroes = true;
            this.lineNumbersTextBox.LineNrs_Offset = new System.Drawing.Size(0, 0);
            this.lineNumbersTextBox.Location = new System.Drawing.Point(0, 0);
            this.lineNumbersTextBox.Margin = new System.Windows.Forms.Padding(0);
            this.lineNumbersTextBox.MarginLines_Color = System.Drawing.Color.SlateGray;
            this.lineNumbersTextBox.MarginLines_Side = LineNumbers.LineNumbers_For_RichTextBox.LineNumberDockSide.Right;
            this.lineNumbersTextBox.MarginLines_Style = System.Drawing.Drawing2D.DashStyle.Solid;
            this.lineNumbersTextBox.MarginLines_Thickness = 1F;
            this.lineNumbersTextBox.Name = "lineNumbersTextBox";
            this.lineNumbersTextBox.Padding = new System.Windows.Forms.Padding(0, 0, 2, 0);
            this.lineNumbersTextBox.ParentRichTextBox = this.codeTextBox;
            this.lineNumbersTextBox.Show_BackgroundGradient = true;
            this.lineNumbersTextBox.Show_BorderLines = true;
            this.lineNumbersTextBox.Show_GridLines = true;
            this.lineNumbersTextBox.Show_LineNrs = true;
            this.lineNumbersTextBox.Show_MarginLines = true;
            this.lineNumbersTextBox.Size = new System.Drawing.Size(17, 322);
            this.lineNumbersTextBox.TabIndex = 12;
            // 
            // PageLayout
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.lineNumbersTextBox);
            this.Controls.Add(this.codeTextBox);
            this.Name = "PageLayout";
            this.Size = new System.Drawing.Size(670, 325);
            this.ResumeLayout(false);

        }

        #endregion

        private LineNumbers.LineNumbers_For_RichTextBox lineNumbersTextBox;
        private System.Windows.Forms.RichTextBox codeTextBox;

    }
}
