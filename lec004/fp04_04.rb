require 'bigdecimal'
require 'bigdecimal/util'

def gcd(x,y)
  begin
    if x == y then
      return x
    elsif x > y
      return gcd(x - y, y)
    else
      return gcd(x, y - x)
    end
  rescue => e
    return e
  end
end

=begin
a. 階乗の計算。
=end
def fact(n)
  begin
    raise "n is Empty" if n == ''
    raise "n is Null" if n == nil
    raise "Out of Range" if 0 > n
    return 1 if n == 0
    return n = n * fact(n - 1)
  rescue => e
    return e
  end
end
