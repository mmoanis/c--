using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace comp
{
    public static class FileController
    {
        /// <summary>
        /// Writes the given content to a given file.
        /// </summary>
        /// <param name="path">File path to write to</param>
        /// <param name="content">what to be written in file</param>
        public static void WriteToFile(string path, string content)
        {
            try
            {
                System.IO.File.WriteAllBytes(path, System.Text.Encoding.ASCII.GetBytes(content));
            }
            catch (Exception e)
            {
                /// log it
            }
        }
    }
}
