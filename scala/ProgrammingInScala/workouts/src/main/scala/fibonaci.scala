object fiboncci{
  def square ( x:Int ) : Int = x*x
  def fibo ( n:Int ) : Int = if ( n == 1 ) 1 else if (n == 2 ) 1 else fibo ( n-1) + fibo ( n-2 )
  def fiboNby2 ( n:Int ) : Int = {
    if ( n == 1 ) 1 else if (n == 2 ) 1 else {
	  if ( n%2 == 0 ) square( fiboNby2 ( n/2 ) ) + 2 * fiboNby2 ( n/2 ) * fiboNby2 ( n/2-1 )
	  else 
	    square ( fiboNby2 ( (n/2)+1 ) ) + square ( fiboNby2 ( n/2 ) )
	}
  }
  
  def main ( args:Array[String] )={
    val n = 4
    println ( " " + n+"th term of fibonaci number via n/2 recursion is " + fiboNby2(n) )
    println ( " " + n+"th term of fibonaci number via n-1 + n-2  recursion is " + fibo(n) )
  }
}
