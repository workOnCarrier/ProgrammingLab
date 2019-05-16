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

            Program.Main1(new string[0]);

            _consoleOutput = w.ToString().Trim();
        }
        [TestMethod]
        public void SaysHelloWorld()
        {
            Assert.AreEqual("Hello World!", _consoleOutput);
        }
    }

    [TestClass]
    public class whenUsingImmutableCounter
    {
        private ImmutableCounter m_counter;
        [TestInitialize]
        public void Initialize()
        {
            m_counter = new ImmutableCounter();
        }
        [TestMethod]
        public void countImmutable()
        {
            ImmutableCounter c2 = m_counter;
            m_counter = m_counter.getNextVal();
            Assert.AreEqual(1, m_counter.count);
        }
    }

}
