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
    raise ArgumentError if n.nil? || 0 > n
    return 1 if n == 0
    return n = n * fact(n - 1)
  rescue => e
    return e
  end
end

=begin
b. フィボナッチ数。
=end
def fib(n)
  begin
    raise ArgumentError if n.nil? || 0 > n
    return 1 if n == 0 || n == 1
    return fib(n - 1) + fib(n - 2)
  rescue => e
    return e
  end
end

=begin
c. 組み合わせの数の計算
=end
def comb(n, r)
  begin
    raise ArgumentError if n.nil? || r.nil? || 0 > n || 0 > r || r > n
    return 1 if r == n || r == 0
    return comb(n - 1, r) + comb(n - 1, r - 1)
  rescue => e
    return e
  end
end

=begin
d. 正の整数 n の 2 進表現
=end
def binary(n)
end
