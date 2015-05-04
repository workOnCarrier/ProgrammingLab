object workoutHOF{

  // elementary building blocks
  def cube ( a:Int ) : Int = a*a*a
  def ident ( x:Int) : Int = x
  def fact(x:Int):Int = if ( x==0) 1 else x * fact(x-1)

  // plain definitions
  def sumInt ( a:Int, b:Int) : Int = if ( a > b ) 0 else a + sumInt(a+1,b)
  def sumCube ( a:Int, b:Int):Int = if ( a>b) 0 else cube(a) + sumCube ( a+1, b)

  // generic definition of summation of a fucntion
  def sum ( f:(Int)=>Int)( a:Int, b:Int ) : Int = if ( a > b ) 0 else f(a) + sum ( f)( a+1, b)

  def sumTailRec ( f:(Int)=>Int) (a:Int, b:Int) : Int = {
    def loop ( acc:Int, a:Int ) : Int = {              //  def loop ( acc:Int, a:Int, b:Int ) : Int = {
	  if ( a > b) acc else loop ( acc+f(a), a+1 )
	}
	loop ( 0, a )                                          //   loop ( 0, a, b )
  }
  def main ( args:Array[String])={
    println ( "sumInt of 2,4 is " + sumInt(2,4) )
    println ( "sumCube of 2,4 is " + sumCube(2,4) )

    println ( "sum(Id) of 2,4 is " + sum(ident)(2,4) )
    println ( "sum(Cube) of 2,4 is " + sum(cube)(2,4) )
    println ( "sum( fact ) of 2,4 is " + sum(fact  )(2,4) )

	println ( "using anonymous functions" )
    println ( "sum(x) of 2,4 is " + sum( x=>x )(2,4) )
    println ( "sum( x*x*x ) of 2,4 is " + sum( x=>x*x*x )(2,4) )

	println ( "using anonymous functions in tail recursion" )
    println ( "sum(x) of 2,4 is " + sumTailRec( x=>x )(2,4) )
    println ( "sum(x=>x*x) of 3,5 is " + sumTailRec( x=>x*x )(3,5) )
  }
}
