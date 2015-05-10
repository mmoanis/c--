using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.CodeDom.Compiler;
using System.Diagnostics;
using Microsoft.CSharp;

namespace comp
{
    public partial class Form1 : Form
    {
        public string code_filename;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            // DialogResult result = openFileDialog1.ShowDialog();
            openFileDialog1.Title = "Open Text File";
            openFileDialog1.DefaultExt = "*.c--";
            openFileDialog1.Filter = "RTF Files|*.c--";
            openFileDialog1.InitialDirectory = @"C:\Users\Public\";
         

                if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK &&
                     openFileDialog1.FileName.Length > 0)
                {
                    code_filename = openFileDialog1.FileName;
                    richTextBox1.LoadFile(openFileDialog1.FileName, RichTextBoxStreamType.PlainText);
                }
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFile1 = new SaveFileDialog();
            saveFile1.DefaultExt = "*.c--";
            saveFile1.Filter = "RTF Files|*.c--";
            if (saveFile1.ShowDialog() == System.Windows.Forms.DialogResult.OK &&
                      saveFile1.FileName.Length > 0)
            {
                // Save the contents of the RichTextBox into the file.
                richTextBox1.SaveFile(saveFile1.FileName, RichTextBoxStreamType.PlainText);
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            

            try
            {
                var psi = new ProcessStartInfo("c--.exe")
                {
                    RedirectStandardInput = true,
                    RedirectStandardOutput = false,
                    UseShellExecute = false
                };

                var p = new Process { StartInfo = psi };
                p.Start();

                var stdin = p.StandardInput;
                p.StandardInput.WriteLine(System.IO.File.ReadAllBytes(code_filename));  
            }
            catch (Exception E) { System.Console.WriteLine(E.ToString()); }

            /*  CSharpCodeProvider codeProvider = new CSharpCodeProvider();
              ICodeCompiler icc = codeProvider.CreateCompiler();
              string Output = "Out.exe";
              Button ButtonObject = (Button)sender;

              textBox1.Text = "";
              System.CodeDom.Compiler.CompilerParameters parameters = new CompilerParameters();
              //Make sure we generate an EXE, not a DLL
              parameters.GenerateExecutable = true;
              parameters.OutputAssembly = Output;
              CompilerResults results = icc.CompileAssemblyFromSource(parameters, textBox1.Text);

              if (results.Errors.Count > 0)
              {
                  textBox1.ForeColor = Color.Red;
                  foreach (CompilerError CompErr in results.Errors)
                  {
                      textBox1.Text = textBox1.Text +
                                  "Line number " + CompErr.Line +
                                  ", Error Number: " + CompErr.ErrorNumber +
                                  ", '" + CompErr.ErrorText + ";" +
                                  Environment.NewLine + Environment.NewLine;
                  }
              }
              else
              {
                  //Successful Compile
                  textBox1.ForeColor = Color.Blue;
                  textBox1.Text = "Success!";
                  //If we clicked run then launch our EXE
                  if (ButtonObject.Text == "Run") Process.Start(Output);
              }
          }*/


        }

       
    }

}
