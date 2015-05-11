using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace comp
{
    public partial class PageLayout : UserControl
    {
        public PageLayout()
        {
            InitializeComponent();
            isSaved = true;
            fileName = "untitled";
            outputFileName = "a.asm";
            filePath = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetEntryAssembly().Location);
        }

        private string filePath;
        private bool isSaved;
        private string fileName;
        private string outputFileName;

        /// <summary>
        /// Gets or sets the file name.
        /// </summary>
        public string FileName
        {
            get
            {
                return fileName;
            }
            set
            {
                fileName = value;
            }
        }

        /// <summary>
        /// Gets or sets the associated output file names.
        /// </summary>
        public string OutPutFileName
        {
            get
            {
                return outputFileName;
            }
            set
            {
                outputFileName = value;
            }
        }

        /// <summary>
        /// Gets or sets the file path of that page
        /// </summary>
        public string FilePath
        {
            get
            {
                return filePath;
            }
            set
            {
                filePath = value;
            }
        }

        /// <summary>
        /// Gets or sets value indicating that the page was saved
        /// </summary>
        public bool IsSaved
        {
            get
            {
                return isSaved;
            }
            set
            {
                isSaved = value;
            }
        }

        /// <summary>
        /// Gets or sets the content of a page
        /// </summary>
        public string Content
        {
            get
            {
                return codeTextBox.Text;
            }

            set
            {
                codeTextBox.Text = value;
            }
        }

        /// <summary>
        /// Highlit a given text
        /// </summary>
        /// <param name="start"></param>
        /// <param name="length"></param>
        public void SetSelectedText(int start, int length)
        {
            codeTextBox.Select(start, length);
        }

        /// <summary>
        /// Gets the currently selected text.
        /// </summary>
        public string SelectedText
        {
            get
            {
                return codeTextBox.SelectedText;
            }
        }

        /// <summary>
        /// Gets the index of selection
        /// </summary>
        public int CursorIndex
        {
            get
            {
                return codeTextBox.SelectionStart;
            }
        }

        /// <summary>
        /// Save the content of the page to its associated file.
        /// </summary>
        public void SaveContent()
        {
            // double check that file path is not null
            if (!string.IsNullOrEmpty(filePath) && !string.IsNullOrEmpty(fileName))
                FileController.WriteToFile(filePath + "\\" + fileName, codeTextBox.Text);
        }

        /// <summary>
        /// Handles the change in text of the controller, which indicates that file is not saved
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void codeTextBox_TextChanged(object sender, EventArgs e)
        {
            isSaved = false;
        }
    }
}
