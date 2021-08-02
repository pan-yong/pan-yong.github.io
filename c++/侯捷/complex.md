###### 2021.8.2 

```c++
// complex.h

#ifndef __COMPLEX__
#define __COMPLEX__

class complex
{
    public:
    	complex(double r = 0, double i = 0)	 // 默认值
            : re (r), im (i)  				// 初始化列表
            { }
    	complex& operator += (const complex&); 
    	double real() const { return re; }
    	double imag() const { return im; }
    private:
    	double re, im;
    
    friend complex& __doapl (complex *ths, const complex &r);
}

// 操作符重载：成员函数写法
inline complex&
complex:: operator += (const complex &r)
{
    // 成员函数，隐藏了对象自己this指针
    return __doapl(this, r);
}

inline complex&
__doapl (complex *ths, const complex &r)
{
    ths->re += r.re;
    this->im += r.im;
    return *ths;
}

// 操作符重载：非成员函数写法
inline complex  // local 对象，不能传引用
operator + (const complex &x, const complex &y)
{
    return complex(x.real()+y.real(), 
                   x.imag() + y.imag() );
}

// 操作符重载：非成员函数写法
inline ostream&
operator << (ostream &os, const complex& x)
{
    
}

#endif
```

