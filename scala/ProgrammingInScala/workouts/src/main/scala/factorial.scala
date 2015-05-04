object WorkoutFact{
  def fact (n:Int):Int = {
    def loop ( acc:Int, n:Int):Int = if ( n== 0 ) acc else loop ( acc*n, n-1 )
    loop ( 1, n )  
  }
  def main ( args: Array[String] ) = {
    println ( "factorial of 5 is " + fact(5) )
    println ( "factorial of 3 is " + fact(3) )
    println ( "factorial of 4 is " + fact(4) )
    println ( "factorial of 6 is " + fact(6) )
  }

}
