using System;

namespace helloWorld
{
    public class counter
    {
        private int m_count;
        private static int s_totalCount;
        public int getNextValue ()
        {
            m_count += 1;
            s_totalCount += 1;
            return m_count;
        }
        public static int totalcount
        {
            get
            {
                return s_totalCount;
            }
        }
    }
    public class countUser
    {
        public void run()
        {
            counter c = new counter();
            counter newc = c;
            Console.WriteLine("C:" + c.getNextValue());
            Console.WriteLine("C:" + newc.getNextValue());
        }
    }
    public class ImmutableCounter
    {
        private readonly int _count;
        private static int _totalCount;

        public ImmutableCounter()
        {
            _count = 0;
        }
        private ImmutableCounter ( int count)
        {
            _count = count;
        }
        public ImmutableCounter getNextVal()
        {
            _totalCount += 1;
            return new ImmutableCounter(_count + 1);
        }
        public static ImmutableCounter operator ++ ( ImmutableCounter input)
        {
            return input.getNextVal();
        }
        public int count
        {
            get
            {
                return _count;
            }
        }
        public static int TotalCount
        {
            get
            {
                return _totalCount;
            }
        }
    }
    public class ImmutableCountUser
    {
        public void run ()
        {
            ImmutableCounter c = new ImmutableCounter();
            ImmutableCounter newC = c;
            Console.WriteLine("C1:" + c.count);
            //newC++;
            c++;
            Console.WriteLine("C1:" + c.count);
        }
    }
    public class Program
    {
        public static void Main1(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
        public static void Main(string[] args)
        {
            ImmutableCountUser cu = new ImmutableCountUser();
            cu.run();
            //------------
            Console.WriteLine("next mutable counter");
            countUser newcu = new countUser();
            newcu.run();
        }
    }
}