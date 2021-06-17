#include <iostream>
#include <sstream>

using namespace std;

string toString( double v ) {
  ostringstream strs;
  strs << v;
  
  return strs.str();
}

struct Var {
  double operator ()( double x ) const {
    return x;
  }
  
  double dx( double x ) const {
    return 1;
  }
  
  string str() const {
    return "x";
  }
  
  string dx_str() const {
    return "1";
  }
};

Var x;

template <typename A, typename B>
struct Multiplicacao {
  
  Multiplicacao( A a, B b ): a( a ), b( b ) {}
  
  double operator ()( double x ) const {
    return a(x) * b(x);
  }
  
  double dx( double x ) const {
    return a(x)*b.dx(x) + a.dx(x)*b(x);
  }
  
  string str() const {
    return a.str() + "*" + b.str();
  }
  
  string dx_str() const {
    return "(" + a.str() + "*" + b.dx_str() + " + " 
         + a.dx_str() + "*" + b.str() + ")";
  }
  
  A a;
  B b;
};

template <typename B>
struct Multiplicacao<double,B> {
  
  Multiplicacao( double a, B b ): a( a ), b( b ) {}
  
  double operator ()( double x ) const {
    return a * b(x);
  }
  
  double dx( double x ) const {
    return a * b.dx(x);
  }
  
  string str() const {
    return toString( a ) + "*" + b.str();    
  }
  
  string dx_str() const {
    return "(" + toString( a ) + " * " + b.dx_str() + ")";
  }
  
  double a;
  B b;
};

template <typename A, typename B>
struct Divisao {
  
  Divisao( A a, B b ): a( a ), b( b ) {}
  
  double operator ()( double x ) const {
    return a(x) / b(x);
  }
  
  double dx( double x ) const {
    return (b(x)*a.dx(x) - a(x)*b.dx(x)) / (b(x)*b(x));
  }
  
  string str() const {
    return "( " + a.str() + " / " + b.str() + " )";
  }
  
  string dx_str() const {
    return "(( " + b.str() + " * " + a.dx_str() + " - " + a.str() + " * " + b.dx_str() +" ) / ( "+ b.str() + " * " + b.str() + "))";
  }
  
  A a;
  B b;
};

template <typename B>
struct Divisao<double,B> {
  
  Divisao( double a, B b ): a( a ), b( b ) {}
  
  double operator ()( double x ) const {
    return a / b(x);
  }
  
  double dx( double x ) const {
    return ( -1 * a * b.dx(x)) / (b(x)*b(x));
  }
  
  string str() const {
    return "( "+ toString( a ) + " / " + b.str() + " )";    
  }
  
  string dx_str() const {
    return "(( -1 * " + toString(a) + " * "  + b.dx_str() + " ) / (" + b.str() + " )^2)";
  }
  
  double a;
  B b;
};

template <typename B>
struct Divisao<B, double> {
  
  Divisao( B a, double b ): a ( a ), b( b ) {}
  
  double operator ()( double x ) const {
    return a(x) / b;
  }
  
  double dx( double x ) const {
    return (b*a.dx(x)) / (b*b);
  }
  
  string str() const {
    return "( " + a.str() + " / " + toString(b) + " )";    
  }
  
  string dx_str() const {
    return "(( " + toString(b) + " * "  + a.dx_str() + " ) / (" + toString(b) + " )^2)";
  }
  
  B a;
  double b;
};


template <typename A, typename B>
struct Soma {
  
  Soma( A a, B b ): a( a ), b( b ) {}
  
  double operator ()( double x ) const {
    return a(x) + b(x);
  }
  
  double dx( double x ) const {
    return a.dx(x)+ b.dx(x);
  }
  
  string str() const {
    return "( " + a.str() + " + " + b.str()+" )";
  }
  
  string dx_str() const {
    return "( " + a.dx_str() + "+" + b.dx_str() + ")";
  }
  
  A a;
  B b;
};

template <typename B>
struct Soma<double,B> {
  
  Soma(double a, B b ): a( a ), b( b ) {}
  
  double operator ()( double x ) const {
    return a + b(x);
  }
  
  double dx( double x ) const {
    return b.dx(x);
  }
  
  string str() const {
    return "( " + toString( a ) + " + " + b.str()+" )";    
  }
  
  string dx_str() const {
    return b.dx_str();
  }
  
  double a;
  B b;
};

template <typename A, typename B>
struct Subtracao {
  
  Subtracao ( A a, B b ): a( a ), b( b ) {}
  
  double operator ()( double x ) const {
    return a(x) - b(x);
  }
  
  double dx( double x ) const {
    return a.dx(x) - b.dx(x);
  }
  
  string str() const {
    return "( " + a.str() + " - " + b.str()+" )";
  }
  
  string dx_str() const {
    return "( " + a.dx_str() + " - " + b.dx_str() + ")";
  }
  
  A a;
  B b;
};

template <typename B>
struct Subtracao<double,B> {
  
  Subtracao (double a, B b ): a( a ), b( b ) {}
  
  double operator ()( double x ) const {
    return a - b(x);
  }
  
  double dx( double x ) const {
    return b.dx(x);
  }
  
  string str() const {
    return "( " + toString( a ) + " - " + b.str()+" )";    
  }
  
  string dx_str() const {
    return b.dx_str();
  }
  
  double a;
  B b;
};



template <typename A, typename B>
Soma<A,B> operator + ( A a, B b ) {
  return Soma<A,B>( a, b );
}

template <typename B>
Soma<double,B> operator + ( double a, B b ) {
  return Soma<double,B>( a, b );
}

template <typename F>
Soma<double, F > 
operator + ( F a, double b ) {
  return Soma<double, F > ( b, a );
}
template <typename B>
Soma<double,B> operator + ( int a, B b ) {
  return Soma<double,B>( a, b );
}

template <typename F>
Soma<double, F > 
operator + ( F a, int b ) {
  return Soma<double, F > ( b, a );
}



template <typename A, typename B>
Subtracao<A,B> operator - ( A a, B b ) {
  return Subtracao<A,B>( a, b );
}

template <typename B>
Subtracao<double,B> operator - ( double a, B b ) {
  return Subtracao<double,B>( a, b );
}

template <typename F>
Subtracao<double, F > 
operator - ( F a, double b ) {
  return Subtracao<double, F > ( b, a );
}
template <typename B>
Subtracao<double,B> operator - ( int a, B b ) {
  return Subtracao<double,B>( a, b );
}

template <typename F>
Subtracao<double, F > 
operator - ( F a, int b ) {
  return Subtracao<double, F > ( b, a );
}



template <typename A, typename B>
Multiplicacao<A,B> operator * ( A a, B b ) {
  return Multiplicacao<A,B>( a, b );
}

template <typename B>
Multiplicacao<double,B> operator * ( double a, B b ) {
  return Multiplicacao<double,B>( a, b );
}

template <typename F>
Multiplicacao<double, F > 
operator * ( Multiplicacao<double, F> a, double b ) {
  return Multiplicacao<double, F > ( a.a*b, a.b );
}
template <typename B>
Multiplicacao<double,B> operator * ( int a, B b ) {
  return Multiplicacao<double,B>( a, b );
}

template <typename F>
Multiplicacao<double, F > 
operator * ( Multiplicacao<double, F> a, int b ) {
  return Multiplicacao<double, F > ( a.a*b, a.b );
}

template <typename F>
Multiplicacao<double, F > 
operator * ( F a, int b ) {
  return Multiplicacao<double, F > ( b, a );
}



template <typename A, typename B>
Divisao<A,B> operator / ( A a, B b ) {
  return Divisao<A,B>( a, b );
}

template <typename B>
Divisao<double,B> operator / ( double a, B b ) {
  return Divisao<double,B>( a, b );
}

template <typename F>
Divisao<double, F > 
operator / ( Divisao<double, F> a, double b ) {
  return Divisao<double, F > ( a.a*b, a.b );
}
template <typename B>
Divisao<double,B> operator / ( int a, B b ) {
  return Divisao<B, double>( a, b );
}

template <typename F>
Divisao<double, F > 
operator / ( Divisao<double, F> a, int b ) {
  return Divisao< F, double > ( a.a*b, a.b );
}

template <typename F>
Divisao<double, F > 
operator / ( F a, int b ) {
  return Divisao< F, double> ( b, a );
}


int main() {
  auto f = 1/x;
  
  cout << f.str() << endl;
  cout << f.dx_str() << endl;
}

