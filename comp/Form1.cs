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
        private bool errros;
        private string errors;
        private string program;

        // Contains all the opened pages
        private List<TabPage> openedPages;

        public Form1()
        {
            InitializeComponent();
            program = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetEntryAssembly().Location) + "\\c--.exe ";
            // choose the release
            toolStripComboBox1.SelectedIndex = 0;

            openedPages = new List<TabPage>();

            // add the first page that appear when program starts
            openedPages.Add(tabPage1);
            tabPage1.Controls.Add(new PageLayout());

        }

        /// <summary>
        /// Add new tab page.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string fileName = PromptDialog.ShowDialog("new file name", "Add new file");

            if (!string.IsNullOrEmpty(fileName))
            {
                TabPage newPage = new TabPage(fileName);
                PageLayout layout = new PageLayout();
                layout.FileName = fileName;
                layout.FilePath = Path.GetDirectoryName(fileName);
                newPage.Controls.Add(layout);
                openedPages.Add(newPage);

                tabControl1.TabPages.Add(newPage);
            }
        }

        /// <summary>
        /// Exit the IDE.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveAllTabsWithFailureMessage(" will be lost");

            Application.Exit();
        }

        /// <summary>
        /// Open a file.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            RichTextBox textBox = new RichTextBox();
            string name = LoadFileFromDirectory(textBox);
            // if successfully loaded file
            if (!string.IsNullOrEmpty(name))
            {
                PageLayout layout = new PageLayout();
                layout.FileName = Path.GetFileName(name);
                layout.FilePath = Path.GetDirectoryName(name);
                layout.Content = textBox.Text;
                layout.IsSaved = true;
                TabPage newPage = new TabPage(layout.FileName);
                newPage.Controls.Add(layout);
                openedPages.Add(newPage);
                tabControl1.TabPages.Add(newPage);
            }
        }


        /// <summary>
        /// Gets a save file directory.
        /// </summary>
        /// <returns>save file directory, or null if user canceled</returns>
        private string GetSaveFileName()
        {
            SaveFileDialog saveFile1 = new SaveFileDialog();
            saveFile1.DefaultExt = "*.c--";
            saveFile1.Filter = "RTF Files|*.c--";
            DialogResult result = saveFile1.ShowDialog();
            if ( result == System.Windows.Forms.DialogResult.OK &&
                      saveFile1.FileName.Length > 0)
            {
                // Save the contents of the RichTextBox into the file.
                return saveFile1.FileName;
            }

            return string.Empty;
        }

        /// <summary>
        /// Open a file from a certain directory and fill a textBox with its content.
        /// </summary>
        /// <param name="textBox">text box to be filled</param>
        private string LoadFileFromDirectory(RichTextBox textBox)
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
                textBox.LoadFile(openFileDialog1.FileName, RichTextBoxStreamType.PlainText);
                return openFileDialog1.FileName;
            }
            return string.Empty;
        }

        /// <summary>
        /// Save a file.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // paranoid check
            if (tabControl1.SelectedIndex != -1)
            {
                PageLayout layout = tabControl1.SelectedTab.Controls[0] as PageLayout;
                if (!layout.IsSaved)
                {
                    // check if we have a save directory for the file
                    if (!string.IsNullOrEmpty(layout.FilePath))
                    {
                        // save the file to its working directory
                        layout.SaveContent();
                    }
                    else
                    {
                        string name = GetSaveFileName();

                        if (!string.IsNullOrEmpty(name))
                        {
                            layout.FilePath = Path.GetDirectoryName(name);
                            layout.FileName = Path.GetFileName(name);
                            layout.SaveContent();
                        }
                    }
                }
            }
        }

        private void saveAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveAllTabsWithFailureMessage(" unsaved file");
        }

        private void SaveAllTabsWithFailureMessage(string message)
        {
            PageLayout layout;
            // Check all the opened pages, if not saved ask user to save them
            foreach (TabPage page in openedPages)
            {
                layout = page.Controls[0] as PageLayout;

                if (!layout.IsSaved)
                {
                    // check if we have a save directory for the file
                    if (!string.IsNullOrEmpty(layout.FilePath))
                    {
                        // save the file to its working directory
                        layout.SaveContent();
                    }
                    else
                    {
                        string name = GetSaveFileName();

                        if (!string.IsNullOrEmpty(name))
                        {
                            layout.FilePath = Path.GetDirectoryName(name);
                            layout.FileName = Path.GetFileName(name);
                            layout.SaveContent();
                        }
                        else
                        {
                            MessageBox.Show(layout.FileName + message, "Unsaved File", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                        }
                    }
                }
            }
        }

        private void buildToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            errros = false;
            errors = string.Empty;
            if (tabControl1.SelectedIndex != -1)
            {
                PageLayout layout = tabControl1.SelectedTab.Controls[0] as PageLayout;
                if (!layout.IsSaved)
                {
                    // check if we have a save directory for the file
                    if (!string.IsNullOrEmpty(layout.FilePath))
                    {
                        // save the file to its working directory
                        layout.SaveContent();
                    }
                    else
                    {
                        string name = GetSaveFileName();

                        if (!string.IsNullOrEmpty(name))
                        {
                            layout.FilePath = Path.GetDirectoryName(name);
                            layout.FileName = Path.GetFileName(name);
                            layout.SaveContent();
                        }
                        else
                        {
                            MessageBox.Show("Build Cannot procceed without saveing file");
                            return;
                        }
                    }
                }

                if (layout.FileName.IndexOf("c--") == -1)
                {
                    layout.FileName += ".c--"; 
                }

                string format = "start /B " + program + " < " + layout.FilePath + "\\" + layout.FileName + " > " + layout.FilePath + "\\" + layout.OutPutFileName;

                var process = new System.Diagnostics.Process();
                process.StartInfo.FileName = "cmd.exe";
                process.StartInfo.RedirectStandardInput = true;
                process.StartInfo.RedirectStandardOutput = true;
                process.StartInfo.RedirectStandardError = true;
                process.StartInfo.UseShellExecute = false;
                process.ErrorDataReceived += new DataReceivedEventHandler(NetErrorDataHandler);

                Stopwatch buildTimer = new Stopwatch();
                buildTimer.Start();
                richTextBox1.Text = "Build Started with command " + format;
                
                process.Start();
                process.BeginErrorReadLine();

                process.StandardInput.WriteLine(format);
                process.StandardInput.WriteLine("exit 0");
                process.WaitForExit();

                buildTimer.Stop();
                richTextBox1.Text = "Build ended in " + buildTimer.ElapsedMilliseconds + " ms.";

                if (errros)
                {
                    richTextBox1.Text += "\nFailed with errors:\n" + errors;
                }
                else
                {
                    richTextBox1.Text += "\nSuccessfully Build";
                }
            }
        }

        /// <summary>
        /// Open C-- website
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void cDocumentationToolStripMenuItem_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://github.com/mohamed-moanis/c--");
        }

        /// <summary>
        /// About C--
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Koromb IDE for C-- Language\nC-- bate5a");
        }

        private void findToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex != -1)
            {
                string output = PromptDialog.ShowDialog("search for", "find");

                if (!string.IsNullOrEmpty(output))
                {
                    PageLayout layout = tabControl1.SelectedTab.Controls[0] as PageLayout;
                    int i = layout.Content.IndexOf(output);
                    if (i != -1)
                    {
                        layout.SetSelectedText(i, output.Length);
                        MessageBox.Show("found " + output + " at " + i);
                    }
                    else
                        MessageBox.Show(output + " not found");
                }
            }
        }

        /// <summary>
        /// Check saving before exiting.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (e.CloseReason == CloseReason.UserClosing)
            {
                exitToolStripMenuItem_Click(sender, e);
            }
        }

        private void configureToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex != -1)
            {
                string output = PromptDialog.ShowDialog("change output file name", "Build Configuration");

                if (!string.IsNullOrEmpty(output))
                {
                    PageLayout layout = tabControl1.SelectedTab.Controls[0] as PageLayout;
                    layout.OutPutFileName = output;
                }
            }
        }

        /// <summary>
        /// Close a page.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void closeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // save the tab
            saveToolStripMenuItem_Click(sender, e);

            if (tabControl1.SelectedIndex != -1)
            {
                openedPages.Remove(tabControl1.SelectedTab);
                tabControl1.TabPages.Remove(tabControl1.SelectedTab);
            }
        }

        private void NetErrorDataHandler(object sendingProcess, 
            DataReceivedEventArgs errLine)
        {
            if (!String.IsNullOrEmpty(errLine.Data))
            {
                errros = true;
                errors = errLine.Data;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // paranoid check
            if (tabControl1.SelectedIndex != -1)
            {
                PageLayout layout = tabControl1.SelectedTab.Controls[0] as PageLayout;
                if (!string.IsNullOrEmpty(layout.SelectedText))
                {
                    Clipboard.SetText(layout.SelectedText);
                }
            }
        }
    }

}
