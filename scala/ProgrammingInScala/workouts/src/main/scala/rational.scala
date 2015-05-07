object Rational {

  def addRational ( a:Rational, b:Rational):Rational = {
    new Rational ( a.numer*b.denom + a.denom*b.numer, a.denom*b.denom )
  }
  def toString ( a:Rational ) = a.numer + "/" + a.denom

  def main ( args:Array[String] ){
    val x= new Rational ( 1,3 )
    println ( "Numerator is " + x.numer )
    println ( "Denominator is " + x.denom )
	val b = new Rational ( 5,7 )
	// println ( "sum rational is " + toString(addRational(x,b)) )
	println ( "sum rational is " + (x + b) )
	val z = new Rational (3,2)
	// println ( "lecture assignment is" + x.sub(b).sub(z) )
	println ( "lecture assignment is" + (x - b - z) )

	println ( "y.add(y) with gcd is" + (b + b) )
	// val strange = new Rational ( 1,0)

	val newR = new Rational ( 2 );
	println ( "this is new rational with single constructor" + newR )
	println ( "max of " +x + " , " + b + " is " +  (x max b) )
	println ( "product of " +x + " , " + b + " is " +  (x * b) )
  }
}

class Rational ( x:Int, y:Int ){
  require ( y > 0 , "Rational cannot have less that or equal to 0 denominator" ) 

  private def abs(x:Int):Int = if ( x < 0 ) -x else x
  private def gcd(x:Int,y:Int):Int = if ( y == 0 ) x else gcd ( y, abs(x%y) )
  private val g = gcd ( x,y )
  def numer = x / g
  def denom = y / g
  def this(x:Int) = this(x,1)    /// another form to write a constructor
  override def toString = numer + "/" + denom
  // def add ( that:Rational ) : Rational = new Rational ( numer*that.denom + denom*that.numer, denom*that.denom )
  def + ( that:Rational ) : Rational = new Rational ( numer*that.denom + denom*that.numer, denom*that.denom )
  // def neg:Rational = new Rational ( -numer, denom )
  def unary_- :Rational = new Rational ( -numer, denom )
  //def sub ( that:Rational ) : Rational = new Rational ( numer*that.denom - denom*that.numer, denom*that.denom )
  // def sub ( that:Rational ) : Rational = add ( that.neg )
  // def - ( that:Rational ) : Rational = this +  that.neg 
  def - ( that:Rational ) : Rational = this +  -that
  // def less ( that:Rational ) : Boolean = this.numer*that.denom < that.numer*this.denom
  // def max ( that:Rational ) : Rational = if ( this.less(that) ) that else this
  def < ( that:Rational ) : Boolean = this.numer*that.denom < that.numer*this.denom
  def max ( that:Rational ) : Rational = if ( this < that ) that else this
  def * ( that:Rational ) : Rational = new Rational (this.numer*that.numer, this.denom*that.denom)
}
