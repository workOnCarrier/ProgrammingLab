package workout
object Main {
  def abs ( x:Double ) = if ( x < 0 )  -x else x

  def squareroot ( x:Double ) = {
    //def sqrtIter ( guess:Double, x:Double ) : Double = 
    //  if ( isGoodEnough ( guess, x ) ) guess
	//  else sqrtIter ( Improve(guess, x), x)

    //def isGoodEnough ( guess:Double, x:Double ) = abs(guess*guess - x ) < 0.0001
    //def Improve ( guess:Double,x:Double ) = (guess + x/guess)/2
    def sqrtIter ( guess:Double ) : Double = 
      if ( isGoodEnough ( guess) ) guess
	  else sqrtIter ( Improve(guess) )

    def isGoodEnough ( guess:Double ) = abs(guess*guess - x ) < 0.0001
    def Improve ( guess:Double ) = (guess + x/guess)/2

    sqrtIter ( 1.0 )
  }
  def main ( args:Array[String]) = 
  {
      println ( "Value of squqareRoot of 2 is " + squareroot ( 2 ) );
      println ( "Value of squqareRoot of 4 is " + squareroot ( 4 ) );
      println ( "Value of squqareRoot of 16 is " + squareroot ( 16 ) );
  }
}
