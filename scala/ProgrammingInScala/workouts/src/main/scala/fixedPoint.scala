import math.abs
object FixedPoint{
  val tol = 0.0000001
  def averageDamp ( f:Double=>Double )(x:Double) :Double = (x + f(x))/2
  def isCloseEnough ( value:Double, guess:Double) : Boolean =
    if ( abs( guess - value )/guess < tol ) true else false

  def fp ( f:Double=>Double )(firstGuess:Double) = {
    def iterate ( guess:Double ) : Double = {
	  println ( "guess == " + guess )
	  val next = f(guess)
	  if ( isCloseEnough(next, guess) ) next
	  else iterate ( next )
	}
	iterate ( firstGuess )
  }
  //def sqrtByFP ( x:Double ) = fp ( y=>(y+x/y)/2 )(x)
  def sqrtByFP ( x:Double ) = fp ( averageDamp(y=>x/y) )(x)

  def main ( args: Array[String] ) = {
    val n = 10; println ( "fixed point for " + n + " is " + fp(x=>1+x/2) (n) )
    val m = 1 ; println ( "fixed point for " + m + " is " + fp(x=>1+x/2) (m) )
	val o = 9 ; println ( "sqrt by fixed point for " + o + " is " + sqrtByFP (o) )
  }
}
