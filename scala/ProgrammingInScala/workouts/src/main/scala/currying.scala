object workout_currying{
  
  def sum ( f: Int=> Int ) : (Int,Int)=>Int = {
	def loop ( acc:Int, a:Int, b:Int ) : Int = {
	  if ( a > b ) acc else loop ( f(a)+acc, a+1, b)
	}
	def sumF ( a:Int, b:Int ) : Int = loop ( 0, a, b)
	sumF
  }

  def sumSpecial ( f:Int=>Int)(a:Int,b:Int):Int = {
	// this does not work 
	// def loop ( acc:Int, a:Int, b:Int ):Int = if ( a>b) acc else loop ( f(a)+acc, a+1, b)
	// def sumF ( a:Int, b:Int ) : Int = loop (0, a,b)
	// sumF
    if ( a>b) 0 else f(a) + sumSpecial (f) ( a+1, b)
  }

  def prod  ( f:Int=>Int)(a:Int, b:Int):Int = {
    if ( a>b ) 1 else f(a) * prod (f) (a+1,b)
  }
  def fact ( x:Int ) : Int = prod ( x=>x ) (1,x)

  def mapReduce ( f:Int=>Int, combine:(Int,Int)=>Int, zero:Int) ( a:Int, b:Int) : Int = {
      if ( a > b ) zero 
	  else combine ( f(a), mapReduce (f, combine, zero)(a+1,b) )
  }

  def newProd ( f:Int=>Int)(a:Int,b:Int):Int = {
    mapReduce ( f, (x:Int,y:Int)=>x*y, 1 )(a,b)
  }

  def main ( args:Array[String] ) = {
    println ( "sum(x=>x*x*x)(2,4) gives the result : " + sum(x=>x*x*x)(2,4) )
    println ( "sum(x=>x*x)(3,5) gives the result : " + sum(x=>x*x)(3,5) )

    println ( "sumSpecial(x=>x*x*x)(2,4) gives the result : " + sumSpecial(x=>x*x*x)(2,4) )
    println ( "sumSpecial(x=>x*x)(3,5) gives the result : " + sumSpecial(x=>x*x)(3,5) )

    println ( "prod(x=>x)(3,5) gives the result : " + prod(x=>x)(3,5) )
    println ( "prod(x=>x*x)(3,4) gives the result : " + prod(x=>x*x)(3,4) )
    println ( "fact ( 5 ) in terms of product  gives the result : " + fact(5) )

	// new functionality
	println ( "  --- New functionality --- general function ---- " )
    println ( "newProd(x=>x)(3,5) gives the result : " + newProd(x=>x)(3,5) )
    println ( "newProd(x=>x*x)(3,4) gives the result : " + newProd(x=>x*x)(3,4) )
  }
}
