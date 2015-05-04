object Rational {

  def addRational ( a:Rational, b:Rational):Rational = {
    new Rational ( a.numer*b.denom + a.denom*b.numer, a.denom*b.denom )
  }
  def toString ( a:Rational ) = a.numer + "/" + a.denom

  def main ( args:Array[String] ){
    val x= new Rational ( 1,3 )
    println ( "Numerator is " + x.numer )
    println ( "Denominator is " + x.denom )
	val y = new Rational ( 5,7 )
	println ( "sum rational is " + toString(addRational(x,y)) )
	val z = new Rational (3,2)
	println ( "lecture assignment is" + x.sub(y).sub(z) )
  }
}

class Rational ( x:Int, y:Int ){
  def numer = x
  def denom = y
  override def toString = numer + "/" + denom
  def add ( that:Rational ) : Rational = new Rational ( numer*that.denom + denom*that.numer, denom*that.denom )
  def neg:Rational = new Rational ( -numer, denom )
  //def sub ( that:Rational ) : Rational = new Rational ( numer*that.denom - denom*that.numer, denom*that.denom )
  def sub ( that:Rational ) : Rational = add ( that.neg )
}
