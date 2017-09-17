using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using helloWorld;

namespace testHelloWorld
{
    [TestClass]
    public class whenProgramRuns
    {
        private string _consoleOutput;
        [TestInitialize]
        public void Initialize()
        {
            var w = new System.IO.StringWriter();
            Console.SetOut(w);

            Program.Main(new string[0]);

            _consoleOutput = w.ToString().Trim();
        }
        [TestMethod]
        public void SaysHelloWorld()
        {
            Assert.AreEqual("Hello World!", _consoleOutput);
        }
    }
}
